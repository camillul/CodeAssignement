// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from hos_interfaces:srv/DeviceAPICall.idl
// generated code does not contain a copyright notice
#include "hos_interfaces/srv/detail/device_api_call__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `device_id`
// Member `function_name`
#include "rosidl_runtime_c/string_functions.h"
// Member `args`
#include "hos_interfaces/msg/detail/typed_field__functions.h"

bool
hos_interfaces__srv__DeviceAPICall_Request__init(hos_interfaces__srv__DeviceAPICall_Request * msg)
{
  if (!msg) {
    return false;
  }
  // device_id
  if (!rosidl_runtime_c__String__init(&msg->device_id)) {
    hos_interfaces__srv__DeviceAPICall_Request__fini(msg);
    return false;
  }
  // function_name
  if (!rosidl_runtime_c__String__init(&msg->function_name)) {
    hos_interfaces__srv__DeviceAPICall_Request__fini(msg);
    return false;
  }
  // args
  if (!hos_interfaces__msg__TypedField__Sequence__init(&msg->args, 0)) {
    hos_interfaces__srv__DeviceAPICall_Request__fini(msg);
    return false;
  }
  return true;
}

void
hos_interfaces__srv__DeviceAPICall_Request__fini(hos_interfaces__srv__DeviceAPICall_Request * msg)
{
  if (!msg) {
    return;
  }
  // device_id
  rosidl_runtime_c__String__fini(&msg->device_id);
  // function_name
  rosidl_runtime_c__String__fini(&msg->function_name);
  // args
  hos_interfaces__msg__TypedField__Sequence__fini(&msg->args);
}

bool
hos_interfaces__srv__DeviceAPICall_Request__are_equal(const hos_interfaces__srv__DeviceAPICall_Request * lhs, const hos_interfaces__srv__DeviceAPICall_Request * rhs)
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
  // function_name
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->function_name), &(rhs->function_name)))
  {
    return false;
  }
  // args
  if (!hos_interfaces__msg__TypedField__Sequence__are_equal(
      &(lhs->args), &(rhs->args)))
  {
    return false;
  }
  return true;
}

bool
hos_interfaces__srv__DeviceAPICall_Request__copy(
  const hos_interfaces__srv__DeviceAPICall_Request * input,
  hos_interfaces__srv__DeviceAPICall_Request * output)
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
  // function_name
  if (!rosidl_runtime_c__String__copy(
      &(input->function_name), &(output->function_name)))
  {
    return false;
  }
  // args
  if (!hos_interfaces__msg__TypedField__Sequence__copy(
      &(input->args), &(output->args)))
  {
    return false;
  }
  return true;
}

