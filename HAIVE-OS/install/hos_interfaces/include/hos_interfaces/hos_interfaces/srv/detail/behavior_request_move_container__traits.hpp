// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from hos_interfaces:srv/BehaviorRequestMoveContainer.idl
// generated code does not contain a copyright notice

#ifndef HOS_INTERFACES__SRV__DETAIL__BEHAVIOR_REQUEST_MOVE_CONTAINER__TRAITS_HPP_
#define HOS_INTERFACES__SRV__DETAIL__BEHAVIOR_REQUEST_MOVE_CONTAINER__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "hos_interfaces/srv/detail/behavior_request_move_container__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace hos_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const BehaviorRequestMoveContainer_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: container_id
  {
    out << "container_id: ";
    rosidl_generator_traits::value_to_yaml(msg.container_id, out);
    out << ", ";
  }

  // member: haive_id
  {
    out << "haive_id: ";
    rosidl_generator_traits::value_to_yaml(msg.haive_id, out);
    out << ", ";
  }

  // member: slot
  {
    out << "slot: ";
    rosidl_generator_traits::value_to_yaml(msg.slot, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const BehaviorRequestMoveContainer_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: container_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "container_id: ";
    rosidl_generator_traits::value_to_yaml(msg.container_id, out);
    out << "\n";
  }

  // member: haive_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "haive_id: ";
    rosidl_generator_traits::value_to_yaml(msg.haive_id, out);
    out << "\n";
  }

  // member: slot
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "slot: ";
    rosidl_generator_traits::value_to_yaml(msg.slot, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const BehaviorRequestMoveContainer_Request & msg, bool use_flow_style = false)
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
  const hos_interfaces::srv::BehaviorRequestMoveContainer_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  hos_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use hos_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const hos_interfaces::srv::BehaviorRequestMoveContainer_Request & msg)
{
  return hos_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<hos_interfaces::srv::BehaviorRequestMoveContainer_Request>()
{
  return "hos_interfaces::srv::BehaviorRequestMoveContainer_Request";
}

template<>
inline const char * name<hos_interfaces::srv::BehaviorRequestMoveContainer_Request>()
{
  return "hos_interfaces/srv/BehaviorRequestMoveContainer_Request";
}

template<>
struct has_fixed_size<hos_interfaces::srv::BehaviorRequestMoveContainer_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<hos_interfaces::srv::BehaviorRequestMoveContainer_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<hos_interfaces::srv::BehaviorRequestMoveContainer_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace hos_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const BehaviorRequestMoveContainer_Response & msg,
  std::ostream & out)
{
  out << "{";
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
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const BehaviorRequestMoveContainer_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
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
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const BehaviorRequestMoveContainer_Response & msg, bool use_flow_style = false)
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
  const hos_interfaces::srv::BehaviorRequestMoveContainer_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  hos_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use hos_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const hos_interfaces::srv::BehaviorRequestMoveContainer_Response & msg)
{
  return hos_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<hos_interfaces::srv::BehaviorRequestMoveContainer_Response>()
{
  return "hos_interfaces::srv::BehaviorRequestMoveContainer_Response";
}

template<>
inline const char * name<hos_interfaces::srv::BehaviorRequestMoveContainer_Response>()
{
  return "hos_interfaces/srv/BehaviorRequestMoveContainer_Response";
}

template<>
struct has_fixed_size<hos_interfaces::srv::BehaviorRequestMoveContainer_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<hos_interfaces::srv::BehaviorRequestMoveContainer_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<hos_interfaces::srv::BehaviorRequestMoveContainer_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<hos_interfaces::srv::BehaviorRequestMoveContainer>()
{
  return "hos_interfaces::srv::BehaviorRequestMoveContainer";
}

template<>
inline const char * name<hos_interfaces::srv::BehaviorRequestMoveContainer>()
{
  return "hos_interfaces/srv/BehaviorRequestMoveContainer";
}

template<>
struct has_fixed_size<hos_interfaces::srv::BehaviorRequestMoveContainer>
  : std::integral_constant<
    bool,
    has_fixed_size<hos_interfaces::srv::BehaviorRequestMoveContainer_Request>::value &&
    has_fixed_size<hos_interfaces::srv::BehaviorRequestMoveContainer_Response>::value
  >
{
};

template<>
struct has_bounded_size<hos_interfaces::srv::BehaviorRequestMoveContainer>
  : std::integral_constant<
    bool,
    has_bounded_size<hos_interfaces::srv::BehaviorRequestMoveContainer_Request>::value &&
    has_bounded_size<hos_interfaces::srv::BehaviorRequestMoveContainer_Response>::value
  >
{
};

template<>
struct is_service<hos_interfaces::srv::BehaviorRequestMoveContainer>
  : std::true_type
{
};

template<>
struct is_service_request<hos_interfaces::srv::BehaviorRequestMoveContainer_Request>
  : std::true_type
{
};

template<>
struct is_service_response<hos_interfaces::srv::BehaviorRequestMoveContainer_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // HOS_INTERFACES__SRV__DETAIL__BEHAVIOR_REQUEST_MOVE_CONTAINER__TRAITS_HPP_
