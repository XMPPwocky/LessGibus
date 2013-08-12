// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: Declarations.proto

#include "stdafx.h"

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#ifdef _MSC_VER
#  pragma warning(push)
#  pragma warning(disable: 4127 4244 4267)
#endif
#include "Declarations.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace protobuf {

namespace {

const ::google::protobuf::Descriptor* VertexDeclaration_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  VertexDeclaration_reflection_ = NULL;
const ::google::protobuf::Descriptor* VertexDeclaration_VertexAttrib_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  VertexDeclaration_VertexAttrib_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_Declarations_2eproto() {
  protobuf_AddDesc_Declarations_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "Declarations.proto");
  GOOGLE_CHECK(file != NULL);
  VertexDeclaration_descriptor_ = file->message_type(0);
  static const int VertexDeclaration_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(VertexDeclaration, attributes_),
  };
  VertexDeclaration_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      VertexDeclaration_descriptor_,
      VertexDeclaration::default_instance_,
      VertexDeclaration_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(VertexDeclaration, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(VertexDeclaration, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(VertexDeclaration));
  VertexDeclaration_VertexAttrib_descriptor_ = VertexDeclaration_descriptor_->nested_type(0);
  static const int VertexDeclaration_VertexAttrib_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(VertexDeclaration_VertexAttrib, type_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(VertexDeclaration_VertexAttrib, attrib_id_),
  };
  VertexDeclaration_VertexAttrib_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      VertexDeclaration_VertexAttrib_descriptor_,
      VertexDeclaration_VertexAttrib::default_instance_,
      VertexDeclaration_VertexAttrib_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(VertexDeclaration_VertexAttrib, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(VertexDeclaration_VertexAttrib, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(VertexDeclaration_VertexAttrib));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_Declarations_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    VertexDeclaration_descriptor_, &VertexDeclaration::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    VertexDeclaration_VertexAttrib_descriptor_, &VertexDeclaration_VertexAttrib::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_Declarations_2eproto() {
  delete VertexDeclaration::default_instance_;
  delete VertexDeclaration_reflection_;
  delete VertexDeclaration_VertexAttrib::default_instance_;
  delete VertexDeclaration_VertexAttrib_reflection_;
}

void protobuf_AddDesc_Declarations_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::protobuf::protobuf_AddDesc_DataType_2eproto();
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\022Declarations.proto\022\010protobuf\032\016DataType"
    ".proto\"\226\001\n\021VertexDeclaration\022<\n\nattribut"
    "es\030\001 \003(\0132(.protobuf.VertexDeclaration.Ve"
    "rtexAttrib\032C\n\014VertexAttrib\022 \n\004type\030\001 \002(\013"
    "2\022.protobuf.DataType\022\021\n\tattrib_id\030\002 \002(\r", 199);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "Declarations.proto", &protobuf_RegisterTypes);
  VertexDeclaration::default_instance_ = new VertexDeclaration();
  VertexDeclaration_VertexAttrib::default_instance_ = new VertexDeclaration_VertexAttrib();
  VertexDeclaration::default_instance_->InitAsDefaultInstance();
  VertexDeclaration_VertexAttrib::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_Declarations_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_Declarations_2eproto {
  StaticDescriptorInitializer_Declarations_2eproto() {
    protobuf_AddDesc_Declarations_2eproto();
  }
} static_descriptor_initializer_Declarations_2eproto_;

// ===================================================================

#ifndef _MSC_VER
const int VertexDeclaration_VertexAttrib::kTypeFieldNumber;
const int VertexDeclaration_VertexAttrib::kAttribIdFieldNumber;
#endif  // !_MSC_VER

VertexDeclaration_VertexAttrib::VertexDeclaration_VertexAttrib()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void VertexDeclaration_VertexAttrib::InitAsDefaultInstance() {
  type_ = const_cast< ::protobuf::DataType*>(&::protobuf::DataType::default_instance());
}

VertexDeclaration_VertexAttrib::VertexDeclaration_VertexAttrib(const VertexDeclaration_VertexAttrib& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void VertexDeclaration_VertexAttrib::SharedCtor() {
  _cached_size_ = 0;
  type_ = NULL;
  attrib_id_ = 0u;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

VertexDeclaration_VertexAttrib::~VertexDeclaration_VertexAttrib() {
  SharedDtor();
}

void VertexDeclaration_VertexAttrib::SharedDtor() {
  if (this != default_instance_) {
    delete type_;
  }
}

void VertexDeclaration_VertexAttrib::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* VertexDeclaration_VertexAttrib::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return VertexDeclaration_VertexAttrib_descriptor_;
}

const VertexDeclaration_VertexAttrib& VertexDeclaration_VertexAttrib::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_Declarations_2eproto();
  return *default_instance_;
}

VertexDeclaration_VertexAttrib* VertexDeclaration_VertexAttrib::default_instance_ = NULL;

VertexDeclaration_VertexAttrib* VertexDeclaration_VertexAttrib::New() const {
  return new VertexDeclaration_VertexAttrib;
}

