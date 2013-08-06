// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: Mesh.proto

#ifndef PROTOBUF_Mesh_2eproto__INCLUDED
#define PROTOBUF_Mesh_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 2005000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 2005000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)

namespace protobuf {

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_Mesh_2eproto();
void protobuf_AssignDesc_Mesh_2eproto();
void protobuf_ShutdownFile_Mesh_2eproto();

class Joint;
class Triangle;
class Mesh;

// ===================================================================

class Joint : public ::google::protobuf::Message {
 public:
  Joint();
  virtual ~Joint();

  Joint(const Joint& from);

  inline Joint& operator=(const Joint& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const Joint& default_instance();

  void Swap(Joint* other);

  // implements Message ----------------------------------------------

  Joint* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Joint& from);
  void MergeFrom(const Joint& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // repeated .protobuf.Joint children = 1;
  inline int children_size() const;
  inline void clear_children();
  static const int kChildrenFieldNumber = 1;
  inline const ::protobuf::Joint& children(int index) const;
  inline ::protobuf::Joint* mutable_children(int index);
  inline ::protobuf::Joint* add_children();
  inline const ::google::protobuf::RepeatedPtrField< ::protobuf::Joint >&
      children() const;
  inline ::google::protobuf::RepeatedPtrField< ::protobuf::Joint >*
      mutable_children();

  // repeated float jointspace_transform = 2 [packed = true];
  inline int jointspace_transform_size() const;
  inline void clear_jointspace_transform();
  static const int kJointspaceTransformFieldNumber = 2;
  inline float jointspace_transform(int index) const;
  inline void set_jointspace_transform(int index, float value);
  inline void add_jointspace_transform(float value);
  inline const ::google::protobuf::RepeatedField< float >&
      jointspace_transform() const;
  inline ::google::protobuf::RepeatedField< float >*
      mutable_jointspace_transform();

  // repeated float worldspace_to_jointspace_transform = 3 [packed = true];
  inline int worldspace_to_jointspace_transform_size() const;
  inline void clear_worldspace_to_jointspace_transform();
  static const int kWorldspaceToJointspaceTransformFieldNumber = 3;
  inline float worldspace_to_jointspace_transform(int index) const;
  inline void set_worldspace_to_jointspace_transform(int index, float value);
  inline void add_worldspace_to_jointspace_transform(float value);
  inline const ::google::protobuf::RepeatedField< float >&
      worldspace_to_jointspace_transform() const;
  inline ::google::protobuf::RepeatedField< float >*
      mutable_worldspace_to_jointspace_transform();

  // @@protoc_insertion_point(class_scope:protobuf.Joint)
 private:

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::RepeatedPtrField< ::protobuf::Joint > children_;
  ::google::protobuf::RepeatedField< float > jointspace_transform_;
  mutable int _jointspace_transform_cached_byte_size_;
  ::google::protobuf::RepeatedField< float > worldspace_to_jointspace_transform_;
  mutable int _worldspace_to_jointspace_transform_cached_byte_size_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(3 + 31) / 32];

  friend void  protobuf_AddDesc_Mesh_2eproto();
  friend void protobuf_AssignDesc_Mesh_2eproto();
  friend void protobuf_ShutdownFile_Mesh_2eproto();

  void InitAsDefaultInstance();
  static Joint* default_instance_;
};
// -------------------------------------------------------------------

class Triangle : public ::google::protobuf::Message {
 public:
  Triangle();
  virtual ~Triangle();

  Triangle(const Triangle& from);

  inline Triangle& operator=(const Triangle& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const Triangle& default_instance();

  void Swap(Triangle* other);

  // implements Message ----------------------------------------------

  Triangle* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Triangle& from);
  void MergeFrom(const Triangle& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // required uint32 vert1 = 1;
  inline bool has_vert1() const;
  inline void clear_vert1();
  static const int kVert1FieldNumber = 1;
  inline ::google::protobuf::uint32 vert1() const;
  inline void set_vert1(::google::protobuf::uint32 value);

  // required uint32 vert2 = 2;
  inline bool has_vert2() const;
  inline void clear_vert2();
  static const int kVert2FieldNumber = 2;
  inline ::google::protobuf::uint32 vert2() const;
  inline void set_vert2(::google::protobuf::uint32 value);

  // required uint32 vert3 = 3;
  inline bool has_vert3() const;
  inline void clear_vert3();
  static const int kVert3FieldNumber = 3;
  inline ::google::protobuf::uint32 vert3() const;
  inline void set_vert3(::google::protobuf::uint32 value);

  // @@protoc_insertion_point(class_scope:protobuf.Triangle)
 private:
  inline void set_has_vert1();
  inline void clear_has_vert1();
  inline void set_has_vert2();
  inline void clear_has_vert2();
  inline void set_has_vert3();
  inline void clear_has_vert3();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::uint32 vert1_;
  ::google::protobuf::uint32 vert2_;
  ::google::protobuf::uint32 vert3_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(3 + 31) / 32];

