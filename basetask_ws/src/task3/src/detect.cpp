#include "opencv4/opencv2/opencv.hpp"
#include "rclcpp/rclcpp.hpp"

using namespace cv;
using namespace std;

class Detect : public rclcpp::Node
{
private:
    void getContours(Mat imgDil, Mat img)
    {
        vector<vector<Point>> contours;
        vector<Vec4i> hierarchy;

        findContours(imgDil, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE); // 找到图片轮廓

        vector<Rect> boundRect(contours.size());

        for (int i = 0; i < (int)contours.size(); i++)
        {
            double area = contourArea(contours[i]);
            // 去除较小的噪音
            if (area < 1000)
                continue;

            // 找到该多边形的坐标
            boundRect[i] = boundingRect(contours[i]);

            // 画出多边形轮廓
            drawContours(img, contours, i, Scalar(0, 0, 255), 2);

            // 画出矩形
            rectangle(img, boundRect[i], Scalar(0, 255, 0), 2);
        }
    }

public:
    Detect(string name) : Node(name)
    {
        RCLCPP_INFO(this->get_logger(), "Detecting node is running");

        // 读取图片
        string path = "/home/rcx/workspaece/imgs/detect_test.png";
        Mat img = imread(path);

        if (img.empty())
        {
            RCLCPP_ERROR(this->get_logger(), "图片读取失败！");
            return;
        }

        Mat imgGray, imgBlur, imgCanny, imgDil;

        // 处理图片

        cvtColor(img, imgGray, COLOR_BGR2GRAY); // 转化为灰度图

        GaussianBlur(imgGray, imgBlur, Size(3, 3), 3, 0); // 高斯模糊

        Canny(imgBlur, imgCanny, 25, 75); // 边缘检测
        imshow("canny", imgCanny);

        Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3)); // 内核
        dilate(imgCanny, imgDil, kernel);                           // 膨胀

        getContours(imgDil, img); // 检测图片轮廓

        imshow("Image", img);
        waitKey(0);
    }
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);

    auto node = make_shared<Detect>("node");

    rclcpp::spin(node);

    rclcpp::shutdown();
    return 0;
}