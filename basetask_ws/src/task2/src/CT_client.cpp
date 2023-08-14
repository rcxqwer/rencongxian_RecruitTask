#include <iostream>
#include <string>
#include "rclcpp/rclcpp.hpp"
#include "task_interfaces/srv/coordinate_transformation.hpp"

using namespace std;
using placeholders::_1;
using placeholders::_2;

class CT_client : public rclcpp::Node
{
private:
    // 创建客户端
    rclcpp::Client<task_interfaces::srv::CoordinateTransformation>::SharedPtr client;

    // 客户端回调函数
    void client_callback(rclcpp::Client<task_interfaces::srv::CoordinateTransformation>::SharedFuture response)
    {
        auto result = response.get();

        // 输出转换后的坐标
        RCLCPP_INFO(this->get_logger(), "转换之后的坐标: (%.2lf,%.2lf)", result->x_b, result->y_b);
    }

public:
    CT_client(string name) : Node(name)
    {
        RCLCPP_INFO(this->get_logger(), "This is Client");

        // 实例化客户端
        client = this->create_client<task_interfaces::srv::CoordinateTransformation>("coordinate_transformation");

        while (rclcpp::ok())
        {
            // 发送请求
            send_request();
        }
    }

    // 发送请求
    void send_request()
    {
        // 等待服务端上线
        while (!client->wait_for_service(chrono::seconds(2)))
        {
            RCLCPP_WARN(this->get_logger(), "等待服务端上线");
        }

        // 构造request
        auto request = std::make_shared<task_interfaces::srv::CoordinateTransformation_Request>();
        double x, y, x_offset, y_offset, theta;
        RCLCPP_INFO(this->get_logger(), "请依次输入x, y, x_offset, y_offset, theta");
        cin >> x >> y >> x_offset >> y_offset >> theta;
        request->x_a = x;
        request->y_a = y;
        request->x_offset = x_offset;
        request->y_offset = y_offset;
        request->theta = theta;

        // 发送异步数据
        auto future = client->async_send_request(request);

        if (rclcpp::spin_until_future_complete(this->get_node_base_interface(), future) == rclcpp::executor::FutureReturnCode::SUCCESS)
        {
            // 请求成功，调用回调函数
            client_callback(future);
        }
    }
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);

    auto node = make_shared<CT_client>("client");

    rclcpp::spin(node);

    rclcpp::shutdown();
    return 0;
}