
#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};


#[link(name = "turtle_patrol_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__turtle_patrol_interfaces__action__ExecuteCircle_Goal() -> *const std::ffi::c_void;
}

#[link(name = "turtle_patrol_interfaces__rosidl_generator_c")]
extern "C" {
    fn turtle_patrol_interfaces__action__ExecuteCircle_Goal__init(msg: *mut ExecuteCircle_Goal) -> bool;
    fn turtle_patrol_interfaces__action__ExecuteCircle_Goal__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ExecuteCircle_Goal>, size: usize) -> bool;
    fn turtle_patrol_interfaces__action__ExecuteCircle_Goal__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ExecuteCircle_Goal>);
    fn turtle_patrol_interfaces__action__ExecuteCircle_Goal__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ExecuteCircle_Goal>, out_seq: *mut rosidl_runtime_rs::Sequence<ExecuteCircle_Goal>) -> bool;
}

// Corresponds to turtle_patrol_interfaces__action__ExecuteCircle_Goal
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ExecuteCircle_Goal {

    // This member is not documented.
    #[allow(missing_docs)]
    pub radius: f32,

}



impl Default for ExecuteCircle_Goal {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !turtle_patrol_interfaces__action__ExecuteCircle_Goal__init(&mut msg as *mut _) {
        panic!("Call to turtle_patrol_interfaces__action__ExecuteCircle_Goal__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ExecuteCircle_Goal {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { turtle_patrol_interfaces__action__ExecuteCircle_Goal__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { turtle_patrol_interfaces__action__ExecuteCircle_Goal__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { turtle_patrol_interfaces__action__ExecuteCircle_Goal__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ExecuteCircle_Goal {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ExecuteCircle_Goal where Self: Sized {
  const TYPE_NAME: &'static str = "turtle_patrol_interfaces/action/ExecuteCircle_Goal";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__turtle_patrol_interfaces__action__ExecuteCircle_Goal() }
  }
}


#[link(name = "turtle_patrol_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__turtle_patrol_interfaces__action__ExecuteCircle_Result() -> *const std::ffi::c_void;
}

#[link(name = "turtle_patrol_interfaces__rosidl_generator_c")]
extern "C" {
    fn turtle_patrol_interfaces__action__ExecuteCircle_Result__init(msg: *mut ExecuteCircle_Result) -> bool;
    fn turtle_patrol_interfaces__action__ExecuteCircle_Result__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ExecuteCircle_Result>, size: usize) -> bool;
    fn turtle_patrol_interfaces__action__ExecuteCircle_Result__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ExecuteCircle_Result>);
    fn turtle_patrol_interfaces__action__ExecuteCircle_Result__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ExecuteCircle_Result>, out_seq: *mut rosidl_runtime_rs::Sequence<ExecuteCircle_Result>) -> bool;
}

// Corresponds to turtle_patrol_interfaces__action__ExecuteCircle_Result
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ExecuteCircle_Result {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub final_report: rosidl_runtime_rs::String,

}



impl Default for ExecuteCircle_Result {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !turtle_patrol_interfaces__action__ExecuteCircle_Result__init(&mut msg as *mut _) {
        panic!("Call to turtle_patrol_interfaces__action__ExecuteCircle_Result__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ExecuteCircle_Result {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { turtle_patrol_interfaces__action__ExecuteCircle_Result__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { turtle_patrol_interfaces__action__ExecuteCircle_Result__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { turtle_patrol_interfaces__action__ExecuteCircle_Result__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ExecuteCircle_Result {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ExecuteCircle_Result where Self: Sized {
  const TYPE_NAME: &'static str = "turtle_patrol_interfaces/action/ExecuteCircle_Result";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__turtle_patrol_interfaces__action__ExecuteCircle_Result() }
  }
}


#[link(name = "turtle_patrol_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__turtle_patrol_interfaces__action__ExecuteCircle_Feedback() -> *const std::ffi::c_void;
}

#[link(name = "turtle_patrol_interfaces__rosidl_generator_c")]
extern "C" {
    fn turtle_patrol_interfaces__action__ExecuteCircle_Feedback__init(msg: *mut ExecuteCircle_Feedback) -> bool;
    fn turtle_patrol_interfaces__action__ExecuteCircle_Feedback__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ExecuteCircle_Feedback>, size: usize) -> bool;
    fn turtle_patrol_interfaces__action__ExecuteCircle_Feedback__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ExecuteCircle_Feedback>);
    fn turtle_patrol_interfaces__action__ExecuteCircle_Feedback__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ExecuteCircle_Feedback>, out_seq: *mut rosidl_runtime_rs::Sequence<ExecuteCircle_Feedback>) -> bool;
}

