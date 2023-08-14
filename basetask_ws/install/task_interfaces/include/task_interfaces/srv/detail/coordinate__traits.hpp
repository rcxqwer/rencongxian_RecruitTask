// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from task_interfaces:srv/Coordinate.idl
// generated code does not contain a copyright notice

#ifndef TASK_INTERFACES__SRV__DETAIL__COORDINATE__TRAITS_HPP_
#define TASK_INTERFACES__SRV__DETAIL__COORDINATE__TRAITS_HPP_

#include "task_interfaces/srv/detail/coordinate__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

// Include directives for member types
// Member 'image'
#include "sensor_msgs/msg/detail/image__traits.hpp"

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<task_interfaces::srv::Coordinate_Request>()
{
  return "task_interfaces::srv::Coordinate_Request";
}

template<>
inline const char * name<task_interfaces::srv::Coordinate_Request>()
{
  return "task_interfaces/srv/Coordinate_Request";
}

template<>
struct has_fixed_size<task_interfaces::srv::Coordinate_Request>
  : std::integral_constant<bool, has_fixed_size<sensor_msgs::msg::Image>::value> {};

template<>
struct has_bounded_size<task_interfaces::srv::Coordinate_Request>
  : std::integral_constant<bool, has_bounded_size<sensor_msgs::msg::Image>::value> {};

template<>
struct is_message<task_interfaces::srv::Coordinate_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<task_interfaces::srv::Coordinate_Response>()
{
  return "task_interfaces::srv::Coordinate_Response";
}

template<>
inline const char * name<task_interfaces::srv::Coordinate_Response>()
{
  return "task_interfaces/srv/Coordinate_Response";
}

template<>
struct has_fixed_size<task_interfaces::srv::Coordinate_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<task_interfaces::srv::Coordinate_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<task_interfaces::srv::Coordinate_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<task_interfaces::srv::Coordinate>()
{
  return "task_interfaces::srv::Coordinate";
}

template<>
inline const char * name<task_interfaces::srv::Coordinate>()
{
  return "task_interfaces/srv/Coordinate";
}

template<>
struct has_fixed_size<task_interfaces::srv::Coordinate>
  : std::integral_constant<
    bool,
    has_fixed_size<task_interfaces::srv::Coordinate_Request>::value &&
    has_fixed_size<task_interfaces::srv::Coordinate_Response>::value
  >
{
};

template<>
struct has_bounded_size<task_interfaces::srv::Coordinate>
  : std::integral_constant<
    bool,
    has_bounded_size<task_interfaces::srv::Coordinate_Request>::value &&
    has_bounded_size<task_interfaces::srv::Coordinate_Response>::value
  >
{
};

template<>
struct is_service<task_interfaces::srv::Coordinate>
  : std::true_type
{
};

template<>
struct is_service_request<task_interfaces::srv::Coordinate_Request>
  : std::true_type
{
};

template<>
struct is_service_response<task_interfaces::srv::Coordinate_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // TASK_INTERFACES__SRV__DETAIL__COORDINATE__TRAITS_HPP_
