// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from hos_interfaces:srv/BehaviorRequestMoveContainer.idl
// generated code does not contain a copyright notice

#ifndef HOS_INTERFACES__SRV__DETAIL__BEHAVIOR_REQUEST_MOVE_CONTAINER__STRUCT_H_
#define HOS_INTERFACES__SRV__DETAIL__BEHAVIOR_REQUEST_MOVE_CONTAINER__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'container_id'
// Member 'haive_id'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/BehaviorRequestMoveContainer in the package hos_interfaces.
typedef struct hos_interfaces__srv__BehaviorRequestMoveContainer_Request
{
  rosidl_runtime_c__String container_id;
  rosidl_runtime_c__String haive_id;
  uint8_t slot;
} hos_interfaces__srv__BehaviorRequestMoveContainer_Request;

// Struct for a sequence of hos_interfaces__srv__BehaviorRequestMoveContainer_Request.
typedef struct hos_interfaces__srv__BehaviorRequestMoveContainer_Request__Sequence
{
  hos_interfaces__srv__BehaviorRequestMoveContainer_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} hos_interfaces__srv__BehaviorRequestMoveContainer_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'error'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in srv/BehaviorRequestMoveContainer in the package hos_interfaces.
typedef struct hos_interfaces__srv__BehaviorRequestMoveContainer_Response
{
  bool success;
  rosidl_runtime_c__String error;
} hos_interfaces__srv__BehaviorRequestMoveContainer_Response;

// Struct for a sequence of hos_interfaces__srv__BehaviorRequestMoveContainer_Response.
typedef struct hos_interfaces__srv__BehaviorRequestMoveContainer_Response__Sequence
{
  hos_interfaces__srv__BehaviorRequestMoveContainer_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} hos_interfaces__srv__BehaviorRequestMoveContainer_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // HOS_INTERFACES__SRV__DETAIL__BEHAVIOR_REQUEST_MOVE_CONTAINER__STRUCT_H_
