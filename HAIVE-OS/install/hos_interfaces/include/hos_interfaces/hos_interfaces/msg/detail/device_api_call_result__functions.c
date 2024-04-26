// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from hos_interfaces:msg/DeviceAPICallResult.idl
// generated code does not contain a copyright notice
#include "hos_interfaces/msg/detail/device_api_call_result__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `error`
// Member `result_jsons`
#include "rosidl_runtime_c/string_functions.h"

bool
hos_interfaces__msg__DeviceAPICallResult__init(hos_interfaces__msg__DeviceAPICallResult * msg)
{
  if (!msg) {
    return false;
  }
  // task_id
  // success
  // error
  if (!rosidl_runtime_c__String__init(&msg->error)) {
    hos_interfaces__msg__DeviceAPICallResult__fini(msg);
    return false;
  }
  // result_jsons
  if (!rosidl_runtime_c__String__init(&msg->result_jsons)) {
    hos_interfaces__msg__DeviceAPICallResult__fini(msg);
    return false;
  }
  // request_time_s
  // response_time_s
  return true;
}

void
hos_interfaces__msg__DeviceAPICallResult__fini(hos_interfaces__msg__DeviceAPICallResult * msg)
{
  if (!msg) {
    return;
  }
  // task_id
  // success
  // error
  rosidl_runtime_c__String__fini(&msg->error);
  // result_jsons
  rosidl_runtime_c__String__fini(&msg->result_jsons);
  // request_time_s
  // response_time_s
}

bool
hos_interfaces__msg__DeviceAPICallResult__are_equal(const hos_interfaces__msg__DeviceAPICallResult * lhs, const hos_interfaces__msg__DeviceAPICallResult * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // task_id
  if (lhs->task_id != rhs->task_id) {
    return false;
  }
  // success
  if (lhs->success != rhs->success) {
    return false;
  }
  // error
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->error), &(rhs->error)))
  {
    return false;
  }
  // result_jsons
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->result_jsons), &(rhs->result_jsons)))
  {
    return false;
  }
  // request_time_s
  if (lhs->request_time_s != rhs->request_time_s) {
    return false;
  }
  // response_time_s
  if (lhs->response_time_s != rhs->response_time_s) {
    return false;
  }
  return true;
}

bool
hos_interfaces__msg__DeviceAPICallResult__copy(
  const hos_interfaces__msg__DeviceAPICallResult * input,
  hos_interfaces__msg__DeviceAPICallResult * output)
{
  if (!input || !output) {
    return false;
  }
  // task_id
  output->task_id = input->task_id;
  // success
  output->success = input->success;
  // error
  if (!rosidl_runtime_c__String__copy(
      &(input->error), &(output->error)))
  {
    return false;
  }
  // result_jsons
  if (!rosidl_runtime_c__String__copy(
      &(input->result_jsons), &(output->result_jsons)))
  {
    return false;
  }
  // request_time_s
  output->request_time_s = input->request_time_s;
  // response_time_s
  output->response_time_s = input->response_time_s;
  return true;
}

hos_interfaces__msg__DeviceAPICallResult *
hos_interfaces__msg__DeviceAPICallResult__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  hos_interfaces__msg__DeviceAPICallResult * msg = (hos_interfaces__msg__DeviceAPICallResult *)allocator.allocate(sizeof(hos_interfaces__msg__DeviceAPICallResult), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(hos_interfaces__msg__DeviceAPICallResult));
  bool success = hos_interfaces__msg__DeviceAPICallResult__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
hos_interfaces__msg__DeviceAPICallResult__destroy(hos_interfaces__msg__DeviceAPICallResult * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    hos_interfaces__msg__DeviceAPICallResult__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
hos_interfaces__msg__DeviceAPICallResult__Sequence__init(hos_interfaces__msg__DeviceAPICallResult__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  hos_interfaces__msg__DeviceAPICallResult * data = NULL;

  if (size) {
    data = (hos_interfaces__msg__DeviceAPICallResult *)allocator.zero_allocate(size, sizeof(hos_interfaces__msg__DeviceAPICallResult), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = hos_interfaces__msg__DeviceAPICallResult__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        hos_interfaces__msg__DeviceAPICallResult__fini(&data[i - 1]);
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
hos_interfaces__msg__DeviceAPICallResult__Sequence__fini(hos_interfaces__msg__DeviceAPICallResult__Sequence * array)
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
      hos_interfaces__msg__DeviceAPICallResult__fini(&array->data[i]);
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

hos_interfaces__msg__DeviceAPICallResult__Sequence *
hos_interfaces__msg__DeviceAPICallResult__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  hos_interfaces__msg__DeviceAPICallResult__Sequence * array = (hos_interfaces__msg__DeviceAPICallResult__Sequence *)allocator.allocate(sizeof(hos_interfaces__msg__DeviceAPICallResult__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = hos_interfaces__msg__DeviceAPICallResult__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
hos_interfaces__msg__DeviceAPICallResult__Sequence__destroy(hos_interfaces__msg__DeviceAPICallResult__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    hos_interfaces__msg__DeviceAPICallResult__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
hos_interfaces__msg__DeviceAPICallResult__Sequence__are_equal(const hos_interfaces__msg__DeviceAPICallResult__Sequence * lhs, const hos_interfaces__msg__DeviceAPICallResult__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!hos_interfaces__msg__DeviceAPICallResult__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
hos_interfaces__msg__DeviceAPICallResult__Sequence__copy(
  const hos_interfaces__msg__DeviceAPICallResult__Sequence * input,
  hos_interfaces__msg__DeviceAPICallResult__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(hos_interfaces__msg__DeviceAPICallResult);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    hos_interfaces__msg__DeviceAPICallResult * data =
      (hos_interfaces__msg__DeviceAPICallResult *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!hos_interfaces__msg__DeviceAPICallResult__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          hos_interfaces__msg__DeviceAPICallResult__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!hos_interfaces__msg__DeviceAPICallResult__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
