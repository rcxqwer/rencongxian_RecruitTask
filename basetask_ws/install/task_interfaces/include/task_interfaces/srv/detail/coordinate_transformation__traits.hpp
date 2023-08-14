// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from task_interfaces:srv/CoordinateTransformation.idl
// generated code does not contain a copyright notice

#ifndef TASK_INTERFACES__SRV__DETAIL__COORDINATE_TRANSFORMATION__TRAITS_HPP_
#define TASK_INTERFACES__SRV__DETAIL__COORDINATE_TRANSFORMATION__TRAITS_HPP_

#include "task_interfaces/srv/detail/coordinate_transformation__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<task_interfaces::srv::CoordinateTransformation_Request>()
{
  return "task_interfaces::srv::CoordinateTransformation_Request";
}

template<>
inline const char * name<task_interfaces::srv::CoordinateTransformation_Request>()
{
  return "task_interfaces/srv/CoordinateTransformation_Request";
}

template<>
struct has_fixed_size<task_interfaces::srv::CoordinateTransformation_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<task_interfaces::srv::CoordinateTransformation_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<task_interfaces::srv::CoordinateTransformation_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<task_interfaces::srv::CoordinateTransformation_Response>()
{
  return "task_interfaces::srv::CoordinateTransformation_Response";
}

template<>
inline const char * name<task_interfaces::srv::CoordinateTransformation_Response>()
{
  return "task_interfaces/srv/CoordinateTransformation_Response";
}

template<>
struct has_fixed_size<task_interfaces::srv::CoordinateTransformation_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<task_interfaces::srv::CoordinateTransformation_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<task_interfaces::srv::CoordinateTransformation_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<task_interfaces::srv::CoordinateTransformation>()
{
  return "task_interfaces::srv::CoordinateTransformation";
}

template<>
inline const char * name<task_interfaces::srv::CoordinateTransformation>()
{
  return "task_interfaces/srv/CoordinateTransformation";
}

template<>
struct has_fixed_size<task_interfaces::srv::CoordinateTransformation>
  : std::integral_constant<
    bool,
    has_fixed_size<task_interfaces::srv::CoordinateTransformation_Request>::value &&
    has_fixed_size<task_interfaces::srv::CoordinateTransformation_Response>::value
  >
{
};

template<>
struct has_bounded_size<task_interfaces::srv::CoordinateTransformation>
  : std::integral_constant<
    bool,
    has_bounded_size<task_interfaces::srv::CoordinateTransformation_Request>::value &&
    has_bounded_size<task_interfaces::srv::CoordinateTransformation_Response>::value
  >
{
};

template<>
struct is_service<task_interfaces::srv::CoordinateTransformation>
  : std::true_type
{
};

template<>
struct is_service_request<task_interfaces::srv::CoordinateTransformation_Request>
  : std::true_type
{
};

template<>
struct is_service_response<task_interfaces::srv::CoordinateTransformation_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // TASK_INTERFACES__SRV__DETAIL__COORDINATE_TRANSFORMATION__TRAITS_HPP_
