// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from hos_interfaces:msg/DeviceCommandResult.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "hos_interfaces/msg/detail/device_command_result__rosidl_typesupport_introspection_c.h"
#include "hos_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "hos_interfaces/msg/detail/device_command_result__functions.h"
#include "hos_interfaces/msg/detail/device_command_result__struct.h"


// Include directives for member types
// Member `error`
// Member `result_str`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void hos_interfaces__msg__DeviceCommandResult__rosidl_typesupport_introspection_c__DeviceCommandResult_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  hos_interfaces__msg__DeviceCommandResult__init(message_memory);
}

void hos_interfaces__msg__DeviceCommandResult__rosidl_typesupport_introspection_c__DeviceCommandResult_fini_function(void * message_memory)
{
  hos_interfaces__msg__DeviceCommandResult__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember hos_interfaces__msg__DeviceCommandResult__rosidl_typesupport_introspection_c__DeviceCommandResult_message_member_array[5] = {
  {
    "uid",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hos_interfaces__msg__DeviceCommandResult, uid),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "cmd_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hos_interfaces__msg__DeviceCommandResult, cmd_id),  // bytes offset in struct
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
    offsetof(hos_interfaces__msg__DeviceCommandResult, success),  // bytes offset in struct
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
    offsetof(hos_interfaces__msg__DeviceCommandResult, error),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "result_str",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hos_interfaces__msg__DeviceCommandResult, result_str),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers hos_interfaces__msg__DeviceCommandResult__rosidl_typesupport_introspection_c__DeviceCommandResult_message_members = {
  "hos_interfaces__msg",  // message namespace
  "DeviceCommandResult",  // message name
  5,  // number of fields
  sizeof(hos_interfaces__msg__DeviceCommandResult),
  hos_interfaces__msg__DeviceCommandResult__rosidl_typesupport_introspection_c__DeviceCommandResult_message_member_array,  // message members
  hos_interfaces__msg__DeviceCommandResult__rosidl_typesupport_introspection_c__DeviceCommandResult_init_function,  // function to initialize message memory (memory has to be allocated)
  hos_interfaces__msg__DeviceCommandResult__rosidl_typesupport_introspection_c__DeviceCommandResult_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t hos_interfaces__msg__DeviceCommandResult__rosidl_typesupport_introspection_c__DeviceCommandResult_message_type_support_handle = {
  0,
  &hos_interfaces__msg__DeviceCommandResult__rosidl_typesupport_introspection_c__DeviceCommandResult_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_hos_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, hos_interfaces, msg, DeviceCommandResult)() {
  if (!hos_interfaces__msg__DeviceCommandResult__rosidl_typesupport_introspection_c__DeviceCommandResult_message_type_support_handle.typesupport_identifier) {
    hos_interfaces__msg__DeviceCommandResult__rosidl_typesupport_introspection_c__DeviceCommandResult_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &hos_interfaces__msg__DeviceCommandResult__rosidl_typesupport_introspection_c__DeviceCommandResult_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
