// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from hos_interfaces:msg/TypedField.idl
// generated code does not contain a copyright notice

#ifndef HOS_INTERFACES__MSG__DETAIL__TYPED_FIELD__STRUCT_H_
#define HOS_INTERFACES__MSG__DETAIL__TYPED_FIELD__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'name'
// Member 'type'
// Member 'data'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/TypedField in the package hos_interfaces.
typedef struct hos_interfaces__msg__TypedField
{
  rosidl_runtime_c__String name;
  rosidl_runtime_c__String type;
  rosidl_runtime_c__String data;
} hos_interfaces__msg__TypedField;

// Struct for a sequence of hos_interfaces__msg__TypedField.
typedef struct hos_interfaces__msg__TypedField__Sequence
{
  hos_interfaces__msg__TypedField * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} hos_interfaces__msg__TypedField__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // HOS_INTERFACES__MSG__DETAIL__TYPED_FIELD__STRUCT_H_
