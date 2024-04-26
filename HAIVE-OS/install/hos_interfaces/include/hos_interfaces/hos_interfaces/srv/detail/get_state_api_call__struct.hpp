// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from hos_interfaces:srv/GetStateAPICall.idl
// generated code does not contain a copyright notice

#ifndef HOS_INTERFACES__SRV__DETAIL__GET_STATE_API_CALL__STRUCT_HPP_
#define HOS_INTERFACES__SRV__DETAIL__GET_STATE_API_CALL__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__hos_interfaces__srv__GetStateAPICall_Request __attribute__((deprecated))
#else
# define DEPRECATED__hos_interfaces__srv__GetStateAPICall_Request __declspec(deprecated)
#endif

namespace hos_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct GetStateAPICall_Request_
{
  using Type = GetStateAPICall_Request_<ContainerAllocator>;

  explicit GetStateAPICall_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->device_id = "";
      this->state_type = 0;
    }
  }

  explicit GetStateAPICall_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : device_id(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->device_id = "";
      this->state_type = 0;
    }
  }

  // field types and members
  using _device_id_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _device_id_type device_id;
  using _state_type_type =
    int8_t;
  _state_type_type state_type;

  // setters for named parameter idiom
  Type & set__device_id(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->device_id = _arg;
    return *this;
  }
  Type & set__state_type(
    const int8_t & _arg)
  {
    this->state_type = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    hos_interfaces::srv::GetStateAPICall_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const hos_interfaces::srv::GetStateAPICall_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<hos_interfaces::srv::GetStateAPICall_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<hos_interfaces::srv::GetStateAPICall_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      hos_interfaces::srv::GetStateAPICall_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<hos_interfaces::srv::GetStateAPICall_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      hos_interfaces::srv::GetStateAPICall_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<hos_interfaces::srv::GetStateAPICall_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<hos_interfaces::srv::GetStateAPICall_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<hos_interfaces::srv::GetStateAPICall_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__hos_interfaces__srv__GetStateAPICall_Request
    std::shared_ptr<hos_interfaces::srv::GetStateAPICall_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__hos_interfaces__srv__GetStateAPICall_Request
    std::shared_ptr<hos_interfaces::srv::GetStateAPICall_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GetStateAPICall_Request_ & other) const
  {
    if (this->device_id != other.device_id) {
      return false;
    }
    if (this->state_type != other.state_type) {
      return false;
    }
    return true;
  }
  bool operator!=(const GetStateAPICall_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GetStateAPICall_Request_

// alias to use template instance with default allocator
using GetStateAPICall_Request =
  hos_interfaces::srv::GetStateAPICall_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace hos_interfaces


#ifndef _WIN32
# define DEPRECATED__hos_interfaces__srv__GetStateAPICall_Response __attribute__((deprecated))
#else
# define DEPRECATED__hos_interfaces__srv__GetStateAPICall_Response __declspec(deprecated)
#endif

namespace hos_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct GetStateAPICall_Response_
{
  using Type = GetStateAPICall_Response_<ContainerAllocator>;

  explicit GetStateAPICall_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->is_valid = false;
      this->error = "";
      this->task_id = 0ul;
      this->result_jsons = "";
    }
  }

  explicit GetStateAPICall_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : error(_alloc),
    result_jsons(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->is_valid = false;
      this->error = "";
      this->task_id = 0ul;
      this->result_jsons = "";
    }
  }

  // field types and members
  using _is_valid_type =
    bool;
  _is_valid_type is_valid;
  using _error_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _error_type error;
  using _task_id_type =
    uint32_t;
  _task_id_type task_id;
  using _result_jsons_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _result_jsons_type result_jsons;

  // setters for named parameter idiom
  Type & set__is_valid(
    const bool & _arg)
  {
    this->is_valid = _arg;
    return *this;
  }
  Type & set__error(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->error = _arg;
    return *this;
  }
  Type & set__task_id(
    const uint32_t & _arg)
  {
    this->task_id = _arg;
    return *this;
  }
  Type & set__result_jsons(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->result_jsons = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    hos_interfaces::srv::GetStateAPICall_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const hos_interfaces::srv::GetStateAPICall_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<hos_interfaces::srv::GetStateAPICall_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<hos_interfaces::srv::GetStateAPICall_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      hos_interfaces::srv::GetStateAPICall_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<hos_interfaces::srv::GetStateAPICall_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      hos_interfaces::srv::GetStateAPICall_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<hos_interfaces::srv::GetStateAPICall_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<hos_interfaces::srv::GetStateAPICall_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<hos_interfaces::srv::GetStateAPICall_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__hos_interfaces__srv__GetStateAPICall_Response
    std::shared_ptr<hos_interfaces::srv::GetStateAPICall_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__hos_interfaces__srv__GetStateAPICall_Response
    std::shared_ptr<hos_interfaces::srv::GetStateAPICall_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GetStateAPICall_Response_ & other) const
  {
    if (this->is_valid != other.is_valid) {
      return false;
    }
    if (this->error != other.error) {
      return false;
    }
    if (this->task_id != other.task_id) {
      return false;
    }
    if (this->result_jsons != other.result_jsons) {
      return false;
    }
    return true;
  }
  bool operator!=(const GetStateAPICall_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GetStateAPICall_Response_

// alias to use template instance with default allocator
using GetStateAPICall_Response =
  hos_interfaces::srv::GetStateAPICall_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace hos_interfaces

namespace hos_interfaces
{

namespace srv
{

struct GetStateAPICall
{
  using Request = hos_interfaces::srv::GetStateAPICall_Request;
  using Response = hos_interfaces::srv::GetStateAPICall_Response;
};

}  // namespace srv

}  // namespace hos_interfaces

#endif  // HOS_INTERFACES__SRV__DETAIL__GET_STATE_API_CALL__STRUCT_HPP_
