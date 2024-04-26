// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from hos_interfaces:srv/DeviceCommand.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "hos_interfaces/srv/detail/device_command__rosidl_typesupport_introspection_c.h"
#include "hos_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "hos_interfaces/srv/detail/device_command__functions.h"
#include "hos_interfaces/srv/detail/device_command__struct.h"


// Include directives for member types
// Member `function_name`
#include "rosidl_runtime_c/string_functions.h"
// Member `args`
#include "hos_interfaces/msg/typed_field.h"
// Member `args`
#include "hos_interfaces/msg/detail/typed_field__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void hos_interfaces__srv__DeviceCommand_Request__rosidl_typesupport_introspection_c__DeviceCommand_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  hos_interfaces__srv__DeviceCommand_Request__init(message_memory);
}

void hos_interfaces__srv__DeviceCommand_Request__rosidl_typesupport_introspection_c__DeviceCommand_Request_fini_function(void * message_memory)
{
  hos_interfaces__srv__DeviceCommand_Request__fini(message_memory);
}

size_t hos_interfaces__srv__DeviceCommand_Request__rosidl_typesupport_introspection_c__size_function__DeviceCommand_Request__args(
  const void * untyped_member)
{
  const hos_interfaces__msg__TypedField__Sequence * member =
    (const hos_interfaces__msg__TypedField__Sequence *)(untyped_member);
  return member->size;
}

const void * hos_interfaces__srv__DeviceCommand_Request__rosidl_typesupport_introspection_c__get_const_function__DeviceCommand_Request__args(
  const void * untyped_member, size_t index)
{
  const hos_interfaces__msg__TypedField__Sequence * member =
    (const hos_interfaces__msg__TypedField__Sequence *)(untyped_member);
  return &member->data[index];
}

void * hos_interfaces__srv__DeviceCommand_Request__rosidl_typesupport_introspection_c__get_function__DeviceCommand_Request__args(
  void * untyped_member, size_t index)
{
  hos_interfaces__msg__TypedField__Sequence * member =
    (hos_interfaces__msg__TypedField__Sequence *)(untyped_member);
  return &member->data[index];
}

void hos_interfaces__srv__DeviceCommand_Request__rosidl_typesupport_introspection_c__fetch_function__DeviceCommand_Request__args(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const hos_interfaces__msg__TypedField * item =
    ((const hos_interfaces__msg__TypedField *)
    hos_interfaces__srv__DeviceCommand_Request__rosidl_typesupport_introspection_c__get_const_function__DeviceCommand_Request__args(untyped_member, index));
  hos_interfaces__msg__TypedField * value =
    (hos_interfaces__msg__TypedField *)(untyped_value);
  *value = *item;
}

void hos_interfaces__srv__DeviceCommand_Request__rosidl_typesupport_introspection_c__assign_function__DeviceCommand_Request__args(
  void * untyped_member, size_t index, const void * untyped_value)
{
  hos_interfaces__msg__TypedField * item =
    ((hos_interfaces__msg__TypedField *)
    hos_interfaces__srv__DeviceCommand_Request__rosidl_typesupport_introspection_c__get_function__DeviceCommand_Request__args(untyped_member, index));
  const hos_interfaces__msg__TypedField * value =
    (const hos_interfaces__msg__TypedField *)(untyped_value);
  *item = *value;
}

