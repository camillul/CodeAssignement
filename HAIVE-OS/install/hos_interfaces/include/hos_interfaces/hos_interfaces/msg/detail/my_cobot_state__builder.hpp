// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from hos_interfaces:msg/MyCobotState.idl
// generated code does not contain a copyright notice

#ifndef HOS_INTERFACES__MSG__DETAIL__MY_COBOT_STATE__BUILDER_HPP_
#define HOS_INTERFACES__MSG__DETAIL__MY_COBOT_STATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "hos_interfaces/msg/detail/my_cobot_state__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace hos_interfaces
{

namespace msg
{

namespace builder
{

class Init_MyCobotState_device_id
{
public:
  explicit Init_MyCobotState_device_id(::hos_interfaces::msg::MyCobotState & msg)
  : msg_(msg)
  {}
  ::hos_interfaces::msg::MyCobotState device_id(::hos_interfaces::msg::MyCobotState::_device_id_type arg)
  {
    msg_.device_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::hos_interfaces::msg::MyCobotState msg_;
};

class Init_MyCobotState_device_type
{
public:
  explicit Init_MyCobotState_device_type(::hos_interfaces::msg::MyCobotState & msg)
  : msg_(msg)
  {}
  Init_MyCobotState_device_id device_type(::hos_interfaces::msg::MyCobotState::_device_type_type arg)
  {
    msg_.device_type = std::move(arg);
    return Init_MyCobotState_device_id(msg_);
  }

private:
  ::hos_interfaces::msg::MyCobotState msg_;
};

class Init_MyCobotState_is_reconnected
{
public:
  explicit Init_MyCobotState_is_reconnected(::hos_interfaces::msg::MyCobotState & msg)
  : msg_(msg)
  {}
  Init_MyCobotState_device_type is_reconnected(::hos_interfaces::msg::MyCobotState::_is_reconnected_type arg)
  {
    msg_.is_reconnected = std::move(arg);
    return Init_MyCobotState_device_type(msg_);
  }

private:
  ::hos_interfaces::msg::MyCobotState msg_;
};

class Init_MyCobotState_device_uid
{
public:
  explicit Init_MyCobotState_device_uid(::hos_interfaces::msg::MyCobotState & msg)
  : msg_(msg)
  {}
  Init_MyCobotState_is_reconnected device_uid(::hos_interfaces::msg::MyCobotState::_device_uid_type arg)
  {
    msg_.device_uid = std::move(arg);
    return Init_MyCobotState_is_reconnected(msg_);
  }

private:
  ::hos_interfaces::msg::MyCobotState msg_;
};

class Init_MyCobotState_last_ping
{
public:
  explicit Init_MyCobotState_last_ping(::hos_interfaces::msg::MyCobotState & msg)
  : msg_(msg)
  {}
  Init_MyCobotState_device_uid last_ping(::hos_interfaces::msg::MyCobotState::_last_ping_type arg)
  {
    msg_.last_ping = std::move(arg);
    return Init_MyCobotState_device_uid(msg_);
  }

private:
  ::hos_interfaces::msg::MyCobotState msg_;
};

class Init_MyCobotState_is_connected
{
public:
  Init_MyCobotState_is_connected()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MyCobotState_last_ping is_connected(::hos_interfaces::msg::MyCobotState::_is_connected_type arg)
  {
    msg_.is_connected = std::move(arg);
    return Init_MyCobotState_last_ping(msg_);
  }

private:
  ::hos_interfaces::msg::MyCobotState msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::hos_interfaces::msg::MyCobotState>()
{
  return hos_interfaces::msg::builder::Init_MyCobotState_is_connected();
}

}  // namespace hos_interfaces

#endif  // HOS_INTERFACES__MSG__DETAIL__MY_COBOT_STATE__BUILDER_HPP_
