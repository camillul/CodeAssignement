// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from hos_interfaces:msg/DeltaHaiveState.idl
// generated code does not contain a copyright notice
#include "hos_interfaces/msg/detail/delta_haive_state__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `device_uid`
// Member `device_type`
// Member `device_id`
#include "rosidl_runtime_c/string_functions.h"

bool
hos_interfaces__msg__DeltaHaiveState__init(hos_interfaces__msg__DeltaHaiveState * msg)
{
  if (!msg) {
    return false;
  }
  // x_position
  // y_position
  // turntable_slot
  // is_connected
  // last_ping
  // device_uid
  if (!rosidl_runtime_c__String__init(&msg->device_uid)) {
    hos_interfaces__msg__DeltaHaiveState__fini(msg);
    return false;
  }
  // is_reconnected
  // device_type
  if (!rosidl_runtime_c__String__init(&msg->device_type)) {
    hos_interfaces__msg__DeltaHaiveState__fini(msg);
    return false;
  }
  // device_id
  if (!rosidl_runtime_c__String__init(&msg->device_id)) {
    hos_interfaces__msg__DeltaHaiveState__fini(msg);
    return false;
  }
  return true;
}

void
hos_interfaces__msg__DeltaHaiveState__fini(hos_interfaces__msg__DeltaHaiveState * msg)
{
  if (!msg) {
    return;
  }
  // x_position
  // y_position
  // turntable_slot
  // is_connected
  // last_ping
  // device_uid
  rosidl_runtime_c__String__fini(&msg->device_uid);
  // is_reconnected
  // device_type
  rosidl_runtime_c__String__fini(&msg->device_type);
  // device_id
  rosidl_runtime_c__String__fini(&msg->device_id);
}

bool
hos_interfaces__msg__DeltaHaiveState__are_equal(const hos_interfaces__msg__DeltaHaiveState * lhs, const hos_interfaces__msg__DeltaHaiveState * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // x_position
  if (lhs->x_position != rhs->x_position) {
    return false;
  }
  // y_position
  if (lhs->y_position != rhs->y_position) {
    return false;
  }
  // turntable_slot
  if (lhs->turntable_slot != rhs->turntable_slot) {
    return false;
  }
  // is_connected
  if (lhs->is_connected != rhs->is_connected) {
    return false;
  }
  // last_ping
  if (lhs->last_ping != rhs->last_ping) {
    return false;
  }
  // device_uid
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->device_uid), &(rhs->device_uid)))
  {
    return false;
  }
  // is_reconnected
  if (lhs->is_reconnected != rhs->is_reconnected) {
    return false;
  }
  // device_type
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->device_type), &(rhs->device_type)))
  {
    return false;
  }
  // device_id
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->device_id), &(rhs->device_id)))
  {
    return false;
  }
  return true;
}

bool
hos_interfaces__msg__DeltaHaiveState__copy(
  const hos_interfaces__msg__DeltaHaiveState * input,
  hos_interfaces__msg__DeltaHaiveState * output)
{
  if (!input || !output) {
    return false;
  }
  // x_position
  output->x_position = input->x_position;
  // y_position
  output->y_position = input->y_position;
  // turntable_slot
  output->turntable_slot = input->turntable_slot;
  // is_connected
  output->is_connected = input->is_connected;
  // last_ping
  output->last_ping = input->last_ping;
  // device_uid
  if (!rosidl_runtime_c__String__copy(
      &(input->device_uid), &(output->device_uid)))
  {
    return false;
  }
  // is_reconnected
  output->is_reconnected = input->is_reconnected;
  // device_type
  if (!rosidl_runtime_c__String__copy(
      &(input->device_type), &(output->device_type)))
  {
    return false;
  }
  // device_id
  if (!rosidl_runtime_c__String__copy(
      &(input->device_id), &(output->device_id)))
  {
    return false;
  }
  return true;
}

hos_interfaces__msg__DeltaHaiveState *
hos_interfaces__msg__DeltaHaiveState__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  hos_interfaces__msg__DeltaHaiveState * msg = (hos_interfaces__msg__DeltaHaiveState *)allocator.allocate(sizeof(hos_interfaces__msg__DeltaHaiveState), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(hos_interfaces__msg__DeltaHaiveState));
  bool success = hos_interfaces__msg__DeltaHaiveState__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
hos_interfaces__msg__DeltaHaiveState__destroy(hos_interfaces__msg__DeltaHaiveState * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    hos_interfaces__msg__DeltaHaiveState__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
hos_interfaces__msg__DeltaHaiveState__Sequence__init(hos_interfaces__msg__DeltaHaiveState__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  hos_interfaces__msg__DeltaHaiveState * data = NULL;

  if (size) {
    data = (hos_interfaces__msg__DeltaHaiveState *)allocator.zero_allocate(size, sizeof(hos_interfaces__msg__DeltaHaiveState), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = hos_interfaces__msg__DeltaHaiveState__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        hos_interfaces__msg__DeltaHaiveState__fini(&data[i - 1]);
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
hos_interfaces__msg__DeltaHaiveState__Sequence__fini(hos_interfaces__msg__DeltaHaiveState__Sequence * array)
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
      hos_interfaces__msg__DeltaHaiveState__fini(&array->data[i]);
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

hos_interfaces__msg__DeltaHaiveState__Sequence *
hos_interfaces__msg__DeltaHaiveState__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  hos_interfaces__msg__DeltaHaiveState__Sequence * array = (hos_interfaces__msg__DeltaHaiveState__Sequence *)allocator.allocate(sizeof(hos_interfaces__msg__DeltaHaiveState__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = hos_interfaces__msg__DeltaHaiveState__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
hos_interfaces__msg__DeltaHaiveState__Sequence__destroy(hos_interfaces__msg__DeltaHaiveState__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    hos_interfaces__msg__DeltaHaiveState__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
hos_interfaces__msg__DeltaHaiveState__Sequence__are_equal(const hos_interfaces__msg__DeltaHaiveState__Sequence * lhs, const hos_interfaces__msg__DeltaHaiveState__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!hos_interfaces__msg__DeltaHaiveState__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
hos_interfaces__msg__DeltaHaiveState__Sequence__copy(
  const hos_interfaces__msg__DeltaHaiveState__Sequence * input,
  hos_interfaces__msg__DeltaHaiveState__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(hos_interfaces__msg__DeltaHaiveState);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    hos_interfaces__msg__DeltaHaiveState * data =
      (hos_interfaces__msg__DeltaHaiveState *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!hos_interfaces__msg__DeltaHaiveState__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          hos_interfaces__msg__DeltaHaiveState__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!hos_interfaces__msg__DeltaHaiveState__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
