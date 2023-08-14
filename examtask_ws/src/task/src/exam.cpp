#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/image.hpp"
#include "opencv2/opencv.hpp"
#include "cv_bridge/cv_bridge.h"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;
using placeholders::_1;

// 灯条类
class LightDescriptor
{
public:
    float width, length, angle, area; // 灯条的属性
    cv::Point2f center;               // 灯条中心坐标
public:
    LightDescriptor(){};
    LightDescriptor(const cv::RotatedRect &light) // 灯条函数
    {
        width = light.size.width;
        length = light.size.height;
        center = light.center;
        angle = light.angle;
        area = light.size.area();
    }
};

class ImgSub : public rclcpp::Node
{
public:
    ImgSub(string name) : Node(name)
    {
        RCLCPP_INFO(this->get_logger(), "Node is running");
        // 实例化客户端
        sub = this->create_subscription<sensor_msgs::msg::Image>("/color/image_raw", 10, bind(&ImgSub::image_callback, this, _1));
    }

private:
    // 声明订阅者
    rclcpp::Subscription<sensor_msgs::msg::Image>::SharedPtr sub;

    void image_callback(const sensor_msgs::msg::Image::SharedPtr msg)
    {
        // 尝试读取照片
        try
        {
            Mat image = cv_bridge::toCvCopy(msg, "bgr8")->image;
            // 处理照片
            processImg(image);

            // 显示照片
            imshow("Image", image);
            waitKey(1);
        }
        // 读取失败
        catch (cv_bridge::Exception &e)
        {
            RCLCPP_ERROR(this->get_logger(), "cv_bridge exception: %s", e.what());
            return;
        }
    }

    void processImg(Mat img)
    {
        Mat imgHSV, imgBlur, mask, imgDil, imgEro;

        // 转换颜色空间
        cvtColor(img, imgHSV, COLOR_BGR2HSV);

        int hmin = 80, smin = 0, vmin = 215;   // 阈值上限
        int hmax = 95, smax = 251, vmax = 255; // 阈值下限
        // namedWindow("Trackbars");
        // createTrackbar("Hue Min", "Trackbars", &hmin, 255);
        // createTrackbar("Hue Max", "Trackbars", &hmax, 255);
        // createTrackbar("Sat Min", "Trackbars", &smin, 255);
        // createTrackbar("Sat Max", "Trackbars", &smax, 255);
        // createTrackbar("Val Min", "Trackbars", &vmin, 255);
        // createTrackbar("Val Max", "Trackbars", &vmax, 255);

        vector<Mat> hsvSplit;
        split(imgHSV, hsvSplit); // 分离通道
        equalizeHist(hsvSplit[2], hsvSplit[2]);
        merge(hsvSplit, imgHSV); // 重新合并 提高对比度

        // 高斯模糊
        GaussianBlur(imgHSV, imgBlur, Size(3, 3), 3, 0);

        Scalar lower(hmin, smin, vmin);
        Scalar upper(hmax, smax, vmax);
        // 二值化
        inRange(imgBlur, lower, upper, mask);

        Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
        // 腐蚀和膨胀
        erode(mask, imgEro, kernel);
        dilate(imgEro, imgDil, kernel);

        // 找到轮廓
        vector<vector<Point>> contours;
        findContours(imgDil, contours, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
        vector<LightDescriptor> lightInfos; // 创建一个灯条类的动态数组

        vector<Rect> boundRect(contours.size());

        // 筛选灯条
        for (int i = 0; i < (int)contours.size(); i++)
        {
            // 面积
            double area = contourArea(contours[i]);

            if (area < 100 || contours[i].size() <= 5)
                continue;

            RotatedRect Light_Rec = fitEllipse(contours[i]);

            if (Light_Rec.size.width / Light_Rec.size.height > 4)
                continue;

            boundRect[i] = boundingRect(contours[i]);
            // drawContours(img, contours, i, Scalar(0, 0, 255), 2);
            // rectangle(img, boundRect[i], Scalar(255, 0, 255), 2);
            lightInfos.push_back(LightDescriptor(Light_Rec));
        }

        // 匹配灯条
        for (size_t i = 0; i < lightInfos.size(); i++)
        {
            for (size_t j = i + 1; (j < lightInfos.size()); j++)
            {
                LightDescriptor &leftLight = lightInfos[i];
                LightDescriptor &rightLight = lightInfos[j];
                float angleGap_ = abs(leftLight.angle - rightLight.angle);

                // 远近都要识别灯条，所以用比值去匹配
                // 两个相匹配的灯条长度之差和其中一个长度的比值不会大于1，因为两个灯条相同
                float LenGap_ratio = abs(leftLight.length - rightLight.length) / max(leftLight.length, rightLight.length);
                // 两个灯条的距离
                float dis = pow(pow((leftLight.center.x - rightLight.center.x), 2) + pow((leftLight.center.y - rightLight.center.y), 2), 0.5);

                // 均长
                float meanLen = (leftLight.length + rightLight.length) / 2;
                float lengap_ratio = abs(leftLight.length - rightLight.length) / meanLen;
                float yGap = abs(leftLight.center.y - rightLight.center.y);
                float yGap_ratio = yGap / meanLen;
                float xGap = abs(leftLight.center.x - rightLight.center.x);
                float xGap_ratio = xGap / meanLen;
                float ratio = dis / meanLen;

                // 匹配不通过的条件
                // 这些参数要根据实际去调整
                if (angleGap_ > 15 ||
                    LenGap_ratio > 1.0 ||
                    lengap_ratio > 0.8 ||
                    yGap_ratio > 1.5 ||
                    xGap_ratio > 2.2 ||
                    xGap_ratio < 0.8 ||
                    ratio > 3 ||
                    ratio < 0.8)
                {
                    continue;
                }

                // 绘制矩形
                // 两个灯条的中心点
                Point center = Point((leftLight.center.x + rightLight.center.x) / 2, (leftLight.center.y + rightLight.center.y) / 2);
                // 以中心点为原点的旋转矩形
                RotatedRect rect = RotatedRect(center, Size(dis, meanLen), (leftLight.angle + rightLight.angle) / 2);
                // 利用旋转矩形的四个点
                Point2f vertices[4];
                rect.points(vertices);
                for (int i = 0; i < 4; i++)
                {
                    line(img, vertices[i], vertices[(i + 1) % 4], Scalar(0, 255, 0), 2); // 有点巧妙
                }
            }
        }
    }
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);

    auto node = make_shared<ImgSub>("sub_node");

    rclcpp::spin(node);

    rclcpp::shutdown();

    return 0;
}