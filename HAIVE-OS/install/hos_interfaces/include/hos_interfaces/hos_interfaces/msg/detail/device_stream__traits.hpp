// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from hos_interfaces:msg/DeviceStream.idl
// generated code does not contain a copyright notice

#ifndef HOS_INTERFACES__MSG__DETAIL__DEVICE_STREAM__TRAITS_HPP_
#define HOS_INTERFACES__MSG__DETAIL__DEVICE_STREAM__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "hos_interfaces/msg/detail/device_stream__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace hos_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const DeviceStream & msg,
  std::ostream & out)
{
  out << "{";
  // member: uid
  {
    out << "uid: ";
    rosidl_generator_traits::value_to_yaml(msg.uid, out);
    out << ", ";
  }

  // member: data
  {
    out << "data: ";
    rosidl_generator_traits::value_to_yaml(msg.data, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const DeviceStream & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: uid
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "uid: ";
    rosidl_generator_traits::value_to_yaml(msg.uid, out);
    out << "\n";
  }

  // member: data
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "data: ";
    rosidl_generator_traits::value_to_yaml(msg.data, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const DeviceStream & msg, bool use_flow_style = false)
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
  const hos_interfaces::msg::DeviceStream & msg,
  std::ostream & out, size_t indentation = 0)
{
  hos_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use hos_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const hos_interfaces::msg::DeviceStream & msg)
{
  return hos_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<hos_interfaces::msg::DeviceStream>()
{
  return "hos_interfaces::msg::DeviceStream";
}

template<>
inline const char * name<hos_interfaces::msg::DeviceStream>()
{
  return "hos_interfaces/msg/DeviceStream";
}

template<>
struct has_fixed_size<hos_interfaces::msg::DeviceStream>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<hos_interfaces::msg::DeviceStream>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<hos_interfaces::msg::DeviceStream>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // HOS_INTERFACES__MSG__DETAIL__DEVICE_STREAM__TRAITS_HPP_
