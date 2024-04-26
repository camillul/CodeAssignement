// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from hos_interfaces:srv/ConnectDevice.idl
// generated code does not contain a copyright notice

#ifndef HOS_INTERFACES__SRV__DETAIL__CONNECT_DEVICE__STRUCT_H_
#define HOS_INTERFACES__SRV__DETAIL__CONNECT_DEVICE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/ConnectDevice in the package hos_interfaces.
typedef struct hos_interfaces__srv__ConnectDevice_Request
{
  uint32_t uid;
} hos_interfaces__srv__ConnectDevice_Request;

// Struct for a sequence of hos_interfaces__srv__ConnectDevice_Request.
typedef struct hos_interfaces__srv__ConnectDevice_Request__Sequence
{
  hos_interfaces__srv__ConnectDevice_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} hos_interfaces__srv__ConnectDevice_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'error'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/ConnectDevice in the package hos_interfaces.
typedef struct hos_interfaces__srv__ConnectDevice_Response
{
  bool success;
  rosidl_runtime_c__String error;
} hos_interfaces__srv__ConnectDevice_Response;

// Struct for a sequence of hos_interfaces__srv__ConnectDevice_Response.
typedef struct hos_interfaces__srv__ConnectDevice_Response__Sequence
{
  hos_interfaces__srv__ConnectDevice_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} hos_interfaces__srv__ConnectDevice_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // HOS_INTERFACES__SRV__DETAIL__CONNECT_DEVICE__STRUCT_H_
