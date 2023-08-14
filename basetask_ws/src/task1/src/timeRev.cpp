#include <iostream>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "std_msgs/msg/u_int32.hpp"
#include <string>
#include <ctime>
using namespace std;

using std::placeholders::_1;

class timeRev : public rclcpp::Node
{
private:
    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr sub; // 声明订阅者

    // 回调函数
    void rev_callback(const std_msgs::msg::String::SharedPtr time)
    {
        // 打印当前时间
        RCLCPP_INFO(this->get_logger(), "%s", time->data.c_str());
    }

public:
    timeRev(string name) : Node(name)
    {
        sub = this->create_subscription<std_msgs::msg::String>("time", 10, bind(&timeRev::rev_callback, this, _1));
    }
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);

    auto node = make_shared<timeRev>("time");

    rclcpp::spin(node);

    rclcpp::shutdown();

    return 0;
}