// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from hos_interfaces:srv/SetStateAPICall.idl
// generated code does not contain a copyright notice

#ifndef HOS_INTERFACES__SRV__DETAIL__SET_STATE_API_CALL__STRUCT_H_
#define HOS_INTERFACES__SRV__DETAIL__SET_STATE_API_CALL__STRUCT_H_

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
// Member 'input_jsons'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/SetStateAPICall in the package hos_interfaces.
typedef struct hos_interfaces__srv__SetStateAPICall_Request
{
  rosidl_runtime_c__String device_id;
  int8_t state_type;
  rosidl_runtime_c__String input_jsons;
} hos_interfaces__srv__SetStateAPICall_Request;

// Struct for a sequence of hos_interfaces__srv__SetStateAPICall_Request.
typedef struct hos_interfaces__srv__SetStateAPICall_Request__Sequence
{
  hos_interfaces__srv__SetStateAPICall_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} hos_interfaces__srv__SetStateAPICall_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'error'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in srv/SetStateAPICall in the package hos_interfaces.
typedef struct hos_interfaces__srv__SetStateAPICall_Response
{
  bool is_valid;
  rosidl_runtime_c__String error;
  uint32_t task_id;
} hos_interfaces__srv__SetStateAPICall_Response;

// Struct for a sequence of hos_interfaces__srv__SetStateAPICall_Response.
typedef struct hos_interfaces__srv__SetStateAPICall_Response__Sequence
{
  hos_interfaces__srv__SetStateAPICall_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} hos_interfaces__srv__SetStateAPICall_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // HOS_INTERFACES__SRV__DETAIL__SET_STATE_API_CALL__STRUCT_H_
