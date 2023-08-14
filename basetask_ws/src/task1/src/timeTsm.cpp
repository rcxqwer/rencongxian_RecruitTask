#include <iostream>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "std_msgs/msg/u_int32.hpp"
#include <string>
#include <ctime>
using namespace std;

class timeTsm : public rclcpp::Node
{
private:
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr pub; // 声明发布者

    // 获取当前时间
    string get_cur_time()
    {
        time_t cur_time = time(nullptr); // 获取系统时间

        struct tm *timeinfo;
        char buffer[128];

        timeinfo = localtime(&cur_time); // 转换时间戳
        strftime(buffer, sizeof(buffer), "%Y/%m/%d %H:%M:%S", timeinfo);
        return buffer;
    }

public:
    timeTsm(string name) : Node(name)
    {
        pub = this->create_publisher<std_msgs::msg::String>("time", 10); // 初始化发布者

        rclcpp::Rate rate(0.5);
        while (rclcpp::ok())
        {
            std_msgs::msg::String cur_time;
            cur_time.data = get_cur_time(); // 获取当前时间

            pub->publish(cur_time);

            // pub->publish<std_msgs::msg::String>(cur_time); // 发布当前时间
            rate.sleep();
        }
    }
};

// 主函数
int main(int argc, char **argv)
{
    rclcpp::init(argc, argv); // 初始化

    auto node = make_shared<timeTsm>("time");

    rclcpp::spin(node);

    rclcpp::shutdown();

    return 0;
}