// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from hos_interfaces:msg/BaseHAIVEState.idl
// generated code does not contain a copyright notice

#ifndef HOS_INTERFACES__MSG__DETAIL__BASE_HAIVE_STATE__BUILDER_HPP_
#define HOS_INTERFACES__MSG__DETAIL__BASE_HAIVE_STATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "hos_interfaces/msg/detail/base_haive_state__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace hos_interfaces
{

namespace msg
{

namespace builder
{

class Init_BaseHAIVEState_device_id
{
public:
  explicit Init_BaseHAIVEState_device_id(::hos_interfaces::msg::BaseHAIVEState & msg)
  : msg_(msg)
  {}
  ::hos_interfaces::msg::BaseHAIVEState device_id(::hos_interfaces::msg::BaseHAIVEState::_device_id_type arg)
  {
    msg_.device_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::hos_interfaces::msg::BaseHAIVEState msg_;
};

class Init_BaseHAIVEState_device_type
{
public:
  explicit Init_BaseHAIVEState_device_type(::hos_interfaces::msg::BaseHAIVEState & msg)
  : msg_(msg)
  {}
  Init_BaseHAIVEState_device_id device_type(::hos_interfaces::msg::BaseHAIVEState::_device_type_type arg)
  {
    msg_.device_type = std::move(arg);
    return Init_BaseHAIVEState_device_id(msg_);
  }

private:
  ::hos_interfaces::msg::BaseHAIVEState msg_;
};

class Init_BaseHAIVEState_is_reconnected
{
public:
  explicit Init_BaseHAIVEState_is_reconnected(::hos_interfaces::msg::BaseHAIVEState & msg)
  : msg_(msg)
  {}
  Init_BaseHAIVEState_device_type is_reconnected(::hos_interfaces::msg::BaseHAIVEState::_is_reconnected_type arg)
  {
    msg_.is_reconnected = std::move(arg);
    return Init_BaseHAIVEState_device_type(msg_);
  }

private:
  ::hos_interfaces::msg::BaseHAIVEState msg_;
};

class Init_BaseHAIVEState_device_uid
{
public:
  explicit Init_BaseHAIVEState_device_uid(::hos_interfaces::msg::BaseHAIVEState & msg)
  : msg_(msg)
  {}
  Init_BaseHAIVEState_is_reconnected device_uid(::hos_interfaces::msg::BaseHAIVEState::_device_uid_type arg)
  {
    msg_.device_uid = std::move(arg);
    return Init_BaseHAIVEState_is_reconnected(msg_);
  }

private:
  ::hos_interfaces::msg::BaseHAIVEState msg_;
};

class Init_BaseHAIVEState_last_ping
{
public:
  explicit Init_BaseHAIVEState_last_ping(::hos_interfaces::msg::BaseHAIVEState & msg)
  : msg_(msg)
  {}
  Init_BaseHAIVEState_device_uid last_ping(::hos_interfaces::msg::BaseHAIVEState::_last_ping_type arg)
  {
    msg_.last_ping = std::move(arg);
    return Init_BaseHAIVEState_device_uid(msg_);
  }

private:
  ::hos_interfaces::msg::BaseHAIVEState msg_;
};

class Init_BaseHAIVEState_is_connected
{
public:
  explicit Init_BaseHAIVEState_is_connected(::hos_interfaces::msg::BaseHAIVEState & msg)
  : msg_(msg)
  {}
  Init_BaseHAIVEState_last_ping is_connected(::hos_interfaces::msg::BaseHAIVEState::_is_connected_type arg)
  {
    msg_.is_connected = std::move(arg);
    return Init_BaseHAIVEState_last_ping(msg_);
  }

private:
  ::hos_interfaces::msg::BaseHAIVEState msg_;
};

class Init_BaseHAIVEState_turntable_slot
{
public:
  explicit Init_BaseHAIVEState_turntable_slot(::hos_interfaces::msg::BaseHAIVEState & msg)
  : msg_(msg)
  {}
  Init_BaseHAIVEState_is_connected turntable_slot(::hos_interfaces::msg::BaseHAIVEState::_turntable_slot_type arg)
  {
    msg_.turntable_slot = std::move(arg);
    return Init_BaseHAIVEState_is_connected(msg_);
  }

private:
  ::hos_interfaces::msg::BaseHAIVEState msg_;
};

class Init_BaseHAIVEState_y_position
{
public:
  explicit Init_BaseHAIVEState_y_position(::hos_interfaces::msg::BaseHAIVEState & msg)
  : msg_(msg)
  {}
  Init_BaseHAIVEState_turntable_slot y_position(::hos_interfaces::msg::BaseHAIVEState::_y_position_type arg)
  {
    msg_.y_position = std::move(arg);
    return Init_BaseHAIVEState_turntable_slot(msg_);
  }

private:
  ::hos_interfaces::msg::BaseHAIVEState msg_;
};

class Init_BaseHAIVEState_x_position
{
public:
  Init_BaseHAIVEState_x_position()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_BaseHAIVEState_y_position x_position(::hos_interfaces::msg::BaseHAIVEState::_x_position_type arg)
  {
    msg_.x_position = std::move(arg);
    return Init_BaseHAIVEState_y_position(msg_);
  }

private:
  ::hos_interfaces::msg::BaseHAIVEState msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::hos_interfaces::msg::BaseHAIVEState>()
{
  return hos_interfaces::msg::builder::Init_BaseHAIVEState_x_position();
}

}  // namespace hos_interfaces

#endif  // HOS_INTERFACES__MSG__DETAIL__BASE_HAIVE_STATE__BUILDER_HPP_
