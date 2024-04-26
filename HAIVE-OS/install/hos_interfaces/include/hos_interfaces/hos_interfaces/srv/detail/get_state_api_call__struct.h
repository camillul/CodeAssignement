// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from hos_interfaces:srv/GetStateAPICall.idl
// generated code does not contain a copyright notice

#ifndef HOS_INTERFACES__SRV__DETAIL__GET_STATE_API_CALL__STRUCT_H_
#define HOS_INTERFACES__SRV__DETAIL__GET_STATE_API_CALL__STRUCT_H_

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
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/GetStateAPICall in the package hos_interfaces.
typedef struct hos_interfaces__srv__GetStateAPICall_Request
{
  rosidl_runtime_c__String device_id;
  int8_t state_type;
} hos_interfaces__srv__GetStateAPICall_Request;

// Struct for a sequence of hos_interfaces__srv__GetStateAPICall_Request.
typedef struct hos_interfaces__srv__GetStateAPICall_Request__Sequence
{
  hos_interfaces__srv__GetStateAPICall_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} hos_interfaces__srv__GetStateAPICall_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'error'
// Member 'result_jsons'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in srv/GetStateAPICall in the package hos_interfaces.
typedef struct hos_interfaces__srv__GetStateAPICall_Response
{
  bool is_valid;
  rosidl_runtime_c__String error;
  uint32_t task_id;
  rosidl_runtime_c__String result_jsons;
} hos_interfaces__srv__GetStateAPICall_Response;

// Struct for a sequence of hos_interfaces__srv__GetStateAPICall_Response.
typedef struct hos_interfaces__srv__GetStateAPICall_Response__Sequence
{
  hos_interfaces__srv__GetStateAPICall_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} hos_interfaces__srv__GetStateAPICall_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // HOS_INTERFACES__SRV__DETAIL__GET_STATE_API_CALL__STRUCT_H_
