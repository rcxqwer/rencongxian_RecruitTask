#include "opencv2/opencv.hpp"
#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/image.hpp"
#include "cv_bridge/cv_bridge.h"

using namespace std;
using namespace cv;
using placeholders::_1;

class ImgPub : public rclcpp::Node
{
private:
    // 声明图片发布者
    rclcpp::Publisher<sensor_msgs::msg::Image>::SharedPtr img_pub;

    // 发布图片
    void publish_img(const sensor_msgs::msg::Image::SharedPtr msg)
    {
        img_pub->publish(*msg); // 发布图片
    }

public:
    ImgPub(string name) : Node(name)
    {
        RCLCPP_INFO(this->get_logger(), "Image is publishing·····");

        // 实例化图片发布者
        img_pub = this->create_publisher<sensor_msgs::msg::Image>("image", 1);

        // 读取图片
        // Mat img = imread(path);

        Mat img;
        // 连接摄像头
        VideoCapture cap(0);
        while (rclcpp::ok())
        {
            // 读取画面
            cap.read(img);

            if (img.empty())
            {
                RCLCPP_ERROR(this->get_logger(), "图片读取失败！");
                cap.release();
                return;
            }

            // 将图片转换为ros2格式
            sensor_msgs::msg::Image::SharedPtr msg = cv_bridge::CvImage(std_msgs::msg::Header(), "bgr8", img).toImageMsg();

            // 发布信息
            publish_img(msg);

            // 释放内存
            msg.reset();
        }
        cap.release();
    }
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);

    auto node = make_shared<ImgPub>("pub_node");

    rclcpp::spin(node);

    rclcpp::shutdown();
    return 0;
}