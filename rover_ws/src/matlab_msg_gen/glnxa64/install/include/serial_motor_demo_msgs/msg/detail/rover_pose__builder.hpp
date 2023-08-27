// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from serial_motor_demo_msgs:msg/RoverPose.idl
// generated code does not contain a copyright notice

#ifndef SERIAL_MOTOR_DEMO_MSGS__MSG__DETAIL__ROVER_POSE__BUILDER_HPP_
#define SERIAL_MOTOR_DEMO_MSGS__MSG__DETAIL__ROVER_POSE__BUILDER_HPP_

#include "serial_motor_demo_msgs/msg/detail/rover_pose__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace serial_motor_demo_msgs
{

namespace msg
{

namespace builder
{

class Init_RoverPose_rover_y
{
public:
  explicit Init_RoverPose_rover_y(::serial_motor_demo_msgs::msg::RoverPose & msg)
  : msg_(msg)
  {}
  ::serial_motor_demo_msgs::msg::RoverPose rover_y(::serial_motor_demo_msgs::msg::RoverPose::_rover_y_type arg)
  {
    msg_.rover_y = std::move(arg);
    return std::move(msg_);
  }

private:
  ::serial_motor_demo_msgs::msg::RoverPose msg_;
};

class Init_RoverPose_rover_x
{
public:
  Init_RoverPose_rover_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RoverPose_rover_y rover_x(::serial_motor_demo_msgs::msg::RoverPose::_rover_x_type arg)
  {
    msg_.rover_x = std::move(arg);
    return Init_RoverPose_rover_y(msg_);
  }

private:
  ::serial_motor_demo_msgs::msg::RoverPose msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::serial_motor_demo_msgs::msg::RoverPose>()
{
  return serial_motor_demo_msgs::msg::builder::Init_RoverPose_rover_x();
}

}  // namespace serial_motor_demo_msgs

#endif  // SERIAL_MOTOR_DEMO_MSGS__MSG__DETAIL__ROVER_POSE__BUILDER_HPP_
