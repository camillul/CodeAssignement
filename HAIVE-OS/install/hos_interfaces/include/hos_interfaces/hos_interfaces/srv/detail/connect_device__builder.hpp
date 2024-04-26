// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from hos_interfaces:srv/ConnectDevice.idl
// generated code does not contain a copyright notice

#ifndef HOS_INTERFACES__SRV__DETAIL__CONNECT_DEVICE__BUILDER_HPP_
#define HOS_INTERFACES__SRV__DETAIL__CONNECT_DEVICE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "hos_interfaces/srv/detail/connect_device__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace hos_interfaces
{

namespace srv
{

namespace builder
{

class Init_ConnectDevice_Request_uid
{
public:
  Init_ConnectDevice_Request_uid()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::hos_interfaces::srv::ConnectDevice_Request uid(::hos_interfaces::srv::ConnectDevice_Request::_uid_type arg)
  {
    msg_.uid = std::move(arg);
    return std::move(msg_);
  }

private:
  ::hos_interfaces::srv::ConnectDevice_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::hos_interfaces::srv::ConnectDevice_Request>()
{
  return hos_interfaces::srv::builder::Init_ConnectDevice_Request_uid();
}

}  // namespace hos_interfaces


namespace hos_interfaces
{

namespace srv
{

namespace builder
{

class Init_ConnectDevice_Response_error
{
public:
  explicit Init_ConnectDevice_Response_error(::hos_interfaces::srv::ConnectDevice_Response & msg)
  : msg_(msg)
  {}
  ::hos_interfaces::srv::ConnectDevice_Response error(::hos_interfaces::srv::ConnectDevice_Response::_error_type arg)
  {
    msg_.error = std::move(arg);
    return std::move(msg_);
  }

private:
  ::hos_interfaces::srv::ConnectDevice_Response msg_;
};

class Init_ConnectDevice_Response_success
{
public:
  Init_ConnectDevice_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ConnectDevice_Response_error success(::hos_interfaces::srv::ConnectDevice_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_ConnectDevice_Response_error(msg_);
  }

private:
  ::hos_interfaces::srv::ConnectDevice_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::hos_interfaces::srv::ConnectDevice_Response>()
{
  return hos_interfaces::srv::builder::Init_ConnectDevice_Response_success();
}

}  // namespace hos_interfaces

#endif  // HOS_INTERFACES__SRV__DETAIL__CONNECT_DEVICE__BUILDER_HPP_
