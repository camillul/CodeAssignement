// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from hos_interfaces:msg/DeviceCommandResult.idl
// generated code does not contain a copyright notice

#ifndef HOS_INTERFACES__MSG__DETAIL__DEVICE_COMMAND_RESULT__STRUCT_H_
#define HOS_INTERFACES__MSG__DETAIL__DEVICE_COMMAND_RESULT__STRUCT_H_

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
// Member 'result_str'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/DeviceCommandResult in the package hos_interfaces.
typedef struct hos_interfaces__msg__DeviceCommandResult
{
  uint32_t uid;
  uint32_t cmd_id;
  bool success;
  rosidl_runtime_c__String error;
  rosidl_runtime_c__String result_str;
} hos_interfaces__msg__DeviceCommandResult;

// Struct for a sequence of hos_interfaces__msg__DeviceCommandResult.
typedef struct hos_interfaces__msg__DeviceCommandResult__Sequence
{
  hos_interfaces__msg__DeviceCommandResult * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} hos_interfaces__msg__DeviceCommandResult__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // HOS_INTERFACES__MSG__DETAIL__DEVICE_COMMAND_RESULT__STRUCT_H_
