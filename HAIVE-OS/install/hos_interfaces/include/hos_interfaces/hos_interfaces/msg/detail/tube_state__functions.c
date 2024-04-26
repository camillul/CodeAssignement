// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from hos_interfaces:msg/TubeState.idl
// generated code does not contain a copyright notice
#include "hos_interfaces/msg/detail/tube_state__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `tube_id`
// Member `tube_type`
#include "rosidl_runtime_c/string_functions.h"

bool
hos_interfaces__msg__TubeState__init(hos_interfaces__msg__TubeState * msg)
{
  if (!msg) {
    return false;
  }
  // liquid_level
  // tube_id
  if (!rosidl_runtime_c__String__init(&msg->tube_id)) {
    hos_interfaces__msg__TubeState__fini(msg);
    return false;
  }
  // tube_type
  if (!rosidl_runtime_c__String__init(&msg->tube_type)) {
    hos_interfaces__msg__TubeState__fini(msg);
    return false;
  }
  // volume
  // temperature
  return true;
}

void
hos_interfaces__msg__TubeState__fini(hos_interfaces__msg__TubeState * msg)
{
  if (!msg) {
    return;
  }
  // liquid_level
  // tube_id
  rosidl_runtime_c__String__fini(&msg->tube_id);
  // tube_type
  rosidl_runtime_c__String__fini(&msg->tube_type);
  // volume
  // temperature
}

bool
hos_interfaces__msg__TubeState__are_equal(const hos_interfaces__msg__TubeState * lhs, const hos_interfaces__msg__TubeState * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // liquid_level
  if (lhs->liquid_level != rhs->liquid_level) {
    return false;
  }
  // tube_id
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->tube_id), &(rhs->tube_id)))
  {
    return false;
  }
  // tube_type
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->tube_type), &(rhs->tube_type)))
  {
    return false;
  }
  // volume
  if (lhs->volume != rhs->volume) {
    return false;
  }
  // temperature
  if (lhs->temperature != rhs->temperature) {
    return false;
  }
  return true;
}

bool
hos_interfaces__msg__TubeState__copy(
  const hos_interfaces__msg__TubeState * input,
  hos_interfaces__msg__TubeState * output)
{
  if (!input || !output) {
    return false;
  }
  // liquid_level
  output->liquid_level = input->liquid_level;
  // tube_id
  if (!rosidl_runtime_c__String__copy(
      &(input->tube_id), &(output->tube_id)))
  {
    return false;
  }
  // tube_type
  if (!rosidl_runtime_c__String__copy(
      &(input->tube_type), &(output->tube_type)))
  {
    return false;
  }
  // volume
  output->volume = input->volume;
  // temperature
  output->temperature = input->temperature;
  return true;
}

hos_interfaces__msg__TubeState *
hos_interfaces__msg__TubeState__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  hos_interfaces__msg__TubeState * msg = (hos_interfaces__msg__TubeState *)allocator.allocate(sizeof(hos_interfaces__msg__TubeState), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(hos_interfaces__msg__TubeState));
  bool success = hos_interfaces__msg__TubeState__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
hos_interfaces__msg__TubeState__destroy(hos_interfaces__msg__TubeState * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    hos_interfaces__msg__TubeState__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
hos_interfaces__msg__TubeState__Sequence__init(hos_interfaces__msg__TubeState__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  hos_interfaces__msg__TubeState * data = NULL;

  if (size) {
    data = (hos_interfaces__msg__TubeState *)allocator.zero_allocate(size, sizeof(hos_interfaces__msg__TubeState), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = hos_interfaces__msg__TubeState__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        hos_interfaces__msg__TubeState__fini(&data[i - 1]);
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
hos_interfaces__msg__TubeState__Sequence__fini(hos_interfaces__msg__TubeState__Sequence * array)
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
      hos_interfaces__msg__TubeState__fini(&array->data[i]);
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

hos_interfaces__msg__TubeState__Sequence *
hos_interfaces__msg__TubeState__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  hos_interfaces__msg__TubeState__Sequence * array = (hos_interfaces__msg__TubeState__Sequence *)allocator.allocate(sizeof(hos_interfaces__msg__TubeState__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = hos_interfaces__msg__TubeState__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
hos_interfaces__msg__TubeState__Sequence__destroy(hos_interfaces__msg__TubeState__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    hos_interfaces__msg__TubeState__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
hos_interfaces__msg__TubeState__Sequence__are_equal(const hos_interfaces__msg__TubeState__Sequence * lhs, const hos_interfaces__msg__TubeState__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!hos_interfaces__msg__TubeState__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
hos_interfaces__msg__TubeState__Sequence__copy(
  const hos_interfaces__msg__TubeState__Sequence * input,
  hos_interfaces__msg__TubeState__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(hos_interfaces__msg__TubeState);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    hos_interfaces__msg__TubeState * data =
      (hos_interfaces__msg__TubeState *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!hos_interfaces__msg__TubeState__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          hos_interfaces__msg__TubeState__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!hos_interfaces__msg__TubeState__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
