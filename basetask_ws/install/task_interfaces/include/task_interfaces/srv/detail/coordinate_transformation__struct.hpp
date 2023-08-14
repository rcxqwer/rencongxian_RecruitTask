// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from task_interfaces:srv/CoordinateTransformation.idl
// generated code does not contain a copyright notice

#ifndef TASK_INTERFACES__SRV__DETAIL__COORDINATE_TRANSFORMATION__STRUCT_HPP_
#define TASK_INTERFACES__SRV__DETAIL__COORDINATE_TRANSFORMATION__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__task_interfaces__srv__CoordinateTransformation_Request __attribute__((deprecated))
#else
# define DEPRECATED__task_interfaces__srv__CoordinateTransformation_Request __declspec(deprecated)
#endif

namespace task_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct CoordinateTransformation_Request_
{
  using Type = CoordinateTransformation_Request_<ContainerAllocator>;

  explicit CoordinateTransformation_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x_a = 0.0;
      this->y_a = 0.0;
      this->x_offset = 0.0;
      this->y_offset = 0.0;
      this->theta = 0.0;
    }
  }

  explicit CoordinateTransformation_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x_a = 0.0;
      this->y_a = 0.0;
      this->x_offset = 0.0;
      this->y_offset = 0.0;
      this->theta = 0.0;
    }
  }

  // field types and members
  using _x_a_type =
    double;
  _x_a_type x_a;
  using _y_a_type =
    double;
  _y_a_type y_a;
  using _x_offset_type =
    double;
  _x_offset_type x_offset;
  using _y_offset_type =
    double;
  _y_offset_type y_offset;
  using _theta_type =
    double;
  _theta_type theta;

  // setters for named parameter idiom
  Type & set__x_a(
    const double & _arg)
  {
    this->x_a = _arg;
    return *this;
  }
  Type & set__y_a(
    const double & _arg)
  {
    this->y_a = _arg;
    return *this;
  }
  Type & set__x_offset(
    const double & _arg)
  {
    this->x_offset = _arg;
    return *this;
  }
  Type & set__y_offset(
    const double & _arg)
  {
    this->y_offset = _arg;
    return *this;
  }
  Type & set__theta(
    const double & _arg)
  {
    this->theta = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    task_interfaces::srv::CoordinateTransformation_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const task_interfaces::srv::CoordinateTransformation_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<task_interfaces::srv::CoordinateTransformation_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<task_interfaces::srv::CoordinateTransformation_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      task_interfaces::srv::CoordinateTransformation_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<task_interfaces::srv::CoordinateTransformation_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      task_interfaces::srv::CoordinateTransformation_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<task_interfaces::srv::CoordinateTransformation_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<task_interfaces::srv::CoordinateTransformation_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<task_interfaces::srv::CoordinateTransformation_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__task_interfaces__srv__CoordinateTransformation_Request
    std::shared_ptr<task_interfaces::srv::CoordinateTransformation_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__task_interfaces__srv__CoordinateTransformation_Request
    std::shared_ptr<task_interfaces::srv::CoordinateTransformation_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const CoordinateTransformation_Request_ & other) const
  {
    if (this->x_a != other.x_a) {
      return false;
    }
    if (this->y_a != other.y_a) {
      return false;
    }
    if (this->x_offset != other.x_offset) {
      return false;
    }
    if (this->y_offset != other.y_offset) {
      return false;
    }
    if (this->theta != other.theta) {
      return false;
    }
    return true;
  }
  bool operator!=(const CoordinateTransformation_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct CoordinateTransformation_Request_

// alias to use template instance with default allocator
using CoordinateTransformation_Request =
  task_interfaces::srv::CoordinateTransformation_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace task_interfaces


#ifndef _WIN32
# define DEPRECATED__task_interfaces__srv__CoordinateTransformation_Response __attribute__((deprecated))
#else
# define DEPRECATED__task_interfaces__srv__CoordinateTransformation_Response __declspec(deprecated)
#endif

namespace task_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct CoordinateTransformation_Response_
{
  using Type = CoordinateTransformation_Response_<ContainerAllocator>;

  explicit CoordinateTransformation_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x_b = 0.0;
      this->y_b = 0.0;
    }
  }

  explicit CoordinateTransformation_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x_b = 0.0;
      this->y_b = 0.0;
    }
  }

  // field types and members
  using _x_b_type =
    double;
  _x_b_type x_b;
  using _y_b_type =
    double;
  _y_b_type y_b;

  // setters for named parameter idiom
  Type & set__x_b(
    const double & _arg)
  {
    this->x_b = _arg;
    return *this;
  }
  Type & set__y_b(
    const double & _arg)
  {
    this->y_b = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    task_interfaces::srv::CoordinateTransformation_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const task_interfaces::srv::CoordinateTransformation_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<task_interfaces::srv::CoordinateTransformation_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<task_interfaces::srv::CoordinateTransformation_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      task_interfaces::srv::CoordinateTransformation_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<task_interfaces::srv::CoordinateTransformation_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      task_interfaces::srv::CoordinateTransformation_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<task_interfaces::srv::CoordinateTransformation_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<task_interfaces::srv::CoordinateTransformation_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<task_interfaces::srv::CoordinateTransformation_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__task_interfaces__srv__CoordinateTransformation_Response
    std::shared_ptr<task_interfaces::srv::CoordinateTransformation_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__task_interfaces__srv__CoordinateTransformation_Response
    std::shared_ptr<task_interfaces::srv::CoordinateTransformation_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const CoordinateTransformation_Response_ & other) const
  {
    if (this->x_b != other.x_b) {
      return false;
    }
    if (this->y_b != other.y_b) {
      return false;
    }
    return true;
  }
  bool operator!=(const CoordinateTransformation_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct CoordinateTransformation_Response_

// alias to use template instance with default allocator
using CoordinateTransformation_Response =
  task_interfaces::srv::CoordinateTransformation_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace task_interfaces

namespace task_interfaces
{

namespace srv
{

struct CoordinateTransformation
{
  using Request = task_interfaces::srv::CoordinateTransformation_Request;
  using Response = task_interfaces::srv::CoordinateTransformation_Response;
};

}  // namespace srv

}  // namespace task_interfaces

#endif  // TASK_INTERFACES__SRV__DETAIL__COORDINATE_TRANSFORMATION__STRUCT_HPP_
