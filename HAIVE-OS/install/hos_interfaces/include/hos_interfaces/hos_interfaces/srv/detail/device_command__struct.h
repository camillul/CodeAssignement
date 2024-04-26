// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from hos_interfaces:srv/DeviceCommand.idl
// generated code does not contain a copyright notice

#ifndef HOS_INTERFACES__SRV__DETAIL__DEVICE_COMMAND__STRUCT_H_
#define HOS_INTERFACES__SRV__DETAIL__DEVICE_COMMAND__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'function_name'
#include "rosidl_runtime_c/string.h"
// Member 'args'
#include "hos_interfaces/msg/detail/typed_field__struct.h"

/// Struct defined in srv/DeviceCommand in the package hos_interfaces.
typedef struct hos_interfaces__srv__DeviceCommand_Request
{
  uint32_t cmd_id;
  rosidl_runtime_c__String function_name;
  uint8_t num_args;
  hos_interfaces__msg__TypedField__Sequence args;
} hos_interfaces__srv__DeviceCommand_Request;

// Struct for a sequence of hos_interfaces__srv__DeviceCommand_Request.
typedef struct hos_interfaces__srv__DeviceCommand_Request__Sequence
{
  hos_interfaces__srv__DeviceCommand_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} hos_interfaces__srv__DeviceCommand_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'error'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in srv/DeviceCommand in the package hos_interfaces.
typedef struct hos_interfaces__srv__DeviceCommand_Response
{
  bool is_valid;
  rosidl_runtime_c__String error;
} hos_interfaces__srv__DeviceCommand_Response;

// Struct for a sequence of hos_interfaces__srv__DeviceCommand_Response.
typedef struct hos_interfaces__srv__DeviceCommand_Response__Sequence
{
  hos_interfaces__srv__DeviceCommand_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} hos_interfaces__srv__DeviceCommand_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // HOS_INTERFACES__SRV__DETAIL__DEVICE_COMMAND__STRUCT_H_
