// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from hos_interfaces:msg/TubeState.idl
// generated code does not contain a copyright notice

#ifndef HOS_INTERFACES__MSG__DETAIL__TUBE_STATE__BUILDER_HPP_
#define HOS_INTERFACES__MSG__DETAIL__TUBE_STATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "hos_interfaces/msg/detail/tube_state__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace hos_interfaces
{

namespace msg
{

namespace builder
{

class Init_TubeState_temperature
{
public:
  explicit Init_TubeState_temperature(::hos_interfaces::msg::TubeState & msg)
  : msg_(msg)
  {}
  ::hos_interfaces::msg::TubeState temperature(::hos_interfaces::msg::TubeState::_temperature_type arg)
  {
    msg_.temperature = std::move(arg);
    return std::move(msg_);
  }

private:
  ::hos_interfaces::msg::TubeState msg_;
};

class Init_TubeState_volume
{
public:
  explicit Init_TubeState_volume(::hos_interfaces::msg::TubeState & msg)
  : msg_(msg)
  {}
  Init_TubeState_temperature volume(::hos_interfaces::msg::TubeState::_volume_type arg)
  {
    msg_.volume = std::move(arg);
    return Init_TubeState_temperature(msg_);
  }

private:
  ::hos_interfaces::msg::TubeState msg_;
};

class Init_TubeState_tube_type
{
public:
  explicit Init_TubeState_tube_type(::hos_interfaces::msg::TubeState & msg)
  : msg_(msg)
  {}
  Init_TubeState_volume tube_type(::hos_interfaces::msg::TubeState::_tube_type_type arg)
  {
    msg_.tube_type = std::move(arg);
    return Init_TubeState_volume(msg_);
  }

private:
  ::hos_interfaces::msg::TubeState msg_;
};

class Init_TubeState_tube_id
{
public:
  explicit Init_TubeState_tube_id(::hos_interfaces::msg::TubeState & msg)
  : msg_(msg)
  {}
  Init_TubeState_tube_type tube_id(::hos_interfaces::msg::TubeState::_tube_id_type arg)
  {
    msg_.tube_id = std::move(arg);
    return Init_TubeState_tube_type(msg_);
  }

private:
  ::hos_interfaces::msg::TubeState msg_;
};

class Init_TubeState_liquid_level
{
public:
  Init_TubeState_liquid_level()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_TubeState_tube_id liquid_level(::hos_interfaces::msg::TubeState::_liquid_level_type arg)
  {
    msg_.liquid_level = std::move(arg);
    return Init_TubeState_tube_id(msg_);
  }

private:
  ::hos_interfaces::msg::TubeState msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::hos_interfaces::msg::TubeState>()
{
  return hos_interfaces::msg::builder::Init_TubeState_liquid_level();
}

}  // namespace hos_interfaces

#endif  // HOS_INTERFACES__MSG__DETAIL__TUBE_STATE__BUILDER_HPP_
