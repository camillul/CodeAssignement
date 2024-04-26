// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from hos_interfaces:srv/RobotStateInit.idl
// generated code does not contain a copyright notice

#ifndef HOS_INTERFACES__SRV__DETAIL__ROBOT_STATE_INIT__TRAITS_HPP_
#define HOS_INTERFACES__SRV__DETAIL__ROBOT_STATE_INIT__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "hos_interfaces/srv/detail/robot_state_init__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace hos_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const RobotStateInit_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: file_name
  {
    out << "file_name: ";
    rosidl_generator_traits::value_to_yaml(msg.file_name, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const RobotStateInit_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: file_name
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "file_name: ";
    rosidl_generator_traits::value_to_yaml(msg.file_name, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const RobotStateInit_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace hos_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use hos_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const hos_interfaces::srv::RobotStateInit_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  hos_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use hos_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const hos_interfaces::srv::RobotStateInit_Request & msg)
{
  return hos_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<hos_interfaces::srv::RobotStateInit_Request>()
{
  return "hos_interfaces::srv::RobotStateInit_Request";
}

template<>
inline const char * name<hos_interfaces::srv::RobotStateInit_Request>()
{
  return "hos_interfaces/srv/RobotStateInit_Request";
}

template<>
struct has_fixed_size<hos_interfaces::srv::RobotStateInit_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<hos_interfaces::srv::RobotStateInit_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<hos_interfaces::srv::RobotStateInit_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace hos_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const RobotStateInit_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: is_valid
  {
    out << "is_valid: ";
    rosidl_generator_traits::value_to_yaml(msg.is_valid, out);
    out << ", ";
  }

  // member: error
  {
    out << "error: ";
    rosidl_generator_traits::value_to_yaml(msg.error, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const RobotStateInit_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: is_valid
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "is_valid: ";
    rosidl_generator_traits::value_to_yaml(msg.is_valid, out);
    out << "\n";
  }

  // member: error
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "error: ";
    rosidl_generator_traits::value_to_yaml(msg.error, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const RobotStateInit_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace hos_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use hos_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const hos_interfaces::srv::RobotStateInit_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  hos_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use hos_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const hos_interfaces::srv::RobotStateInit_Response & msg)
{
  return hos_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<hos_interfaces::srv::RobotStateInit_Response>()
{
  return "hos_interfaces::srv::RobotStateInit_Response";
}

template<>
inline const char * name<hos_interfaces::srv::RobotStateInit_Response>()
{
  return "hos_interfaces/srv/RobotStateInit_Response";
}

template<>
struct has_fixed_size<hos_interfaces::srv::RobotStateInit_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<hos_interfaces::srv::RobotStateInit_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<hos_interfaces::srv::RobotStateInit_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<hos_interfaces::srv::RobotStateInit>()
{
  return "hos_interfaces::srv::RobotStateInit";
}

template<>
inline const char * name<hos_interfaces::srv::RobotStateInit>()
{
  return "hos_interfaces/srv/RobotStateInit";
}

template<>
struct has_fixed_size<hos_interfaces::srv::RobotStateInit>
  : std::integral_constant<
    bool,
    has_fixed_size<hos_interfaces::srv::RobotStateInit_Request>::value &&
    has_fixed_size<hos_interfaces::srv::RobotStateInit_Response>::value
  >
{
};

template<>
struct has_bounded_size<hos_interfaces::srv::RobotStateInit>
  : std::integral_constant<
    bool,
    has_bounded_size<hos_interfaces::srv::RobotStateInit_Request>::value &&
    has_bounded_size<hos_interfaces::srv::RobotStateInit_Response>::value
  >
{
};

template<>
struct is_service<hos_interfaces::srv::RobotStateInit>
  : std::true_type
{
};

template<>
struct is_service_request<hos_interfaces::srv::RobotStateInit_Request>
  : std::true_type
{
};

template<>
struct is_service_response<hos_interfaces::srv::RobotStateInit_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // HOS_INTERFACES__SRV__DETAIL__ROBOT_STATE_INIT__TRAITS_HPP_
