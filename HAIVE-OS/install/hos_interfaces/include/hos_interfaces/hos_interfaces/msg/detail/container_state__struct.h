// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from hos_interfaces:msg/ContainerState.idl
// generated code does not contain a copyright notice

#ifndef HOS_INTERFACES__MSG__DETAIL__CONTAINER_STATE__STRUCT_H_
#define HOS_INTERFACES__MSG__DETAIL__CONTAINER_STATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'external_resources'
// Member 'device_uid'
// Member 'device_type'
// Member 'device_id'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/ContainerState in the package hos_interfaces.
typedef struct hos_interfaces__msg__ContainerState
{
  bool is_flipped;
  uint8_t slot_position;
  rosidl_runtime_c__String external_resources;
  float temperature;
  bool is_movable;
  bool is_connected;
  float last_ping;
  rosidl_runtime_c__String device_uid;
  bool is_reconnected;
  rosidl_runtime_c__String device_type;
  rosidl_runtime_c__String device_id;
} hos_interfaces__msg__ContainerState;

// Struct for a sequence of hos_interfaces__msg__ContainerState.
typedef struct hos_interfaces__msg__ContainerState__Sequence
{
  hos_interfaces__msg__ContainerState * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} hos_interfaces__msg__ContainerState__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // HOS_INTERFACES__MSG__DETAIL__CONTAINER_STATE__STRUCT_H_