// Corresponds to turtle_patrol_interfaces__action__ExecuteCircle_Feedback
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ExecuteCircle_Feedback {

    // This member is not documented.
    #[allow(missing_docs)]
    pub distance_traveled: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub current_status: rosidl_runtime_rs::String,

}



impl Default for ExecuteCircle_Feedback {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !turtle_patrol_interfaces__action__ExecuteCircle_Feedback__init(&mut msg as *mut _) {
        panic!("Call to turtle_patrol_interfaces__action__ExecuteCircle_Feedback__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ExecuteCircle_Feedback {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { turtle_patrol_interfaces__action__ExecuteCircle_Feedback__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { turtle_patrol_interfaces__action__ExecuteCircle_Feedback__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { turtle_patrol_interfaces__action__ExecuteCircle_Feedback__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ExecuteCircle_Feedback {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ExecuteCircle_Feedback where Self: Sized {
  const TYPE_NAME: &'static str = "turtle_patrol_interfaces/action/ExecuteCircle_Feedback";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__turtle_patrol_interfaces__action__ExecuteCircle_Feedback() }
  }
}


#[link(name = "turtle_patrol_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__turtle_patrol_interfaces__action__ExecuteCircle_FeedbackMessage() -> *const std::ffi::c_void;
}

#[link(name = "turtle_patrol_interfaces__rosidl_generator_c")]
extern "C" {
    fn turtle_patrol_interfaces__action__ExecuteCircle_FeedbackMessage__init(msg: *mut ExecuteCircle_FeedbackMessage) -> bool;
    fn turtle_patrol_interfaces__action__ExecuteCircle_FeedbackMessage__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ExecuteCircle_FeedbackMessage>, size: usize) -> bool;
    fn turtle_patrol_interfaces__action__ExecuteCircle_FeedbackMessage__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ExecuteCircle_FeedbackMessage>);
    fn turtle_patrol_interfaces__action__ExecuteCircle_FeedbackMessage__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ExecuteCircle_FeedbackMessage>, out_seq: *mut rosidl_runtime_rs::Sequence<ExecuteCircle_FeedbackMessage>) -> bool;
}

// Corresponds to turtle_patrol_interfaces__action__ExecuteCircle_FeedbackMessage
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ExecuteCircle_FeedbackMessage {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::rmw::UUID,


    // This member is not documented.
    #[allow(missing_docs)]
    pub feedback: super::super::action::rmw::ExecuteCircle_Feedback,

}



impl Default for ExecuteCircle_FeedbackMessage {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !turtle_patrol_interfaces__action__ExecuteCircle_FeedbackMessage__init(&mut msg as *mut _) {
        panic!("Call to turtle_patrol_interfaces__action__ExecuteCircle_FeedbackMessage__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ExecuteCircle_FeedbackMessage {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { turtle_patrol_interfaces__action__ExecuteCircle_FeedbackMessage__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { turtle_patrol_interfaces__action__ExecuteCircle_FeedbackMessage__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { turtle_patrol_interfaces__action__ExecuteCircle_FeedbackMessage__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ExecuteCircle_FeedbackMessage {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ExecuteCircle_FeedbackMessage where Self: Sized {
  const TYPE_NAME: &'static str = "turtle_patrol_interfaces/action/ExecuteCircle_FeedbackMessage";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__turtle_patrol_interfaces__action__ExecuteCircle_FeedbackMessage() }
  }
}




#[link(name = "turtle_patrol_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__turtle_patrol_interfaces__action__ExecuteCircle_SendGoal_Request() -> *const std::ffi::c_void;
}

#[link(name = "turtle_patrol_interfaces__rosidl_generator_c")]
extern "C" {
    fn turtle_patrol_interfaces__action__ExecuteCircle_SendGoal_Request__init(msg: *mut ExecuteCircle_SendGoal_Request) -> bool;
    fn turtle_patrol_interfaces__action__ExecuteCircle_SendGoal_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ExecuteCircle_SendGoal_Request>, size: usize) -> bool;
    fn turtle_patrol_interfaces__action__ExecuteCircle_SendGoal_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ExecuteCircle_SendGoal_Request>);
    fn turtle_patrol_interfaces__action__ExecuteCircle_SendGoal_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ExecuteCircle_SendGoal_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<ExecuteCircle_SendGoal_Request>) -> bool;
}

