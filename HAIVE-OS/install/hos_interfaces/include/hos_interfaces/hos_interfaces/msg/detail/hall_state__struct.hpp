// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from hos_interfaces:msg/HallState.idl
// generated code does not contain a copyright notice

#ifndef HOS_INTERFACES__MSG__DETAIL__HALL_STATE__STRUCT_HPP_
#define HOS_INTERFACES__MSG__DETAIL__HALL_STATE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__hos_interfaces__msg__HallState __attribute__((deprecated))
#else
# define DEPRECATED__hos_interfaces__msg__HallState __declspec(deprecated)
#endif

namespace hos_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct HallState_
{
  using Type = HallState_<ContainerAllocator>;

  explicit HallState_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->is_connected = false;
      this->last_ping = 0.0f;
      this->device_uid = "";
      this->is_reconnected = false;
      this->device_type = "";
      this->device_id = "";
    }
  }

  explicit HallState_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : device_uid(_alloc),
    device_type(_alloc),
    device_id(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->is_connected = false;
      this->last_ping = 0.0f;
      this->device_uid = "";
      this->is_reconnected = false;
      this->device_type = "";
      this->device_id = "";
    }
  }

  // field types and members
  using _is_connected_type =
    bool;
  _is_connected_type is_connected;
  using _last_ping_type =
    float;
  _last_ping_type last_ping;
  using _device_uid_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _device_uid_type device_uid;
  using _is_reconnected_type =
    bool;
  _is_reconnected_type is_reconnected;
  using _device_type_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _device_type_type device_type;
  using _device_id_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _device_id_type device_id;

  // setters for named parameter idiom
  Type & set__is_connected(
    const bool & _arg)
  {
    this->is_connected = _arg;
    return *this;
  }
  Type & set__last_ping(
    const float & _arg)
  {
    this->last_ping = _arg;
    return *this;
  }
  Type & set__device_uid(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->device_uid = _arg;
    return *this;
  }
  Type & set__is_reconnected(
    const bool & _arg)
  {
    this->is_reconnected = _arg;
    return *this;
  }
  Type & set__device_type(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->device_type = _arg;
    return *this;
  }
  Type & set__device_id(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->device_id = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    hos_interfaces::msg::HallState_<ContainerAllocator> *;
  using ConstRawPtr =
    const hos_interfaces::msg::HallState_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<hos_interfaces::msg::HallState_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<hos_interfaces::msg::HallState_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      hos_interfaces::msg::HallState_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<hos_interfaces::msg::HallState_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      hos_interfaces::msg::HallState_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<hos_interfaces::msg::HallState_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<hos_interfaces::msg::HallState_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<hos_interfaces::msg::HallState_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__hos_interfaces__msg__HallState
    std::shared_ptr<hos_interfaces::msg::HallState_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__hos_interfaces__msg__HallState
    std::shared_ptr<hos_interfaces::msg::HallState_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const HallState_ & other) const
  {
    if (this->is_connected != other.is_connected) {
      return false;
    }
    if (this->last_ping != other.last_ping) {
      return false;
    }
    if (this->device_uid != other.device_uid) {
      return false;
    }
    if (this->is_reconnected != other.is_reconnected) {
      return false;
    }
    if (this->device_type != other.device_type) {
      return false;
    }
    if (this->device_id != other.device_id) {
      return false;
    }
    return true;
  }
  bool operator!=(const HallState_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct HallState_

// alias to use template instance with default allocator
using HallState =
  hos_interfaces::msg::HallState_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace hos_interfaces

#endif  // HOS_INTERFACES__MSG__DETAIL__HALL_STATE__STRUCT_HPP_