bool hos_interfaces__srv__DeviceCommand_Request__rosidl_typesupport_introspection_c__resize_function__DeviceCommand_Request__args(
  void * untyped_member, size_t size)
{
  hos_interfaces__msg__TypedField__Sequence * member =
    (hos_interfaces__msg__TypedField__Sequence *)(untyped_member);
  hos_interfaces__msg__TypedField__Sequence__fini(member);
  return hos_interfaces__msg__TypedField__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember hos_interfaces__srv__DeviceCommand_Request__rosidl_typesupport_introspection_c__DeviceCommand_Request_message_member_array[4] = {
  {
    "cmd_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hos_interfaces__srv__DeviceCommand_Request, cmd_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "function_name",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hos_interfaces__srv__DeviceCommand_Request, function_name),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "num_args",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hos_interfaces__srv__DeviceCommand_Request, num_args),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "args",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hos_interfaces__srv__DeviceCommand_Request, args),  // bytes offset in struct
    NULL,  // default value
    hos_interfaces__srv__DeviceCommand_Request__rosidl_typesupport_introspection_c__size_function__DeviceCommand_Request__args,  // size() function pointer
    hos_interfaces__srv__DeviceCommand_Request__rosidl_typesupport_introspection_c__get_const_function__DeviceCommand_Request__args,  // get_const(index) function pointer
    hos_interfaces__srv__DeviceCommand_Request__rosidl_typesupport_introspection_c__get_function__DeviceCommand_Request__args,  // get(index) function pointer
    hos_interfaces__srv__DeviceCommand_Request__rosidl_typesupport_introspection_c__fetch_function__DeviceCommand_Request__args,  // fetch(index, &value) function pointer
    hos_interfaces__srv__DeviceCommand_Request__rosidl_typesupport_introspection_c__assign_function__DeviceCommand_Request__args,  // assign(index, value) function pointer
    hos_interfaces__srv__DeviceCommand_Request__rosidl_typesupport_introspection_c__resize_function__DeviceCommand_Request__args  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers hos_interfaces__srv__DeviceCommand_Request__rosidl_typesupport_introspection_c__DeviceCommand_Request_message_members = {
  "hos_interfaces__srv",  // message namespace
  "DeviceCommand_Request",  // message name
  4,  // number of fields
  sizeof(hos_interfaces__srv__DeviceCommand_Request),
  hos_interfaces__srv__DeviceCommand_Request__rosidl_typesupport_introspection_c__DeviceCommand_Request_message_member_array,  // message members
  hos_interfaces__srv__DeviceCommand_Request__rosidl_typesupport_introspection_c__DeviceCommand_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  hos_interfaces__srv__DeviceCommand_Request__rosidl_typesupport_introspection_c__DeviceCommand_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t hos_interfaces__srv__DeviceCommand_Request__rosidl_typesupport_introspection_c__DeviceCommand_Request_message_type_support_handle = {
  0,
  &hos_interfaces__srv__DeviceCommand_Request__rosidl_typesupport_introspection_c__DeviceCommand_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_hos_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, hos_interfaces, srv, DeviceCommand_Request)() {
  hos_interfaces__srv__DeviceCommand_Request__rosidl_typesupport_introspection_c__DeviceCommand_Request_message_member_array[3].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, hos_interfaces, msg, TypedField)();
  if (!hos_interfaces__srv__DeviceCommand_Request__rosidl_typesupport_introspection_c__DeviceCommand_Request_message_type_support_handle.typesupport_identifier) {
    hos_interfaces__srv__DeviceCommand_Request__rosidl_typesupport_introspection_c__DeviceCommand_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &hos_interfaces__srv__DeviceCommand_Request__rosidl_typesupport_introspection_c__DeviceCommand_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "hos_interfaces/srv/detail/device_command__rosidl_typesupport_introspection_c.h"
// already included above
// #include "hos_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "hos_interfaces/srv/detail/device_command__functions.h"
// already included above
// #include "hos_interfaces/srv/detail/device_command__struct.h"


// Include directives for member types
// Member `error`
// already included above
// #include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void hos_interfaces__srv__DeviceCommand_Response__rosidl_typesupport_introspection_c__DeviceCommand_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  hos_interfaces__srv__DeviceCommand_Response__init(message_memory);
}

void hos_interfaces__srv__DeviceCommand_Response__rosidl_typesupport_introspection_c__DeviceCommand_Response_fini_function(void * message_memory)
{
  hos_interfaces__srv__DeviceCommand_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember hos_interfaces__srv__DeviceCommand_Response__rosidl_typesupport_introspection_c__DeviceCommand_Response_message_member_array[2] = {
  {
    "is_valid",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hos_interfaces__srv__DeviceCommand_Response, is_valid),  // bytes offset in struct
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
    offsetof(hos_interfaces__srv__DeviceCommand_Response, error),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers hos_interfaces__srv__DeviceCommand_Response__rosidl_typesupport_introspection_c__DeviceCommand_Response_message_members = {
  "hos_interfaces__srv",  // message namespace
  "DeviceCommand_Response",  // message name
  2,  // number of fields
  sizeof(hos_interfaces__srv__DeviceCommand_Response),
  hos_interfaces__srv__DeviceCommand_Response__rosidl_typesupport_introspection_c__DeviceCommand_Response_message_member_array,  // message members
  hos_interfaces__srv__DeviceCommand_Response__rosidl_typesupport_introspection_c__DeviceCommand_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  hos_interfaces__srv__DeviceCommand_Response__rosidl_typesupport_introspection_c__DeviceCommand_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t hos_interfaces__srv__DeviceCommand_Response__rosidl_typesupport_introspection_c__DeviceCommand_Response_message_type_support_handle = {
  0,
  &hos_interfaces__srv__DeviceCommand_Response__rosidl_typesupport_introspection_c__DeviceCommand_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_hos_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, hos_interfaces, srv, DeviceCommand_Response)() {
  if (!hos_interfaces__srv__DeviceCommand_Response__rosidl_typesupport_introspection_c__DeviceCommand_Response_message_type_support_handle.typesupport_identifier) {
    hos_interfaces__srv__DeviceCommand_Response__rosidl_typesupport_introspection_c__DeviceCommand_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &hos_interfaces__srv__DeviceCommand_Response__rosidl_typesupport_introspection_c__DeviceCommand_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "hos_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "hos_interfaces/srv/detail/device_command__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers hos_interfaces__srv__detail__device_command__rosidl_typesupport_introspection_c__DeviceCommand_service_members = {
  "hos_interfaces__srv",  // service namespace
  "DeviceCommand",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // hos_interfaces__srv__detail__device_command__rosidl_typesupport_introspection_c__DeviceCommand_Request_message_type_support_handle,
  NULL  // response message
  // hos_interfaces__srv__detail__device_command__rosidl_typesupport_introspection_c__DeviceCommand_Response_message_type_support_handle
};

static rosidl_service_type_support_t hos_interfaces__srv__detail__device_command__rosidl_typesupport_introspection_c__DeviceCommand_service_type_support_handle = {
  0,
  &hos_interfaces__srv__detail__device_command__rosidl_typesupport_introspection_c__DeviceCommand_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, hos_interfaces, srv, DeviceCommand_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, hos_interfaces, srv, DeviceCommand_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_hos_interfaces
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, hos_interfaces, srv, DeviceCommand)() {
  if (!hos_interfaces__srv__detail__device_command__rosidl_typesupport_introspection_c__DeviceCommand_service_type_support_handle.typesupport_identifier) {
    hos_interfaces__srv__detail__device_command__rosidl_typesupport_introspection_c__DeviceCommand_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)hos_interfaces__srv__detail__device_command__rosidl_typesupport_introspection_c__DeviceCommand_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, hos_interfaces, srv, DeviceCommand_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, hos_interfaces, srv, DeviceCommand_Response)()->data;
  }

  return &hos_interfaces__srv__detail__device_command__rosidl_typesupport_introspection_c__DeviceCommand_service_type_support_handle;
}
