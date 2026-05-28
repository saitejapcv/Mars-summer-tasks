// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from turtle_patrol_interfaces:action/ExecuteCircle.idl
// generated code does not contain a copyright notice
#include "turtle_patrol_interfaces/action/detail/execute_circle__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
turtle_patrol_interfaces__action__ExecuteCircle_Goal__init(turtle_patrol_interfaces__action__ExecuteCircle_Goal * msg)
{
  if (!msg) {
    return false;
  }
  // radius
  return true;
}

void
turtle_patrol_interfaces__action__ExecuteCircle_Goal__fini(turtle_patrol_interfaces__action__ExecuteCircle_Goal * msg)
{
  if (!msg) {
    return;
  }
  // radius
}

bool
turtle_patrol_interfaces__action__ExecuteCircle_Goal__are_equal(const turtle_patrol_interfaces__action__ExecuteCircle_Goal * lhs, const turtle_patrol_interfaces__action__ExecuteCircle_Goal * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // radius
  if (lhs->radius != rhs->radius) {
    return false;
  }
  return true;
}

bool
turtle_patrol_interfaces__action__ExecuteCircle_Goal__copy(
  const turtle_patrol_interfaces__action__ExecuteCircle_Goal * input,
  turtle_patrol_interfaces__action__ExecuteCircle_Goal * output)
{
  if (!input || !output) {
    return false;
  }
  // radius
  output->radius = input->radius;
  return true;
}

turtle_patrol_interfaces__action__ExecuteCircle_Goal *
turtle_patrol_interfaces__action__ExecuteCircle_Goal__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  turtle_patrol_interfaces__action__ExecuteCircle_Goal * msg = (turtle_patrol_interfaces__action__ExecuteCircle_Goal *)allocator.allocate(sizeof(turtle_patrol_interfaces__action__ExecuteCircle_Goal), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(turtle_patrol_interfaces__action__ExecuteCircle_Goal));
  bool success = turtle_patrol_interfaces__action__ExecuteCircle_Goal__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
