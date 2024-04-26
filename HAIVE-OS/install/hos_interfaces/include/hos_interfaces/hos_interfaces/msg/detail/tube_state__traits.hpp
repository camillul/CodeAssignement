// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from hos_interfaces:msg/TubeState.idl
// generated code does not contain a copyright notice

#ifndef HOS_INTERFACES__MSG__DETAIL__TUBE_STATE__TRAITS_HPP_
#define HOS_INTERFACES__MSG__DETAIL__TUBE_STATE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "hos_interfaces/msg/detail/tube_state__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace hos_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const TubeState & msg,
  std::ostream & out)
{
  out << "{";
  // member: liquid_level
  {
    out << "liquid_level: ";
    rosidl_generator_traits::value_to_yaml(msg.liquid_level, out);
    out << ", ";
  }

  // member: tube_id
  {
    out << "tube_id: ";
    rosidl_generator_traits::value_to_yaml(msg.tube_id, out);
    out << ", ";
  }

  // member: tube_type
  {
    out << "tube_type: ";
    rosidl_generator_traits::value_to_yaml(msg.tube_type, out);
    out << ", ";
  }

  // member: volume
  {
    out << "volume: ";
    rosidl_generator_traits::value_to_yaml(msg.volume, out);
    out << ", ";
  }

  // member: temperature
  {
    out << "temperature: ";
    rosidl_generator_traits::value_to_yaml(msg.temperature, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const TubeState & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: liquid_level
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "liquid_level: ";
    rosidl_generator_traits::value_to_yaml(msg.liquid_level, out);
    out << "\n";
  }

  // member: tube_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "tube_id: ";
    rosidl_generator_traits::value_to_yaml(msg.tube_id, out);
    out << "\n";
  }

  // member: tube_type
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "tube_type: ";
    rosidl_generator_traits::value_to_yaml(msg.tube_type, out);
    out << "\n";
  }

  // member: volume
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "volume: ";
    rosidl_generator_traits::value_to_yaml(msg.volume, out);
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
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const TubeState & msg, bool use_flow_style = false)
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
  const hos_interfaces::msg::TubeState & msg,
  std::ostream & out, size_t indentation = 0)
{
  hos_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use hos_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const hos_interfaces::msg::TubeState & msg)
{
  return hos_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<hos_interfaces::msg::TubeState>()
{
  return "hos_interfaces::msg::TubeState";
}

template<>
inline const char * name<hos_interfaces::msg::TubeState>()
{
  return "hos_interfaces/msg/TubeState";
}

template<>
struct has_fixed_size<hos_interfaces::msg::TubeState>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<hos_interfaces::msg::TubeState>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<hos_interfaces::msg::TubeState>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // HOS_INTERFACES__MSG__DETAIL__TUBE_STATE__TRAITS_HPP_
