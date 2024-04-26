// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from hos_interfaces:srv/BehaviorRequestMoveContainer.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "hos_interfaces/srv/detail/behavior_request_move_container__rosidl_typesupport_introspection_c.h"
#include "hos_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "hos_interfaces/srv/detail/behavior_request_move_container__functions.h"
#include "hos_interfaces/srv/detail/behavior_request_move_container__struct.h"


// Include directives for member types
// Member `container_id`
// Member `haive_id`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void hos_interfaces__srv__BehaviorRequestMoveContainer_Request__rosidl_typesupport_introspection_c__BehaviorRequestMoveContainer_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  hos_interfaces__srv__BehaviorRequestMoveContainer_Request__init(message_memory);
}

void hos_interfaces__srv__BehaviorRequestMoveContainer_Request__rosidl_typesupport_introspection_c__BehaviorRequestMoveContainer_Request_fini_function(void * message_memory)
{
  hos_interfaces__srv__BehaviorRequestMoveContainer_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember hos_interfaces__srv__BehaviorRequestMoveContainer_Request__rosidl_typesupport_introspection_c__BehaviorRequestMoveContainer_Request_message_member_array[3] = {
  {
    "container_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hos_interfaces__srv__BehaviorRequestMoveContainer_Request, container_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "haive_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hos_interfaces__srv__BehaviorRequestMoveContainer_Request, haive_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "slot",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hos_interfaces__srv__BehaviorRequestMoveContainer_Request, slot),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers hos_interfaces__srv__BehaviorRequestMoveContainer_Request__rosidl_typesupport_introspection_c__BehaviorRequestMoveContainer_Request_message_members = {
  "hos_interfaces__srv",  // message namespace
  "BehaviorRequestMoveContainer_Request",  // message name
  3,  // number of fields
  sizeof(hos_interfaces__srv__BehaviorRequestMoveContainer_Request),
  hos_interfaces__srv__BehaviorRequestMoveContainer_Request__rosidl_typesupport_introspection_c__BehaviorRequestMoveContainer_Request_message_member_array,  // message members
  hos_interfaces__srv__BehaviorRequestMoveContainer_Request__rosidl_typesupport_introspection_c__BehaviorRequestMoveContainer_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  hos_interfaces__srv__BehaviorRequestMoveContainer_Request__rosidl_typesupport_introspection_c__BehaviorRequestMoveContainer_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t hos_interfaces__srv__BehaviorRequestMoveContainer_Request__rosidl_typesupport_introspection_c__BehaviorRequestMoveContainer_Request_message_type_support_handle = {
  0,
  &hos_interfaces__srv__BehaviorRequestMoveContainer_Request__rosidl_typesupport_introspection_c__BehaviorRequestMoveContainer_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_hos_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, hos_interfaces, srv, BehaviorRequestMoveContainer_Request)() {
  if (!hos_interfaces__srv__BehaviorRequestMoveContainer_Request__rosidl_typesupport_introspection_c__BehaviorRequestMoveContainer_Request_message_type_support_handle.typesupport_identifier) {
    hos_interfaces__srv__BehaviorRequestMoveContainer_Request__rosidl_typesupport_introspection_c__BehaviorRequestMoveContainer_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &hos_interfaces__srv__BehaviorRequestMoveContainer_Request__rosidl_typesupport_introspection_c__BehaviorRequestMoveContainer_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "hos_interfaces/srv/detail/behavior_request_move_container__rosidl_typesupport_introspection_c.h"
// already included above
// #include "hos_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "hos_interfaces/srv/detail/behavior_request_move_container__functions.h"
// already included above
// #include "hos_interfaces/srv/detail/behavior_request_move_container__struct.h"


// Include directives for member types
// Member `error`
// already included above
// #include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void hos_interfaces__srv__BehaviorRequestMoveContainer_Response__rosidl_typesupport_introspection_c__BehaviorRequestMoveContainer_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  hos_interfaces__srv__BehaviorRequestMoveContainer_Response__init(message_memory);
}

void hos_interfaces__srv__BehaviorRequestMoveContainer_Response__rosidl_typesupport_introspection_c__BehaviorRequestMoveContainer_Response_fini_function(void * message_memory)
{
  hos_interfaces__srv__BehaviorRequestMoveContainer_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember hos_interfaces__srv__BehaviorRequestMoveContainer_Response__rosidl_typesupport_introspection_c__BehaviorRequestMoveContainer_Response_message_member_array[2] = {
  {
    "success",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hos_interfaces__srv__BehaviorRequestMoveContainer_Response, success),  // bytes offset in struct
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
    offsetof(hos_interfaces__srv__BehaviorRequestMoveContainer_Response, error),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers hos_interfaces__srv__BehaviorRequestMoveContainer_Response__rosidl_typesupport_introspection_c__BehaviorRequestMoveContainer_Response_message_members = {
  "hos_interfaces__srv",  // message namespace
  "BehaviorRequestMoveContainer_Response",  // message name
  2,  // number of fields
  sizeof(hos_interfaces__srv__BehaviorRequestMoveContainer_Response),
  hos_interfaces__srv__BehaviorRequestMoveContainer_Response__rosidl_typesupport_introspection_c__BehaviorRequestMoveContainer_Response_message_member_array,  // message members
  hos_interfaces__srv__BehaviorRequestMoveContainer_Response__rosidl_typesupport_introspection_c__BehaviorRequestMoveContainer_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  hos_interfaces__srv__BehaviorRequestMoveContainer_Response__rosidl_typesupport_introspection_c__BehaviorRequestMoveContainer_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t hos_interfaces__srv__BehaviorRequestMoveContainer_Response__rosidl_typesupport_introspection_c__BehaviorRequestMoveContainer_Response_message_type_support_handle = {
  0,
  &hos_interfaces__srv__BehaviorRequestMoveContainer_Response__rosidl_typesupport_introspection_c__BehaviorRequestMoveContainer_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_hos_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, hos_interfaces, srv, BehaviorRequestMoveContainer_Response)() {
  if (!hos_interfaces__srv__BehaviorRequestMoveContainer_Response__rosidl_typesupport_introspection_c__BehaviorRequestMoveContainer_Response_message_type_support_handle.typesupport_identifier) {
    hos_interfaces__srv__BehaviorRequestMoveContainer_Response__rosidl_typesupport_introspection_c__BehaviorRequestMoveContainer_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &hos_interfaces__srv__BehaviorRequestMoveContainer_Response__rosidl_typesupport_introspection_c__BehaviorRequestMoveContainer_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "hos_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "hos_interfaces/srv/detail/behavior_request_move_container__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers hos_interfaces__srv__detail__behavior_request_move_container__rosidl_typesupport_introspection_c__BehaviorRequestMoveContainer_service_members = {
  "hos_interfaces__srv",  // service namespace
  "BehaviorRequestMoveContainer",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // hos_interfaces__srv__detail__behavior_request_move_container__rosidl_typesupport_introspection_c__BehaviorRequestMoveContainer_Request_message_type_support_handle,
  NULL  // response message
  // hos_interfaces__srv__detail__behavior_request_move_container__rosidl_typesupport_introspection_c__BehaviorRequestMoveContainer_Response_message_type_support_handle
};

static rosidl_service_type_support_t hos_interfaces__srv__detail__behavior_request_move_container__rosidl_typesupport_introspection_c__BehaviorRequestMoveContainer_service_type_support_handle = {
  0,
  &hos_interfaces__srv__detail__behavior_request_move_container__rosidl_typesupport_introspection_c__BehaviorRequestMoveContainer_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, hos_interfaces, srv, BehaviorRequestMoveContainer_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, hos_interfaces, srv, BehaviorRequestMoveContainer_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_hos_interfaces
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, hos_interfaces, srv, BehaviorRequestMoveContainer)() {
  if (!hos_interfaces__srv__detail__behavior_request_move_container__rosidl_typesupport_introspection_c__BehaviorRequestMoveContainer_service_type_support_handle.typesupport_identifier) {
    hos_interfaces__srv__detail__behavior_request_move_container__rosidl_typesupport_introspection_c__BehaviorRequestMoveContainer_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)hos_interfaces__srv__detail__behavior_request_move_container__rosidl_typesupport_introspection_c__BehaviorRequestMoveContainer_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, hos_interfaces, srv, BehaviorRequestMoveContainer_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, hos_interfaces, srv, BehaviorRequestMoveContainer_Response)()->data;
  }

  return &hos_interfaces__srv__detail__behavior_request_move_container__rosidl_typesupport_introspection_c__BehaviorRequestMoveContainer_service_type_support_handle;
}
