// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from task_interfaces:srv/CoordinateTransformation.idl
// generated code does not contain a copyright notice

#ifndef TASK_INTERFACES__SRV__DETAIL__COORDINATE_TRANSFORMATION__BUILDER_HPP_
#define TASK_INTERFACES__SRV__DETAIL__COORDINATE_TRANSFORMATION__BUILDER_HPP_

#include "task_interfaces/srv/detail/coordinate_transformation__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace task_interfaces
{

namespace srv
{

namespace builder
{

class Init_CoordinateTransformation_Request_theta
{
public:
  explicit Init_CoordinateTransformation_Request_theta(::task_interfaces::srv::CoordinateTransformation_Request & msg)
  : msg_(msg)
  {}
  ::task_interfaces::srv::CoordinateTransformation_Request theta(::task_interfaces::srv::CoordinateTransformation_Request::_theta_type arg)
  {
    msg_.theta = std::move(arg);
    return std::move(msg_);
  }

private:
  ::task_interfaces::srv::CoordinateTransformation_Request msg_;
};

class Init_CoordinateTransformation_Request_y_offset
{
public:
  explicit Init_CoordinateTransformation_Request_y_offset(::task_interfaces::srv::CoordinateTransformation_Request & msg)
  : msg_(msg)
  {}
  Init_CoordinateTransformation_Request_theta y_offset(::task_interfaces::srv::CoordinateTransformation_Request::_y_offset_type arg)
  {
    msg_.y_offset = std::move(arg);
    return Init_CoordinateTransformation_Request_theta(msg_);
  }

private:
  ::task_interfaces::srv::CoordinateTransformation_Request msg_;
};

class Init_CoordinateTransformation_Request_x_offset
{
public:
  explicit Init_CoordinateTransformation_Request_x_offset(::task_interfaces::srv::CoordinateTransformation_Request & msg)
  : msg_(msg)
  {}
  Init_CoordinateTransformation_Request_y_offset x_offset(::task_interfaces::srv::CoordinateTransformation_Request::_x_offset_type arg)
  {
    msg_.x_offset = std::move(arg);
    return Init_CoordinateTransformation_Request_y_offset(msg_);
  }

private:
  ::task_interfaces::srv::CoordinateTransformation_Request msg_;
};

class Init_CoordinateTransformation_Request_y_a
{
public:
  explicit Init_CoordinateTransformation_Request_y_a(::task_interfaces::srv::CoordinateTransformation_Request & msg)
  : msg_(msg)
  {}
  Init_CoordinateTransformation_Request_x_offset y_a(::task_interfaces::srv::CoordinateTransformation_Request::_y_a_type arg)
  {
    msg_.y_a = std::move(arg);
    return Init_CoordinateTransformation_Request_x_offset(msg_);
  }

private:
  ::task_interfaces::srv::CoordinateTransformation_Request msg_;
};

class Init_CoordinateTransformation_Request_x_a
{
public:
  Init_CoordinateTransformation_Request_x_a()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_CoordinateTransformation_Request_y_a x_a(::task_interfaces::srv::CoordinateTransformation_Request::_x_a_type arg)
  {
    msg_.x_a = std::move(arg);
    return Init_CoordinateTransformation_Request_y_a(msg_);
  }

private:
  ::task_interfaces::srv::CoordinateTransformation_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::task_interfaces::srv::CoordinateTransformation_Request>()
{
  return task_interfaces::srv::builder::Init_CoordinateTransformation_Request_x_a();
}

}  // namespace task_interfaces


namespace task_interfaces
{

namespace srv
{

namespace builder
{

class Init_CoordinateTransformation_Response_y_b
{
public:
  explicit Init_CoordinateTransformation_Response_y_b(::task_interfaces::srv::CoordinateTransformation_Response & msg)
  : msg_(msg)
  {}
  ::task_interfaces::srv::CoordinateTransformation_Response y_b(::task_interfaces::srv::CoordinateTransformation_Response::_y_b_type arg)
  {
    msg_.y_b = std::move(arg);
    return std::move(msg_);
  }

private:
  ::task_interfaces::srv::CoordinateTransformation_Response msg_;
};

class Init_CoordinateTransformation_Response_x_b
{
public:
  Init_CoordinateTransformation_Response_x_b()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_CoordinateTransformation_Response_y_b x_b(::task_interfaces::srv::CoordinateTransformation_Response::_x_b_type arg)
  {
    msg_.x_b = std::move(arg);
    return Init_CoordinateTransformation_Response_y_b(msg_);
  }

private:
  ::task_interfaces::srv::CoordinateTransformation_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::task_interfaces::srv::CoordinateTransformation_Response>()
{
  return task_interfaces::srv::builder::Init_CoordinateTransformation_Response_x_b();
}

}  // namespace task_interfaces

#endif  // TASK_INTERFACES__SRV__DETAIL__COORDINATE_TRANSFORMATION__BUILDER_HPP_
