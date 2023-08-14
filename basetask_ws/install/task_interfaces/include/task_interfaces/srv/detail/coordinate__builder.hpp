// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from task_interfaces:srv/Coordinate.idl
// generated code does not contain a copyright notice

#ifndef TASK_INTERFACES__SRV__DETAIL__COORDINATE__BUILDER_HPP_
#define TASK_INTERFACES__SRV__DETAIL__COORDINATE__BUILDER_HPP_

#include "task_interfaces/srv/detail/coordinate__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace task_interfaces
{

namespace srv
{

namespace builder
{

class Init_Coordinate_Request_image
{
public:
  Init_Coordinate_Request_image()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::task_interfaces::srv::Coordinate_Request image(::task_interfaces::srv::Coordinate_Request::_image_type arg)
  {
    msg_.image = std::move(arg);
    return std::move(msg_);
  }

private:
  ::task_interfaces::srv::Coordinate_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::task_interfaces::srv::Coordinate_Request>()
{
  return task_interfaces::srv::builder::Init_Coordinate_Request_image();
}

}  // namespace task_interfaces


namespace task_interfaces
{

namespace srv
{

namespace builder
{

class Init_Coordinate_Response_y
{
public:
  explicit Init_Coordinate_Response_y(::task_interfaces::srv::Coordinate_Response & msg)
  : msg_(msg)
  {}
  ::task_interfaces::srv::Coordinate_Response y(::task_interfaces::srv::Coordinate_Response::_y_type arg)
  {
    msg_.y = std::move(arg);
    return std::move(msg_);
  }

private:
  ::task_interfaces::srv::Coordinate_Response msg_;
};

class Init_Coordinate_Response_x
{
public:
  Init_Coordinate_Response_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Coordinate_Response_y x(::task_interfaces::srv::Coordinate_Response::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_Coordinate_Response_y(msg_);
  }

private:
  ::task_interfaces::srv::Coordinate_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::task_interfaces::srv::Coordinate_Response>()
{
  return task_interfaces::srv::builder::Init_Coordinate_Response_x();
}

}  // namespace task_interfaces

#endif  // TASK_INTERFACES__SRV__DETAIL__COORDINATE__BUILDER_HPP_
