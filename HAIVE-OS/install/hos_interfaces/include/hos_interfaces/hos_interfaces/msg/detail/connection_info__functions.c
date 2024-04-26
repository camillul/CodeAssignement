// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from hos_interfaces:msg/ConnectionInfo.idl
// generated code does not contain a copyright notice
#include "hos_interfaces/msg/detail/connection_info__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `device_id`
// Member `device_type`
#include "rosidl_runtime_c/string_functions.h"

bool
hos_interfaces__msg__ConnectionInfo__init(hos_interfaces__msg__ConnectionInfo * msg)
{
  if (!msg) {
    return false;
  }
  // device_id
  if (!rosidl_runtime_c__String__init(&msg->device_id)) {
    hos_interfaces__msg__ConnectionInfo__fini(msg);
    return false;
  }
  // device_uid
  // device_type
  if (!rosidl_runtime_c__String__init(&msg->device_type)) {
    hos_interfaces__msg__ConnectionInfo__fini(msg);
    return false;
  }
  // event_time_s
  return true;
}

void
hos_interfaces__msg__ConnectionInfo__fini(hos_interfaces__msg__ConnectionInfo * msg)
{
  if (!msg) {
    return;
  }
  // device_id
  rosidl_runtime_c__String__fini(&msg->device_id);
  // device_uid
  // device_type
  rosidl_runtime_c__String__fini(&msg->device_type);
  // event_time_s
}

bool
hos_interfaces__msg__ConnectionInfo__are_equal(const hos_interfaces__msg__ConnectionInfo * lhs, const hos_interfaces__msg__ConnectionInfo * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // device_id
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->device_id), &(rhs->device_id)))
  {
    return false;
  }
  // device_uid
  if (lhs->device_uid != rhs->device_uid) {
    return false;
  }
  // device_type
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->device_type), &(rhs->device_type)))
  {
    return false;
  }
  // event_time_s
  if (lhs->event_time_s != rhs->event_time_s) {
    return false;
  }
  return true;
}

bool
hos_interfaces__msg__ConnectionInfo__copy(
  const hos_interfaces__msg__ConnectionInfo * input,
  hos_interfaces__msg__ConnectionInfo * output)
{
  if (!input || !output) {
    return false;
  }
  // device_id
  if (!rosidl_runtime_c__String__copy(
      &(input->device_id), &(output->device_id)))
  {
    return false;
  }
  // device_uid
  output->device_uid = input->device_uid;
  // device_type
  if (!rosidl_runtime_c__String__copy(
      &(input->device_type), &(output->device_type)))
  {
    return false;
  }
  // event_time_s
  output->event_time_s = input->event_time_s;
  return true;
}

hos_interfaces__msg__ConnectionInfo *
hos_interfaces__msg__ConnectionInfo__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  hos_interfaces__msg__ConnectionInfo * msg = (hos_interfaces__msg__ConnectionInfo *)allocator.allocate(sizeof(hos_interfaces__msg__ConnectionInfo), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(hos_interfaces__msg__ConnectionInfo));
  bool success = hos_interfaces__msg__ConnectionInfo__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
hos_interfaces__msg__ConnectionInfo__destroy(hos_interfaces__msg__ConnectionInfo * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    hos_interfaces__msg__ConnectionInfo__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
hos_interfaces__msg__ConnectionInfo__Sequence__init(hos_interfaces__msg__ConnectionInfo__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  hos_interfaces__msg__ConnectionInfo * data = NULL;

  if (size) {
    data = (hos_interfaces__msg__ConnectionInfo *)allocator.zero_allocate(size, sizeof(hos_interfaces__msg__ConnectionInfo), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = hos_interfaces__msg__ConnectionInfo__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        hos_interfaces__msg__ConnectionInfo__fini(&data[i - 1]);
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
hos_interfaces__msg__ConnectionInfo__Sequence__fini(hos_interfaces__msg__ConnectionInfo__Sequence * array)
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
      hos_interfaces__msg__ConnectionInfo__fini(&array->data[i]);
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

hos_interfaces__msg__ConnectionInfo__Sequence *
hos_interfaces__msg__ConnectionInfo__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  hos_interfaces__msg__ConnectionInfo__Sequence * array = (hos_interfaces__msg__ConnectionInfo__Sequence *)allocator.allocate(sizeof(hos_interfaces__msg__ConnectionInfo__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = hos_interfaces__msg__ConnectionInfo__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
hos_interfaces__msg__ConnectionInfo__Sequence__destroy(hos_interfaces__msg__ConnectionInfo__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    hos_interfaces__msg__ConnectionInfo__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
hos_interfaces__msg__ConnectionInfo__Sequence__are_equal(const hos_interfaces__msg__ConnectionInfo__Sequence * lhs, const hos_interfaces__msg__ConnectionInfo__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!hos_interfaces__msg__ConnectionInfo__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
hos_interfaces__msg__ConnectionInfo__Sequence__copy(
  const hos_interfaces__msg__ConnectionInfo__Sequence * input,
  hos_interfaces__msg__ConnectionInfo__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(hos_interfaces__msg__ConnectionInfo);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    hos_interfaces__msg__ConnectionInfo * data =
      (hos_interfaces__msg__ConnectionInfo *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!hos_interfaces__msg__ConnectionInfo__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          hos_interfaces__msg__ConnectionInfo__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!hos_interfaces__msg__ConnectionInfo__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
