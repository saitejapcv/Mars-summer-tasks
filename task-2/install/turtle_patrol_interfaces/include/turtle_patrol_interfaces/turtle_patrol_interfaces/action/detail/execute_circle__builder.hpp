// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from turtle_patrol_interfaces:action/ExecuteCircle.idl
// generated code does not contain a copyright notice

#ifndef TURTLE_PATROL_INTERFACES__ACTION__DETAIL__EXECUTE_CIRCLE__BUILDER_HPP_
#define TURTLE_PATROL_INTERFACES__ACTION__DETAIL__EXECUTE_CIRCLE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "turtle_patrol_interfaces/action/detail/execute_circle__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace turtle_patrol_interfaces
{

namespace action
{

namespace builder
{

class Init_ExecuteCircle_Goal_radius
{
public:
  Init_ExecuteCircle_Goal_radius()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::turtle_patrol_interfaces::action::ExecuteCircle_Goal radius(::turtle_patrol_interfaces::action::ExecuteCircle_Goal::_radius_type arg)
  {
    msg_.radius = std::move(arg);
    return std::move(msg_);
  }

private:
  ::turtle_patrol_interfaces::action::ExecuteCircle_Goal msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::turtle_patrol_interfaces::action::ExecuteCircle_Goal>()
{
  return turtle_patrol_interfaces::action::builder::Init_ExecuteCircle_Goal_radius();
}

}  // namespace turtle_patrol_interfaces


namespace turtle_patrol_interfaces
{

namespace action
{

namespace builder
{

class Init_ExecuteCircle_Result_final_report
{
public:
  explicit Init_ExecuteCircle_Result_final_report(::turtle_patrol_interfaces::action::ExecuteCircle_Result & msg)
  : msg_(msg)
  {}
  ::turtle_patrol_interfaces::action::ExecuteCircle_Result final_report(::turtle_patrol_interfaces::action::ExecuteCircle_Result::_final_report_type arg)
  {
    msg_.final_report = std::move(arg);
    return std::move(msg_);
  }

private:
  ::turtle_patrol_interfaces::action::ExecuteCircle_Result msg_;
};

class Init_ExecuteCircle_Result_success
{
public:
  Init_ExecuteCircle_Result_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ExecuteCircle_Result_final_report success(::turtle_patrol_interfaces::action::ExecuteCircle_Result::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_ExecuteCircle_Result_final_report(msg_);
  }

private:
  ::turtle_patrol_interfaces::action::ExecuteCircle_Result msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::turtle_patrol_interfaces::action::ExecuteCircle_Result>()
{
  return turtle_patrol_interfaces::action::builder::Init_ExecuteCircle_Result_success();
}

}  // namespace turtle_patrol_interfaces


namespace turtle_patrol_interfaces
{

namespace action
{

namespace builder
{

class Init_ExecuteCircle_Feedback_current_status
{
public:
  explicit Init_ExecuteCircle_Feedback_current_status(::turtle_patrol_interfaces::action::ExecuteCircle_Feedback & msg)
  : msg_(msg)
  {}
  ::turtle_patrol_interfaces::action::ExecuteCircle_Feedback current_status(::turtle_patrol_interfaces::action::ExecuteCircle_Feedback::_current_status_type arg)
  {
    msg_.current_status = std::move(arg);
    return std::move(msg_);
  }

private:
  ::turtle_patrol_interfaces::action::ExecuteCircle_Feedback msg_;
};

class Init_ExecuteCircle_Feedback_distance_traveled
{
public:
  Init_ExecuteCircle_Feedback_distance_traveled()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ExecuteCircle_Feedback_current_status distance_traveled(::turtle_patrol_interfaces::action::ExecuteCircle_Feedback::_distance_traveled_type arg)
  {
    msg_.distance_traveled = std::move(arg);
    return Init_ExecuteCircle_Feedback_current_status(msg_);
  }

private:
  ::turtle_patrol_interfaces::action::ExecuteCircle_Feedback msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::turtle_patrol_interfaces::action::ExecuteCircle_Feedback>()
{
  return turtle_patrol_interfaces::action::builder::Init_ExecuteCircle_Feedback_distance_traveled();
}

}  // namespace turtle_patrol_interfaces


namespace turtle_patrol_interfaces
{

namespace action
{

namespace builder
{

class Init_ExecuteCircle_SendGoal_Request_goal
{
public:
  explicit Init_ExecuteCircle_SendGoal_Request_goal(::turtle_patrol_interfaces::action::ExecuteCircle_SendGoal_Request & msg)
  : msg_(msg)
  {}
  ::turtle_patrol_interfaces::action::ExecuteCircle_SendGoal_Request goal(::turtle_patrol_interfaces::action::ExecuteCircle_SendGoal_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::turtle_patrol_interfaces::action::ExecuteCircle_SendGoal_Request msg_;
};

class Init_ExecuteCircle_SendGoal_Request_goal_id
{
public:
  Init_ExecuteCircle_SendGoal_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ExecuteCircle_SendGoal_Request_goal goal_id(::turtle_patrol_interfaces::action::ExecuteCircle_SendGoal_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_ExecuteCircle_SendGoal_Request_goal(msg_);
  }

private:
  ::turtle_patrol_interfaces::action::ExecuteCircle_SendGoal_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::turtle_patrol_interfaces::action::ExecuteCircle_SendGoal_Request>()
{
  return turtle_patrol_interfaces::action::builder::Init_ExecuteCircle_SendGoal_Request_goal_id();
}

}  // namespace turtle_patrol_interfaces


namespace turtle_patrol_interfaces
{

namespace action
{

namespace builder
{

class Init_ExecuteCircle_SendGoal_Response_stamp
{
public:
  explicit Init_ExecuteCircle_SendGoal_Response_stamp(::turtle_patrol_interfaces::action::ExecuteCircle_SendGoal_Response & msg)
  : msg_(msg)
  {}
  ::turtle_patrol_interfaces::action::ExecuteCircle_SendGoal_Response stamp(::turtle_patrol_interfaces::action::ExecuteCircle_SendGoal_Response::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::turtle_patrol_interfaces::action::ExecuteCircle_SendGoal_Response msg_;
};

class Init_ExecuteCircle_SendGoal_Response_accepted
{
public:
  Init_ExecuteCircle_SendGoal_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ExecuteCircle_SendGoal_Response_stamp accepted(::turtle_patrol_interfaces::action::ExecuteCircle_SendGoal_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_ExecuteCircle_SendGoal_Response_stamp(msg_);
  }

private:
  ::turtle_patrol_interfaces::action::ExecuteCircle_SendGoal_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::turtle_patrol_interfaces::action::ExecuteCircle_SendGoal_Response>()
{
  return turtle_patrol_interfaces::action::builder::Init_ExecuteCircle_SendGoal_Response_accepted();
}

}  // namespace turtle_patrol_interfaces


namespace turtle_patrol_interfaces
{

namespace action
{

namespace builder
{

class Init_ExecuteCircle_GetResult_Request_goal_id
{
public:
  Init_ExecuteCircle_GetResult_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::turtle_patrol_interfaces::action::ExecuteCircle_GetResult_Request goal_id(::turtle_patrol_interfaces::action::ExecuteCircle_GetResult_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::turtle_patrol_interfaces::action::ExecuteCircle_GetResult_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::turtle_patrol_interfaces::action::ExecuteCircle_GetResult_Request>()
{
  return turtle_patrol_interfaces::action::builder::Init_ExecuteCircle_GetResult_Request_goal_id();
}

}  // namespace turtle_patrol_interfaces


namespace turtle_patrol_interfaces
{

namespace action
{

namespace builder
{

class Init_ExecuteCircle_GetResult_Response_result
{
public:
  explicit Init_ExecuteCircle_GetResult_Response_result(::turtle_patrol_interfaces::action::ExecuteCircle_GetResult_Response & msg)
  : msg_(msg)
  {}
  ::turtle_patrol_interfaces::action::ExecuteCircle_GetResult_Response result(::turtle_patrol_interfaces::action::ExecuteCircle_GetResult_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::turtle_patrol_interfaces::action::ExecuteCircle_GetResult_Response msg_;
};

class Init_ExecuteCircle_GetResult_Response_status
{
public:
  Init_ExecuteCircle_GetResult_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ExecuteCircle_GetResult_Response_result status(::turtle_patrol_interfaces::action::ExecuteCircle_GetResult_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_ExecuteCircle_GetResult_Response_result(msg_);
  }

private:
  ::turtle_patrol_interfaces::action::ExecuteCircle_GetResult_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::turtle_patrol_interfaces::action::ExecuteCircle_GetResult_Response>()
{
  return turtle_patrol_interfaces::action::builder::Init_ExecuteCircle_GetResult_Response_status();
}

}  // namespace turtle_patrol_interfaces


namespace turtle_patrol_interfaces
{

namespace action
{

namespace builder
{

class Init_ExecuteCircle_FeedbackMessage_feedback
{
public:
  explicit Init_ExecuteCircle_FeedbackMessage_feedback(::turtle_patrol_interfaces::action::ExecuteCircle_FeedbackMessage & msg)
  : msg_(msg)
  {}
  ::turtle_patrol_interfaces::action::ExecuteCircle_FeedbackMessage feedback(::turtle_patrol_interfaces::action::ExecuteCircle_FeedbackMessage::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::turtle_patrol_interfaces::action::ExecuteCircle_FeedbackMessage msg_;
};

class Init_ExecuteCircle_FeedbackMessage_goal_id
{
public:
  Init_ExecuteCircle_FeedbackMessage_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ExecuteCircle_FeedbackMessage_feedback goal_id(::turtle_patrol_interfaces::action::ExecuteCircle_FeedbackMessage::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_ExecuteCircle_FeedbackMessage_feedback(msg_);
  }

private:
  ::turtle_patrol_interfaces::action::ExecuteCircle_FeedbackMessage msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::turtle_patrol_interfaces::action::ExecuteCircle_FeedbackMessage>()
{
  return turtle_patrol_interfaces::action::builder::Init_ExecuteCircle_FeedbackMessage_goal_id();
}

}  // namespace turtle_patrol_interfaces

#endif  // TURTLE_PATROL_INTERFACES__ACTION__DETAIL__EXECUTE_CIRCLE__BUILDER_HPP_
