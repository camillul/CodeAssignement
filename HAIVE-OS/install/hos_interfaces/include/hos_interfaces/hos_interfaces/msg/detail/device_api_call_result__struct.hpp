// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from hos_interfaces:msg/DeviceAPICallResult.idl
// generated code does not contain a copyright notice

#ifndef HOS_INTERFACES__MSG__DETAIL__DEVICE_API_CALL_RESULT__STRUCT_HPP_
#define HOS_INTERFACES__MSG__DETAIL__DEVICE_API_CALL_RESULT__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__hos_interfaces__msg__DeviceAPICallResult __attribute__((deprecated))
#else
# define DEPRECATED__hos_interfaces__msg__DeviceAPICallResult __declspec(deprecated)
#endif

namespace hos_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct DeviceAPICallResult_
{
  using Type = DeviceAPICallResult_<ContainerAllocator>;

  explicit DeviceAPICallResult_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->task_id = 0ul;
      this->success = false;
      this->error = "";
      this->result_jsons = "";
      this->request_time_s = 0.0;
      this->response_time_s = 0.0;
    }
  }

  explicit DeviceAPICallResult_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : error(_alloc),
    result_jsons(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->task_id = 0ul;
      this->success = false;
      this->error = "";
      this->result_jsons = "";
      this->request_time_s = 0.0;
      this->response_time_s = 0.0;
    }
  }

  // field types and members
  using _task_id_type =
    uint32_t;
  _task_id_type task_id;
  using _success_type =
    bool;
  _success_type success;
  using _error_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _error_type error;
  using _result_jsons_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _result_jsons_type result_jsons;
  using _request_time_s_type =
    double;
  _request_time_s_type request_time_s;
  using _response_time_s_type =
    double;
  _response_time_s_type response_time_s;

  // setters for named parameter idiom
  Type & set__task_id(
    const uint32_t & _arg)
  {
    this->task_id = _arg;
    return *this;
  }
  Type & set__success(
    const bool & _arg)
  {
    this->success = _arg;
    return *this;
  }
  Type & set__error(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->error = _arg;
    return *this;
  }
  Type & set__result_jsons(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->result_jsons = _arg;
    return *this;
  }
  Type & set__request_time_s(
    const double & _arg)
  {
    this->request_time_s = _arg;
    return *this;
  }
  Type & set__response_time_s(
    const double & _arg)
  {
    this->response_time_s = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    hos_interfaces::msg::DeviceAPICallResult_<ContainerAllocator> *;
  using ConstRawPtr =
    const hos_interfaces::msg::DeviceAPICallResult_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<hos_interfaces::msg::DeviceAPICallResult_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<hos_interfaces::msg::DeviceAPICallResult_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      hos_interfaces::msg::DeviceAPICallResult_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<hos_interfaces::msg::DeviceAPICallResult_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      hos_interfaces::msg::DeviceAPICallResult_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<hos_interfaces::msg::DeviceAPICallResult_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<hos_interfaces::msg::DeviceAPICallResult_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<hos_interfaces::msg::DeviceAPICallResult_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__hos_interfaces__msg__DeviceAPICallResult
    std::shared_ptr<hos_interfaces::msg::DeviceAPICallResult_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__hos_interfaces__msg__DeviceAPICallResult
    std::shared_ptr<hos_interfaces::msg::DeviceAPICallResult_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const DeviceAPICallResult_ & other) const
  {
    if (this->task_id != other.task_id) {
      return false;
    }
    if (this->success != other.success) {
      return false;
    }
    if (this->error != other.error) {
      return false;
    }
    if (this->result_jsons != other.result_jsons) {
      return false;
    }
    if (this->request_time_s != other.request_time_s) {
      return false;
    }
    if (this->response_time_s != other.response_time_s) {
      return false;
    }
    return true;
  }
  bool operator!=(const DeviceAPICallResult_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct DeviceAPICallResult_

// alias to use template instance with default allocator
using DeviceAPICallResult =
  hos_interfaces::msg::DeviceAPICallResult_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace hos_interfaces

#endif  // HOS_INTERFACES__MSG__DETAIL__DEVICE_API_CALL_RESULT__STRUCT_HPP_
