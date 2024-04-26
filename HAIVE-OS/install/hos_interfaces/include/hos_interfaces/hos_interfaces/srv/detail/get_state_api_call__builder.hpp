// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from hos_interfaces:srv/GetStateAPICall.idl
// generated code does not contain a copyright notice

#ifndef HOS_INTERFACES__SRV__DETAIL__GET_STATE_API_CALL__BUILDER_HPP_
#define HOS_INTERFACES__SRV__DETAIL__GET_STATE_API_CALL__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "hos_interfaces/srv/detail/get_state_api_call__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace hos_interfaces
{

namespace srv
{

namespace builder
{

class Init_GetStateAPICall_Request_state_type
{
public:
  explicit Init_GetStateAPICall_Request_state_type(::hos_interfaces::srv::GetStateAPICall_Request & msg)
  : msg_(msg)
  {}
  ::hos_interfaces::srv::GetStateAPICall_Request state_type(::hos_interfaces::srv::GetStateAPICall_Request::_state_type_type arg)
  {
    msg_.state_type = std::move(arg);
    return std::move(msg_);
  }

private:
  ::hos_interfaces::srv::GetStateAPICall_Request msg_;
};

class Init_GetStateAPICall_Request_device_id
{
public:
  Init_GetStateAPICall_Request_device_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GetStateAPICall_Request_state_type device_id(::hos_interfaces::srv::GetStateAPICall_Request::_device_id_type arg)
  {
    msg_.device_id = std::move(arg);
    return Init_GetStateAPICall_Request_state_type(msg_);
  }

private:
  ::hos_interfaces::srv::GetStateAPICall_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::hos_interfaces::srv::GetStateAPICall_Request>()
{
  return hos_interfaces::srv::builder::Init_GetStateAPICall_Request_device_id();
}

}  // namespace hos_interfaces


namespace hos_interfaces
{

namespace srv
{

namespace builder
{

class Init_GetStateAPICall_Response_result_jsons
{
public:
  explicit Init_GetStateAPICall_Response_result_jsons(::hos_interfaces::srv::GetStateAPICall_Response & msg)
  : msg_(msg)
  {}
  ::hos_interfaces::srv::GetStateAPICall_Response result_jsons(::hos_interfaces::srv::GetStateAPICall_Response::_result_jsons_type arg)
  {
    msg_.result_jsons = std::move(arg);
    return std::move(msg_);
  }

private:
  ::hos_interfaces::srv::GetStateAPICall_Response msg_;
};

class Init_GetStateAPICall_Response_task_id
{
public:
  explicit Init_GetStateAPICall_Response_task_id(::hos_interfaces::srv::GetStateAPICall_Response & msg)
  : msg_(msg)
  {}
  Init_GetStateAPICall_Response_result_jsons task_id(::hos_interfaces::srv::GetStateAPICall_Response::_task_id_type arg)
  {
    msg_.task_id = std::move(arg);
    return Init_GetStateAPICall_Response_result_jsons(msg_);
  }

private:
  ::hos_interfaces::srv::GetStateAPICall_Response msg_;
};

class Init_GetStateAPICall_Response_error
{
public:
  explicit Init_GetStateAPICall_Response_error(::hos_interfaces::srv::GetStateAPICall_Response & msg)
  : msg_(msg)
  {}
  Init_GetStateAPICall_Response_task_id error(::hos_interfaces::srv::GetStateAPICall_Response::_error_type arg)
  {
    msg_.error = std::move(arg);
    return Init_GetStateAPICall_Response_task_id(msg_);
  }

private:
  ::hos_interfaces::srv::GetStateAPICall_Response msg_;
};

class Init_GetStateAPICall_Response_is_valid
{
public:
  Init_GetStateAPICall_Response_is_valid()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GetStateAPICall_Response_error is_valid(::hos_interfaces::srv::GetStateAPICall_Response::_is_valid_type arg)
  {
    msg_.is_valid = std::move(arg);
    return Init_GetStateAPICall_Response_error(msg_);
  }

private:
  ::hos_interfaces::srv::GetStateAPICall_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::hos_interfaces::srv::GetStateAPICall_Response>()
{
  return hos_interfaces::srv::builder::Init_GetStateAPICall_Response_is_valid();
}

}  // namespace hos_interfaces

#endif  // HOS_INTERFACES__SRV__DETAIL__GET_STATE_API_CALL__BUILDER_HPP_
