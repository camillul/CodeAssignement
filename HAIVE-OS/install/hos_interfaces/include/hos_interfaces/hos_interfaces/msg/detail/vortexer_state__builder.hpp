// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from hos_interfaces:msg/VortexerState.idl
// generated code does not contain a copyright notice

#ifndef HOS_INTERFACES__MSG__DETAIL__VORTEXER_STATE__BUILDER_HPP_
#define HOS_INTERFACES__MSG__DETAIL__VORTEXER_STATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "hos_interfaces/msg/detail/vortexer_state__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace hos_interfaces
{

namespace msg
{

namespace builder
{

class Init_VortexerState_device_id
{
public:
  explicit Init_VortexerState_device_id(::hos_interfaces::msg::VortexerState & msg)
  : msg_(msg)
  {}
  ::hos_interfaces::msg::VortexerState device_id(::hos_interfaces::msg::VortexerState::_device_id_type arg)
  {
    msg_.device_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::hos_interfaces::msg::VortexerState msg_;
};

class Init_VortexerState_device_type
{
public:
  explicit Init_VortexerState_device_type(::hos_interfaces::msg::VortexerState & msg)
  : msg_(msg)
  {}
  Init_VortexerState_device_id device_type(::hos_interfaces::msg::VortexerState::_device_type_type arg)
  {
    msg_.device_type = std::move(arg);
    return Init_VortexerState_device_id(msg_);
  }

private:
  ::hos_interfaces::msg::VortexerState msg_;
};

class Init_VortexerState_is_reconnected
{
public:
  explicit Init_VortexerState_is_reconnected(::hos_interfaces::msg::VortexerState & msg)
  : msg_(msg)
  {}
  Init_VortexerState_device_type is_reconnected(::hos_interfaces::msg::VortexerState::_is_reconnected_type arg)
  {
    msg_.is_reconnected = std::move(arg);
    return Init_VortexerState_device_type(msg_);
  }

private:
  ::hos_interfaces::msg::VortexerState msg_;
};

class Init_VortexerState_device_uid
{
public:
  explicit Init_VortexerState_device_uid(::hos_interfaces::msg::VortexerState & msg)
  : msg_(msg)
  {}
  Init_VortexerState_is_reconnected device_uid(::hos_interfaces::msg::VortexerState::_device_uid_type arg)
  {
    msg_.device_uid = std::move(arg);
    return Init_VortexerState_is_reconnected(msg_);
  }

private:
  ::hos_interfaces::msg::VortexerState msg_;
};

class Init_VortexerState_last_ping
{
public:
  explicit Init_VortexerState_last_ping(::hos_interfaces::msg::VortexerState & msg)
  : msg_(msg)
  {}
  Init_VortexerState_device_uid last_ping(::hos_interfaces::msg::VortexerState::_last_ping_type arg)
  {
    msg_.last_ping = std::move(arg);
    return Init_VortexerState_device_uid(msg_);
  }

private:
  ::hos_interfaces::msg::VortexerState msg_;
};

class Init_VortexerState_is_connected
{
public:
  explicit Init_VortexerState_is_connected(::hos_interfaces::msg::VortexerState & msg)
  : msg_(msg)
  {}
  Init_VortexerState_last_ping is_connected(::hos_interfaces::msg::VortexerState::_is_connected_type arg)
  {
    msg_.is_connected = std::move(arg);
    return Init_VortexerState_last_ping(msg_);
  }

private:
  ::hos_interfaces::msg::VortexerState msg_;
};

class Init_VortexerState_rotation_speed
{
public:
  Init_VortexerState_rotation_speed()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_VortexerState_is_connected rotation_speed(::hos_interfaces::msg::VortexerState::_rotation_speed_type arg)
  {
    msg_.rotation_speed = std::move(arg);
    return Init_VortexerState_is_connected(msg_);
  }

private:
  ::hos_interfaces::msg::VortexerState msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::hos_interfaces::msg::VortexerState>()
{
  return hos_interfaces::msg::builder::Init_VortexerState_rotation_speed();
}

}  // namespace hos_interfaces

#endif  // HOS_INTERFACES__MSG__DETAIL__VORTEXER_STATE__BUILDER_HPP_
