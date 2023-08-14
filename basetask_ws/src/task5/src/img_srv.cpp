#include "opencv2/opencv.hpp"
#include "rclcpp/rclcpp.hpp"
#include "image_transport/image_transport.hpp"
#include "cv_bridge/cv_bridge.h"
#include "task_interfaces/srv/coordinate.hpp"

using namespace std;
using namespace cv;
using placeholders::_1;
using placeholders::_2;

class ImgSrv : public rclcpp::Node
{
private:
    // 声明订阅者
    rclcpp::Subscription<sensor_msgs::msg::Image>::SharedPtr image_sub;

    // 声明服务端
    rclcpp::Service<task_interfaces::srv::Coordinate>::SharedPtr img_srv;

    void image_callback(const sensor_msgs::msg::Image::SharedPtr msg)
    {
        RCLCPP_INFO(this->get_logger(), "Image has received");
        Mat img = cv_bridge::toCvCopy(msg, "bgr8")->image; // 将ros2格式转化为opencv格式

        // 处理图片
        // processImg(img);

        // 展示图片
        imshow("Image", img);
        waitKey(1);
    }

    void srv_callback(const task_interfaces::srv::Coordinate::Request::SharedPtr request,
                      const task_interfaces::srv::Coordinate::Response::SharedPtr response)
    {
        // 转化为opencv格式
        sensor_msgs::msg::Image image = request->image;
        Mat img = cv_bridge::toCvCopy(image, "bgr8")->image;

        // 处理图片
        Mat imgHSV, mask;

        // 转化为HSV颜色空间
        cvtColor(img, imgHSV, COLOR_BGR2HSV);

        // 阈值下限129
        int hmin = 47, smin = 72, vmin = 76;
        // 阈值上限
        int hmax = 93, smax = 255, vmax = 255;

        // 二值化
        Scalar lower(hmin, smin, vmin);
        Scalar upper(hmax, smax, vmax);
        inRange(imgHSV, lower, upper, mask);

        vector<vector<Point>> contours;

        // 轮廓检测
        findContours(mask, contours, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);

        vector<Rect> boundRect(contours.size());

        // 去除噪音
        for (int i = 0; i < (int)contours.size(); i++)
        {
            double area = contourArea(contours[i]);
            if (area < 1000)
                continue;
            boundRect[i] = boundingRect(contours[i]);

            cout << boundRect[i].x << ',' << boundRect[i].y << " " << i << endl;

            drawContours(img, contours, i, Scalar(255, 0, 255), 1);

            rectangle(img, boundRect[i], Scalar(0, 255, 0), 2);

            response->x = (double)boundRect[i].x;
            response->y = (double)boundRect[i].y;
        }
    }

public:
    ImgSrv(string name) : Node(name)
    {
        RCLCPP_INFO(this->get_logger(), "This is service·····");

        // 实例化订阅者
        image_sub = this->create_subscription<sensor_msgs::msg::Image>("image", 1, bind(&ImgSrv::image_callback, this, _1));

        // 实例化服务端
        img_srv = this->create_service<task_interfaces::srv::Coordinate>("Coordinate", bind(&ImgSrv::srv_callback, this, _1, _2));
    }
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);

    auto node = make_shared<ImgSrv>("srv_node");

    rclcpp::spin(node);

    rclcpp::shutdown();
    return 0;
}