// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from hos_interfaces:srv/DeviceAPICall.idl
// generated code does not contain a copyright notice

#ifndef HOS_INTERFACES__SRV__DETAIL__DEVICE_API_CALL__STRUCT_HPP_
#define HOS_INTERFACES__SRV__DETAIL__DEVICE_API_CALL__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'args'
#include "hos_interfaces/msg/detail/typed_field__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__hos_interfaces__srv__DeviceAPICall_Request __attribute__((deprecated))
#else
# define DEPRECATED__hos_interfaces__srv__DeviceAPICall_Request __declspec(deprecated)
#endif

namespace hos_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct DeviceAPICall_Request_
{
  using Type = DeviceAPICall_Request_<ContainerAllocator>;

  explicit DeviceAPICall_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->device_id = "";
      this->function_name = "";
    }
  }

  explicit DeviceAPICall_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : device_id(_alloc),
    function_name(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->device_id = "";
      this->function_name = "";
    }
  }

  // field types and members
  using _device_id_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _device_id_type device_id;
  using _function_name_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _function_name_type function_name;
  using _args_type =
    std::vector<hos_interfaces::msg::TypedField_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<hos_interfaces::msg::TypedField_<ContainerAllocator>>>;
  _args_type args;

  // setters for named parameter idiom
  Type & set__device_id(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->device_id = _arg;
    return *this;
  }
  Type & set__function_name(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->function_name = _arg;
    return *this;
  }
  Type & set__args(
    const std::vector<hos_interfaces::msg::TypedField_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<hos_interfaces::msg::TypedField_<ContainerAllocator>>> & _arg)
  {
    this->args = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    hos_interfaces::srv::DeviceAPICall_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const hos_interfaces::srv::DeviceAPICall_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<hos_interfaces::srv::DeviceAPICall_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<hos_interfaces::srv::DeviceAPICall_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      hos_interfaces::srv::DeviceAPICall_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<hos_interfaces::srv::DeviceAPICall_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      hos_interfaces::srv::DeviceAPICall_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<hos_interfaces::srv::DeviceAPICall_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<hos_interfaces::srv::DeviceAPICall_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<hos_interfaces::srv::DeviceAPICall_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__hos_interfaces__srv__DeviceAPICall_Request
    std::shared_ptr<hos_interfaces::srv::DeviceAPICall_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__hos_interfaces__srv__DeviceAPICall_Request
    std::shared_ptr<hos_interfaces::srv::DeviceAPICall_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const DeviceAPICall_Request_ & other) const
  {
    if (this->device_id != other.device_id) {
      return false;
    }
    if (this->function_name != other.function_name) {
      return false;
    }
    if (this->args != other.args) {
      return false;
    }
    return true;
  }
  bool operator!=(const DeviceAPICall_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct DeviceAPICall_Request_

// alias to use template instance with default allocator
using DeviceAPICall_Request =
  hos_interfaces::srv::DeviceAPICall_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace hos_interfaces


#ifndef _WIN32
# define DEPRECATED__hos_interfaces__srv__DeviceAPICall_Response __attribute__((deprecated))
#else
# define DEPRECATED__hos_interfaces__srv__DeviceAPICall_Response __declspec(deprecated)
#endif

namespace hos_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct DeviceAPICall_Response_
{
  using Type = DeviceAPICall_Response_<ContainerAllocator>;

  explicit DeviceAPICall_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->is_valid = false;
      this->error = "";
      this->task_id = 0ul;
    }
  }

  explicit DeviceAPICall_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : error(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->is_valid = false;
      this->error = "";
      this->task_id = 0ul;
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

  // constant declarations

  // pointer types
  using RawPtr =
    hos_interfaces::srv::DeviceAPICall_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const hos_interfaces::srv::DeviceAPICall_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<hos_interfaces::srv::DeviceAPICall_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<hos_interfaces::srv::DeviceAPICall_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      hos_interfaces::srv::DeviceAPICall_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<hos_interfaces::srv::DeviceAPICall_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      hos_interfaces::srv::DeviceAPICall_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<hos_interfaces::srv::DeviceAPICall_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<hos_interfaces::srv::DeviceAPICall_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<hos_interfaces::srv::DeviceAPICall_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__hos_interfaces__srv__DeviceAPICall_Response
    std::shared_ptr<hos_interfaces::srv::DeviceAPICall_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__hos_interfaces__srv__DeviceAPICall_Response
    std::shared_ptr<hos_interfaces::srv::DeviceAPICall_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const DeviceAPICall_Response_ & other) const
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
    return true;
  }
  bool operator!=(const DeviceAPICall_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct DeviceAPICall_Response_

// alias to use template instance with default allocator
using DeviceAPICall_Response =
  hos_interfaces::srv::DeviceAPICall_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace hos_interfaces

namespace hos_interfaces
{

namespace srv
{

struct DeviceAPICall
{
  using Request = hos_interfaces::srv::DeviceAPICall_Request;
  using Response = hos_interfaces::srv::DeviceAPICall_Response;
};

}  // namespace srv

}  // namespace hos_interfaces

#endif  // HOS_INTERFACES__SRV__DETAIL__DEVICE_API_CALL__STRUCT_HPP_