  friend void  protobuf_AddDesc_Mesh_2eproto();
  friend void protobuf_AssignDesc_Mesh_2eproto();
  friend void protobuf_ShutdownFile_Mesh_2eproto();

  void InitAsDefaultInstance();
  static Triangle* default_instance_;
};
// -------------------------------------------------------------------

class Mesh : public ::google::protobuf::Message {
 public:
  Mesh();
  virtual ~Mesh();

  Mesh(const Mesh& from);

  inline Mesh& operator=(const Mesh& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const Mesh& default_instance();

  void Swap(Mesh* other);

  // implements Message ----------------------------------------------

  Mesh* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Mesh& from);
  void MergeFrom(const Mesh& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // required string material = 1;
  inline bool has_material() const;
  inline void clear_material();
  static const int kMaterialFieldNumber = 1;
  inline const ::std::string& material() const;
  inline void set_material(const ::std::string& value);
  inline void set_material(const char* value);
  inline void set_material(const char* value, size_t size);
  inline ::std::string* mutable_material();
  inline ::std::string* release_material();
  inline void set_allocated_material(::std::string* material);

  // repeated string texture = 2;
  inline int texture_size() const;
  inline void clear_texture();
  static const int kTextureFieldNumber = 2;
  inline const ::std::string& texture(int index) const;
  inline ::std::string* mutable_texture(int index);
  inline void set_texture(int index, const ::std::string& value);
  inline void set_texture(int index, const char* value);
  inline void set_texture(int index, const char* value, size_t size);
  inline ::std::string* add_texture();
  inline void add_texture(const ::std::string& value);
  inline void add_texture(const char* value);
  inline void add_texture(const char* value, size_t size);
  inline const ::google::protobuf::RepeatedPtrField< ::std::string>& texture() const;
  inline ::google::protobuf::RepeatedPtrField< ::std::string>* mutable_texture();

  // required uint32 vertices_format = 3;
  inline bool has_vertices_format() const;
  inline void clear_vertices_format();
  static const int kVerticesFormatFieldNumber = 3;
  inline ::google::protobuf::uint32 vertices_format() const;
  inline void set_vertices_format(::google::protobuf::uint32 value);

  // required bytes vertices_data = 4;
  inline bool has_vertices_data() const;
  inline void clear_vertices_data();
  static const int kVerticesDataFieldNumber = 4;
  inline const ::std::string& vertices_data() const;
  inline void set_vertices_data(const ::std::string& value);
  inline void set_vertices_data(const char* value);
  inline void set_vertices_data(const void* value, size_t size);
  inline ::std::string* mutable_vertices_data();
  inline ::std::string* release_vertices_data();
  inline void set_allocated_vertices_data(::std::string* vertices_data);

  // repeated .protobuf.Joint joints = 5;
  inline int joints_size() const;
  inline void clear_joints();
  static const int kJointsFieldNumber = 5;
  inline const ::protobuf::Joint& joints(int index) const;
  inline ::protobuf::Joint* mutable_joints(int index);
  inline ::protobuf::Joint* add_joints();
  inline const ::google::protobuf::RepeatedPtrField< ::protobuf::Joint >&
      joints() const;
  inline ::google::protobuf::RepeatedPtrField< ::protobuf::Joint >*
      mutable_joints();

  // repeated .protobuf.Triangle triangles = 6;
  inline int triangles_size() const;
  inline void clear_triangles();
  static const int kTrianglesFieldNumber = 6;
  inline const ::protobuf::Triangle& triangles(int index) const;
  inline ::protobuf::Triangle* mutable_triangles(int index);
  inline ::protobuf::Triangle* add_triangles();
  inline const ::google::protobuf::RepeatedPtrField< ::protobuf::Triangle >&
      triangles() const;
  inline ::google::protobuf::RepeatedPtrField< ::protobuf::Triangle >*
      mutable_triangles();

  // @@protoc_insertion_point(class_scope:protobuf.Mesh)
 private:
  inline void set_has_material();
  inline void clear_has_material();
  inline void set_has_vertices_format();
  inline void clear_has_vertices_format();
  inline void set_has_vertices_data();
  inline void clear_has_vertices_data();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::std::string* material_;
  ::google::protobuf::RepeatedPtrField< ::std::string> texture_;
  ::std::string* vertices_data_;
  ::google::protobuf::RepeatedPtrField< ::protobuf::Joint > joints_;
  ::google::protobuf::RepeatedPtrField< ::protobuf::Triangle > triangles_;
  ::google::protobuf::uint32 vertices_format_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(6 + 31) / 32];

