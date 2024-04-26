// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from hos_interfaces:msg/P1000ContainerState.idl
// generated code does not contain a copyright notice

#ifndef HOS_INTERFACES__MSG__DETAIL__P1000_CONTAINER_STATE__STRUCT_HPP_
#define HOS_INTERFACES__MSG__DETAIL__P1000_CONTAINER_STATE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__hos_interfaces__msg__P1000ContainerState __attribute__((deprecated))
#else
# define DEPRECATED__hos_interfaces__msg__P1000ContainerState __declspec(deprecated)
#endif

namespace hos_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct P1000ContainerState_
{
  using Type = P1000ContainerState_<ContainerAllocator>;

  explicit P1000ContainerState_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x_size = 0;
      this->y_size = 0;
      this->is_flipped = false;
      this->slot_position = 0;
      this->external_resources = "";
      this->temperature = 0.0f;
      this->is_movable = false;
      this->is_connected = false;
      this->last_ping = 0.0f;
      this->device_uid = "";
      this->is_reconnected = false;
      this->device_type = "";
      this->device_id = "";
    }
  }

  explicit P1000ContainerState_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : external_resources(_alloc),
    device_uid(_alloc),
    device_type(_alloc),
    device_id(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x_size = 0;
      this->y_size = 0;
      this->is_flipped = false;
      this->slot_position = 0;
      this->external_resources = "";
      this->temperature = 0.0f;
      this->is_movable = false;
      this->is_connected = false;
      this->last_ping = 0.0f;
      this->device_uid = "";
      this->is_reconnected = false;
      this->device_type = "";
      this->device_id = "";
    }
  }

  // field types and members
  using _x_size_type =
    uint8_t;
  _x_size_type x_size;
  using _y_size_type =
    uint8_t;
  _y_size_type y_size;
  using _tips_availaible_type =
    std::vector<uint16_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<uint16_t>>;
  _tips_availaible_type tips_availaible;
  using _is_flipped_type =
    bool;
  _is_flipped_type is_flipped;
  using _slot_position_type =
    uint8_t;
  _slot_position_type slot_position;
  using _external_resources_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _external_resources_type external_resources;
  using _temperature_type =
    float;
  _temperature_type temperature;
  using _is_movable_type =
    bool;
  _is_movable_type is_movable;
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
  Type & set__x_size(
    const uint8_t & _arg)
  {
    this->x_size = _arg;
    return *this;
  }
  Type & set__y_size(
    const uint8_t & _arg)
  {
    this->y_size = _arg;
    return *this;
  }
  Type & set__tips_availaible(
    const std::vector<uint16_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<uint16_t>> & _arg)
  {
    this->tips_availaible = _arg;
    return *this;
  }
  Type & set__is_flipped(
    const bool & _arg)
  {
    this->is_flipped = _arg;
    return *this;
  }
  Type & set__slot_position(
    const uint8_t & _arg)
  {
    this->slot_position = _arg;
    return *this;
  }
  Type & set__external_resources(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->external_resources = _arg;
    return *this;
  }
  Type & set__temperature(
    const float & _arg)
  {
    this->temperature = _arg;
    return *this;
  }
  Type & set__is_movable(
    const bool & _arg)
  {
    this->is_movable = _arg;
    return *this;
  }
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
    hos_interfaces::msg::P1000ContainerState_<ContainerAllocator> *;
  using ConstRawPtr =
    const hos_interfaces::msg::P1000ContainerState_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<hos_interfaces::msg::P1000ContainerState_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<hos_interfaces::msg::P1000ContainerState_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      hos_interfaces::msg::P1000ContainerState_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<hos_interfaces::msg::P1000ContainerState_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      hos_interfaces::msg::P1000ContainerState_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<hos_interfaces::msg::P1000ContainerState_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<hos_interfaces::msg::P1000ContainerState_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<hos_interfaces::msg::P1000ContainerState_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__hos_interfaces__msg__P1000ContainerState
    std::shared_ptr<hos_interfaces::msg::P1000ContainerState_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__hos_interfaces__msg__P1000ContainerState
    std::shared_ptr<hos_interfaces::msg::P1000ContainerState_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const P1000ContainerState_ & other) const
  {
    if (this->x_size != other.x_size) {
      return false;
    }
    if (this->y_size != other.y_size) {
      return false;
    }
    if (this->tips_availaible != other.tips_availaible) {
      return false;
    }
    if (this->is_flipped != other.is_flipped) {
      return false;
    }
    if (this->slot_position != other.slot_position) {
      return false;
    }
    if (this->external_resources != other.external_resources) {
      return false;
    }
    if (this->temperature != other.temperature) {
      return false;
    }
    if (this->is_movable != other.is_movable) {
      return false;
    }
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
  bool operator!=(const P1000ContainerState_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct P1000ContainerState_

// alias to use template instance with default allocator
using P1000ContainerState =
  hos_interfaces::msg::P1000ContainerState_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace hos_interfaces

#endif  // HOS_INTERFACES__MSG__DETAIL__P1000_CONTAINER_STATE__STRUCT_HPP_
