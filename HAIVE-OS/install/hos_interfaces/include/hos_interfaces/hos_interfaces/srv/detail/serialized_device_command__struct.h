// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from hos_interfaces:srv/SerializedDeviceCommand.idl
// generated code does not contain a copyright notice

#ifndef HOS_INTERFACES__SRV__DETAIL__SERIALIZED_DEVICE_COMMAND__STRUCT_H_
#define HOS_INTERFACES__SRV__DETAIL__SERIALIZED_DEVICE_COMMAND__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'serialized_command'
// Member 'function_name'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/SerializedDeviceCommand in the package hos_interfaces.
typedef struct hos_interfaces__srv__SerializedDeviceCommand_Request
{
  uint32_t cmd_id;
  rosidl_runtime_c__String serialized_command;
  rosidl_runtime_c__String function_name;
} hos_interfaces__srv__SerializedDeviceCommand_Request;

// Struct for a sequence of hos_interfaces__srv__SerializedDeviceCommand_Request.
typedef struct hos_interfaces__srv__SerializedDeviceCommand_Request__Sequence
{
  hos_interfaces__srv__SerializedDeviceCommand_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} hos_interfaces__srv__SerializedDeviceCommand_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'error'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in srv/SerializedDeviceCommand in the package hos_interfaces.
typedef struct hos_interfaces__srv__SerializedDeviceCommand_Response
{
  bool is_valid;
  rosidl_runtime_c__String error;
} hos_interfaces__srv__SerializedDeviceCommand_Response;

// Struct for a sequence of hos_interfaces__srv__SerializedDeviceCommand_Response.
typedef struct hos_interfaces__srv__SerializedDeviceCommand_Response__Sequence
{
  hos_interfaces__srv__SerializedDeviceCommand_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} hos_interfaces__srv__SerializedDeviceCommand_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // HOS_INTERFACES__SRV__DETAIL__SERIALIZED_DEVICE_COMMAND__STRUCT_H_
