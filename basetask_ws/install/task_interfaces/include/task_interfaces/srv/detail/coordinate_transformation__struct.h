// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from task_interfaces:srv/CoordinateTransformation.idl
// generated code does not contain a copyright notice

#ifndef TASK_INTERFACES__SRV__DETAIL__COORDINATE_TRANSFORMATION__STRUCT_H_
#define TASK_INTERFACES__SRV__DETAIL__COORDINATE_TRANSFORMATION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in srv/CoordinateTransformation in the package task_interfaces.
typedef struct task_interfaces__srv__CoordinateTransformation_Request
{
  double x_a;
  double y_a;
  double x_offset;
  double y_offset;
  double theta;
} task_interfaces__srv__CoordinateTransformation_Request;

// Struct for a sequence of task_interfaces__srv__CoordinateTransformation_Request.
typedef struct task_interfaces__srv__CoordinateTransformation_Request__Sequence
{
  task_interfaces__srv__CoordinateTransformation_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} task_interfaces__srv__CoordinateTransformation_Request__Sequence;


// Constants defined in the message

// Struct defined in srv/CoordinateTransformation in the package task_interfaces.
typedef struct task_interfaces__srv__CoordinateTransformation_Response
{
  double x_b;
  double y_b;
} task_interfaces__srv__CoordinateTransformation_Response;

// Struct for a sequence of task_interfaces__srv__CoordinateTransformation_Response.
typedef struct task_interfaces__srv__CoordinateTransformation_Response__Sequence
{
  task_interfaces__srv__CoordinateTransformation_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} task_interfaces__srv__CoordinateTransformation_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TASK_INTERFACES__SRV__DETAIL__COORDINATE_TRANSFORMATION__STRUCT_H_
