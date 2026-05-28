// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from turtle_patrol_interfaces:action/ExecuteCircle.idl
// generated code does not contain a copyright notice

#ifndef TURTLE_PATROL_INTERFACES__ACTION__DETAIL__EXECUTE_CIRCLE__STRUCT_H_
#define TURTLE_PATROL_INTERFACES__ACTION__DETAIL__EXECUTE_CIRCLE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in action/ExecuteCircle in the package turtle_patrol_interfaces.
typedef struct turtle_patrol_interfaces__action__ExecuteCircle_Goal
{
  float radius;
} turtle_patrol_interfaces__action__ExecuteCircle_Goal;

// Struct for a sequence of turtle_patrol_interfaces__action__ExecuteCircle_Goal.
typedef struct turtle_patrol_interfaces__action__ExecuteCircle_Goal__Sequence
{
  turtle_patrol_interfaces__action__ExecuteCircle_Goal * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} turtle_patrol_interfaces__action__ExecuteCircle_Goal__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'final_report'
#include "rosidl_runtime_c/string.h"

/// Struct defined in action/ExecuteCircle in the package turtle_patrol_interfaces.
typedef struct turtle_patrol_interfaces__action__ExecuteCircle_Result
{
  bool success;
  rosidl_runtime_c__String final_report;
} turtle_patrol_interfaces__action__ExecuteCircle_Result;

// Struct for a sequence of turtle_patrol_interfaces__action__ExecuteCircle_Result.
typedef struct turtle_patrol_interfaces__action__ExecuteCircle_Result__Sequence
{
  turtle_patrol_interfaces__action__ExecuteCircle_Result * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} turtle_patrol_interfaces__action__ExecuteCircle_Result__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'current_status'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in action/ExecuteCircle in the package turtle_patrol_interfaces.
typedef struct turtle_patrol_interfaces__action__ExecuteCircle_Feedback
{
  float distance_traveled;
  rosidl_runtime_c__String current_status;
} turtle_patrol_interfaces__action__ExecuteCircle_Feedback;

// Struct for a sequence of turtle_patrol_interfaces__action__ExecuteCircle_Feedback.
typedef struct turtle_patrol_interfaces__action__ExecuteCircle_Feedback__Sequence
{
  turtle_patrol_interfaces__action__ExecuteCircle_Feedback * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} turtle_patrol_interfaces__action__ExecuteCircle_Feedback__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'goal'
#include "turtle_patrol_interfaces/action/detail/execute_circle__struct.h"

/// Struct defined in action/ExecuteCircle in the package turtle_patrol_interfaces.
typedef struct turtle_patrol_interfaces__action__ExecuteCircle_SendGoal_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
  turtle_patrol_interfaces__action__ExecuteCircle_Goal goal;
} turtle_patrol_interfaces__action__ExecuteCircle_SendGoal_Request;

// Struct for a sequence of turtle_patrol_interfaces__action__ExecuteCircle_SendGoal_Request.
typedef struct turtle_patrol_interfaces__action__ExecuteCircle_SendGoal_Request__Sequence
{
  turtle_patrol_interfaces__action__ExecuteCircle_SendGoal_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} turtle_patrol_interfaces__action__ExecuteCircle_SendGoal_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.h"

/// Struct defined in action/ExecuteCircle in the package turtle_patrol_interfaces.
typedef struct turtle_patrol_interfaces__action__ExecuteCircle_SendGoal_Response
{
  bool accepted;
  builtin_interfaces__msg__Time stamp;
} turtle_patrol_interfaces__action__ExecuteCircle_SendGoal_Response;

// Struct for a sequence of turtle_patrol_interfaces__action__ExecuteCircle_SendGoal_Response.
typedef struct turtle_patrol_interfaces__action__ExecuteCircle_SendGoal_Response__Sequence
{
  turtle_patrol_interfaces__action__ExecuteCircle_SendGoal_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} turtle_patrol_interfaces__action__ExecuteCircle_SendGoal_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"

/// Struct defined in action/ExecuteCircle in the package turtle_patrol_interfaces.
typedef struct turtle_patrol_interfaces__action__ExecuteCircle_GetResult_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
} turtle_patrol_interfaces__action__ExecuteCircle_GetResult_Request;

// Struct for a sequence of turtle_patrol_interfaces__action__ExecuteCircle_GetResult_Request.
typedef struct turtle_patrol_interfaces__action__ExecuteCircle_GetResult_Request__Sequence
{
  turtle_patrol_interfaces__action__ExecuteCircle_GetResult_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} turtle_patrol_interfaces__action__ExecuteCircle_GetResult_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'result'
// already included above
// #include "turtle_patrol_interfaces/action/detail/execute_circle__struct.h"

/// Struct defined in action/ExecuteCircle in the package turtle_patrol_interfaces.
typedef struct turtle_patrol_interfaces__action__ExecuteCircle_GetResult_Response
{
  int8_t status;
  turtle_patrol_interfaces__action__ExecuteCircle_Result result;
} turtle_patrol_interfaces__action__ExecuteCircle_GetResult_Response;

// Struct for a sequence of turtle_patrol_interfaces__action__ExecuteCircle_GetResult_Response.
typedef struct turtle_patrol_interfaces__action__ExecuteCircle_GetResult_Response__Sequence
{
  turtle_patrol_interfaces__action__ExecuteCircle_GetResult_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} turtle_patrol_interfaces__action__ExecuteCircle_GetResult_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'feedback'
// already included above
// #include "turtle_patrol_interfaces/action/detail/execute_circle__struct.h"

/// Struct defined in action/ExecuteCircle in the package turtle_patrol_interfaces.
typedef struct turtle_patrol_interfaces__action__ExecuteCircle_FeedbackMessage
{
  unique_identifier_msgs__msg__UUID goal_id;
  turtle_patrol_interfaces__action__ExecuteCircle_Feedback feedback;
} turtle_patrol_interfaces__action__ExecuteCircle_FeedbackMessage;

// Struct for a sequence of turtle_patrol_interfaces__action__ExecuteCircle_FeedbackMessage.
typedef struct turtle_patrol_interfaces__action__ExecuteCircle_FeedbackMessage__Sequence
{
  turtle_patrol_interfaces__action__ExecuteCircle_FeedbackMessage * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} turtle_patrol_interfaces__action__ExecuteCircle_FeedbackMessage__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TURTLE_PATROL_INTERFACES__ACTION__DETAIL__EXECUTE_CIRCLE__STRUCT_H_
