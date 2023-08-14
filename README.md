# rencongxian_RecruitTask

下载项目

``` bash
git clone https://github.com/rcxqwer/rencongxian_RecruitTask.git
```

切换目录

``` bash
cd rencongxian_RecruitTask/basetask_ws
```

编译文件

```bash
source install/setup.bash
```

``` bash
colcon build
```

```bash
source install/setup.bash
```

## **基础任务**

### 任务一

- 请你利用话题实时传输当前时间

```bash
ros2 run task1 timeRev 
```

新建一个终端

```bash
source install/setup.bash
ros2 run task1 timeTsm
```

然后在 timeRev 就能看到传输的时间(2秒一次)



实现

要实现该功能，首先需要发布话题，然后订阅该话题，该话题的内容是当前系统时间(用string来保存)，最后在订阅端输出当前时间来验证。

一、发布者( timeTsm.cpp)

1.首先要创建发布者

```cpp
rclcpp::Publisher<std_msgs::msg::String>::SharedPtr pub; 
```

2.然后将其初始化(话题为time)

```cpp
pub = this->create_publisher<std_msgs::msg::String>("time", 10); 
```

3.写一个获得当前系统时间成员函数

```cpp
string get_cur_time()
{
    time_t cur_time = time(nullptr); // 获取系统时间

    struct tm *timeinfo;
    char buffer[128];

    timeinfo = localtime(&cur_time); // 转换时间戳
    strftime(buffer, sizeof(buffer), "%Y/%m/%d %H:%M:%S", timeinfo);
    return buffer;
}
```

4.循环发布时间

```cpp
while (rclcpp::ok())
{
    std_msgs::msg::String cur_time;
    cur_time.data = get_cur_time(); // 获取当前时间

    pub->publish(cur_time);

    rate.sleep();
}
```

完整代码

```cpp
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
```

二、订阅者( timeRev.cpp)

1.创建订阅者

```cpp
rclcpp::Subscription<std_msgs::msg::String>::SharedPtr sub;
```

2.写回调函数

```cpp
void rev_callback(const std_msgs::msg::String::SharedPtr time)
{
    // 打印当前时间
    RCLCPP_INFO(this->get_logger(), "%s", time->data.c_str());
}
```

3.初始化订阅者

```cpp
sub = this->create_subscription<std_msgs::msg::String>("time", 10, bind(&timeRev::rev_callback, this, _1));
```

完整代码

```cpp
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
```



### 任务二

- 请你利用服务实现坐标转换
- 如：存在两个平面直角坐标系，且知道这两个坐标系的相对位置，给定一个点的坐标，求解该点在另外一个坐标系的位置，要求数据输入：点的坐标，两坐标系的相对位置

```bash
source install/setup.bash 
ros2 run task2 CT_client_node
```

打开另一个终端

```bash
source install/setup.bash
ros2 run task2 CT_srv_node 
```

在 CT_client_node 输入坐标，就会返回转换后的坐标



要实现该功能，首先需要定义一个新的接口，request 括点的坐标和两坐标系的相对位置,，response 包括 另一个点的坐标.

```cpp
# request
float64 x_a
float64 y_a  
float64 x_offset  
float64 y_offset  
float64 theta  
---
# response
float64 x_b  
float64 y_b  
```

一、服务端 (CT_client.cpp): 接收 request 并对其处理;

1.创建客户端 

```cpp
rclcpp::Client<task_interfaces::srv::CoordinateTransformation>::SharedPtr client;
```

2.创建回调函数

```cpp
void srv_callback(const task_interfaces::srv::CoordinateTransformation::Request::SharedPtr request,
                      const task_interfaces::srv::CoordinateTransformation::Response::SharedPtr response)
{
    RCLCPP_INFO(this->get_logger(), "收到一个请求 x:%lf y:%lf x_offset:%lf y_offset:%lf theta:%lf", request->x_a, request->y_a, request->x_offset, request->y_offset, request->theta);
    response->x_b = request->x_a * cos(request->theta) - request->y_a * sin(request->theta) + request->x_offset;
    response->y_b = request->x_a * sin(request->theta) + request->y_a * cos(request->theta) + request->y_offset;
}
```

3.初始化客户端

```cpp
srv = this->create_service<task_interfaces::srv::CoordinateTransformation>("coordinate_transformation", std::bind(&CT_srv::srv_callback, this, _1, _2));
```

完整代码

```cpp
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
```



二、客户端 (CT_srv.cpp): 输入数据(request), 发送数据, 输出结果;

1.创建客户端

```cpp
rclcpp::Client<task_interfaces::srv::CoordinateTransformation>::SharedPtr client;
```

2.创建服务端回调函数

```cpp
void client_callback(rclcpp::Client<task_interfaces::srv::CoordinateTransformation>::SharedFuture response)
{
    auto result = response.get();

    // 输出转换后的坐标
    RCLCPP_INFO(this->get_logger(), "转换之后的坐标: (%.2lf,%.2lf)", result->x_b, result->y_b);
}
```

3.初始化客户端

```cpp
 client = this->create_client<task_interfaces::srv::CoordinateTransformation>("coordinate_transformation");
```

4.循环发送请求

```cpp
while (rclcpp::ok())
{
// 发送请求
    send_request();
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
```

完整代码

```cpp
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
```





### 任务三

- 利用opencv识别某张图片里的物品

要修改一下图片的目录

```bash
source install/setup.bash 
```

```
ros2 run task3 detect_node 
```

修改代码之后 
``` bash
colcon build --packages-select task3
source install/setup.bash 

```


