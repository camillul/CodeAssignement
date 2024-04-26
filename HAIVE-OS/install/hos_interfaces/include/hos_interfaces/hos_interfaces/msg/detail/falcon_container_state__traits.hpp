// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from hos_interfaces:msg/FalconContainerState.idl
// generated code does not contain a copyright notice

#ifndef HOS_INTERFACES__MSG__DETAIL__FALCON_CONTAINER_STATE__TRAITS_HPP_
#define HOS_INTERFACES__MSG__DETAIL__FALCON_CONTAINER_STATE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "hos_interfaces/msg/detail/falcon_container_state__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace hos_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const FalconContainerState & msg,
  std::ostream & out)
{
  out << "{";
  // member: is_flipped
  {
    out << "is_flipped: ";
    rosidl_generator_traits::value_to_yaml(msg.is_flipped, out);
    out << ", ";
  }

  // member: slot_position
  {
    out << "slot_position: ";
    rosidl_generator_traits::value_to_yaml(msg.slot_position, out);
    out << ", ";
  }

  // member: external_resources
  {
    out << "external_resources: ";
    rosidl_generator_traits::value_to_yaml(msg.external_resources, out);
    out << ", ";
  }

  // member: temperature
  {
    out << "temperature: ";
    rosidl_generator_traits::value_to_yaml(msg.temperature, out);
    out << ", ";
  }

  // member: is_movable
  {
    out << "is_movable: ";
    rosidl_generator_traits::value_to_yaml(msg.is_movable, out);
    out << ", ";
  }

  // member: is_connected
  {
    out << "is_connected: ";
    rosidl_generator_traits::value_to_yaml(msg.is_connected, out);
    out << ", ";
  }

  // member: last_ping
  {
    out << "last_ping: ";
    rosidl_generator_traits::value_to_yaml(msg.last_ping, out);
    out << ", ";
  }

  // member: device_uid
  {
    out << "device_uid: ";
    rosidl_generator_traits::value_to_yaml(msg.device_uid, out);
    out << ", ";
  }

  // member: is_reconnected
  {
    out << "is_reconnected: ";
    rosidl_generator_traits::value_to_yaml(msg.is_reconnected, out);
    out << ", ";
  }

  // member: device_type
  {
    out << "device_type: ";
    rosidl_generator_traits::value_to_yaml(msg.device_type, out);
    out << ", ";
  }

  // member: device_id
  {
    out << "device_id: ";
    rosidl_generator_traits::value_to_yaml(msg.device_id, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const FalconContainerState & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: is_flipped
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "is_flipped: ";
    rosidl_generator_traits::value_to_yaml(msg.is_flipped, out);
    out << "\n";
  }

  // member: slot_position
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "slot_position: ";
    rosidl_generator_traits::value_to_yaml(msg.slot_position, out);
    out << "\n";
  }

  // member: external_resources
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "external_resources: ";
    rosidl_generator_traits::value_to_yaml(msg.external_resources, out);
    out << "\n";
  }

  // member: temperature
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "temperature: ";
    rosidl_generator_traits::value_to_yaml(msg.temperature, out);
    out << "\n";
  }

  // member: is_movable
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "is_movable: ";
    rosidl_generator_traits::value_to_yaml(msg.is_movable, out);
    out << "\n";
  }

  // member: is_connected
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "is_connected: ";
    rosidl_generator_traits::value_to_yaml(msg.is_connected, out);
    out << "\n";
  }

  // member: last_ping
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "last_ping: ";
    rosidl_generator_traits::value_to_yaml(msg.last_ping, out);
    out << "\n";
  }

  // member: device_uid
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "device_uid: ";
    rosidl_generator_traits::value_to_yaml(msg.device_uid, out);
    out << "\n";
  }

  // member: is_reconnected
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "is_reconnected: ";
    rosidl_generator_traits::value_to_yaml(msg.is_reconnected, out);
    out << "\n";
  }

  // member: device_type
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "device_type: ";
    rosidl_generator_traits::value_to_yaml(msg.device_type, out);
    out << "\n";
  }

  // member: device_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "device_id: ";
    rosidl_generator_traits::value_to_yaml(msg.device_id, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const FalconContainerState & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace hos_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use hos_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const hos_interfaces::msg::FalconContainerState & msg,
  std::ostream & out, size_t indentation = 0)
{
  hos_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use hos_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const hos_interfaces::msg::FalconContainerState & msg)
{
  return hos_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<hos_interfaces::msg::FalconContainerState>()
{
  return "hos_interfaces::msg::FalconContainerState";
}

template<>
inline const char * name<hos_interfaces::msg::FalconContainerState>()
{
  return "hos_interfaces/msg/FalconContainerState";
}

template<>
struct has_fixed_size<hos_interfaces::msg::FalconContainerState>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<hos_interfaces::msg::FalconContainerState>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<hos_interfaces::msg::FalconContainerState>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // HOS_INTERFACES__MSG__DETAIL__FALCON_CONTAINER_STATE__TRAITS_HPP_
