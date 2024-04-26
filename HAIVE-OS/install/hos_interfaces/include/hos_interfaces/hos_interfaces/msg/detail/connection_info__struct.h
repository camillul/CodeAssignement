// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from hos_interfaces:msg/ConnectionInfo.idl
// generated code does not contain a copyright notice

#ifndef HOS_INTERFACES__MSG__DETAIL__CONNECTION_INFO__STRUCT_H_
#define HOS_INTERFACES__MSG__DETAIL__CONNECTION_INFO__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'device_id'
// Member 'device_type'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/ConnectionInfo in the package hos_interfaces.
typedef struct hos_interfaces__msg__ConnectionInfo
{
  rosidl_runtime_c__String device_id;
  uint32_t device_uid;
  rosidl_runtime_c__String device_type;
  double event_time_s;
} hos_interfaces__msg__ConnectionInfo;

// Struct for a sequence of hos_interfaces__msg__ConnectionInfo.
typedef struct hos_interfaces__msg__ConnectionInfo__Sequence
{
  hos_interfaces__msg__ConnectionInfo * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} hos_interfaces__msg__ConnectionInfo__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // HOS_INTERFACES__MSG__DETAIL__CONNECTION_INFO__STRUCT_H_
