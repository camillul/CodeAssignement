// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from hos_interfaces:msg/MyCobotState.idl
// generated code does not contain a copyright notice

#ifndef HOS_INTERFACES__MSG__DETAIL__MY_COBOT_STATE__STRUCT_H_
#define HOS_INTERFACES__MSG__DETAIL__MY_COBOT_STATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'device_uid'
// Member 'device_type'
// Member 'device_id'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/MyCobotState in the package hos_interfaces.
typedef struct hos_interfaces__msg__MyCobotState
{
  bool is_connected;
  float last_ping;
  rosidl_runtime_c__String device_uid;
  bool is_reconnected;
  rosidl_runtime_c__String device_type;
  rosidl_runtime_c__String device_id;
} hos_interfaces__msg__MyCobotState;

// Struct for a sequence of hos_interfaces__msg__MyCobotState.
typedef struct hos_interfaces__msg__MyCobotState__Sequence
{
  hos_interfaces__msg__MyCobotState * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} hos_interfaces__msg__MyCobotState__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // HOS_INTERFACES__MSG__DETAIL__MY_COBOT_STATE__STRUCT_H_
