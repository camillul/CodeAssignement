// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from hos_interfaces:msg/TubeState.idl
// generated code does not contain a copyright notice

#ifndef HOS_INTERFACES__MSG__DETAIL__TUBE_STATE__STRUCT_H_
#define HOS_INTERFACES__MSG__DETAIL__TUBE_STATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'tube_id'
// Member 'tube_type'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/TubeState in the package hos_interfaces.
typedef struct hos_interfaces__msg__TubeState
{
  float liquid_level;
  rosidl_runtime_c__String tube_id;
  rosidl_runtime_c__String tube_type;
  float volume;
  float temperature;
} hos_interfaces__msg__TubeState;

// Struct for a sequence of hos_interfaces__msg__TubeState.
typedef struct hos_interfaces__msg__TubeState__Sequence
{
  hos_interfaces__msg__TubeState * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} hos_interfaces__msg__TubeState__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // HOS_INTERFACES__MSG__DETAIL__TUBE_STATE__STRUCT_H_
