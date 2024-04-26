// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from hos_interfaces:srv/DeviceConnectionInfos.idl
// generated code does not contain a copyright notice

#ifndef HOS_INTERFACES__SRV__DETAIL__DEVICE_CONNECTION_INFOS__TRAITS_HPP_
#define HOS_INTERFACES__SRV__DETAIL__DEVICE_CONNECTION_INFOS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "hos_interfaces/srv/detail/device_connection_infos__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace hos_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const DeviceConnectionInfos_Request & msg,
  std::ostream & out)
{
  (void)msg;
  out << "null";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const DeviceConnectionInfos_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  (void)msg;
  (void)indentation;
  out << "null\n";
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const DeviceConnectionInfos_Request & msg, bool use_flow_style = false)
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
  const hos_interfaces::srv::DeviceConnectionInfos_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  hos_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use hos_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const hos_interfaces::srv::DeviceConnectionInfos_Request & msg)
{
  return hos_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<hos_interfaces::srv::DeviceConnectionInfos_Request>()
{
  return "hos_interfaces::srv::DeviceConnectionInfos_Request";
}

template<>
inline const char * name<hos_interfaces::srv::DeviceConnectionInfos_Request>()
{
  return "hos_interfaces/srv/DeviceConnectionInfos_Request";
}

template<>
struct has_fixed_size<hos_interfaces::srv::DeviceConnectionInfos_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<hos_interfaces::srv::DeviceConnectionInfos_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<hos_interfaces::srv::DeviceConnectionInfos_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'device_infos'
#include "hos_interfaces/msg/detail/connection_info__traits.hpp"

namespace hos_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const DeviceConnectionInfos_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: device_infos
  {
    if (msg.device_infos.size() == 0) {
      out << "device_infos: []";
    } else {
      out << "device_infos: [";
      size_t pending_items = msg.device_infos.size();
      for (auto item : msg.device_infos) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const DeviceConnectionInfos_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: device_infos
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.device_infos.size() == 0) {
      out << "device_infos: []\n";
    } else {
      out << "device_infos:\n";
      for (auto item : msg.device_infos) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const DeviceConnectionInfos_Response & msg, bool use_flow_style = false)
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
  const hos_interfaces::srv::DeviceConnectionInfos_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  hos_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use hos_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const hos_interfaces::srv::DeviceConnectionInfos_Response & msg)
{
  return hos_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<hos_interfaces::srv::DeviceConnectionInfos_Response>()
{
  return "hos_interfaces::srv::DeviceConnectionInfos_Response";
}

template<>
inline const char * name<hos_interfaces::srv::DeviceConnectionInfos_Response>()
{
  return "hos_interfaces/srv/DeviceConnectionInfos_Response";
}

template<>
struct has_fixed_size<hos_interfaces::srv::DeviceConnectionInfos_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<hos_interfaces::srv::DeviceConnectionInfos_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<hos_interfaces::srv::DeviceConnectionInfos_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<hos_interfaces::srv::DeviceConnectionInfos>()
{
  return "hos_interfaces::srv::DeviceConnectionInfos";
}

template<>
inline const char * name<hos_interfaces::srv::DeviceConnectionInfos>()
{
  return "hos_interfaces/srv/DeviceConnectionInfos";
}

template<>
struct has_fixed_size<hos_interfaces::srv::DeviceConnectionInfos>
  : std::integral_constant<
    bool,
    has_fixed_size<hos_interfaces::srv::DeviceConnectionInfos_Request>::value &&
    has_fixed_size<hos_interfaces::srv::DeviceConnectionInfos_Response>::value
  >
{
};

template<>
struct has_bounded_size<hos_interfaces::srv::DeviceConnectionInfos>
  : std::integral_constant<
    bool,
    has_bounded_size<hos_interfaces::srv::DeviceConnectionInfos_Request>::value &&
    has_bounded_size<hos_interfaces::srv::DeviceConnectionInfos_Response>::value
  >
{
};

template<>
struct is_service<hos_interfaces::srv::DeviceConnectionInfos>
  : std::true_type
{
};

template<>
struct is_service_request<hos_interfaces::srv::DeviceConnectionInfos_Request>
  : std::true_type
{
};

template<>
struct is_service_response<hos_interfaces::srv::DeviceConnectionInfos_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // HOS_INTERFACES__SRV__DETAIL__DEVICE_CONNECTION_INFOS__TRAITS_HPP_
