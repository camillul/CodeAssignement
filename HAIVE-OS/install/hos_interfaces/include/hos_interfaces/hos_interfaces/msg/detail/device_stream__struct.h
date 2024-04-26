// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from hos_interfaces:msg/DeviceStream.idl
// generated code does not contain a copyright notice

#ifndef HOS_INTERFACES__MSG__DETAIL__DEVICE_STREAM__STRUCT_H_
#define HOS_INTERFACES__MSG__DETAIL__DEVICE_STREAM__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'data'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/DeviceStream in the package hos_interfaces.
typedef struct hos_interfaces__msg__DeviceStream
{
  uint32_t uid;
  rosidl_runtime_c__String data;
} hos_interfaces__msg__DeviceStream;

// Struct for a sequence of hos_interfaces__msg__DeviceStream.
typedef struct hos_interfaces__msg__DeviceStream__Sequence
{
  hos_interfaces__msg__DeviceStream * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} hos_interfaces__msg__DeviceStream__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // HOS_INTERFACES__MSG__DETAIL__DEVICE_STREAM__STRUCT_H_