// Corresponds to turtle_patrol_interfaces__action__ExecuteCircle_SendGoal_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ExecuteCircle_SendGoal_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::rmw::UUID,


    // This member is not documented.
    #[allow(missing_docs)]
    pub goal: super::super::action::rmw::ExecuteCircle_Goal,

}



impl Default for ExecuteCircle_SendGoal_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !turtle_patrol_interfaces__action__ExecuteCircle_SendGoal_Request__init(&mut msg as *mut _) {
        panic!("Call to turtle_patrol_interfaces__action__ExecuteCircle_SendGoal_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ExecuteCircle_SendGoal_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { turtle_patrol_interfaces__action__ExecuteCircle_SendGoal_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { turtle_patrol_interfaces__action__ExecuteCircle_SendGoal_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { turtle_patrol_interfaces__action__ExecuteCircle_SendGoal_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ExecuteCircle_SendGoal_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ExecuteCircle_SendGoal_Request where Self: Sized {
  const TYPE_NAME: &'static str = "turtle_patrol_interfaces/action/ExecuteCircle_SendGoal_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__turtle_patrol_interfaces__action__ExecuteCircle_SendGoal_Request() }
  }
}


#[link(name = "turtle_patrol_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__turtle_patrol_interfaces__action__ExecuteCircle_SendGoal_Response() -> *const std::ffi::c_void;
}

#[link(name = "turtle_patrol_interfaces__rosidl_generator_c")]
extern "C" {
    fn turtle_patrol_interfaces__action__ExecuteCircle_SendGoal_Response__init(msg: *mut ExecuteCircle_SendGoal_Response) -> bool;
    fn turtle_patrol_interfaces__action__ExecuteCircle_SendGoal_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ExecuteCircle_SendGoal_Response>, size: usize) -> bool;
    fn turtle_patrol_interfaces__action__ExecuteCircle_SendGoal_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ExecuteCircle_SendGoal_Response>);
    fn turtle_patrol_interfaces__action__ExecuteCircle_SendGoal_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ExecuteCircle_SendGoal_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<ExecuteCircle_SendGoal_Response>) -> bool;
}

// Corresponds to turtle_patrol_interfaces__action__ExecuteCircle_SendGoal_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ExecuteCircle_SendGoal_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub accepted: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub stamp: builtin_interfaces::msg::rmw::Time,

}



impl Default for ExecuteCircle_SendGoal_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !turtle_patrol_interfaces__action__ExecuteCircle_SendGoal_Response__init(&mut msg as *mut _) {
        panic!("Call to turtle_patrol_interfaces__action__ExecuteCircle_SendGoal_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ExecuteCircle_SendGoal_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { turtle_patrol_interfaces__action__ExecuteCircle_SendGoal_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { turtle_patrol_interfaces__action__ExecuteCircle_SendGoal_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { turtle_patrol_interfaces__action__ExecuteCircle_SendGoal_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ExecuteCircle_SendGoal_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ExecuteCircle_SendGoal_Response where Self: Sized {
  const TYPE_NAME: &'static str = "turtle_patrol_interfaces/action/ExecuteCircle_SendGoal_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__turtle_patrol_interfaces__action__ExecuteCircle_SendGoal_Response() }
  }
}


#[link(name = "turtle_patrol_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__turtle_patrol_interfaces__action__ExecuteCircle_GetResult_Request() -> *const std::ffi::c_void;
}

#[link(name = "turtle_patrol_interfaces__rosidl_generator_c")]
extern "C" {
    fn turtle_patrol_interfaces__action__ExecuteCircle_GetResult_Request__init(msg: *mut ExecuteCircle_GetResult_Request) -> bool;
    fn turtle_patrol_interfaces__action__ExecuteCircle_GetResult_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ExecuteCircle_GetResult_Request>, size: usize) -> bool;
    fn turtle_patrol_interfaces__action__ExecuteCircle_GetResult_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ExecuteCircle_GetResult_Request>);
    fn turtle_patrol_interfaces__action__ExecuteCircle_GetResult_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ExecuteCircle_GetResult_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<ExecuteCircle_GetResult_Request>) -> bool;
}

