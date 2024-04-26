// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from hos_interfaces:srv/GetStateAPICall.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "hos_interfaces/srv/detail/get_state_api_call__rosidl_typesupport_introspection_c.h"
#include "hos_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "hos_interfaces/srv/detail/get_state_api_call__functions.h"
#include "hos_interfaces/srv/detail/get_state_api_call__struct.h"


// Include directives for member types
// Member `device_id`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void hos_interfaces__srv__GetStateAPICall_Request__rosidl_typesupport_introspection_c__GetStateAPICall_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  hos_interfaces__srv__GetStateAPICall_Request__init(message_memory);
}

void hos_interfaces__srv__GetStateAPICall_Request__rosidl_typesupport_introspection_c__GetStateAPICall_Request_fini_function(void * message_memory)
{
  hos_interfaces__srv__GetStateAPICall_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember hos_interfaces__srv__GetStateAPICall_Request__rosidl_typesupport_introspection_c__GetStateAPICall_Request_message_member_array[2] = {
  {
    "device_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hos_interfaces__srv__GetStateAPICall_Request, device_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "state_type",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hos_interfaces__srv__GetStateAPICall_Request, state_type),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers hos_interfaces__srv__GetStateAPICall_Request__rosidl_typesupport_introspection_c__GetStateAPICall_Request_message_members = {
  "hos_interfaces__srv",  // message namespace
  "GetStateAPICall_Request",  // message name
  2,  // number of fields
  sizeof(hos_interfaces__srv__GetStateAPICall_Request),
  hos_interfaces__srv__GetStateAPICall_Request__rosidl_typesupport_introspection_c__GetStateAPICall_Request_message_member_array,  // message members
  hos_interfaces__srv__GetStateAPICall_Request__rosidl_typesupport_introspection_c__GetStateAPICall_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  hos_interfaces__srv__GetStateAPICall_Request__rosidl_typesupport_introspection_c__GetStateAPICall_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t hos_interfaces__srv__GetStateAPICall_Request__rosidl_typesupport_introspection_c__GetStateAPICall_Request_message_type_support_handle = {
  0,
  &hos_interfaces__srv__GetStateAPICall_Request__rosidl_typesupport_introspection_c__GetStateAPICall_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_hos_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, hos_interfaces, srv, GetStateAPICall_Request)() {
  if (!hos_interfaces__srv__GetStateAPICall_Request__rosidl_typesupport_introspection_c__GetStateAPICall_Request_message_type_support_handle.typesupport_identifier) {
    hos_interfaces__srv__GetStateAPICall_Request__rosidl_typesupport_introspection_c__GetStateAPICall_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &hos_interfaces__srv__GetStateAPICall_Request__rosidl_typesupport_introspection_c__GetStateAPICall_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "hos_interfaces/srv/detail/get_state_api_call__rosidl_typesupport_introspection_c.h"
// already included above
// #include "hos_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "hos_interfaces/srv/detail/get_state_api_call__functions.h"
// already included above
// #include "hos_interfaces/srv/detail/get_state_api_call__struct.h"


// Include directives for member types
// Member `error`
// Member `result_jsons`
// already included above
// #include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void hos_interfaces__srv__GetStateAPICall_Response__rosidl_typesupport_introspection_c__GetStateAPICall_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  hos_interfaces__srv__GetStateAPICall_Response__init(message_memory);
}

void hos_interfaces__srv__GetStateAPICall_Response__rosidl_typesupport_introspection_c__GetStateAPICall_Response_fini_function(void * message_memory)
{
  hos_interfaces__srv__GetStateAPICall_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember hos_interfaces__srv__GetStateAPICall_Response__rosidl_typesupport_introspection_c__GetStateAPICall_Response_message_member_array[4] = {
  {
    "is_valid",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hos_interfaces__srv__GetStateAPICall_Response, is_valid),  // bytes offset in struct
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
    offsetof(hos_interfaces__srv__GetStateAPICall_Response, error),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "task_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hos_interfaces__srv__GetStateAPICall_Response, task_id),  // bytes offset in struct
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
    offsetof(hos_interfaces__srv__GetStateAPICall_Response, result_jsons),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers hos_interfaces__srv__GetStateAPICall_Response__rosidl_typesupport_introspection_c__GetStateAPICall_Response_message_members = {
  "hos_interfaces__srv",  // message namespace
  "GetStateAPICall_Response",  // message name
  4,  // number of fields
  sizeof(hos_interfaces__srv__GetStateAPICall_Response),
  hos_interfaces__srv__GetStateAPICall_Response__rosidl_typesupport_introspection_c__GetStateAPICall_Response_message_member_array,  // message members
  hos_interfaces__srv__GetStateAPICall_Response__rosidl_typesupport_introspection_c__GetStateAPICall_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  hos_interfaces__srv__GetStateAPICall_Response__rosidl_typesupport_introspection_c__GetStateAPICall_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t hos_interfaces__srv__GetStateAPICall_Response__rosidl_typesupport_introspection_c__GetStateAPICall_Response_message_type_support_handle = {
  0,
  &hos_interfaces__srv__GetStateAPICall_Response__rosidl_typesupport_introspection_c__GetStateAPICall_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_hos_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, hos_interfaces, srv, GetStateAPICall_Response)() {
  if (!hos_interfaces__srv__GetStateAPICall_Response__rosidl_typesupport_introspection_c__GetStateAPICall_Response_message_type_support_handle.typesupport_identifier) {
    hos_interfaces__srv__GetStateAPICall_Response__rosidl_typesupport_introspection_c__GetStateAPICall_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &hos_interfaces__srv__GetStateAPICall_Response__rosidl_typesupport_introspection_c__GetStateAPICall_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "hos_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "hos_interfaces/srv/detail/get_state_api_call__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers hos_interfaces__srv__detail__get_state_api_call__rosidl_typesupport_introspection_c__GetStateAPICall_service_members = {
  "hos_interfaces__srv",  // service namespace
  "GetStateAPICall",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // hos_interfaces__srv__detail__get_state_api_call__rosidl_typesupport_introspection_c__GetStateAPICall_Request_message_type_support_handle,
  NULL  // response message
  // hos_interfaces__srv__detail__get_state_api_call__rosidl_typesupport_introspection_c__GetStateAPICall_Response_message_type_support_handle
};

static rosidl_service_type_support_t hos_interfaces__srv__detail__get_state_api_call__rosidl_typesupport_introspection_c__GetStateAPICall_service_type_support_handle = {
  0,
  &hos_interfaces__srv__detail__get_state_api_call__rosidl_typesupport_introspection_c__GetStateAPICall_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, hos_interfaces, srv, GetStateAPICall_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, hos_interfaces, srv, GetStateAPICall_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_hos_interfaces
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, hos_interfaces, srv, GetStateAPICall)() {
  if (!hos_interfaces__srv__detail__get_state_api_call__rosidl_typesupport_introspection_c__GetStateAPICall_service_type_support_handle.typesupport_identifier) {
    hos_interfaces__srv__detail__get_state_api_call__rosidl_typesupport_introspection_c__GetStateAPICall_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)hos_interfaces__srv__detail__get_state_api_call__rosidl_typesupport_introspection_c__GetStateAPICall_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, hos_interfaces, srv, GetStateAPICall_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, hos_interfaces, srv, GetStateAPICall_Response)()->data;
  }

  return &hos_interfaces__srv__detail__get_state_api_call__rosidl_typesupport_introspection_c__GetStateAPICall_service_type_support_handle;
}