  friend void  protobuf_AddDesc_Mesh_2eproto();
  friend void protobuf_AssignDesc_Mesh_2eproto();
  friend void protobuf_ShutdownFile_Mesh_2eproto();

  void InitAsDefaultInstance();
  static Mesh* default_instance_;
};
// ===================================================================


// ===================================================================

// Joint

// repeated .protobuf.Joint children = 1;
inline int Joint::children_size() const {
  return children_.size();
}
inline void Joint::clear_children() {
  children_.Clear();
}
inline const ::protobuf::Joint& Joint::children(int index) const {
  return children_.Get(index);
}
inline ::protobuf::Joint* Joint::mutable_children(int index) {
  return children_.Mutable(index);
}
inline ::protobuf::Joint* Joint::add_children() {
  return children_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::protobuf::Joint >&
Joint::children() const {
  return children_;
}
inline ::google::protobuf::RepeatedPtrField< ::protobuf::Joint >*
Joint::mutable_children() {
  return &children_;
}

// repeated float jointspace_transform = 2 [packed = true];
inline int Joint::jointspace_transform_size() const {
  return jointspace_transform_.size();
}
inline void Joint::clear_jointspace_transform() {
  jointspace_transform_.Clear();
}
inline float Joint::jointspace_transform(int index) const {
  return jointspace_transform_.Get(index);
}
inline void Joint::set_jointspace_transform(int index, float value) {
  jointspace_transform_.Set(index, value);
}
inline void Joint::add_jointspace_transform(float value) {
  jointspace_transform_.Add(value);
}
inline const ::google::protobuf::RepeatedField< float >&
Joint::jointspace_transform() const {
  return jointspace_transform_;
}
inline ::google::protobuf::RepeatedField< float >*
Joint::mutable_jointspace_transform() {
  return &jointspace_transform_;
}

// repeated float worldspace_to_jointspace_transform = 3 [packed = true];
inline int Joint::worldspace_to_jointspace_transform_size() const {
  return worldspace_to_jointspace_transform_.size();
}
inline void Joint::clear_worldspace_to_jointspace_transform() {
  worldspace_to_jointspace_transform_.Clear();
}
inline float Joint::worldspace_to_jointspace_transform(int index) const {
  return worldspace_to_jointspace_transform_.Get(index);
}
inline void Joint::set_worldspace_to_jointspace_transform(int index, float value) {
  worldspace_to_jointspace_transform_.Set(index, value);
}
inline void Joint::add_worldspace_to_jointspace_transform(float value) {
  worldspace_to_jointspace_transform_.Add(value);
}
inline const ::google::protobuf::RepeatedField< float >&
Joint::worldspace_to_jointspace_transform() const {
  return worldspace_to_jointspace_transform_;
}
inline ::google::protobuf::RepeatedField< float >*
Joint::mutable_worldspace_to_jointspace_transform() {
  return &worldspace_to_jointspace_transform_;
}

// -------------------------------------------------------------------

// Triangle

// required uint32 vert1 = 1;
inline bool Triangle::has_vert1() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void Triangle::set_has_vert1() {
  _has_bits_[0] |= 0x00000001u;
}
inline void Triangle::clear_has_vert1() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void Triangle::clear_vert1() {
  vert1_ = 0u;
  clear_has_vert1();
}
inline ::google::protobuf::uint32 Triangle::vert1() const {
  return vert1_;
}
inline void Triangle::set_vert1(::google::protobuf::uint32 value) {
  set_has_vert1();
  vert1_ = value;
}

// required uint32 vert2 = 2;
inline bool Triangle::has_vert2() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void Triangle::set_has_vert2() {
  _has_bits_[0] |= 0x00000002u;
}
inline void Triangle::clear_has_vert2() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void Triangle::clear_vert2() {
  vert2_ = 0u;
  clear_has_vert2();
}
inline ::google::protobuf::uint32 Triangle::vert2() const {
  return vert2_;
}
inline void Triangle::set_vert2(::google::protobuf::uint32 value) {
  set_has_vert2();
  vert2_ = value;
}

// required uint32 vert3 = 3;
inline bool Triangle::has_vert3() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void Triangle::set_has_vert3() {
  _has_bits_[0] |= 0x00000004u;
}
inline void Triangle::clear_has_vert3() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void Triangle::clear_vert3() {
  vert3_ = 0u;
  clear_has_vert3();
}
inline ::google::protobuf::uint32 Triangle::vert3() const {
  return vert3_;
}
inline void Triangle::set_vert3(::google::protobuf::uint32 value) {
  set_has_vert3();
  vert3_ = value;
}

// -------------------------------------------------------------------

// Mesh

// required string material = 1;
inline bool Mesh::has_material() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void Mesh::set_has_material() {
  _has_bits_[0] |= 0x00000001u;
}
inline void Mesh::clear_has_material() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void Mesh::clear_material() {
  if (material_ != &::google::protobuf::internal::kEmptyString) {
    material_->clear();
  }
  clear_has_material();
}
inline const ::std::string& Mesh::material() const {
  return *material_;
}
inline void Mesh::set_material(const ::std::string& value) {
  set_has_material();
  if (material_ == &::google::protobuf::internal::kEmptyString) {
    material_ = new ::std::string;
  }
  material_->assign(value);
}
inline void Mesh::set_material(const char* value) {
  set_has_material();
  if (material_ == &::google::protobuf::internal::kEmptyString) {
    material_ = new ::std::string;
  }
  material_->assign(value);
}
inline void Mesh::set_material(const char* value, size_t size) {
  set_has_material();
  if (material_ == &::google::protobuf::internal::kEmptyString) {
    material_ = new ::std::string;
  }
  material_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* Mesh::mutable_material() {
  set_has_material();
  if (material_ == &::google::protobuf::internal::kEmptyString) {
    material_ = new ::std::string;
  }
  return material_;
}
inline ::std::string* Mesh::release_material() {
  clear_has_material();
  if (material_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = material_;
    material_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void Mesh::set_allocated_material(::std::string* material) {
  if (material_ != &::google::protobuf::internal::kEmptyString) {
    delete material_;
  }
  if (material) {
    set_has_material();
    material_ = material;
  } else {
    clear_has_material();
    material_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  }
}

// repeated string texture = 2;
inline int Mesh::texture_size() const {
  return texture_.size();
}
inline void Mesh::clear_texture() {
  texture_.Clear();
}
inline const ::std::string& Mesh::texture(int index) const {
  return texture_.Get(index);
}
inline ::std::string* Mesh::mutable_texture(int index) {
  return texture_.Mutable(index);
}
inline void Mesh::set_texture(int index, const ::std::string& value) {
  texture_.Mutable(index)->assign(value);
}
inline void Mesh::set_texture(int index, const char* value) {
  texture_.Mutable(index)->assign(value);
}
inline void Mesh::set_texture(int index, const char* value, size_t size) {
  texture_.Mutable(index)->assign(
    reinterpret_cast<const char*>(value), size);
}
inline ::std::string* Mesh::add_texture() {
  return texture_.Add();
}
inline void Mesh::add_texture(const ::std::string& value) {
  texture_.Add()->assign(value);
}
inline void Mesh::add_texture(const char* value) {
  texture_.Add()->assign(value);
}
inline void Mesh::add_texture(const char* value, size_t size) {
  texture_.Add()->assign(reinterpret_cast<const char*>(value), size);
}
inline const ::google::protobuf::RepeatedPtrField< ::std::string>&
Mesh::texture() const {
  return texture_;
}
inline ::google::protobuf::RepeatedPtrField< ::std::string>*
Mesh::mutable_texture() {
  return &texture_;
}

// required uint32 vertices_format = 3;
inline bool Mesh::has_vertices_format() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void Mesh::set_has_vertices_format() {
  _has_bits_[0] |= 0x00000004u;
}
inline void Mesh::clear_has_vertices_format() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void Mesh::clear_vertices_format() {
  vertices_format_ = 0u;
  clear_has_vertices_format();
}
inline ::google::protobuf::uint32 Mesh::vertices_format() const {
  return vertices_format_;
}
inline void Mesh::set_vertices_format(::google::protobuf::uint32 value) {
  set_has_vertices_format();
  vertices_format_ = value;
}

// required bytes vertices_data = 4;
inline bool Mesh::has_vertices_data() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void Mesh::set_has_vertices_data() {
  _has_bits_[0] |= 0x00000008u;
}
inline void Mesh::clear_has_vertices_data() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void Mesh::clear_vertices_data() {
  if (vertices_data_ != &::google::protobuf::internal::kEmptyString) {
    vertices_data_->clear();
  }
  clear_has_vertices_data();
}
inline const ::std::string& Mesh::vertices_data() const {
  return *vertices_data_;
}
inline void Mesh::set_vertices_data(const ::std::string& value) {
  set_has_vertices_data();
  if (vertices_data_ == &::google::protobuf::internal::kEmptyString) {
    vertices_data_ = new ::std::string;
  }
  vertices_data_->assign(value);
}
inline void Mesh::set_vertices_data(const char* value) {
  set_has_vertices_data();
  if (vertices_data_ == &::google::protobuf::internal::kEmptyString) {
    vertices_data_ = new ::std::string;
  }
  vertices_data_->assign(value);
}
inline void Mesh::set_vertices_data(const void* value, size_t size) {
  set_has_vertices_data();
  if (vertices_data_ == &::google::protobuf::internal::kEmptyString) {
    vertices_data_ = new ::std::string;
  }
  vertices_data_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* Mesh::mutable_vertices_data() {
  set_has_vertices_data();
  if (vertices_data_ == &::google::protobuf::internal::kEmptyString) {
    vertices_data_ = new ::std::string;
  }
  return vertices_data_;
}
inline ::std::string* Mesh::release_vertices_data() {
  clear_has_vertices_data();
  if (vertices_data_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = vertices_data_;
    vertices_data_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void Mesh::set_allocated_vertices_data(::std::string* vertices_data) {
  if (vertices_data_ != &::google::protobuf::internal::kEmptyString) {
    delete vertices_data_;
  }
  if (vertices_data) {
    set_has_vertices_data();
    vertices_data_ = vertices_data;
  } else {
    clear_has_vertices_data();
    vertices_data_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  }
}

// repeated .protobuf.Joint joints = 5;
inline int Mesh::joints_size() const {
  return joints_.size();
}
inline void Mesh::clear_joints() {
  joints_.Clear();
}
inline const ::protobuf::Joint& Mesh::joints(int index) const {
  return joints_.Get(index);
}
inline ::protobuf::Joint* Mesh::mutable_joints(int index) {
  return joints_.Mutable(index);
}
inline ::protobuf::Joint* Mesh::add_joints() {
  return joints_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::protobuf::Joint >&
Mesh::joints() const {
  return joints_;
}
inline ::google::protobuf::RepeatedPtrField< ::protobuf::Joint >*
Mesh::mutable_joints() {
  return &joints_;
}

// repeated .protobuf.Triangle triangles = 6;
inline int Mesh::triangles_size() const {
  return triangles_.size();
}
inline void Mesh::clear_triangles() {
  triangles_.Clear();
}
inline const ::protobuf::Triangle& Mesh::triangles(int index) const {
  return triangles_.Get(index);
}
inline ::protobuf::Triangle* Mesh::mutable_triangles(int index) {
  return triangles_.Mutable(index);
}
inline ::protobuf::Triangle* Mesh::add_triangles() {
  return triangles_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::protobuf::Triangle >&
Mesh::triangles() const {
  return triangles_;
}
inline ::google::protobuf::RepeatedPtrField< ::protobuf::Triangle >*
Mesh::mutable_triangles() {
  return &triangles_;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace protobuf

#ifndef SWIG
namespace google {
namespace protobuf {


}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_Mesh_2eproto__INCLUDED