// Corresponds to turtle_patrol_interfaces__action__ExecuteCircle_GetResult_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ExecuteCircle_GetResult_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::rmw::UUID,

}



impl Default for ExecuteCircle_GetResult_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !turtle_patrol_interfaces__action__ExecuteCircle_GetResult_Request__init(&mut msg as *mut _) {
        panic!("Call to turtle_patrol_interfaces__action__ExecuteCircle_GetResult_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ExecuteCircle_GetResult_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { turtle_patrol_interfaces__action__ExecuteCircle_GetResult_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { turtle_patrol_interfaces__action__ExecuteCircle_GetResult_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { turtle_patrol_interfaces__action__ExecuteCircle_GetResult_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ExecuteCircle_GetResult_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ExecuteCircle_GetResult_Request where Self: Sized {
  const TYPE_NAME: &'static str = "turtle_patrol_interfaces/action/ExecuteCircle_GetResult_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__turtle_patrol_interfaces__action__ExecuteCircle_GetResult_Request() }
  }
}


#[link(name = "turtle_patrol_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__turtle_patrol_interfaces__action__ExecuteCircle_GetResult_Response() -> *const std::ffi::c_void;
}

#[link(name = "turtle_patrol_interfaces__rosidl_generator_c")]
extern "C" {
    fn turtle_patrol_interfaces__action__ExecuteCircle_GetResult_Response__init(msg: *mut ExecuteCircle_GetResult_Response) -> bool;
    fn turtle_patrol_interfaces__action__ExecuteCircle_GetResult_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ExecuteCircle_GetResult_Response>, size: usize) -> bool;
    fn turtle_patrol_interfaces__action__ExecuteCircle_GetResult_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ExecuteCircle_GetResult_Response>);
    fn turtle_patrol_interfaces__action__ExecuteCircle_GetResult_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ExecuteCircle_GetResult_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<ExecuteCircle_GetResult_Response>) -> bool;
}

// Corresponds to turtle_patrol_interfaces__action__ExecuteCircle_GetResult_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ExecuteCircle_GetResult_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub status: i8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub result: super::super::action::rmw::ExecuteCircle_Result,

}



impl Default for ExecuteCircle_GetResult_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !turtle_patrol_interfaces__action__ExecuteCircle_GetResult_Response__init(&mut msg as *mut _) {
        panic!("Call to turtle_patrol_interfaces__action__ExecuteCircle_GetResult_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ExecuteCircle_GetResult_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { turtle_patrol_interfaces__action__ExecuteCircle_GetResult_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { turtle_patrol_interfaces__action__ExecuteCircle_GetResult_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { turtle_patrol_interfaces__action__ExecuteCircle_GetResult_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ExecuteCircle_GetResult_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ExecuteCircle_GetResult_Response where Self: Sized {
  const TYPE_NAME: &'static str = "turtle_patrol_interfaces/action/ExecuteCircle_GetResult_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__turtle_patrol_interfaces__action__ExecuteCircle_GetResult_Response() }
  }
}






#[link(name = "turtle_patrol_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__turtle_patrol_interfaces__action__ExecuteCircle_SendGoal() -> *const std::ffi::c_void;
}

// Corresponds to turtle_patrol_interfaces__action__ExecuteCircle_SendGoal
#[allow(missing_docs, non_camel_case_types)]
pub struct ExecuteCircle_SendGoal;

impl rosidl_runtime_rs::Service for ExecuteCircle_SendGoal {
    type Request = ExecuteCircle_SendGoal_Request;
    type Response = ExecuteCircle_SendGoal_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__turtle_patrol_interfaces__action__ExecuteCircle_SendGoal() }
    }
}




#[link(name = "turtle_patrol_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__turtle_patrol_interfaces__action__ExecuteCircle_GetResult() -> *const std::ffi::c_void;
}

// Corresponds to turtle_patrol_interfaces__action__ExecuteCircle_GetResult
#[allow(missing_docs, non_camel_case_types)]
pub struct ExecuteCircle_GetResult;

impl rosidl_runtime_rs::Service for ExecuteCircle_GetResult {
    type Request = ExecuteCircle_GetResult_Request;
    type Response = ExecuteCircle_GetResult_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__turtle_patrol_interfaces__action__ExecuteCircle_GetResult() }
    }
}