void VertexDeclaration_VertexAttrib::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (has_type()) {
      if (type_ != NULL) type_->::protobuf::DataType::Clear();
    }
    attrib_id_ = 0u;
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool VertexDeclaration_VertexAttrib::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required .protobuf.DataType type = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_type()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(16)) goto parse_attrib_id;
        break;
      }

      // required uint32 attrib_id = 2;
      case 2: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_attrib_id:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &attrib_id_)));
          set_has_attrib_id();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectAtEnd()) return true;
        break;
      }

      default: {
      handle_uninterpreted:
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          return true;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
  return true;
#undef DO_
}

void VertexDeclaration_VertexAttrib::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // required .protobuf.DataType type = 1;
  if (has_type()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->type(), output);
  }

  // required uint32 attrib_id = 2;
  if (has_attrib_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(2, this->attrib_id(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* VertexDeclaration_VertexAttrib::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // required .protobuf.DataType type = 1;
  if (has_type()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->type(), target);
  }

  // required uint32 attrib_id = 2;
  if (has_attrib_id()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(2, this->attrib_id(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int VertexDeclaration_VertexAttrib::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required .protobuf.DataType type = 1;
    if (has_type()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->type());
    }

    // required uint32 attrib_id = 2;
    if (has_attrib_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->attrib_id());
    }

  }
  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void VertexDeclaration_VertexAttrib::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const VertexDeclaration_VertexAttrib* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const VertexDeclaration_VertexAttrib*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void VertexDeclaration_VertexAttrib::MergeFrom(const VertexDeclaration_VertexAttrib& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_type()) {
      mutable_type()->::protobuf::DataType::MergeFrom(from.type());
    }
    if (from.has_attrib_id()) {
      set_attrib_id(from.attrib_id());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void VertexDeclaration_VertexAttrib::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void VertexDeclaration_VertexAttrib::CopyFrom(const VertexDeclaration_VertexAttrib& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool VertexDeclaration_VertexAttrib::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000003) != 0x00000003) return false;

  if (has_type()) {
    if (!this->type().IsInitialized()) return false;
  }
  return true;
}

void VertexDeclaration_VertexAttrib::Swap(VertexDeclaration_VertexAttrib* other) {
  if (other != this) {
    std::swap(type_, other->type_);
    std::swap(attrib_id_, other->attrib_id_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata VertexDeclaration_VertexAttrib::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = VertexDeclaration_VertexAttrib_descriptor_;
  metadata.reflection = VertexDeclaration_VertexAttrib_reflection_;
  return metadata;
}


// -------------------------------------------------------------------

#ifndef _MSC_VER
const int VertexDeclaration::kAttributesFieldNumber;
#endif  // !_MSC_VER

VertexDeclaration::VertexDeclaration()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void VertexDeclaration::InitAsDefaultInstance() {
}

VertexDeclaration::VertexDeclaration(const VertexDeclaration& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void VertexDeclaration::SharedCtor() {
  _cached_size_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

VertexDeclaration::~VertexDeclaration() {
  SharedDtor();
}

void VertexDeclaration::SharedDtor() {
  if (this != default_instance_) {
  }
}

void VertexDeclaration::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* VertexDeclaration::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return VertexDeclaration_descriptor_;
}

const VertexDeclaration& VertexDeclaration::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_Declarations_2eproto();
  return *default_instance_;
}

VertexDeclaration* VertexDeclaration::default_instance_ = NULL;

VertexDeclaration* VertexDeclaration::New() const {
  return new VertexDeclaration;
}

void VertexDeclaration::Clear() {
  attributes_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool VertexDeclaration::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // repeated .protobuf.VertexDeclaration.VertexAttrib attributes = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_attributes:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_attributes()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(10)) goto parse_attributes;
        if (input->ExpectAtEnd()) return true;
        break;
      }

      default: {
      handle_uninterpreted:
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          return true;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
  return true;
#undef DO_
}

void VertexDeclaration::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // repeated .protobuf.VertexDeclaration.VertexAttrib attributes = 1;
  for (int i = 0; i < this->attributes_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->attributes(i), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* VertexDeclaration::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // repeated .protobuf.VertexDeclaration.VertexAttrib attributes = 1;
  for (int i = 0; i < this->attributes_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->attributes(i), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int VertexDeclaration::ByteSize() const {
  int total_size = 0;

  // repeated .protobuf.VertexDeclaration.VertexAttrib attributes = 1;
  total_size += 1 * this->attributes_size();
  for (int i = 0; i < this->attributes_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->attributes(i));
  }

  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void VertexDeclaration::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const VertexDeclaration* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const VertexDeclaration*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void VertexDeclaration::MergeFrom(const VertexDeclaration& from) {
  GOOGLE_CHECK_NE(&from, this);
  attributes_.MergeFrom(from.attributes_);
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void VertexDeclaration::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void VertexDeclaration::CopyFrom(const VertexDeclaration& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool VertexDeclaration::IsInitialized() const {

  for (int i = 0; i < attributes_size(); i++) {
    if (!this->attributes(i).IsInitialized()) return false;
  }
  return true;
}

void VertexDeclaration::Swap(VertexDeclaration* other) {
  if (other != this) {
    attributes_.Swap(&other->attributes_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata VertexDeclaration::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = VertexDeclaration_descriptor_;
  metadata.reflection = VertexDeclaration_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace protobuf

// @@protoc_insertion_point(global_scope)
#ifdef _MSC_VER
#  pragma warning(pop)
#endif
