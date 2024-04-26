// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from hos_interfaces:msg/P200AttachementContainerState.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "hos_interfaces/msg/detail/p200_attachement_container_state__rosidl_typesupport_introspection_c.h"
#include "hos_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "hos_interfaces/msg/detail/p200_attachement_container_state__functions.h"
#include "hos_interfaces/msg/detail/p200_attachement_container_state__struct.h"


// Include directives for member types
// Member `external_resources`
// Member `device_uid`
// Member `device_type`
// Member `device_id`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void hos_interfaces__msg__P200AttachementContainerState__rosidl_typesupport_introspection_c__P200AttachementContainerState_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  hos_interfaces__msg__P200AttachementContainerState__init(message_memory);
}

void hos_interfaces__msg__P200AttachementContainerState__rosidl_typesupport_introspection_c__P200AttachementContainerState_fini_function(void * message_memory)
{
  hos_interfaces__msg__P200AttachementContainerState__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember hos_interfaces__msg__P200AttachementContainerState__rosidl_typesupport_introspection_c__P200AttachementContainerState_message_member_array[11] = {
  {
    "is_flipped",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hos_interfaces__msg__P200AttachementContainerState, is_flipped),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "slot_position",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hos_interfaces__msg__P200AttachementContainerState, slot_position),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "external_resources",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hos_interfaces__msg__P200AttachementContainerState, external_resources),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "temperature",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hos_interfaces__msg__P200AttachementContainerState, temperature),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "is_movable",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hos_interfaces__msg__P200AttachementContainerState, is_movable),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "is_connected",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hos_interfaces__msg__P200AttachementContainerState, is_connected),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "last_ping",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hos_interfaces__msg__P200AttachementContainerState, last_ping),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "device_uid",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hos_interfaces__msg__P200AttachementContainerState, device_uid),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "is_reconnected",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hos_interfaces__msg__P200AttachementContainerState, is_reconnected),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "device_type",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hos_interfaces__msg__P200AttachementContainerState, device_type),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "device_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hos_interfaces__msg__P200AttachementContainerState, device_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers hos_interfaces__msg__P200AttachementContainerState__rosidl_typesupport_introspection_c__P200AttachementContainerState_message_members = {
  "hos_interfaces__msg",  // message namespace
  "P200AttachementContainerState",  // message name
  11,  // number of fields
  sizeof(hos_interfaces__msg__P200AttachementContainerState),
  hos_interfaces__msg__P200AttachementContainerState__rosidl_typesupport_introspection_c__P200AttachementContainerState_message_member_array,  // message members
  hos_interfaces__msg__P200AttachementContainerState__rosidl_typesupport_introspection_c__P200AttachementContainerState_init_function,  // function to initialize message memory (memory has to be allocated)
  hos_interfaces__msg__P200AttachementContainerState__rosidl_typesupport_introspection_c__P200AttachementContainerState_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t hos_interfaces__msg__P200AttachementContainerState__rosidl_typesupport_introspection_c__P200AttachementContainerState_message_type_support_handle = {
  0,
  &hos_interfaces__msg__P200AttachementContainerState__rosidl_typesupport_introspection_c__P200AttachementContainerState_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_hos_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, hos_interfaces, msg, P200AttachementContainerState)() {
  if (!hos_interfaces__msg__P200AttachementContainerState__rosidl_typesupport_introspection_c__P200AttachementContainerState_message_type_support_handle.typesupport_identifier) {
    hos_interfaces__msg__P200AttachementContainerState__rosidl_typesupport_introspection_c__P200AttachementContainerState_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &hos_interfaces__msg__P200AttachementContainerState__rosidl_typesupport_introspection_c__P200AttachementContainerState_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
