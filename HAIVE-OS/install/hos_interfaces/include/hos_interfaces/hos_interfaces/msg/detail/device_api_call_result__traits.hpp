// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from hos_interfaces:msg/DeviceAPICallResult.idl
// generated code does not contain a copyright notice

#ifndef HOS_INTERFACES__MSG__DETAIL__DEVICE_API_CALL_RESULT__TRAITS_HPP_
#define HOS_INTERFACES__MSG__DETAIL__DEVICE_API_CALL_RESULT__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "hos_interfaces/msg/detail/device_api_call_result__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace hos_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const DeviceAPICallResult & msg,
  std::ostream & out)
{
  out << "{";
  // member: task_id
  {
    out << "task_id: ";
    rosidl_generator_traits::value_to_yaml(msg.task_id, out);
    out << ", ";
  }

  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << ", ";
  }

  // member: error
  {
    out << "error: ";
    rosidl_generator_traits::value_to_yaml(msg.error, out);
    out << ", ";
  }

  // member: result_jsons
  {
    out << "result_jsons: ";
    rosidl_generator_traits::value_to_yaml(msg.result_jsons, out);
    out << ", ";
  }

  // member: request_time_s
  {
    out << "request_time_s: ";
    rosidl_generator_traits::value_to_yaml(msg.request_time_s, out);
    out << ", ";
  }

  // member: response_time_s
  {
    out << "response_time_s: ";
    rosidl_generator_traits::value_to_yaml(msg.response_time_s, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const DeviceAPICallResult & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: task_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "task_id: ";
    rosidl_generator_traits::value_to_yaml(msg.task_id, out);
    out << "\n";
  }

  // member: success
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
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

  // member: result_jsons
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "result_jsons: ";
    rosidl_generator_traits::value_to_yaml(msg.result_jsons, out);
    out << "\n";
  }

  // member: request_time_s
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "request_time_s: ";
    rosidl_generator_traits::value_to_yaml(msg.request_time_s, out);
    out << "\n";
  }

  // member: response_time_s
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "response_time_s: ";
    rosidl_generator_traits::value_to_yaml(msg.response_time_s, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const DeviceAPICallResult & msg, bool use_flow_style = false)
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
  const hos_interfaces::msg::DeviceAPICallResult & msg,
  std::ostream & out, size_t indentation = 0)
{
  hos_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use hos_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const hos_interfaces::msg::DeviceAPICallResult & msg)
{
  return hos_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<hos_interfaces::msg::DeviceAPICallResult>()
{
  return "hos_interfaces::msg::DeviceAPICallResult";
}

template<>
inline const char * name<hos_interfaces::msg::DeviceAPICallResult>()
{
  return "hos_interfaces/msg/DeviceAPICallResult";
}

template<>
struct has_fixed_size<hos_interfaces::msg::DeviceAPICallResult>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<hos_interfaces::msg::DeviceAPICallResult>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<hos_interfaces::msg::DeviceAPICallResult>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // HOS_INTERFACES__MSG__DETAIL__DEVICE_API_CALL_RESULT__TRAITS_HPP_
