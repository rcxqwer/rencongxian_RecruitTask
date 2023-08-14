// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from task_interfaces:srv/Coordinate.idl
// generated code does not contain a copyright notice
#include "task_interfaces/srv/detail/coordinate__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `image`
#include "sensor_msgs/msg/detail/image__functions.h"

bool
task_interfaces__srv__Coordinate_Request__init(task_interfaces__srv__Coordinate_Request * msg)
{
  if (!msg) {
    return false;
  }
  // image
  if (!sensor_msgs__msg__Image__init(&msg->image)) {
    task_interfaces__srv__Coordinate_Request__fini(msg);
    return false;
  }
  return true;
}

void
task_interfaces__srv__Coordinate_Request__fini(task_interfaces__srv__Coordinate_Request * msg)
{
  if (!msg) {
    return;
  }
  // image
  sensor_msgs__msg__Image__fini(&msg->image);
}

bool
task_interfaces__srv__Coordinate_Request__are_equal(const task_interfaces__srv__Coordinate_Request * lhs, const task_interfaces__srv__Coordinate_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // image
  if (!sensor_msgs__msg__Image__are_equal(
      &(lhs->image), &(rhs->image)))
  {
    return false;
  }
  return true;
}

bool
task_interfaces__srv__Coordinate_Request__copy(
  const task_interfaces__srv__Coordinate_Request * input,
  task_interfaces__srv__Coordinate_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // image
  if (!sensor_msgs__msg__Image__copy(
      &(input->image), &(output->image)))
  {
    return false;
  }
  return true;
}

task_interfaces__srv__Coordinate_Request *
task_interfaces__srv__Coordinate_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  task_interfaces__srv__Coordinate_Request * msg = (task_interfaces__srv__Coordinate_Request *)allocator.allocate(sizeof(task_interfaces__srv__Coordinate_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(task_interfaces__srv__Coordinate_Request));
  bool success = task_interfaces__srv__Coordinate_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
task_interfaces__srv__Coordinate_Request__destroy(task_interfaces__srv__Coordinate_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    task_interfaces__srv__Coordinate_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
task_interfaces__srv__Coordinate_Request__Sequence__init(task_interfaces__srv__Coordinate_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  task_interfaces__srv__Coordinate_Request * data = NULL;

  if (size) {
    data = (task_interfaces__srv__Coordinate_Request *)allocator.zero_allocate(size, sizeof(task_interfaces__srv__Coordinate_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = task_interfaces__srv__Coordinate_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        task_interfaces__srv__Coordinate_Request__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
task_interfaces__srv__Coordinate_Request__Sequence__fini(task_interfaces__srv__Coordinate_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      task_interfaces__srv__Coordinate_Request__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

task_interfaces__srv__Coordinate_Request__Sequence *
task_interfaces__srv__Coordinate_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  task_interfaces__srv__Coordinate_Request__Sequence * array = (task_interfaces__srv__Coordinate_Request__Sequence *)allocator.allocate(sizeof(task_interfaces__srv__Coordinate_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = task_interfaces__srv__Coordinate_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
task_interfaces__srv__Coordinate_Request__Sequence__destroy(task_interfaces__srv__Coordinate_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    task_interfaces__srv__Coordinate_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
task_interfaces__srv__Coordinate_Request__Sequence__are_equal(const task_interfaces__srv__Coordinate_Request__Sequence * lhs, const task_interfaces__srv__Coordinate_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!task_interfaces__srv__Coordinate_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
task_interfaces__srv__Coordinate_Request__Sequence__copy(
  const task_interfaces__srv__Coordinate_Request__Sequence * input,
  task_interfaces__srv__Coordinate_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(task_interfaces__srv__Coordinate_Request);
    task_interfaces__srv__Coordinate_Request * data =
      (task_interfaces__srv__Coordinate_Request *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!task_interfaces__srv__Coordinate_Request__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          task_interfaces__srv__Coordinate_Request__fini(&data[i]);
        }
        free(data);
        return false;
      }
    }
    output->data = data;
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!task_interfaces__srv__Coordinate_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
task_interfaces__srv__Coordinate_Response__init(task_interfaces__srv__Coordinate_Response * msg)
{
  if (!msg) {
    return false;
  }
  // x
  // y
  return true;
}

void
task_interfaces__srv__Coordinate_Response__fini(task_interfaces__srv__Coordinate_Response * msg)
{
  if (!msg) {
    return;
  }
  // x
  // y
}

bool
task_interfaces__srv__Coordinate_Response__are_equal(const task_interfaces__srv__Coordinate_Response * lhs, const task_interfaces__srv__Coordinate_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // x
  if (lhs->x != rhs->x) {
    return false;
  }
  // y
  if (lhs->y != rhs->y) {
    return false;
  }
  return true;
}

bool
task_interfaces__srv__Coordinate_Response__copy(
  const task_interfaces__srv__Coordinate_Response * input,
  task_interfaces__srv__Coordinate_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // x
  output->x = input->x;
  // y
  output->y = input->y;
  return true;
}

task_interfaces__srv__Coordinate_Response *
task_interfaces__srv__Coordinate_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  task_interfaces__srv__Coordinate_Response * msg = (task_interfaces__srv__Coordinate_Response *)allocator.allocate(sizeof(task_interfaces__srv__Coordinate_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(task_interfaces__srv__Coordinate_Response));
  bool success = task_interfaces__srv__Coordinate_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
task_interfaces__srv__Coordinate_Response__destroy(task_interfaces__srv__Coordinate_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    task_interfaces__srv__Coordinate_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
task_interfaces__srv__Coordinate_Response__Sequence__init(task_interfaces__srv__Coordinate_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  task_interfaces__srv__Coordinate_Response * data = NULL;

  if (size) {
    data = (task_interfaces__srv__Coordinate_Response *)allocator.zero_allocate(size, sizeof(task_interfaces__srv__Coordinate_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = task_interfaces__srv__Coordinate_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        task_interfaces__srv__Coordinate_Response__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
task_interfaces__srv__Coordinate_Response__Sequence__fini(task_interfaces__srv__Coordinate_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      task_interfaces__srv__Coordinate_Response__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

task_interfaces__srv__Coordinate_Response__Sequence *
task_interfaces__srv__Coordinate_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  task_interfaces__srv__Coordinate_Response__Sequence * array = (task_interfaces__srv__Coordinate_Response__Sequence *)allocator.allocate(sizeof(task_interfaces__srv__Coordinate_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = task_interfaces__srv__Coordinate_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
task_interfaces__srv__Coordinate_Response__Sequence__destroy(task_interfaces__srv__Coordinate_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    task_interfaces__srv__Coordinate_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
task_interfaces__srv__Coordinate_Response__Sequence__are_equal(const task_interfaces__srv__Coordinate_Response__Sequence * lhs, const task_interfaces__srv__Coordinate_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!task_interfaces__srv__Coordinate_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
task_interfaces__srv__Coordinate_Response__Sequence__copy(
  const task_interfaces__srv__Coordinate_Response__Sequence * input,
  task_interfaces__srv__Coordinate_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(task_interfaces__srv__Coordinate_Response);
    task_interfaces__srv__Coordinate_Response * data =
      (task_interfaces__srv__Coordinate_Response *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!task_interfaces__srv__Coordinate_Response__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          task_interfaces__srv__Coordinate_Response__fini(&data[i]);
        }
        free(data);
        return false;
      }
    }
    output->data = data;
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!task_interfaces__srv__Coordinate_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
