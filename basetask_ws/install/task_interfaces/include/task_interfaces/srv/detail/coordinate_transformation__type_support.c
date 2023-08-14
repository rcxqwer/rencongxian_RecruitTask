// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from task_interfaces:srv/CoordinateTransformation.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "task_interfaces/srv/detail/coordinate_transformation__rosidl_typesupport_introspection_c.h"
#include "task_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "task_interfaces/srv/detail/coordinate_transformation__functions.h"
#include "task_interfaces/srv/detail/coordinate_transformation__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void CoordinateTransformation_Request__rosidl_typesupport_introspection_c__CoordinateTransformation_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  task_interfaces__srv__CoordinateTransformation_Request__init(message_memory);
}

void CoordinateTransformation_Request__rosidl_typesupport_introspection_c__CoordinateTransformation_Request_fini_function(void * message_memory)
{
  task_interfaces__srv__CoordinateTransformation_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember CoordinateTransformation_Request__rosidl_typesupport_introspection_c__CoordinateTransformation_Request_message_member_array[5] = {
  {
    "x_a",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(task_interfaces__srv__CoordinateTransformation_Request, x_a),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "y_a",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(task_interfaces__srv__CoordinateTransformation_Request, y_a),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "x_offset",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(task_interfaces__srv__CoordinateTransformation_Request, x_offset),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "y_offset",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(task_interfaces__srv__CoordinateTransformation_Request, y_offset),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "theta",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(task_interfaces__srv__CoordinateTransformation_Request, theta),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers CoordinateTransformation_Request__rosidl_typesupport_introspection_c__CoordinateTransformation_Request_message_members = {
  "task_interfaces__srv",  // message namespace
  "CoordinateTransformation_Request",  // message name
  5,  // number of fields
  sizeof(task_interfaces__srv__CoordinateTransformation_Request),
  CoordinateTransformation_Request__rosidl_typesupport_introspection_c__CoordinateTransformation_Request_message_member_array,  // message members
  CoordinateTransformation_Request__rosidl_typesupport_introspection_c__CoordinateTransformation_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  CoordinateTransformation_Request__rosidl_typesupport_introspection_c__CoordinateTransformation_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t CoordinateTransformation_Request__rosidl_typesupport_introspection_c__CoordinateTransformation_Request_message_type_support_handle = {
  0,
  &CoordinateTransformation_Request__rosidl_typesupport_introspection_c__CoordinateTransformation_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_task_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, task_interfaces, srv, CoordinateTransformation_Request)() {
  if (!CoordinateTransformation_Request__rosidl_typesupport_introspection_c__CoordinateTransformation_Request_message_type_support_handle.typesupport_identifier) {
    CoordinateTransformation_Request__rosidl_typesupport_introspection_c__CoordinateTransformation_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &CoordinateTransformation_Request__rosidl_typesupport_introspection_c__CoordinateTransformation_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "task_interfaces/srv/detail/coordinate_transformation__rosidl_typesupport_introspection_c.h"
// already included above
// #include "task_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "task_interfaces/srv/detail/coordinate_transformation__functions.h"
// already included above
// #include "task_interfaces/srv/detail/coordinate_transformation__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void CoordinateTransformation_Response__rosidl_typesupport_introspection_c__CoordinateTransformation_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  task_interfaces__srv__CoordinateTransformation_Response__init(message_memory);
}

void CoordinateTransformation_Response__rosidl_typesupport_introspection_c__CoordinateTransformation_Response_fini_function(void * message_memory)
{
  task_interfaces__srv__CoordinateTransformation_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember CoordinateTransformation_Response__rosidl_typesupport_introspection_c__CoordinateTransformation_Response_message_member_array[2] = {
  {
    "x_b",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(task_interfaces__srv__CoordinateTransformation_Response, x_b),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "y_b",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(task_interfaces__srv__CoordinateTransformation_Response, y_b),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers CoordinateTransformation_Response__rosidl_typesupport_introspection_c__CoordinateTransformation_Response_message_members = {
  "task_interfaces__srv",  // message namespace
  "CoordinateTransformation_Response",  // message name
  2,  // number of fields
  sizeof(task_interfaces__srv__CoordinateTransformation_Response),
  CoordinateTransformation_Response__rosidl_typesupport_introspection_c__CoordinateTransformation_Response_message_member_array,  // message members
  CoordinateTransformation_Response__rosidl_typesupport_introspection_c__CoordinateTransformation_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  CoordinateTransformation_Response__rosidl_typesupport_introspection_c__CoordinateTransformation_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t CoordinateTransformation_Response__rosidl_typesupport_introspection_c__CoordinateTransformation_Response_message_type_support_handle = {
  0,
  &CoordinateTransformation_Response__rosidl_typesupport_introspection_c__CoordinateTransformation_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_task_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, task_interfaces, srv, CoordinateTransformation_Response)() {
  if (!CoordinateTransformation_Response__rosidl_typesupport_introspection_c__CoordinateTransformation_Response_message_type_support_handle.typesupport_identifier) {
    CoordinateTransformation_Response__rosidl_typesupport_introspection_c__CoordinateTransformation_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &CoordinateTransformation_Response__rosidl_typesupport_introspection_c__CoordinateTransformation_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "task_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "task_interfaces/srv/detail/coordinate_transformation__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers task_interfaces__srv__detail__coordinate_transformation__rosidl_typesupport_introspection_c__CoordinateTransformation_service_members = {
  "task_interfaces__srv",  // service namespace
  "CoordinateTransformation",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // task_interfaces__srv__detail__coordinate_transformation__rosidl_typesupport_introspection_c__CoordinateTransformation_Request_message_type_support_handle,
  NULL  // response message
  // task_interfaces__srv__detail__coordinate_transformation__rosidl_typesupport_introspection_c__CoordinateTransformation_Response_message_type_support_handle
};

static rosidl_service_type_support_t task_interfaces__srv__detail__coordinate_transformation__rosidl_typesupport_introspection_c__CoordinateTransformation_service_type_support_handle = {
  0,
  &task_interfaces__srv__detail__coordinate_transformation__rosidl_typesupport_introspection_c__CoordinateTransformation_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, task_interfaces, srv, CoordinateTransformation_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, task_interfaces, srv, CoordinateTransformation_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_task_interfaces
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, task_interfaces, srv, CoordinateTransformation)() {
  if (!task_interfaces__srv__detail__coordinate_transformation__rosidl_typesupport_introspection_c__CoordinateTransformation_service_type_support_handle.typesupport_identifier) {
    task_interfaces__srv__detail__coordinate_transformation__rosidl_typesupport_introspection_c__CoordinateTransformation_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)task_interfaces__srv__detail__coordinate_transformation__rosidl_typesupport_introspection_c__CoordinateTransformation_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, task_interfaces, srv, CoordinateTransformation_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, task_interfaces, srv, CoordinateTransformation_Response)()->data;
  }

  return &task_interfaces__srv__detail__coordinate_transformation__rosidl_typesupport_introspection_c__CoordinateTransformation_service_type_support_handle;
}
