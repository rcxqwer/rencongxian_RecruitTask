#include "opencv2/opencv.hpp"
#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/image.hpp"
#include "cv_bridge/cv_bridge.h"
#include "task_interfaces/srv/coordinate.hpp"

using namespace std;
using namespace cv;
using placeholders::_1;

class ImgClient : public rclcpp::Node
{
private:
    // 声明图片发布者
    rclcpp::Publisher<sensor_msgs::msg::Image>::SharedPtr img_pub;
    // 声明客户端
    rclcpp::Client<task_interfaces::srv::Coordinate>::SharedPtr img_client;

    // 发布图片
    void publish_img(const sensor_msgs::msg::Image::SharedPtr msg)
    {
        img_pub->publish(*msg); // 发布图片
    }

    // 发送请求
    void send_img(sensor_msgs::msg::Image::SharedPtr msg)
    {
        // 等待服务端上线
        while (!img_client->wait_for_service(chrono::seconds(2)) && rclcpp::ok())
        {
            RCLCPP_WARN(this->get_logger(), "等待服务端上线");
        }

        // 构造请求
        auto request = std::make_shared<task_interfaces::srv::Coordinate_Request>();

        request->image = *msg;

        // 发送请求
        auto future = img_client->async_send_request(request);

        if (rclcpp::spin_until_future_complete(this->get_node_base_interface(), future) == rclcpp::executor::FutureReturnCode::SUCCESS)
        {
            // 请求成功，调用回调函数
            client_callback(future);
        }
    }

    // 客户端回调函数
    void client_callback(const rclcpp::Client<task_interfaces::srv::Coordinate>::SharedFuture response)
    {
        auto result = response.get();

        // 输出坐标
        if (result->x - 0 < 1e-5 && result->y - 0 < 1e-5)
            return;
        RCLCPP_INFO(this->get_logger(), "(x,y) = (%.2f,%.2f)", result->x, result->y);
    }

public:
    ImgClient(string name) : Node(name)
    {
        RCLCPP_INFO(this->get_logger(), "This is client·····");

        // 实例化图片发布者
        img_pub = this->create_publisher<sensor_msgs::msg::Image>("image", 1);

        // 实例化客户端
        img_client = this->create_client<task_interfaces::srv::Coordinate>("Coordinate");

        Mat img;
        // 连接摄像头
        VideoCapture cap(0);

        // 读取画面
        cap.read(img);

        while (rclcpp::ok())
        {
            Mat img;
            cap.read(img);

            if (img.empty())
            {
                RCLCPP_ERROR(this->get_logger(), "无法读取图像！");
                break;
            }

            sensor_msgs::msg::Image::SharedPtr msg = cv_bridge::CvImage(std_msgs::msg::Header(), "bgr8", img).toImageMsg();

            // 发送图像并调用回调函数
            send_img(msg);

            // 释放内存
            msg.reset();
        }

        cap.release();
        destroyAllWindows();
    }
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);

    auto node = make_shared<ImgClient>("client_node");

    rclcpp::spin(node);

    rclcpp::shutdown();
    return 0;
}