hos_interfaces__srv__DeviceAPICall_Request *
hos_interfaces__srv__DeviceAPICall_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  hos_interfaces__srv__DeviceAPICall_Request * msg = (hos_interfaces__srv__DeviceAPICall_Request *)allocator.allocate(sizeof(hos_interfaces__srv__DeviceAPICall_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(hos_interfaces__srv__DeviceAPICall_Request));
  bool success = hos_interfaces__srv__DeviceAPICall_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
hos_interfaces__srv__DeviceAPICall_Request__destroy(hos_interfaces__srv__DeviceAPICall_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    hos_interfaces__srv__DeviceAPICall_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
hos_interfaces__srv__DeviceAPICall_Request__Sequence__init(hos_interfaces__srv__DeviceAPICall_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  hos_interfaces__srv__DeviceAPICall_Request * data = NULL;

  if (size) {
    data = (hos_interfaces__srv__DeviceAPICall_Request *)allocator.zero_allocate(size, sizeof(hos_interfaces__srv__DeviceAPICall_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = hos_interfaces__srv__DeviceAPICall_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        hos_interfaces__srv__DeviceAPICall_Request__fini(&data[i - 1]);
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
hos_interfaces__srv__DeviceAPICall_Request__Sequence__fini(hos_interfaces__srv__DeviceAPICall_Request__Sequence * array)
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
      hos_interfaces__srv__DeviceAPICall_Request__fini(&array->data[i]);
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

hos_interfaces__srv__DeviceAPICall_Request__Sequence *
hos_interfaces__srv__DeviceAPICall_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  hos_interfaces__srv__DeviceAPICall_Request__Sequence * array = (hos_interfaces__srv__DeviceAPICall_Request__Sequence *)allocator.allocate(sizeof(hos_interfaces__srv__DeviceAPICall_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = hos_interfaces__srv__DeviceAPICall_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
hos_interfaces__srv__DeviceAPICall_Request__Sequence__destroy(hos_interfaces__srv__DeviceAPICall_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    hos_interfaces__srv__DeviceAPICall_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
hos_interfaces__srv__DeviceAPICall_Request__Sequence__are_equal(const hos_interfaces__srv__DeviceAPICall_Request__Sequence * lhs, const hos_interfaces__srv__DeviceAPICall_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!hos_interfaces__srv__DeviceAPICall_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
hos_interfaces__srv__DeviceAPICall_Request__Sequence__copy(
  const hos_interfaces__srv__DeviceAPICall_Request__Sequence * input,
  hos_interfaces__srv__DeviceAPICall_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(hos_interfaces__srv__DeviceAPICall_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    hos_interfaces__srv__DeviceAPICall_Request * data =
      (hos_interfaces__srv__DeviceAPICall_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!hos_interfaces__srv__DeviceAPICall_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          hos_interfaces__srv__DeviceAPICall_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!hos_interfaces__srv__DeviceAPICall_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `error`
// already included above
// #include "rosidl_runtime_c/string_functions.h"

bool
hos_interfaces__srv__DeviceAPICall_Response__init(hos_interfaces__srv__DeviceAPICall_Response * msg)
{
  if (!msg) {
    return false;
  }
  // is_valid
  // error
  if (!rosidl_runtime_c__String__init(&msg->error)) {
    hos_interfaces__srv__DeviceAPICall_Response__fini(msg);
    return false;
  }
  // task_id
  return true;
}

void
hos_interfaces__srv__DeviceAPICall_Response__fini(hos_interfaces__srv__DeviceAPICall_Response * msg)
{
  if (!msg) {
    return;
  }
  // is_valid
  // error
  rosidl_runtime_c__String__fini(&msg->error);
  // task_id
}

bool
hos_interfaces__srv__DeviceAPICall_Response__are_equal(const hos_interfaces__srv__DeviceAPICall_Response * lhs, const hos_interfaces__srv__DeviceAPICall_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // is_valid
  if (lhs->is_valid != rhs->is_valid) {
    return false;
  }
  // error
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->error), &(rhs->error)))
  {
    return false;
  }
  // task_id
  if (lhs->task_id != rhs->task_id) {
    return false;
  }
  return true;
}

bool
hos_interfaces__srv__DeviceAPICall_Response__copy(
  const hos_interfaces__srv__DeviceAPICall_Response * input,
  hos_interfaces__srv__DeviceAPICall_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // is_valid
  output->is_valid = input->is_valid;
  // error
  if (!rosidl_runtime_c__String__copy(
      &(input->error), &(output->error)))
  {
    return false;
  }
  // task_id
  output->task_id = input->task_id;
  return true;
}

hos_interfaces__srv__DeviceAPICall_Response *
hos_interfaces__srv__DeviceAPICall_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  hos_interfaces__srv__DeviceAPICall_Response * msg = (hos_interfaces__srv__DeviceAPICall_Response *)allocator.allocate(sizeof(hos_interfaces__srv__DeviceAPICall_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(hos_interfaces__srv__DeviceAPICall_Response));
  bool success = hos_interfaces__srv__DeviceAPICall_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
hos_interfaces__srv__DeviceAPICall_Response__destroy(hos_interfaces__srv__DeviceAPICall_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    hos_interfaces__srv__DeviceAPICall_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
hos_interfaces__srv__DeviceAPICall_Response__Sequence__init(hos_interfaces__srv__DeviceAPICall_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  hos_interfaces__srv__DeviceAPICall_Response * data = NULL;

  if (size) {
    data = (hos_interfaces__srv__DeviceAPICall_Response *)allocator.zero_allocate(size, sizeof(hos_interfaces__srv__DeviceAPICall_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = hos_interfaces__srv__DeviceAPICall_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        hos_interfaces__srv__DeviceAPICall_Response__fini(&data[i - 1]);
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
hos_interfaces__srv__DeviceAPICall_Response__Sequence__fini(hos_interfaces__srv__DeviceAPICall_Response__Sequence * array)
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
      hos_interfaces__srv__DeviceAPICall_Response__fini(&array->data[i]);
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

hos_interfaces__srv__DeviceAPICall_Response__Sequence *
hos_interfaces__srv__DeviceAPICall_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  hos_interfaces__srv__DeviceAPICall_Response__Sequence * array = (hos_interfaces__srv__DeviceAPICall_Response__Sequence *)allocator.allocate(sizeof(hos_interfaces__srv__DeviceAPICall_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = hos_interfaces__srv__DeviceAPICall_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
hos_interfaces__srv__DeviceAPICall_Response__Sequence__destroy(hos_interfaces__srv__DeviceAPICall_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    hos_interfaces__srv__DeviceAPICall_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
hos_interfaces__srv__DeviceAPICall_Response__Sequence__are_equal(const hos_interfaces__srv__DeviceAPICall_Response__Sequence * lhs, const hos_interfaces__srv__DeviceAPICall_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!hos_interfaces__srv__DeviceAPICall_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
hos_interfaces__srv__DeviceAPICall_Response__Sequence__copy(
  const hos_interfaces__srv__DeviceAPICall_Response__Sequence * input,
  hos_interfaces__srv__DeviceAPICall_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(hos_interfaces__srv__DeviceAPICall_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    hos_interfaces__srv__DeviceAPICall_Response * data =
      (hos_interfaces__srv__DeviceAPICall_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!hos_interfaces__srv__DeviceAPICall_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          hos_interfaces__srv__DeviceAPICall_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!hos_interfaces__srv__DeviceAPICall_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
