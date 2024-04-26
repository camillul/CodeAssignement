// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from hos_interfaces:msg/DeviceAPICallResult.idl
// generated code does not contain a copyright notice

#ifndef HOS_INTERFACES__MSG__DETAIL__DEVICE_API_CALL_RESULT__STRUCT_H_
#define HOS_INTERFACES__MSG__DETAIL__DEVICE_API_CALL_RESULT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'error'
// Member 'result_jsons'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/DeviceAPICallResult in the package hos_interfaces.
typedef struct hos_interfaces__msg__DeviceAPICallResult
{
  uint32_t task_id;
  bool success;
  rosidl_runtime_c__String error;
  rosidl_runtime_c__String result_jsons;
  double request_time_s;
  double response_time_s;
} hos_interfaces__msg__DeviceAPICallResult;

// Struct for a sequence of hos_interfaces__msg__DeviceAPICallResult.
typedef struct hos_interfaces__msg__DeviceAPICallResult__Sequence
{
  hos_interfaces__msg__DeviceAPICallResult * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} hos_interfaces__msg__DeviceAPICallResult__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // HOS_INTERFACES__MSG__DETAIL__DEVICE_API_CALL_RESULT__STRUCT_H_
