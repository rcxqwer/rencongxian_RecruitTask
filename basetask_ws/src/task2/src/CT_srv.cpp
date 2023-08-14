#include <iostream>
#include <string>
#include "rclcpp/rclcpp.hpp"
#include "task_interfaces/srv/coordinate_transformation.hpp"

using namespace std;
using placeholders::_1;
using placeholders::_2;

class CT_srv : public rclcpp::Node
{
private:
    // 声明服务端
    rclcpp::Service<task_interfaces::srv::CoordinateTransformation>::SharedPtr srv;

    // 服务端回调函数
    void srv_callback(const task_interfaces::srv::CoordinateTransformation::Request::SharedPtr request,
                      const task_interfaces::srv::CoordinateTransformation::Response::SharedPtr response)
    {
        RCLCPP_INFO(this->get_logger(), "收到一个请求 x:%lf y:%lf x_offset:%lf y_offset:%lf theta:%lf", request->x_a, request->y_a, request->x_offset, request->y_offset, request->theta);
        response->x_b = request->x_a * cos(request->theta) - request->y_a * sin(request->theta) + request->x_offset;
        response->y_b = request->x_a * sin(request->theta) + request->y_a * cos(request->theta) + request->y_offset;
    }

public:
    CT_srv(string name) : Node(name)
    {
        RCLCPP_INFO(this->get_logger(), "Service is starting ······");

        // 实例化服务
        srv = this->create_service<task_interfaces::srv::CoordinateTransformation>("coordinate_transformation", std::bind(&CT_srv::srv_callback, this, _1, _2));
    }
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = make_shared<CT_srv>("srv");

    rclcpp::spin(node);

    rclcpp::shutdown();

    return 0;
}