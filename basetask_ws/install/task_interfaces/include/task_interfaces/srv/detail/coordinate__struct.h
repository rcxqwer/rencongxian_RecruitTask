// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from task_interfaces:srv/Coordinate.idl
// generated code does not contain a copyright notice

#ifndef TASK_INTERFACES__SRV__DETAIL__COORDINATE__STRUCT_H_
#define TASK_INTERFACES__SRV__DETAIL__COORDINATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'image'
#include "sensor_msgs/msg/detail/image__struct.h"

// Struct defined in srv/Coordinate in the package task_interfaces.
typedef struct task_interfaces__srv__Coordinate_Request
{
  sensor_msgs__msg__Image image;
} task_interfaces__srv__Coordinate_Request;

// Struct for a sequence of task_interfaces__srv__Coordinate_Request.
typedef struct task_interfaces__srv__Coordinate_Request__Sequence
{
  task_interfaces__srv__Coordinate_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} task_interfaces__srv__Coordinate_Request__Sequence;


// Constants defined in the message

// Struct defined in srv/Coordinate in the package task_interfaces.
typedef struct task_interfaces__srv__Coordinate_Response
{
  double x;
  double y;
} task_interfaces__srv__Coordinate_Response;

// Struct for a sequence of task_interfaces__srv__Coordinate_Response.
typedef struct task_interfaces__srv__Coordinate_Response__Sequence
{
  task_interfaces__srv__Coordinate_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} task_interfaces__srv__Coordinate_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TASK_INTERFACES__SRV__DETAIL__COORDINATE__STRUCT_H_
