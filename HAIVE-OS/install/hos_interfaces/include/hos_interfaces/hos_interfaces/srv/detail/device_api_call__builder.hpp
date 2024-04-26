// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from hos_interfaces:srv/DeviceAPICall.idl
// generated code does not contain a copyright notice

#ifndef HOS_INTERFACES__SRV__DETAIL__DEVICE_API_CALL__BUILDER_HPP_
#define HOS_INTERFACES__SRV__DETAIL__DEVICE_API_CALL__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "hos_interfaces/srv/detail/device_api_call__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace hos_interfaces
{

namespace srv
{

namespace builder
{

class Init_DeviceAPICall_Request_args
{
public:
  explicit Init_DeviceAPICall_Request_args(::hos_interfaces::srv::DeviceAPICall_Request & msg)
  : msg_(msg)
  {}
  ::hos_interfaces::srv::DeviceAPICall_Request args(::hos_interfaces::srv::DeviceAPICall_Request::_args_type arg)
  {
    msg_.args = std::move(arg);
    return std::move(msg_);
  }

private:
  ::hos_interfaces::srv::DeviceAPICall_Request msg_;
};

class Init_DeviceAPICall_Request_function_name
{
public:
  explicit Init_DeviceAPICall_Request_function_name(::hos_interfaces::srv::DeviceAPICall_Request & msg)
  : msg_(msg)
  {}
  Init_DeviceAPICall_Request_args function_name(::hos_interfaces::srv::DeviceAPICall_Request::_function_name_type arg)
  {
    msg_.function_name = std::move(arg);
    return Init_DeviceAPICall_Request_args(msg_);
  }

private:
  ::hos_interfaces::srv::DeviceAPICall_Request msg_;
};

class Init_DeviceAPICall_Request_device_id
{
public:
  Init_DeviceAPICall_Request_device_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_DeviceAPICall_Request_function_name device_id(::hos_interfaces::srv::DeviceAPICall_Request::_device_id_type arg)
  {
    msg_.device_id = std::move(arg);
    return Init_DeviceAPICall_Request_function_name(msg_);
  }

private:
  ::hos_interfaces::srv::DeviceAPICall_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::hos_interfaces::srv::DeviceAPICall_Request>()
{
  return hos_interfaces::srv::builder::Init_DeviceAPICall_Request_device_id();
}

}  // namespace hos_interfaces


namespace hos_interfaces
{

namespace srv
{

namespace builder
{

class Init_DeviceAPICall_Response_task_id
{
public:
  explicit Init_DeviceAPICall_Response_task_id(::hos_interfaces::srv::DeviceAPICall_Response & msg)
  : msg_(msg)
  {}
  ::hos_interfaces::srv::DeviceAPICall_Response task_id(::hos_interfaces::srv::DeviceAPICall_Response::_task_id_type arg)
  {
    msg_.task_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::hos_interfaces::srv::DeviceAPICall_Response msg_;
};

class Init_DeviceAPICall_Response_error
{
public:
  explicit Init_DeviceAPICall_Response_error(::hos_interfaces::srv::DeviceAPICall_Response & msg)
  : msg_(msg)
  {}
  Init_DeviceAPICall_Response_task_id error(::hos_interfaces::srv::DeviceAPICall_Response::_error_type arg)
  {
    msg_.error = std::move(arg);
    return Init_DeviceAPICall_Response_task_id(msg_);
  }

private:
  ::hos_interfaces::srv::DeviceAPICall_Response msg_;
};

class Init_DeviceAPICall_Response_is_valid
{
public:
  Init_DeviceAPICall_Response_is_valid()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_DeviceAPICall_Response_error is_valid(::hos_interfaces::srv::DeviceAPICall_Response::_is_valid_type arg)
  {
    msg_.is_valid = std::move(arg);
    return Init_DeviceAPICall_Response_error(msg_);
  }

private:
  ::hos_interfaces::srv::DeviceAPICall_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::hos_interfaces::srv::DeviceAPICall_Response>()
{
  return hos_interfaces::srv::builder::Init_DeviceAPICall_Response_is_valid();
}

}  // namespace hos_interfaces

#endif  // HOS_INTERFACES__SRV__DETAIL__DEVICE_API_CALL__BUILDER_HPP_
