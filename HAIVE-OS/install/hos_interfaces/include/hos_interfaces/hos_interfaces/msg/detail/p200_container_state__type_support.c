// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from hos_interfaces:msg/P200ContainerState.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "hos_interfaces/msg/detail/p200_container_state__rosidl_typesupport_introspection_c.h"
#include "hos_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "hos_interfaces/msg/detail/p200_container_state__functions.h"
#include "hos_interfaces/msg/detail/p200_container_state__struct.h"


// Include directives for member types
// Member `tips_availaible`
#include "rosidl_runtime_c/primitives_sequence_functions.h"
// Member `external_resources`
// Member `device_uid`
// Member `device_type`
// Member `device_id`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void hos_interfaces__msg__P200ContainerState__rosidl_typesupport_introspection_c__P200ContainerState_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  hos_interfaces__msg__P200ContainerState__init(message_memory);
}

void hos_interfaces__msg__P200ContainerState__rosidl_typesupport_introspection_c__P200ContainerState_fini_function(void * message_memory)
{
  hos_interfaces__msg__P200ContainerState__fini(message_memory);
}

size_t hos_interfaces__msg__P200ContainerState__rosidl_typesupport_introspection_c__size_function__P200ContainerState__tips_availaible(
  const void * untyped_member)
{
  const rosidl_runtime_c__uint16__Sequence * member =
    (const rosidl_runtime_c__uint16__Sequence *)(untyped_member);
  return member->size;
}

const void * hos_interfaces__msg__P200ContainerState__rosidl_typesupport_introspection_c__get_const_function__P200ContainerState__tips_availaible(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__uint16__Sequence * member =
    (const rosidl_runtime_c__uint16__Sequence *)(untyped_member);
  return &member->data[index];
}

void * hos_interfaces__msg__P200ContainerState__rosidl_typesupport_introspection_c__get_function__P200ContainerState__tips_availaible(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__uint16__Sequence * member =
    (rosidl_runtime_c__uint16__Sequence *)(untyped_member);
  return &member->data[index];
}

void hos_interfaces__msg__P200ContainerState__rosidl_typesupport_introspection_c__fetch_function__P200ContainerState__tips_availaible(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const uint16_t * item =
    ((const uint16_t *)
    hos_interfaces__msg__P200ContainerState__rosidl_typesupport_introspection_c__get_const_function__P200ContainerState__tips_availaible(untyped_member, index));
  uint16_t * value =
    (uint16_t *)(untyped_value);
  *value = *item;
}

void hos_interfaces__msg__P200ContainerState__rosidl_typesupport_introspection_c__assign_function__P200ContainerState__tips_availaible(
  void * untyped_member, size_t index, const void * untyped_value)
{
  uint16_t * item =
    ((uint16_t *)
    hos_interfaces__msg__P200ContainerState__rosidl_typesupport_introspection_c__get_function__P200ContainerState__tips_availaible(untyped_member, index));
  const uint16_t * value =
    (const uint16_t *)(untyped_value);
  *item = *value;
}

bool hos_interfaces__msg__P200ContainerState__rosidl_typesupport_introspection_c__resize_function__P200ContainerState__tips_availaible(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__uint16__Sequence * member =
    (rosidl_runtime_c__uint16__Sequence *)(untyped_member);
  rosidl_runtime_c__uint16__Sequence__fini(member);
  return rosidl_runtime_c__uint16__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember hos_interfaces__msg__P200ContainerState__rosidl_typesupport_introspection_c__P200ContainerState_message_member_array[14] = {
  {
    "x_size",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hos_interfaces__msg__P200ContainerState, x_size),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "y_size",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hos_interfaces__msg__P200ContainerState, y_size),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "tips_availaible",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT16,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hos_interfaces__msg__P200ContainerState, tips_availaible),  // bytes offset in struct
    NULL,  // default value
    hos_interfaces__msg__P200ContainerState__rosidl_typesupport_introspection_c__size_function__P200ContainerState__tips_availaible,  // size() function pointer
    hos_interfaces__msg__P200ContainerState__rosidl_typesupport_introspection_c__get_const_function__P200ContainerState__tips_availaible,  // get_const(index) function pointer
    hos_interfaces__msg__P200ContainerState__rosidl_typesupport_introspection_c__get_function__P200ContainerState__tips_availaible,  // get(index) function pointer
    hos_interfaces__msg__P200ContainerState__rosidl_typesupport_introspection_c__fetch_function__P200ContainerState__tips_availaible,  // fetch(index, &value) function pointer
    hos_interfaces__msg__P200ContainerState__rosidl_typesupport_introspection_c__assign_function__P200ContainerState__tips_availaible,  // assign(index, value) function pointer
    hos_interfaces__msg__P200ContainerState__rosidl_typesupport_introspection_c__resize_function__P200ContainerState__tips_availaible  // resize(index) function pointer
  },
  {
    "is_flipped",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hos_interfaces__msg__P200ContainerState, is_flipped),  // bytes offset in struct
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
    offsetof(hos_interfaces__msg__P200ContainerState, slot_position),  // bytes offset in struct
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
    offsetof(hos_interfaces__msg__P200ContainerState, external_resources),  // bytes offset in struct
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
    offsetof(hos_interfaces__msg__P200ContainerState, temperature),  // bytes offset in struct
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
    offsetof(hos_interfaces__msg__P200ContainerState, is_movable),  // bytes offset in struct
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
    offsetof(hos_interfaces__msg__P200ContainerState, is_connected),  // bytes offset in struct
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
    offsetof(hos_interfaces__msg__P200ContainerState, last_ping),  // bytes offset in struct
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
    offsetof(hos_interfaces__msg__P200ContainerState, device_uid),  // bytes offset in struct
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
    offsetof(hos_interfaces__msg__P200ContainerState, is_reconnected),  // bytes offset in struct
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
    offsetof(hos_interfaces__msg__P200ContainerState, device_type),  // bytes offset in struct
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
    offsetof(hos_interfaces__msg__P200ContainerState, device_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers hos_interfaces__msg__P200ContainerState__rosidl_typesupport_introspection_c__P200ContainerState_message_members = {
  "hos_interfaces__msg",  // message namespace
  "P200ContainerState",  // message name
  14,  // number of fields
  sizeof(hos_interfaces__msg__P200ContainerState),
  hos_interfaces__msg__P200ContainerState__rosidl_typesupport_introspection_c__P200ContainerState_message_member_array,  // message members
  hos_interfaces__msg__P200ContainerState__rosidl_typesupport_introspection_c__P200ContainerState_init_function,  // function to initialize message memory (memory has to be allocated)
  hos_interfaces__msg__P200ContainerState__rosidl_typesupport_introspection_c__P200ContainerState_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t hos_interfaces__msg__P200ContainerState__rosidl_typesupport_introspection_c__P200ContainerState_message_type_support_handle = {
  0,
  &hos_interfaces__msg__P200ContainerState__rosidl_typesupport_introspection_c__P200ContainerState_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_hos_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, hos_interfaces, msg, P200ContainerState)() {
  if (!hos_interfaces__msg__P200ContainerState__rosidl_typesupport_introspection_c__P200ContainerState_message_type_support_handle.typesupport_identifier) {
    hos_interfaces__msg__P200ContainerState__rosidl_typesupport_introspection_c__P200ContainerState_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &hos_interfaces__msg__P200ContainerState__rosidl_typesupport_introspection_c__P200ContainerState_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