turtle_patrol_interfaces__action__ExecuteCircle_Goal__destroy(turtle_patrol_interfaces__action__ExecuteCircle_Goal * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    turtle_patrol_interfaces__action__ExecuteCircle_Goal__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
turtle_patrol_interfaces__action__ExecuteCircle_Goal__Sequence__init(turtle_patrol_interfaces__action__ExecuteCircle_Goal__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  turtle_patrol_interfaces__action__ExecuteCircle_Goal * data = NULL;

  if (size) {
    data = (turtle_patrol_interfaces__action__ExecuteCircle_Goal *)allocator.zero_allocate(size, sizeof(turtle_patrol_interfaces__action__ExecuteCircle_Goal), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = turtle_patrol_interfaces__action__ExecuteCircle_Goal__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        turtle_patrol_interfaces__action__ExecuteCircle_Goal__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
turtle_patrol_interfaces__action__ExecuteCircle_Goal__Sequence__fini(turtle_patrol_interfaces__action__ExecuteCircle_Goal__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      turtle_patrol_interfaces__action__ExecuteCircle_Goal__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

turtle_patrol_interfaces__action__ExecuteCircle_Goal__Sequence *
turtle_patrol_interfaces__action__ExecuteCircle_Goal__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  turtle_patrol_interfaces__action__ExecuteCircle_Goal__Sequence * array = (turtle_patrol_interfaces__action__ExecuteCircle_Goal__Sequence *)allocator.allocate(sizeof(turtle_patrol_interfaces__action__ExecuteCircle_Goal__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = turtle_patrol_interfaces__action__ExecuteCircle_Goal__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
turtle_patrol_interfaces__action__ExecuteCircle_Goal__Sequence__destroy(turtle_patrol_interfaces__action__ExecuteCircle_Goal__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    turtle_patrol_interfaces__action__ExecuteCircle_Goal__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
turtle_patrol_interfaces__action__ExecuteCircle_Goal__Sequence__are_equal(const turtle_patrol_interfaces__action__ExecuteCircle_Goal__Sequence * lhs, const turtle_patrol_interfaces__action__ExecuteCircle_Goal__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!turtle_patrol_interfaces__action__ExecuteCircle_Goal__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
turtle_patrol_interfaces__action__ExecuteCircle_Goal__Sequence__copy(
  const turtle_patrol_interfaces__action__ExecuteCircle_Goal__Sequence * input,
  turtle_patrol_interfaces__action__ExecuteCircle_Goal__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(turtle_patrol_interfaces__action__ExecuteCircle_Goal);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    turtle_patrol_interfaces__action__ExecuteCircle_Goal * data =
      (turtle_patrol_interfaces__action__ExecuteCircle_Goal *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!turtle_patrol_interfaces__action__ExecuteCircle_Goal__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          turtle_patrol_interfaces__action__ExecuteCircle_Goal__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!turtle_patrol_interfaces__action__ExecuteCircle_Goal__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `final_report`
#include "rosidl_runtime_c/string_functions.h"

bool
turtle_patrol_interfaces__action__ExecuteCircle_Result__init(turtle_patrol_interfaces__action__ExecuteCircle_Result * msg)
{
  if (!msg) {
    return false;
  }
  // success
  // final_report
  if (!rosidl_runtime_c__String__init(&msg->final_report)) {
    turtle_patrol_interfaces__action__ExecuteCircle_Result__fini(msg);
    return false;
  }
  return true;
}

void
turtle_patrol_interfaces__action__ExecuteCircle_Result__fini(turtle_patrol_interfaces__action__ExecuteCircle_Result * msg)
{
  if (!msg) {
    return;
  }
  // success
  // final_report
  rosidl_runtime_c__String__fini(&msg->final_report);
}

bool
turtle_patrol_interfaces__action__ExecuteCircle_Result__are_equal(const turtle_patrol_interfaces__action__ExecuteCircle_Result * lhs, const turtle_patrol_interfaces__action__ExecuteCircle_Result * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // success
  if (lhs->success != rhs->success) {
    return false;
  }
  // final_report
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->final_report), &(rhs->final_report)))
  {
    return false;
  }
  return true;
}

bool
turtle_patrol_interfaces__action__ExecuteCircle_Result__copy(
  const turtle_patrol_interfaces__action__ExecuteCircle_Result * input,
  turtle_patrol_interfaces__action__ExecuteCircle_Result * output)
{
  if (!input || !output) {
    return false;
  }
  // success
  output->success = input->success;
  // final_report
  if (!rosidl_runtime_c__String__copy(
      &(input->final_report), &(output->final_report)))
  {
    return false;
  }
  return true;
}

turtle_patrol_interfaces__action__ExecuteCircle_Result *
turtle_patrol_interfaces__action__ExecuteCircle_Result__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  turtle_patrol_interfaces__action__ExecuteCircle_Result * msg = (turtle_patrol_interfaces__action__ExecuteCircle_Result *)allocator.allocate(sizeof(turtle_patrol_interfaces__action__ExecuteCircle_Result), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(turtle_patrol_interfaces__action__ExecuteCircle_Result));
  bool success = turtle_patrol_interfaces__action__ExecuteCircle_Result__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
turtle_patrol_interfaces__action__ExecuteCircle_Result__destroy(turtle_patrol_interfaces__action__ExecuteCircle_Result * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    turtle_patrol_interfaces__action__ExecuteCircle_Result__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
turtle_patrol_interfaces__action__ExecuteCircle_Result__Sequence__init(turtle_patrol_interfaces__action__ExecuteCircle_Result__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  turtle_patrol_interfaces__action__ExecuteCircle_Result * data = NULL;

  if (size) {
    data = (turtle_patrol_interfaces__action__ExecuteCircle_Result *)allocator.zero_allocate(size, sizeof(turtle_patrol_interfaces__action__ExecuteCircle_Result), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = turtle_patrol_interfaces__action__ExecuteCircle_Result__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        turtle_patrol_interfaces__action__ExecuteCircle_Result__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
turtle_patrol_interfaces__action__ExecuteCircle_Result__Sequence__fini(turtle_patrol_interfaces__action__ExecuteCircle_Result__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      turtle_patrol_interfaces__action__ExecuteCircle_Result__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

turtle_patrol_interfaces__action__ExecuteCircle_Result__Sequence *
turtle_patrol_interfaces__action__ExecuteCircle_Result__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  turtle_patrol_interfaces__action__ExecuteCircle_Result__Sequence * array = (turtle_patrol_interfaces__action__ExecuteCircle_Result__Sequence *)allocator.allocate(sizeof(turtle_patrol_interfaces__action__ExecuteCircle_Result__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = turtle_patrol_interfaces__action__ExecuteCircle_Result__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
turtle_patrol_interfaces__action__ExecuteCircle_Result__Sequence__destroy(turtle_patrol_interfaces__action__ExecuteCircle_Result__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    turtle_patrol_interfaces__action__ExecuteCircle_Result__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
turtle_patrol_interfaces__action__ExecuteCircle_Result__Sequence__are_equal(const turtle_patrol_interfaces__action__ExecuteCircle_Result__Sequence * lhs, const turtle_patrol_interfaces__action__ExecuteCircle_Result__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!turtle_patrol_interfaces__action__ExecuteCircle_Result__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
turtle_patrol_interfaces__action__ExecuteCircle_Result__Sequence__copy(
  const turtle_patrol_interfaces__action__ExecuteCircle_Result__Sequence * input,
  turtle_patrol_interfaces__action__ExecuteCircle_Result__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(turtle_patrol_interfaces__action__ExecuteCircle_Result);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    turtle_patrol_interfaces__action__ExecuteCircle_Result * data =
      (turtle_patrol_interfaces__action__ExecuteCircle_Result *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!turtle_patrol_interfaces__action__ExecuteCircle_Result__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          turtle_patrol_interfaces__action__ExecuteCircle_Result__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!turtle_patrol_interfaces__action__ExecuteCircle_Result__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `current_status`
// already included above
// #include "rosidl_runtime_c/string_functions.h"

bool
turtle_patrol_interfaces__action__ExecuteCircle_Feedback__init(turtle_patrol_interfaces__action__ExecuteCircle_Feedback * msg)
{
  if (!msg) {
    return false;
  }
  // distance_traveled
  // current_status
  if (!rosidl_runtime_c__String__init(&msg->current_status)) {
    turtle_patrol_interfaces__action__ExecuteCircle_Feedback__fini(msg);
    return false;
  }
  return true;
}

void
turtle_patrol_interfaces__action__ExecuteCircle_Feedback__fini(turtle_patrol_interfaces__action__ExecuteCircle_Feedback * msg)
{
  if (!msg) {
    return;
  }
  // distance_traveled
  // current_status
  rosidl_runtime_c__String__fini(&msg->current_status);
}

bool
turtle_patrol_interfaces__action__ExecuteCircle_Feedback__are_equal(const turtle_patrol_interfaces__action__ExecuteCircle_Feedback * lhs, const turtle_patrol_interfaces__action__ExecuteCircle_Feedback * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // distance_traveled
  if (lhs->distance_traveled != rhs->distance_traveled) {
    return false;
  }
  // current_status
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->current_status), &(rhs->current_status)))
  {
    return false;
  }
  return true;
}

bool
turtle_patrol_interfaces__action__ExecuteCircle_Feedback__copy(
  const turtle_patrol_interfaces__action__ExecuteCircle_Feedback * input,
  turtle_patrol_interfaces__action__ExecuteCircle_Feedback * output)
{
  if (!input || !output) {
    return false;
  }
  // distance_traveled
  output->distance_traveled = input->distance_traveled;
  // current_status
  if (!rosidl_runtime_c__String__copy(
      &(input->current_status), &(output->current_status)))
  {
    return false;
  }
  return true;
}

turtle_patrol_interfaces__action__ExecuteCircle_Feedback *
turtle_patrol_interfaces__action__ExecuteCircle_Feedback__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  turtle_patrol_interfaces__action__ExecuteCircle_Feedback * msg = (turtle_patrol_interfaces__action__ExecuteCircle_Feedback *)allocator.allocate(sizeof(turtle_patrol_interfaces__action__ExecuteCircle_Feedback), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(turtle_patrol_interfaces__action__ExecuteCircle_Feedback));
  bool success = turtle_patrol_interfaces__action__ExecuteCircle_Feedback__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
turtle_patrol_interfaces__action__ExecuteCircle_Feedback__destroy(turtle_patrol_interfaces__action__ExecuteCircle_Feedback * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    turtle_patrol_interfaces__action__ExecuteCircle_Feedback__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
turtle_patrol_interfaces__action__ExecuteCircle_Feedback__Sequence__init(turtle_patrol_interfaces__action__ExecuteCircle_Feedback__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  turtle_patrol_interfaces__action__ExecuteCircle_Feedback * data = NULL;

  if (size) {
    data = (turtle_patrol_interfaces__action__ExecuteCircle_Feedback *)allocator.zero_allocate(size, sizeof(turtle_patrol_interfaces__action__ExecuteCircle_Feedback), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = turtle_patrol_interfaces__action__ExecuteCircle_Feedback__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        turtle_patrol_interfaces__action__ExecuteCircle_Feedback__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
turtle_patrol_interfaces__action__ExecuteCircle_Feedback__Sequence__fini(turtle_patrol_interfaces__action__ExecuteCircle_Feedback__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      turtle_patrol_interfaces__action__ExecuteCircle_Feedback__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

turtle_patrol_interfaces__action__ExecuteCircle_Feedback__Sequence *
turtle_patrol_interfaces__action__ExecuteCircle_Feedback__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  turtle_patrol_interfaces__action__ExecuteCircle_Feedback__Sequence * array = (turtle_patrol_interfaces__action__ExecuteCircle_Feedback__Sequence *)allocator.allocate(sizeof(turtle_patrol_interfaces__action__ExecuteCircle_Feedback__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = turtle_patrol_interfaces__action__ExecuteCircle_Feedback__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
turtle_patrol_interfaces__action__ExecuteCircle_Feedback__Sequence__destroy(turtle_patrol_interfaces__action__ExecuteCircle_Feedback__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    turtle_patrol_interfaces__action__ExecuteCircle_Feedback__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
turtle_patrol_interfaces__action__ExecuteCircle_Feedback__Sequence__are_equal(const turtle_patrol_interfaces__action__ExecuteCircle_Feedback__Sequence * lhs, const turtle_patrol_interfaces__action__ExecuteCircle_Feedback__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!turtle_patrol_interfaces__action__ExecuteCircle_Feedback__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
turtle_patrol_interfaces__action__ExecuteCircle_Feedback__Sequence__copy(
  const turtle_patrol_interfaces__action__ExecuteCircle_Feedback__Sequence * input,
  turtle_patrol_interfaces__action__ExecuteCircle_Feedback__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(turtle_patrol_interfaces__action__ExecuteCircle_Feedback);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    turtle_patrol_interfaces__action__ExecuteCircle_Feedback * data =
      (turtle_patrol_interfaces__action__ExecuteCircle_Feedback *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!turtle_patrol_interfaces__action__ExecuteCircle_Feedback__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          turtle_patrol_interfaces__action__ExecuteCircle_Feedback__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!turtle_patrol_interfaces__action__ExecuteCircle_Feedback__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
#include "unique_identifier_msgs/msg/detail/uuid__functions.h"
// Member `goal`
// already included above
// #include "turtle_patrol_interfaces/action/detail/execute_circle__functions.h"

bool
turtle_patrol_interfaces__action__ExecuteCircle_SendGoal_Request__init(turtle_patrol_interfaces__action__ExecuteCircle_SendGoal_Request * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    turtle_patrol_interfaces__action__ExecuteCircle_SendGoal_Request__fini(msg);
    return false;
  }
  // goal
  if (!turtle_patrol_interfaces__action__ExecuteCircle_Goal__init(&msg->goal)) {
    turtle_patrol_interfaces__action__ExecuteCircle_SendGoal_Request__fini(msg);
    return false;
  }
  return true;
}

void
turtle_patrol_interfaces__action__ExecuteCircle_SendGoal_Request__fini(turtle_patrol_interfaces__action__ExecuteCircle_SendGoal_Request * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
  // goal
  turtle_patrol_interfaces__action__ExecuteCircle_Goal__fini(&msg->goal);
}

bool
turtle_patrol_interfaces__action__ExecuteCircle_SendGoal_Request__are_equal(const turtle_patrol_interfaces__action__ExecuteCircle_SendGoal_Request * lhs, const turtle_patrol_interfaces__action__ExecuteCircle_SendGoal_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  // goal
  if (!turtle_patrol_interfaces__action__ExecuteCircle_Goal__are_equal(
      &(lhs->goal), &(rhs->goal)))
  {
    return false;
  }
  return true;
}

bool
turtle_patrol_interfaces__action__ExecuteCircle_SendGoal_Request__copy(
  const turtle_patrol_interfaces__action__ExecuteCircle_SendGoal_Request * input,
  turtle_patrol_interfaces__action__ExecuteCircle_SendGoal_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  // goal
  if (!turtle_patrol_interfaces__action__ExecuteCircle_Goal__copy(
      &(input->goal), &(output->goal)))
  {
    return false;
  }
  return true;
}

turtle_patrol_interfaces__action__ExecuteCircle_SendGoal_Request *
turtle_patrol_interfaces__action__ExecuteCircle_SendGoal_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  turtle_patrol_interfaces__action__ExecuteCircle_SendGoal_Request * msg = (turtle_patrol_interfaces__action__ExecuteCircle_SendGoal_Request *)allocator.allocate(sizeof(turtle_patrol_interfaces__action__ExecuteCircle_SendGoal_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(turtle_patrol_interfaces__action__ExecuteCircle_SendGoal_Request));
  bool success = turtle_patrol_interfaces__action__ExecuteCircle_SendGoal_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
turtle_patrol_interfaces__action__ExecuteCircle_SendGoal_Request__destroy(turtle_patrol_interfaces__action__ExecuteCircle_SendGoal_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    turtle_patrol_interfaces__action__ExecuteCircle_SendGoal_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
turtle_patrol_interfaces__action__ExecuteCircle_SendGoal_Request__Sequence__init(turtle_patrol_interfaces__action__ExecuteCircle_SendGoal_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  turtle_patrol_interfaces__action__ExecuteCircle_SendGoal_Request * data = NULL;

  if (size) {
    data = (turtle_patrol_interfaces__action__ExecuteCircle_SendGoal_Request *)allocator.zero_allocate(size, sizeof(turtle_patrol_interfaces__action__ExecuteCircle_SendGoal_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = turtle_patrol_interfaces__action__ExecuteCircle_SendGoal_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        turtle_patrol_interfaces__action__ExecuteCircle_SendGoal_Request__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
turtle_patrol_interfaces__action__ExecuteCircle_SendGoal_Request__Sequence__fini(turtle_patrol_interfaces__action__ExecuteCircle_SendGoal_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      turtle_patrol_interfaces__action__ExecuteCircle_SendGoal_Request__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

turtle_patrol_interfaces__action__ExecuteCircle_SendGoal_Request__Sequence *
turtle_patrol_interfaces__action__ExecuteCircle_SendGoal_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  turtle_patrol_interfaces__action__ExecuteCircle_SendGoal_Request__Sequence * array = (turtle_patrol_interfaces__action__ExecuteCircle_SendGoal_Request__Sequence *)allocator.allocate(sizeof(turtle_patrol_interfaces__action__ExecuteCircle_SendGoal_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = turtle_patrol_interfaces__action__ExecuteCircle_SendGoal_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
turtle_patrol_interfaces__action__ExecuteCircle_SendGoal_Request__Sequence__destroy(turtle_patrol_interfaces__action__ExecuteCircle_SendGoal_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    turtle_patrol_interfaces__action__ExecuteCircle_SendGoal_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
turtle_patrol_interfaces__action__ExecuteCircle_SendGoal_Request__Sequence__are_equal(const turtle_patrol_interfaces__action__ExecuteCircle_SendGoal_Request__Sequence * lhs, const turtle_patrol_interfaces__action__ExecuteCircle_SendGoal_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!turtle_patrol_interfaces__action__ExecuteCircle_SendGoal_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
turtle_patrol_interfaces__action__ExecuteCircle_SendGoal_Request__Sequence__copy(
  const turtle_patrol_interfaces__action__ExecuteCircle_SendGoal_Request__Sequence * input,
  turtle_patrol_interfaces__action__ExecuteCircle_SendGoal_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(turtle_patrol_interfaces__action__ExecuteCircle_SendGoal_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    turtle_patrol_interfaces__action__ExecuteCircle_SendGoal_Request * data =
      (turtle_patrol_interfaces__action__ExecuteCircle_SendGoal_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!turtle_patrol_interfaces__action__ExecuteCircle_SendGoal_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          turtle_patrol_interfaces__action__ExecuteCircle_SendGoal_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!turtle_patrol_interfaces__action__ExecuteCircle_SendGoal_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `stamp`
#include "builtin_interfaces/msg/detail/time__functions.h"

bool
turtle_patrol_interfaces__action__ExecuteCircle_SendGoal_Response__init(turtle_patrol_interfaces__action__ExecuteCircle_SendGoal_Response * msg)
{
  if (!msg) {
    return false;
  }
  // accepted
  // stamp
  if (!builtin_interfaces__msg__Time__init(&msg->stamp)) {
    turtle_patrol_interfaces__action__ExecuteCircle_SendGoal_Response__fini(msg);
    return false;
  }
  return true;
}

void
turtle_patrol_interfaces__action__ExecuteCircle_SendGoal_Response__fini(turtle_patrol_interfaces__action__ExecuteCircle_SendGoal_Response * msg)
{
  if (!msg) {
    return;
  }
  // accepted
  // stamp
  builtin_interfaces__msg__Time__fini(&msg->stamp);
}

bool
turtle_patrol_interfaces__action__ExecuteCircle_SendGoal_Response__are_equal(const turtle_patrol_interfaces__action__ExecuteCircle_SendGoal_Response * lhs, const turtle_patrol_interfaces__action__ExecuteCircle_SendGoal_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // accepted
  if (lhs->accepted != rhs->accepted) {
    return false;
  }
  // stamp
  if (!builtin_interfaces__msg__Time__are_equal(
      &(lhs->stamp), &(rhs->stamp)))
  {
    return false;
  }
  return true;
}

bool
turtle_patrol_interfaces__action__ExecuteCircle_SendGoal_Response__copy(
  const turtle_patrol_interfaces__action__ExecuteCircle_SendGoal_Response * input,
  turtle_patrol_interfaces__action__ExecuteCircle_SendGoal_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // accepted
  output->accepted = input->accepted;
  // stamp
  if (!builtin_interfaces__msg__Time__copy(
      &(input->stamp), &(output->stamp)))
  {
    return false;
  }
  return true;
}

turtle_patrol_interfaces__action__ExecuteCircle_SendGoal_Response *
turtle_patrol_interfaces__action__ExecuteCircle_SendGoal_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  turtle_patrol_interfaces__action__ExecuteCircle_SendGoal_Response * msg = (turtle_patrol_interfaces__action__ExecuteCircle_SendGoal_Response *)allocator.allocate(sizeof(turtle_patrol_interfaces__action__ExecuteCircle_SendGoal_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(turtle_patrol_interfaces__action__ExecuteCircle_SendGoal_Response));
  bool success = turtle_patrol_interfaces__action__ExecuteCircle_SendGoal_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
turtle_patrol_interfaces__action__ExecuteCircle_SendGoal_Response__destroy(turtle_patrol_interfaces__action__ExecuteCircle_SendGoal_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    turtle_patrol_interfaces__action__ExecuteCircle_SendGoal_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
turtle_patrol_interfaces__action__ExecuteCircle_SendGoal_Response__Sequence__init(turtle_patrol_interfaces__action__ExecuteCircle_SendGoal_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  turtle_patrol_interfaces__action__ExecuteCircle_SendGoal_Response * data = NULL;

  if (size) {
    data = (turtle_patrol_interfaces__action__ExecuteCircle_SendGoal_Response *)allocator.zero_allocate(size, sizeof(turtle_patrol_interfaces__action__ExecuteCircle_SendGoal_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = turtle_patrol_interfaces__action__ExecuteCircle_SendGoal_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        turtle_patrol_interfaces__action__ExecuteCircle_SendGoal_Response__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
turtle_patrol_interfaces__action__ExecuteCircle_SendGoal_Response__Sequence__fini(turtle_patrol_interfaces__action__ExecuteCircle_SendGoal_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      turtle_patrol_interfaces__action__ExecuteCircle_SendGoal_Response__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

turtle_patrol_interfaces__action__ExecuteCircle_SendGoal_Response__Sequence *
turtle_patrol_interfaces__action__ExecuteCircle_SendGoal_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  turtle_patrol_interfaces__action__ExecuteCircle_SendGoal_Response__Sequence * array = (turtle_patrol_interfaces__action__ExecuteCircle_SendGoal_Response__Sequence *)allocator.allocate(sizeof(turtle_patrol_interfaces__action__ExecuteCircle_SendGoal_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = turtle_patrol_interfaces__action__ExecuteCircle_SendGoal_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
turtle_patrol_interfaces__action__ExecuteCircle_SendGoal_Response__Sequence__destroy(turtle_patrol_interfaces__action__ExecuteCircle_SendGoal_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    turtle_patrol_interfaces__action__ExecuteCircle_SendGoal_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
turtle_patrol_interfaces__action__ExecuteCircle_SendGoal_Response__Sequence__are_equal(const turtle_patrol_interfaces__action__ExecuteCircle_SendGoal_Response__Sequence * lhs, const turtle_patrol_interfaces__action__ExecuteCircle_SendGoal_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!turtle_patrol_interfaces__action__ExecuteCircle_SendGoal_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
turtle_patrol_interfaces__action__ExecuteCircle_SendGoal_Response__Sequence__copy(
  const turtle_patrol_interfaces__action__ExecuteCircle_SendGoal_Response__Sequence * input,
  turtle_patrol_interfaces__action__ExecuteCircle_SendGoal_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(turtle_patrol_interfaces__action__ExecuteCircle_SendGoal_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    turtle_patrol_interfaces__action__ExecuteCircle_SendGoal_Response * data =
      (turtle_patrol_interfaces__action__ExecuteCircle_SendGoal_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!turtle_patrol_interfaces__action__ExecuteCircle_SendGoal_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          turtle_patrol_interfaces__action__ExecuteCircle_SendGoal_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!turtle_patrol_interfaces__action__ExecuteCircle_SendGoal_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__functions.h"

bool
turtle_patrol_interfaces__action__ExecuteCircle_GetResult_Request__init(turtle_patrol_interfaces__action__ExecuteCircle_GetResult_Request * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    turtle_patrol_interfaces__action__ExecuteCircle_GetResult_Request__fini(msg);
    return false;
  }
  return true;
}

void
turtle_patrol_interfaces__action__ExecuteCircle_GetResult_Request__fini(turtle_patrol_interfaces__action__ExecuteCircle_GetResult_Request * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
}

bool
turtle_patrol_interfaces__action__ExecuteCircle_GetResult_Request__are_equal(const turtle_patrol_interfaces__action__ExecuteCircle_GetResult_Request * lhs, const turtle_patrol_interfaces__action__ExecuteCircle_GetResult_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  return true;
}

bool
turtle_patrol_interfaces__action__ExecuteCircle_GetResult_Request__copy(
  const turtle_patrol_interfaces__action__ExecuteCircle_GetResult_Request * input,
  turtle_patrol_interfaces__action__ExecuteCircle_GetResult_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  return true;
}

turtle_patrol_interfaces__action__ExecuteCircle_GetResult_Request *
turtle_patrol_interfaces__action__ExecuteCircle_GetResult_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  turtle_patrol_interfaces__action__ExecuteCircle_GetResult_Request * msg = (turtle_patrol_interfaces__action__ExecuteCircle_GetResult_Request *)allocator.allocate(sizeof(turtle_patrol_interfaces__action__ExecuteCircle_GetResult_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(turtle_patrol_interfaces__action__ExecuteCircle_GetResult_Request));
  bool success = turtle_patrol_interfaces__action__ExecuteCircle_GetResult_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
turtle_patrol_interfaces__action__ExecuteCircle_GetResult_Request__destroy(turtle_patrol_interfaces__action__ExecuteCircle_GetResult_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    turtle_patrol_interfaces__action__ExecuteCircle_GetResult_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
turtle_patrol_interfaces__action__ExecuteCircle_GetResult_Request__Sequence__init(turtle_patrol_interfaces__action__ExecuteCircle_GetResult_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  turtle_patrol_interfaces__action__ExecuteCircle_GetResult_Request * data = NULL;

  if (size) {
    data = (turtle_patrol_interfaces__action__ExecuteCircle_GetResult_Request *)allocator.zero_allocate(size, sizeof(turtle_patrol_interfaces__action__ExecuteCircle_GetResult_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = turtle_patrol_interfaces__action__ExecuteCircle_GetResult_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        turtle_patrol_interfaces__action__ExecuteCircle_GetResult_Request__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
turtle_patrol_interfaces__action__ExecuteCircle_GetResult_Request__Sequence__fini(turtle_patrol_interfaces__action__ExecuteCircle_GetResult_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      turtle_patrol_interfaces__action__ExecuteCircle_GetResult_Request__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

turtle_patrol_interfaces__action__ExecuteCircle_GetResult_Request__Sequence *
turtle_patrol_interfaces__action__ExecuteCircle_GetResult_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  turtle_patrol_interfaces__action__ExecuteCircle_GetResult_Request__Sequence * array = (turtle_patrol_interfaces__action__ExecuteCircle_GetResult_Request__Sequence *)allocator.allocate(sizeof(turtle_patrol_interfaces__action__ExecuteCircle_GetResult_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = turtle_patrol_interfaces__action__ExecuteCircle_GetResult_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
turtle_patrol_interfaces__action__ExecuteCircle_GetResult_Request__Sequence__destroy(turtle_patrol_interfaces__action__ExecuteCircle_GetResult_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    turtle_patrol_interfaces__action__ExecuteCircle_GetResult_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
turtle_patrol_interfaces__action__ExecuteCircle_GetResult_Request__Sequence__are_equal(const turtle_patrol_interfaces__action__ExecuteCircle_GetResult_Request__Sequence * lhs, const turtle_patrol_interfaces__action__ExecuteCircle_GetResult_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!turtle_patrol_interfaces__action__ExecuteCircle_GetResult_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
turtle_patrol_interfaces__action__ExecuteCircle_GetResult_Request__Sequence__copy(
  const turtle_patrol_interfaces__action__ExecuteCircle_GetResult_Request__Sequence * input,
  turtle_patrol_interfaces__action__ExecuteCircle_GetResult_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(turtle_patrol_interfaces__action__ExecuteCircle_GetResult_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    turtle_patrol_interfaces__action__ExecuteCircle_GetResult_Request * data =
      (turtle_patrol_interfaces__action__ExecuteCircle_GetResult_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!turtle_patrol_interfaces__action__ExecuteCircle_GetResult_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          turtle_patrol_interfaces__action__ExecuteCircle_GetResult_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!turtle_patrol_interfaces__action__ExecuteCircle_GetResult_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `result`
// already included above
// #include "turtle_patrol_interfaces/action/detail/execute_circle__functions.h"

bool
turtle_patrol_interfaces__action__ExecuteCircle_GetResult_Response__init(turtle_patrol_interfaces__action__ExecuteCircle_GetResult_Response * msg)
{
  if (!msg) {
    return false;
  }
  // status
  // result
  if (!turtle_patrol_interfaces__action__ExecuteCircle_Result__init(&msg->result)) {
    turtle_patrol_interfaces__action__ExecuteCircle_GetResult_Response__fini(msg);
    return false;
  }
  return true;
}

void
turtle_patrol_interfaces__action__ExecuteCircle_GetResult_Response__fini(turtle_patrol_interfaces__action__ExecuteCircle_GetResult_Response * msg)
{
  if (!msg) {
    return;
  }
  // status
  // result
  turtle_patrol_interfaces__action__ExecuteCircle_Result__fini(&msg->result);
}

bool
turtle_patrol_interfaces__action__ExecuteCircle_GetResult_Response__are_equal(const turtle_patrol_interfaces__action__ExecuteCircle_GetResult_Response * lhs, const turtle_patrol_interfaces__action__ExecuteCircle_GetResult_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // status
  if (lhs->status != rhs->status) {
    return false;
  }
  // result
  if (!turtle_patrol_interfaces__action__ExecuteCircle_Result__are_equal(
      &(lhs->result), &(rhs->result)))
  {
    return false;
  }
  return true;
}

bool
turtle_patrol_interfaces__action__ExecuteCircle_GetResult_Response__copy(
  const turtle_patrol_interfaces__action__ExecuteCircle_GetResult_Response * input,
  turtle_patrol_interfaces__action__ExecuteCircle_GetResult_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // status
  output->status = input->status;
  // result
  if (!turtle_patrol_interfaces__action__ExecuteCircle_Result__copy(
      &(input->result), &(output->result)))
  {
    return false;
  }
  return true;
}

turtle_patrol_interfaces__action__ExecuteCircle_GetResult_Response *
turtle_patrol_interfaces__action__ExecuteCircle_GetResult_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  turtle_patrol_interfaces__action__ExecuteCircle_GetResult_Response * msg = (turtle_patrol_interfaces__action__ExecuteCircle_GetResult_Response *)allocator.allocate(sizeof(turtle_patrol_interfaces__action__ExecuteCircle_GetResult_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(turtle_patrol_interfaces__action__ExecuteCircle_GetResult_Response));
  bool success = turtle_patrol_interfaces__action__ExecuteCircle_GetResult_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
turtle_patrol_interfaces__action__ExecuteCircle_GetResult_Response__destroy(turtle_patrol_interfaces__action__ExecuteCircle_GetResult_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    turtle_patrol_interfaces__action__ExecuteCircle_GetResult_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
turtle_patrol_interfaces__action__ExecuteCircle_GetResult_Response__Sequence__init(turtle_patrol_interfaces__action__ExecuteCircle_GetResult_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  turtle_patrol_interfaces__action__ExecuteCircle_GetResult_Response * data = NULL;

  if (size) {
    data = (turtle_patrol_interfaces__action__ExecuteCircle_GetResult_Response *)allocator.zero_allocate(size, sizeof(turtle_patrol_interfaces__action__ExecuteCircle_GetResult_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = turtle_patrol_interfaces__action__ExecuteCircle_GetResult_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        turtle_patrol_interfaces__action__ExecuteCircle_GetResult_Response__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
turtle_patrol_interfaces__action__ExecuteCircle_GetResult_Response__Sequence__fini(turtle_patrol_interfaces__action__ExecuteCircle_GetResult_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      turtle_patrol_interfaces__action__ExecuteCircle_GetResult_Response__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

turtle_patrol_interfaces__action__ExecuteCircle_GetResult_Response__Sequence *
turtle_patrol_interfaces__action__ExecuteCircle_GetResult_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  turtle_patrol_interfaces__action__ExecuteCircle_GetResult_Response__Sequence * array = (turtle_patrol_interfaces__action__ExecuteCircle_GetResult_Response__Sequence *)allocator.allocate(sizeof(turtle_patrol_interfaces__action__ExecuteCircle_GetResult_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = turtle_patrol_interfaces__action__ExecuteCircle_GetResult_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
turtle_patrol_interfaces__action__ExecuteCircle_GetResult_Response__Sequence__destroy(turtle_patrol_interfaces__action__ExecuteCircle_GetResult_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    turtle_patrol_interfaces__action__ExecuteCircle_GetResult_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
turtle_patrol_interfaces__action__ExecuteCircle_GetResult_Response__Sequence__are_equal(const turtle_patrol_interfaces__action__ExecuteCircle_GetResult_Response__Sequence * lhs, const turtle_patrol_interfaces__action__ExecuteCircle_GetResult_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!turtle_patrol_interfaces__action__ExecuteCircle_GetResult_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
turtle_patrol_interfaces__action__ExecuteCircle_GetResult_Response__Sequence__copy(
  const turtle_patrol_interfaces__action__ExecuteCircle_GetResult_Response__Sequence * input,
  turtle_patrol_interfaces__action__ExecuteCircle_GetResult_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(turtle_patrol_interfaces__action__ExecuteCircle_GetResult_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    turtle_patrol_interfaces__action__ExecuteCircle_GetResult_Response * data =
      (turtle_patrol_interfaces__action__ExecuteCircle_GetResult_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!turtle_patrol_interfaces__action__ExecuteCircle_GetResult_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          turtle_patrol_interfaces__action__ExecuteCircle_GetResult_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!turtle_patrol_interfaces__action__ExecuteCircle_GetResult_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__functions.h"
// Member `feedback`
// already included above
// #include "turtle_patrol_interfaces/action/detail/execute_circle__functions.h"

bool
turtle_patrol_interfaces__action__ExecuteCircle_FeedbackMessage__init(turtle_patrol_interfaces__action__ExecuteCircle_FeedbackMessage * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    turtle_patrol_interfaces__action__ExecuteCircle_FeedbackMessage__fini(msg);
    return false;
  }
  // feedback
  if (!turtle_patrol_interfaces__action__ExecuteCircle_Feedback__init(&msg->feedback)) {
    turtle_patrol_interfaces__action__ExecuteCircle_FeedbackMessage__fini(msg);
    return false;
  }
  return true;
}

void
turtle_patrol_interfaces__action__ExecuteCircle_FeedbackMessage__fini(turtle_patrol_interfaces__action__ExecuteCircle_FeedbackMessage * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
  // feedback
  turtle_patrol_interfaces__action__ExecuteCircle_Feedback__fini(&msg->feedback);
}

bool
turtle_patrol_interfaces__action__ExecuteCircle_FeedbackMessage__are_equal(const turtle_patrol_interfaces__action__ExecuteCircle_FeedbackMessage * lhs, const turtle_patrol_interfaces__action__ExecuteCircle_FeedbackMessage * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  // feedback
  if (!turtle_patrol_interfaces__action__ExecuteCircle_Feedback__are_equal(
      &(lhs->feedback), &(rhs->feedback)))
  {
    return false;
  }
  return true;
}

bool
turtle_patrol_interfaces__action__ExecuteCircle_FeedbackMessage__copy(
  const turtle_patrol_interfaces__action__ExecuteCircle_FeedbackMessage * input,
  turtle_patrol_interfaces__action__ExecuteCircle_FeedbackMessage * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  // feedback
  if (!turtle_patrol_interfaces__action__ExecuteCircle_Feedback__copy(
      &(input->feedback), &(output->feedback)))
  {
    return false;
  }
  return true;
}

turtle_patrol_interfaces__action__ExecuteCircle_FeedbackMessage *
turtle_patrol_interfaces__action__ExecuteCircle_FeedbackMessage__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  turtle_patrol_interfaces__action__ExecuteCircle_FeedbackMessage * msg = (turtle_patrol_interfaces__action__ExecuteCircle_FeedbackMessage *)allocator.allocate(sizeof(turtle_patrol_interfaces__action__ExecuteCircle_FeedbackMessage), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(turtle_patrol_interfaces__action__ExecuteCircle_FeedbackMessage));
  bool success = turtle_patrol_interfaces__action__ExecuteCircle_FeedbackMessage__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
turtle_patrol_interfaces__action__ExecuteCircle_FeedbackMessage__destroy(turtle_patrol_interfaces__action__ExecuteCircle_FeedbackMessage * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    turtle_patrol_interfaces__action__ExecuteCircle_FeedbackMessage__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
turtle_patrol_interfaces__action__ExecuteCircle_FeedbackMessage__Sequence__init(turtle_patrol_interfaces__action__ExecuteCircle_FeedbackMessage__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  turtle_patrol_interfaces__action__ExecuteCircle_FeedbackMessage * data = NULL;

  if (size) {
    data = (turtle_patrol_interfaces__action__ExecuteCircle_FeedbackMessage *)allocator.zero_allocate(size, sizeof(turtle_patrol_interfaces__action__ExecuteCircle_FeedbackMessage), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = turtle_patrol_interfaces__action__ExecuteCircle_FeedbackMessage__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        turtle_patrol_interfaces__action__ExecuteCircle_FeedbackMessage__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
turtle_patrol_interfaces__action__ExecuteCircle_FeedbackMessage__Sequence__fini(turtle_patrol_interfaces__action__ExecuteCircle_FeedbackMessage__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      turtle_patrol_interfaces__action__ExecuteCircle_FeedbackMessage__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

turtle_patrol_interfaces__action__ExecuteCircle_FeedbackMessage__Sequence *
turtle_patrol_interfaces__action__ExecuteCircle_FeedbackMessage__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  turtle_patrol_interfaces__action__ExecuteCircle_FeedbackMessage__Sequence * array = (turtle_patrol_interfaces__action__ExecuteCircle_FeedbackMessage__Sequence *)allocator.allocate(sizeof(turtle_patrol_interfaces__action__ExecuteCircle_FeedbackMessage__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = turtle_patrol_interfaces__action__ExecuteCircle_FeedbackMessage__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
turtle_patrol_interfaces__action__ExecuteCircle_FeedbackMessage__Sequence__destroy(turtle_patrol_interfaces__action__ExecuteCircle_FeedbackMessage__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    turtle_patrol_interfaces__action__ExecuteCircle_FeedbackMessage__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
turtle_patrol_interfaces__action__ExecuteCircle_FeedbackMessage__Sequence__are_equal(const turtle_patrol_interfaces__action__ExecuteCircle_FeedbackMessage__Sequence * lhs, const turtle_patrol_interfaces__action__ExecuteCircle_FeedbackMessage__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!turtle_patrol_interfaces__action__ExecuteCircle_FeedbackMessage__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
turtle_patrol_interfaces__action__ExecuteCircle_FeedbackMessage__Sequence__copy(
  const turtle_patrol_interfaces__action__ExecuteCircle_FeedbackMessage__Sequence * input,
  turtle_patrol_interfaces__action__ExecuteCircle_FeedbackMessage__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(turtle_patrol_interfaces__action__ExecuteCircle_FeedbackMessage);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    turtle_patrol_interfaces__action__ExecuteCircle_FeedbackMessage * data =
      (turtle_patrol_interfaces__action__ExecuteCircle_FeedbackMessage *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!turtle_patrol_interfaces__action__ExecuteCircle_FeedbackMessage__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          turtle_patrol_interfaces__action__ExecuteCircle_FeedbackMessage__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!turtle_patrol_interfaces__action__ExecuteCircle_FeedbackMessage__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
