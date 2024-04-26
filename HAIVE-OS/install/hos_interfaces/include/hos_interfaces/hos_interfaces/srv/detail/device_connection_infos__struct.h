// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from hos_interfaces:srv/DeviceConnectionInfos.idl
// generated code does not contain a copyright notice

#ifndef HOS_INTERFACES__SRV__DETAIL__DEVICE_CONNECTION_INFOS__STRUCT_H_
#define HOS_INTERFACES__SRV__DETAIL__DEVICE_CONNECTION_INFOS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/DeviceConnectionInfos in the package hos_interfaces.
typedef struct hos_interfaces__srv__DeviceConnectionInfos_Request
{
  uint8_t structure_needs_at_least_one_member;
} hos_interfaces__srv__DeviceConnectionInfos_Request;

// Struct for a sequence of hos_interfaces__srv__DeviceConnectionInfos_Request.
typedef struct hos_interfaces__srv__DeviceConnectionInfos_Request__Sequence
{
  hos_interfaces__srv__DeviceConnectionInfos_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} hos_interfaces__srv__DeviceConnectionInfos_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'device_infos'
#include "hos_interfaces/msg/detail/connection_info__struct.h"

/// Struct defined in srv/DeviceConnectionInfos in the package hos_interfaces.
typedef struct hos_interfaces__srv__DeviceConnectionInfos_Response
{
  hos_interfaces__msg__ConnectionInfo__Sequence device_infos;
} hos_interfaces__srv__DeviceConnectionInfos_Response;

// Struct for a sequence of hos_interfaces__srv__DeviceConnectionInfos_Response.
typedef struct hos_interfaces__srv__DeviceConnectionInfos_Response__Sequence
{
  hos_interfaces__srv__DeviceConnectionInfos_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} hos_interfaces__srv__DeviceConnectionInfos_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // HOS_INTERFACES__SRV__DETAIL__DEVICE_CONNECTION_INFOS__STRUCT_H_
