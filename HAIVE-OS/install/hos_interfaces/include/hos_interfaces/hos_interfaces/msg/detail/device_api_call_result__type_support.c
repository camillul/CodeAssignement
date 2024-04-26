// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from hos_interfaces:msg/DeviceAPICallResult.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "hos_interfaces/msg/detail/device_api_call_result__rosidl_typesupport_introspection_c.h"
#include "hos_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "hos_interfaces/msg/detail/device_api_call_result__functions.h"
#include "hos_interfaces/msg/detail/device_api_call_result__struct.h"


// Include directives for member types
// Member `error`
// Member `result_jsons`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void hos_interfaces__msg__DeviceAPICallResult__rosidl_typesupport_introspection_c__DeviceAPICallResult_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  hos_interfaces__msg__DeviceAPICallResult__init(message_memory);
}

void hos_interfaces__msg__DeviceAPICallResult__rosidl_typesupport_introspection_c__DeviceAPICallResult_fini_function(void * message_memory)
{
  hos_interfaces__msg__DeviceAPICallResult__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember hos_interfaces__msg__DeviceAPICallResult__rosidl_typesupport_introspection_c__DeviceAPICallResult_message_member_array[6] = {
  {
    "task_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hos_interfaces__msg__DeviceAPICallResult, task_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "success",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hos_interfaces__msg__DeviceAPICallResult, success),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "error",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hos_interfaces__msg__DeviceAPICallResult, error),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "result_jsons",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hos_interfaces__msg__DeviceAPICallResult, result_jsons),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "request_time_s",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hos_interfaces__msg__DeviceAPICallResult, request_time_s),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "response_time_s",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hos_interfaces__msg__DeviceAPICallResult, response_time_s),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers hos_interfaces__msg__DeviceAPICallResult__rosidl_typesupport_introspection_c__DeviceAPICallResult_message_members = {
  "hos_interfaces__msg",  // message namespace
  "DeviceAPICallResult",  // message name
  6,  // number of fields
  sizeof(hos_interfaces__msg__DeviceAPICallResult),
  hos_interfaces__msg__DeviceAPICallResult__rosidl_typesupport_introspection_c__DeviceAPICallResult_message_member_array,  // message members
  hos_interfaces__msg__DeviceAPICallResult__rosidl_typesupport_introspection_c__DeviceAPICallResult_init_function,  // function to initialize message memory (memory has to be allocated)
  hos_interfaces__msg__DeviceAPICallResult__rosidl_typesupport_introspection_c__DeviceAPICallResult_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t hos_interfaces__msg__DeviceAPICallResult__rosidl_typesupport_introspection_c__DeviceAPICallResult_message_type_support_handle = {
  0,
  &hos_interfaces__msg__DeviceAPICallResult__rosidl_typesupport_introspection_c__DeviceAPICallResult_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_hos_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, hos_interfaces, msg, DeviceAPICallResult)() {
  if (!hos_interfaces__msg__DeviceAPICallResult__rosidl_typesupport_introspection_c__DeviceAPICallResult_message_type_support_handle.typesupport_identifier) {
    hos_interfaces__msg__DeviceAPICallResult__rosidl_typesupport_introspection_c__DeviceAPICallResult_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &hos_interfaces__msg__DeviceAPICallResult__rosidl_typesupport_introspection_c__DeviceAPICallResult_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
