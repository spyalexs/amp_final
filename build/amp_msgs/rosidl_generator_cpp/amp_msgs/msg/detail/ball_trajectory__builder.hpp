// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from amp_msgs:msg/BallTrajectory.idl
// generated code does not contain a copyright notice

#ifndef AMP_MSGS__MSG__DETAIL__BALL_TRAJECTORY__BUILDER_HPP_
#define AMP_MSGS__MSG__DETAIL__BALL_TRAJECTORY__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "amp_msgs/msg/detail/ball_trajectory__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace amp_msgs
{

namespace msg
{

namespace builder
{

class Init_BallTrajectory_landing_height
{
public:
  explicit Init_BallTrajectory_landing_height(::amp_msgs::msg::BallTrajectory & msg)
  : msg_(msg)
  {}
  ::amp_msgs::msg::BallTrajectory landing_height(::amp_msgs::msg::BallTrajectory::_landing_height_type arg)
  {
    msg_.landing_height = std::move(arg);
    return std::move(msg_);
  }

private:
  ::amp_msgs::msg::BallTrajectory msg_;
};

class Init_BallTrajectory_current_mass
{
public:
  explicit Init_BallTrajectory_current_mass(::amp_msgs::msg::BallTrajectory & msg)
  : msg_(msg)
  {}
  Init_BallTrajectory_landing_height current_mass(::amp_msgs::msg::BallTrajectory::_current_mass_type arg)
  {
    msg_.current_mass = std::move(arg);
    return Init_BallTrajectory_landing_height(msg_);
  }

private:
  ::amp_msgs::msg::BallTrajectory msg_;
};

class Init_BallTrajectory_current_damping_z
{
public:
  explicit Init_BallTrajectory_current_damping_z(::amp_msgs::msg::BallTrajectory & msg)
  : msg_(msg)
  {}
  Init_BallTrajectory_current_mass current_damping_z(::amp_msgs::msg::BallTrajectory::_current_damping_z_type arg)
  {
    msg_.current_damping_z = std::move(arg);
    return Init_BallTrajectory_current_mass(msg_);
  }

private:
  ::amp_msgs::msg::BallTrajectory msg_;
};

class Init_BallTrajectory_current_damping_y
{
public:
  explicit Init_BallTrajectory_current_damping_y(::amp_msgs::msg::BallTrajectory & msg)
  : msg_(msg)
  {}
  Init_BallTrajectory_current_damping_z current_damping_y(::amp_msgs::msg::BallTrajectory::_current_damping_y_type arg)
  {
    msg_.current_damping_y = std::move(arg);
    return Init_BallTrajectory_current_damping_z(msg_);
  }

private:
  ::amp_msgs::msg::BallTrajectory msg_;
};

class Init_BallTrajectory_current_damping_x
{
public:
  explicit Init_BallTrajectory_current_damping_x(::amp_msgs::msg::BallTrajectory & msg)
  : msg_(msg)
  {}
  Init_BallTrajectory_current_damping_y current_damping_x(::amp_msgs::msg::BallTrajectory::_current_damping_x_type arg)
  {
    msg_.current_damping_x = std::move(arg);
    return Init_BallTrajectory_current_damping_y(msg_);
  }

private:
  ::amp_msgs::msg::BallTrajectory msg_;
};

class Init_BallTrajectory_current_vel_z
{
public:
  explicit Init_BallTrajectory_current_vel_z(::amp_msgs::msg::BallTrajectory & msg)
  : msg_(msg)
  {}
  Init_BallTrajectory_current_damping_x current_vel_z(::amp_msgs::msg::BallTrajectory::_current_vel_z_type arg)
  {
    msg_.current_vel_z = std::move(arg);
    return Init_BallTrajectory_current_damping_x(msg_);
  }

private:
  ::amp_msgs::msg::BallTrajectory msg_;
};

class Init_BallTrajectory_current_vel_y
{
public:
  explicit Init_BallTrajectory_current_vel_y(::amp_msgs::msg::BallTrajectory & msg)
  : msg_(msg)
  {}
  Init_BallTrajectory_current_vel_z current_vel_y(::amp_msgs::msg::BallTrajectory::_current_vel_y_type arg)
  {
    msg_.current_vel_y = std::move(arg);
    return Init_BallTrajectory_current_vel_z(msg_);
  }

private:
  ::amp_msgs::msg::BallTrajectory msg_;
};

class Init_BallTrajectory_current_vel_x
{
public:
  explicit Init_BallTrajectory_current_vel_x(::amp_msgs::msg::BallTrajectory & msg)
  : msg_(msg)
  {}
  Init_BallTrajectory_current_vel_y current_vel_x(::amp_msgs::msg::BallTrajectory::_current_vel_x_type arg)
  {
    msg_.current_vel_x = std::move(arg);
    return Init_BallTrajectory_current_vel_y(msg_);
  }

private:
  ::amp_msgs::msg::BallTrajectory msg_;
};

class Init_BallTrajectory_current_pos_z
{
public:
  explicit Init_BallTrajectory_current_pos_z(::amp_msgs::msg::BallTrajectory & msg)
  : msg_(msg)
  {}
  Init_BallTrajectory_current_vel_x current_pos_z(::amp_msgs::msg::BallTrajectory::_current_pos_z_type arg)
  {
    msg_.current_pos_z = std::move(arg);
    return Init_BallTrajectory_current_vel_x(msg_);
  }

private:
  ::amp_msgs::msg::BallTrajectory msg_;
};

class Init_BallTrajectory_current_pos_y
{
public:
  explicit Init_BallTrajectory_current_pos_y(::amp_msgs::msg::BallTrajectory & msg)
  : msg_(msg)
  {}
  Init_BallTrajectory_current_pos_z current_pos_y(::amp_msgs::msg::BallTrajectory::_current_pos_y_type arg)
  {
    msg_.current_pos_y = std::move(arg);
    return Init_BallTrajectory_current_pos_z(msg_);
  }

private:
  ::amp_msgs::msg::BallTrajectory msg_;
};

class Init_BallTrajectory_current_pos_x
{
public:
  Init_BallTrajectory_current_pos_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_BallTrajectory_current_pos_y current_pos_x(::amp_msgs::msg::BallTrajectory::_current_pos_x_type arg)
  {
    msg_.current_pos_x = std::move(arg);
    return Init_BallTrajectory_current_pos_y(msg_);
  }

private:
  ::amp_msgs::msg::BallTrajectory msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::amp_msgs::msg::BallTrajectory>()
{
  return amp_msgs::msg::builder::Init_BallTrajectory_current_pos_x();
}

}  // namespace amp_msgs

#endif  // AMP_MSGS__MSG__DETAIL__BALL_TRAJECTORY__BUILDER_HPP_
