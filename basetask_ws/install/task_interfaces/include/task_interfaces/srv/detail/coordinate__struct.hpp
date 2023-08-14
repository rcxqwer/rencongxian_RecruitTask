// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from task_interfaces:srv/Coordinate.idl
// generated code does not contain a copyright notice

#ifndef TASK_INTERFACES__SRV__DETAIL__COORDINATE__STRUCT_HPP_
#define TASK_INTERFACES__SRV__DETAIL__COORDINATE__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


// Include directives for member types
// Member 'image'
#include "sensor_msgs/msg/detail/image__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__task_interfaces__srv__Coordinate_Request __attribute__((deprecated))
#else
# define DEPRECATED__task_interfaces__srv__Coordinate_Request __declspec(deprecated)
#endif

namespace task_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Coordinate_Request_
{
  using Type = Coordinate_Request_<ContainerAllocator>;

  explicit Coordinate_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : image(_init)
  {
    (void)_init;
  }

  explicit Coordinate_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : image(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _image_type =
    sensor_msgs::msg::Image_<ContainerAllocator>;
  _image_type image;

  // setters for named parameter idiom
  Type & set__image(
    const sensor_msgs::msg::Image_<ContainerAllocator> & _arg)
  {
    this->image = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    task_interfaces::srv::Coordinate_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const task_interfaces::srv::Coordinate_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<task_interfaces::srv::Coordinate_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<task_interfaces::srv::Coordinate_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      task_interfaces::srv::Coordinate_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<task_interfaces::srv::Coordinate_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      task_interfaces::srv::Coordinate_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<task_interfaces::srv::Coordinate_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<task_interfaces::srv::Coordinate_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<task_interfaces::srv::Coordinate_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__task_interfaces__srv__Coordinate_Request
    std::shared_ptr<task_interfaces::srv::Coordinate_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__task_interfaces__srv__Coordinate_Request
    std::shared_ptr<task_interfaces::srv::Coordinate_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Coordinate_Request_ & other) const
  {
    if (this->image != other.image) {
      return false;
    }
    return true;
  }
  bool operator!=(const Coordinate_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Coordinate_Request_

// alias to use template instance with default allocator
using Coordinate_Request =
  task_interfaces::srv::Coordinate_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace task_interfaces


#ifndef _WIN32
# define DEPRECATED__task_interfaces__srv__Coordinate_Response __attribute__((deprecated))
#else
# define DEPRECATED__task_interfaces__srv__Coordinate_Response __declspec(deprecated)
#endif

namespace task_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Coordinate_Response_
{
  using Type = Coordinate_Response_<ContainerAllocator>;

  explicit Coordinate_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x = 0.0;
      this->y = 0.0;
    }
  }

  explicit Coordinate_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x = 0.0;
      this->y = 0.0;
    }
  }

  // field types and members
  using _x_type =
    double;
  _x_type x;
  using _y_type =
    double;
  _y_type y;

  // setters for named parameter idiom
  Type & set__x(
    const double & _arg)
  {
    this->x = _arg;
    return *this;
  }
  Type & set__y(
    const double & _arg)
  {
    this->y = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    task_interfaces::srv::Coordinate_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const task_interfaces::srv::Coordinate_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<task_interfaces::srv::Coordinate_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<task_interfaces::srv::Coordinate_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      task_interfaces::srv::Coordinate_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<task_interfaces::srv::Coordinate_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      task_interfaces::srv::Coordinate_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<task_interfaces::srv::Coordinate_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<task_interfaces::srv::Coordinate_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<task_interfaces::srv::Coordinate_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__task_interfaces__srv__Coordinate_Response
    std::shared_ptr<task_interfaces::srv::Coordinate_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__task_interfaces__srv__Coordinate_Response
    std::shared_ptr<task_interfaces::srv::Coordinate_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Coordinate_Response_ & other) const
  {
    if (this->x != other.x) {
      return false;
    }
    if (this->y != other.y) {
      return false;
    }
    return true;
  }
  bool operator!=(const Coordinate_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Coordinate_Response_

// alias to use template instance with default allocator
using Coordinate_Response =
  task_interfaces::srv::Coordinate_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace task_interfaces

namespace task_interfaces
{

namespace srv
{

struct Coordinate
{
  using Request = task_interfaces::srv::Coordinate_Request;
  using Response = task_interfaces::srv::Coordinate_Response;
};

}  // namespace srv

}  // namespace task_interfaces

#endif  // TASK_INTERFACES__SRV__DETAIL__COORDINATE__STRUCT_HPP_