我的打算是用opencv识别图片中的一些多边形，如(三角形，矩形，圆)
1.转换图片颜色空间，高斯模糊，Canny边缘检测，膨胀处理
2.描绘出多边形的轮廓

完整代码

```cpp
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
        string path = "/home/rcx/workspaece/imgs/detect_test.png"; // 根据情况换成实际的目录
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
```



### 任务四

- 将电脑摄像头连接到虚拟机，编写两个节点，节点之间通过话题进行通讯，节点一为图像获取并发送出去，节点二为接收图像并进行识别

将摄像头接入虚拟机

```bash
source install/setup.bash
ros2 run task4 img_sub_node
```

打开另一个终端

```
source install/setup.bash
ros2 run task4 img_pub_node
```



在节点一连接电脑摄像头，实时读取摄像头的每一帧以图片的形式保存下来，发送到节点一；
节点二接受图片后进行处理；

**问题1: 怎么传输图片？**
**ros2 中包内置了保存图片的库  ->  sensor_msgs/msg/image.hpp**

**问题2：ros2的图片怎么和opencv的图片关联起来**
**ros2 内置了 cv_bridge 库，可以将 ros2 格式的图片和 opencv 的图片相互转换**

如果用任务三的代码来进行识别，我发现接上摄像头后的情况有点复杂，不太好进行识别处理,  所以我更换了代码，识别的是一块绿色的海绵(相对来说好识别一点)。

完整代码

一、发布者

```cpp
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
```

二、订阅者

```cpp
#include "opencv2/opencv.hpp"
#include "rclcpp/rclcpp.hpp"
#include "image_transport/image_transport.hpp"
#include "cv_bridge/cv_bridge.h"

using namespace std;
using namespace cv;
using placeholders::_1;

class ImgSub : public rclcpp::Node
{
private:
    // 声明订阅者
    rclcpp::Subscription<sensor_msgs::msg::Image>::SharedPtr image_sub;

    void image_callback(const sensor_msgs::msg::Image::SharedPtr msg)
    {
        RCLCPP_INFO(this->get_logger(), "Image has received");

        // 将ros2格式转化为opencv格式
        Mat img = cv_bridge::toCvCopy(msg, "bgr8")->image;

        // 处理图片
        processImg(img);

        // 展示图片
        imshow("Image", img);
        waitKey(1);
    }

    void processImg(Mat img)
    {
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
            cout << area << endl;
            boundRect[i] = boundingRect(contours[i]);
            drawContours(img, contours, i, Scalar(255, 0, 255), 1);
            rectangle(img, boundRect[i], Scalar(0, 255, 0), 2);
        }
    }

public:
    ImgSub(string name) : Node(name)
    {
        RCLCPP_INFO(this->get_logger(), "Image is receiving·····");

        image_sub = this->create_subscription<sensor_msgs::msg::Image>("image", 1, bind(&ImgSub::image_callback, this, _1));
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
```



### 任务五

- 在任务四的基础上，增加一个服务通讯，尝试获取物品的坐标点，并思考：在实时获取物品的坐标上，话题和服务哪个更为合适？

```bash
source install/setup.bash
ros2 run task5 img_srv_node
```

打开另外一个终端

```bash
source install/setup.bash
ros2 run task5 img_srv_node
```

把绿色的海绵放在摄像头前移动就能获取到坐标


思考：考虑实际情况，机器人获取到图片，交给电脑处理，但是如果机器人想要获取到实时坐标，就要获得电脑返回处理的结果，才能知道物品坐标，如果用话题，就得不到处理的结果，因此用服务比较合适。

在描绘图像轮廓时，利用 boundingRect() 函数，就能获取到图像左上角和右下角的坐标了，再进行处理就能得到中心坐标。

完整代码

一、服务端 

```
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
```

二、客户端

```
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
```

## **考核任务**

代码借鉴了https://blog.csdn.net/weixin_64054906/article/details/126674493
因为刚开始学opencv，很多都不太懂，因此就借鉴了别人的代码，利用了别人的思路来进行实现。

切换路径
```bash
cd ..
cd examtask_ws

```
编译环境
``` bash
source install/setup.bash
colcon build
source install/setup.bash
```
运行代码
``` bash
ros2 run task exam_node
```
发布视频

``` bash
ros2 bag play vision_task_0.db3

```


查看视频数据

```bash
ros2 bag info vision_task_0.db3
```

找到视频发布的话题

```bash
color/image_raw
```

打开另一个终端
发布视频 
```bash
ros2 bag play vison_task_0.db3
```

编写程序接收话题信息



基本的代码框架，先读取视频，对视频进行分析。

```cpp
#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/image.hpp"
#include "opencv2/opencv.hpp"
#include "cv_bridge/cv_bridge.h"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;
using placeholders::_1;

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
            // processImg(image);

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

};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);

    auto node = make_shared<ImgSub>("sub_node");

    rclcpp::spin(node);

    rclcpp::shutdown();

    return 0;
}
```

下一步就是要利用灯条来识别装甲板了。

首先要找到两个相互匹配的灯条(左灯条和右灯条)，那应该怎么来找到这对灯条呢。
在网上看到了一些方法，包括利用了灯条的长宽比，角度，距离等等属性来进行匹配。
因为要用到灯条的属性，所以创建一个灯条类，方便使用

```cpp
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
```

然后在筛选灯条时，把灯条保存起来，然后进行匹配

```
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
```

最后就完成了装甲板的识别。

完整代码

```cpp
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
```
