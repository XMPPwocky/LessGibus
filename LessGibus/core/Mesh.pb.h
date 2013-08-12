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
#include "Skeleton.pb.h"
#include "Types.pb.h"
// @@protoc_insertion_point(includes)

namespace protobuf {

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_Mesh_2eproto();
void protobuf_AssignDesc_Mesh_2eproto();
void protobuf_ShutdownFile_Mesh_2eproto();

class Mesh;
class Mesh_Vertex;
class Mesh_Triangle;

// ===================================================================

class Mesh_Vertex : public ::google::protobuf::Message {
 public:
  Mesh_Vertex();
  virtual ~Mesh_Vertex();

  Mesh_Vertex(const Mesh_Vertex& from);

  inline Mesh_Vertex& operator=(const Mesh_Vertex& from) {
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
  static const Mesh_Vertex& default_instance();

  void Swap(Mesh_Vertex* other);

  // implements Message ----------------------------------------------

  Mesh_Vertex* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Mesh_Vertex& from);
  void MergeFrom(const Mesh_Vertex& from);
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

  // optional .protobuf.vec3 position = 1;
  inline bool has_position() const;
  inline void clear_position();
  static const int kPositionFieldNumber = 1;
  inline const ::protobuf::vec3& position() const;
  inline ::protobuf::vec3* mutable_position();
  inline ::protobuf::vec3* release_position();
  inline void set_allocated_position(::protobuf::vec3* position);

  // optional .protobuf.vec3 normal = 2;
  inline bool has_normal() const;
  inline void clear_normal();
  static const int kNormalFieldNumber = 2;
  inline const ::protobuf::vec3& normal() const;
  inline ::protobuf::vec3* mutable_normal();
  inline ::protobuf::vec3* release_normal();
  inline void set_allocated_normal(::protobuf::vec3* normal);

  // optional .protobuf.vec3 texcoord = 3;
  inline bool has_texcoord() const;
  inline void clear_texcoord();
  static const int kTexcoordFieldNumber = 3;
  inline const ::protobuf::vec3& texcoord() const;
  inline ::protobuf::vec3* mutable_texcoord();
  inline ::protobuf::vec3* release_texcoord();
  inline void set_allocated_texcoord(::protobuf::vec3* texcoord);

  // @@protoc_insertion_point(class_scope:protobuf.Mesh.Vertex)
 private:
  inline void set_has_position();
  inline void clear_has_position();
  inline void set_has_normal();
  inline void clear_has_normal();
  inline void set_has_texcoord();
  inline void clear_has_texcoord();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::protobuf::vec3* position_;
  ::protobuf::vec3* normal_;
  ::protobuf::vec3* texcoord_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(3 + 31) / 32];

  friend void  protobuf_AddDesc_Mesh_2eproto();
  friend void protobuf_AssignDesc_Mesh_2eproto();
  friend void protobuf_ShutdownFile_Mesh_2eproto();

  void InitAsDefaultInstance();
  static Mesh_Vertex* default_instance_;
};
// -------------------------------------------------------------------

class Mesh_Triangle : public ::google::protobuf::Message {
 public:
  Mesh_Triangle();
  virtual ~Mesh_Triangle();

  Mesh_Triangle(const Mesh_Triangle& from);

  inline Mesh_Triangle& operator=(const Mesh_Triangle& from) {
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
  static const Mesh_Triangle& default_instance();

  void Swap(Mesh_Triangle* other);

  // implements Message ----------------------------------------------

  Mesh_Triangle* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Mesh_Triangle& from);
  void MergeFrom(const Mesh_Triangle& from);
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

  // @@protoc_insertion_point(class_scope:protobuf.Mesh.Triangle)
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
  static Mesh_Triangle* default_instance_;
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

  typedef Mesh_Vertex Vertex;
  typedef Mesh_Triangle Triangle;

  // accessors -------------------------------------------------------

  // required string material_path = 1;
  inline bool has_material_path() const;
  inline void clear_material_path();
  static const int kMaterialPathFieldNumber = 1;
  inline const ::std::string& material_path() const;
  inline void set_material_path(const ::std::string& value);
  inline void set_material_path(const char* value);
  inline void set_material_path(const char* value, size_t size);
  inline ::std::string* mutable_material_path();
  inline ::std::string* release_material_path();
  inline void set_allocated_material_path(::std::string* material_path);

  // repeated .protobuf.Mesh.Vertex vertices = 2;
  inline int vertices_size() const;
  inline void clear_vertices();
  static const int kVerticesFieldNumber = 2;
  inline const ::protobuf::Mesh_Vertex& vertices(int index) const;
  inline ::protobuf::Mesh_Vertex* mutable_vertices(int index);
  inline ::protobuf::Mesh_Vertex* add_vertices();
  inline const ::google::protobuf::RepeatedPtrField< ::protobuf::Mesh_Vertex >&
      vertices() const;
  inline ::google::protobuf::RepeatedPtrField< ::protobuf::Mesh_Vertex >*
      mutable_vertices();

  // optional .protobuf.Joint skeleton = 3;
  inline bool has_skeleton() const;
  inline void clear_skeleton();
  static const int kSkeletonFieldNumber = 3;
  inline const ::protobuf::Joint& skeleton() const;
  inline ::protobuf::Joint* mutable_skeleton();
  inline ::protobuf::Joint* release_skeleton();
  inline void set_allocated_skeleton(::protobuf::Joint* skeleton);

  // repeated .protobuf.Mesh.Triangle triangles = 4;
  inline int triangles_size() const;
  inline void clear_triangles();
  static const int kTrianglesFieldNumber = 4;
  inline const ::protobuf::Mesh_Triangle& triangles(int index) const;
  inline ::protobuf::Mesh_Triangle* mutable_triangles(int index);
  inline ::protobuf::Mesh_Triangle* add_triangles();
  inline const ::google::protobuf::RepeatedPtrField< ::protobuf::Mesh_Triangle >&
      triangles() const;
  inline ::google::protobuf::RepeatedPtrField< ::protobuf::Mesh_Triangle >*
      mutable_triangles();

  // @@protoc_insertion_point(class_scope:protobuf.Mesh)
 private:
  inline void set_has_material_path();
  inline void clear_has_material_path();
  inline void set_has_skeleton();
  inline void clear_has_skeleton();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::std::string* material_path_;
  ::google::protobuf::RepeatedPtrField< ::protobuf::Mesh_Vertex > vertices_;
  ::protobuf::Joint* skeleton_;
  ::google::protobuf::RepeatedPtrField< ::protobuf::Mesh_Triangle > triangles_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(4 + 31) / 32];

  friend void  protobuf_AddDesc_Mesh_2eproto();
  friend void protobuf_AssignDesc_Mesh_2eproto();
  friend void protobuf_ShutdownFile_Mesh_2eproto();

  void InitAsDefaultInstance();
  static Mesh* default_instance_;
};
// ===================================================================


// ===================================================================

// Mesh_Vertex

// optional .protobuf.vec3 position = 1;
inline bool Mesh_Vertex::has_position() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void Mesh_Vertex::set_has_position() {
  _has_bits_[0] |= 0x00000001u;
}
inline void Mesh_Vertex::clear_has_position() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void Mesh_Vertex::clear_position() {
  if (position_ != NULL) position_->::protobuf::vec3::Clear();
  clear_has_position();
}
inline const ::protobuf::vec3& Mesh_Vertex::position() const {
  return position_ != NULL ? *position_ : *default_instance_->position_;
}
inline ::protobuf::vec3* Mesh_Vertex::mutable_position() {
  set_has_position();
  if (position_ == NULL) position_ = new ::protobuf::vec3;
  return position_;
}
inline ::protobuf::vec3* Mesh_Vertex::release_position() {
  clear_has_position();
  ::protobuf::vec3* temp = position_;
  position_ = NULL;
  return temp;
}
inline void Mesh_Vertex::set_allocated_position(::protobuf::vec3* position) {
  delete position_;
  position_ = position;
  if (position) {
    set_has_position();
  } else {
    clear_has_position();
  }
}

// optional .protobuf.vec3 normal = 2;
inline bool Mesh_Vertex::has_normal() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void Mesh_Vertex::set_has_normal() {
  _has_bits_[0] |= 0x00000002u;
}
inline void Mesh_Vertex::clear_has_normal() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void Mesh_Vertex::clear_normal() {
  if (normal_ != NULL) normal_->::protobuf::vec3::Clear();
  clear_has_normal();
}
inline const ::protobuf::vec3& Mesh_Vertex::normal() const {
  return normal_ != NULL ? *normal_ : *default_instance_->normal_;
}
inline ::protobuf::vec3* Mesh_Vertex::mutable_normal() {
  set_has_normal();
  if (normal_ == NULL) normal_ = new ::protobuf::vec3;
  return normal_;
}
inline ::protobuf::vec3* Mesh_Vertex::release_normal() {
  clear_has_normal();
  ::protobuf::vec3* temp = normal_;
  normal_ = NULL;
  return temp;
}
inline void Mesh_Vertex::set_allocated_normal(::protobuf::vec3* normal) {
  delete normal_;
  normal_ = normal;
  if (normal) {
    set_has_normal();
  } else {
    clear_has_normal();
  }
}

// optional .protobuf.vec3 texcoord = 3;
inline bool Mesh_Vertex::has_texcoord() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void Mesh_Vertex::set_has_texcoord() {
  _has_bits_[0] |= 0x00000004u;
}
inline void Mesh_Vertex::clear_has_texcoord() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void Mesh_Vertex::clear_texcoord() {
  if (texcoord_ != NULL) texcoord_->::protobuf::vec3::Clear();
  clear_has_texcoord();
}
inline const ::protobuf::vec3& Mesh_Vertex::texcoord() const {
  return texcoord_ != NULL ? *texcoord_ : *default_instance_->texcoord_;
}
inline ::protobuf::vec3* Mesh_Vertex::mutable_texcoord() {
  set_has_texcoord();
  if (texcoord_ == NULL) texcoord_ = new ::protobuf::vec3;
  return texcoord_;
}
inline ::protobuf::vec3* Mesh_Vertex::release_texcoord() {
  clear_has_texcoord();
  ::protobuf::vec3* temp = texcoord_;
  texcoord_ = NULL;
  return temp;
}
inline void Mesh_Vertex::set_allocated_texcoord(::protobuf::vec3* texcoord) {
  delete texcoord_;
  texcoord_ = texcoord;
  if (texcoord) {
    set_has_texcoord();
  } else {
    clear_has_texcoord();
  }
}

// -------------------------------------------------------------------

// Mesh_Triangle

// required uint32 vert1 = 1;
inline bool Mesh_Triangle::has_vert1() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void Mesh_Triangle::set_has_vert1() {
  _has_bits_[0] |= 0x00000001u;
}
inline void Mesh_Triangle::clear_has_vert1() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void Mesh_Triangle::clear_vert1() {
  vert1_ = 0u;
  clear_has_vert1();
}
inline ::google::protobuf::uint32 Mesh_Triangle::vert1() const {
  return vert1_;
}
inline void Mesh_Triangle::set_vert1(::google::protobuf::uint32 value) {
  set_has_vert1();
  vert1_ = value;
}

// required uint32 vert2 = 2;
inline bool Mesh_Triangle::has_vert2() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void Mesh_Triangle::set_has_vert2() {
  _has_bits_[0] |= 0x00000002u;
}
inline void Mesh_Triangle::clear_has_vert2() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void Mesh_Triangle::clear_vert2() {
  vert2_ = 0u;
  clear_has_vert2();
}
inline ::google::protobuf::uint32 Mesh_Triangle::vert2() const {
  return vert2_;
}
inline void Mesh_Triangle::set_vert2(::google::protobuf::uint32 value) {
  set_has_vert2();
  vert2_ = value;
}

// required uint32 vert3 = 3;
inline bool Mesh_Triangle::has_vert3() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void Mesh_Triangle::set_has_vert3() {
  _has_bits_[0] |= 0x00000004u;
}
inline void Mesh_Triangle::clear_has_vert3() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void Mesh_Triangle::clear_vert3() {
  vert3_ = 0u;
  clear_has_vert3();
}
inline ::google::protobuf::uint32 Mesh_Triangle::vert3() const {
  return vert3_;
}
inline void Mesh_Triangle::set_vert3(::google::protobuf::uint32 value) {
  set_has_vert3();
  vert3_ = value;
}

// -------------------------------------------------------------------

// Mesh

// required string material_path = 1;
inline bool Mesh::has_material_path() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void Mesh::set_has_material_path() {
  _has_bits_[0] |= 0x00000001u;
}
inline void Mesh::clear_has_material_path() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void Mesh::clear_material_path() {
  if (material_path_ != &::google::protobuf::internal::kEmptyString) {
    material_path_->clear();
  }
  clear_has_material_path();
}
inline const ::std::string& Mesh::material_path() const {
  return *material_path_;
}
inline void Mesh::set_material_path(const ::std::string& value) {
  set_has_material_path();
  if (material_path_ == &::google::protobuf::internal::kEmptyString) {
    material_path_ = new ::std::string;
  }
  material_path_->assign(value);
}
inline void Mesh::set_material_path(const char* value) {
  set_has_material_path();
  if (material_path_ == &::google::protobuf::internal::kEmptyString) {
    material_path_ = new ::std::string;
  }
  material_path_->assign(value);
}
inline void Mesh::set_material_path(const char* value, size_t size) {
  set_has_material_path();
  if (material_path_ == &::google::protobuf::internal::kEmptyString) {
    material_path_ = new ::std::string;
  }
  material_path_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* Mesh::mutable_material_path() {
  set_has_material_path();
  if (material_path_ == &::google::protobuf::internal::kEmptyString) {
    material_path_ = new ::std::string;
  }
  return material_path_;
}
inline ::std::string* Mesh::release_material_path() {
  clear_has_material_path();
  if (material_path_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = material_path_;
    material_path_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void Mesh::set_allocated_material_path(::std::string* material_path) {
  if (material_path_ != &::google::protobuf::internal::kEmptyString) {
    delete material_path_;
  }
  if (material_path) {
    set_has_material_path();
    material_path_ = material_path;
  } else {
    clear_has_material_path();
    material_path_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  }
}

// repeated .protobuf.Mesh.Vertex vertices = 2;
inline int Mesh::vertices_size() const {
  return vertices_.size();
}
inline void Mesh::clear_vertices() {
  vertices_.Clear();
}
inline const ::protobuf::Mesh_Vertex& Mesh::vertices(int index) const {
  return vertices_.Get(index);
}
inline ::protobuf::Mesh_Vertex* Mesh::mutable_vertices(int index) {
  return vertices_.Mutable(index);
}
inline ::protobuf::Mesh_Vertex* Mesh::add_vertices() {
  return vertices_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::protobuf::Mesh_Vertex >&
Mesh::vertices() const {
  return vertices_;
}
inline ::google::protobuf::RepeatedPtrField< ::protobuf::Mesh_Vertex >*
Mesh::mutable_vertices() {
  return &vertices_;
}

// optional .protobuf.Joint skeleton = 3;
inline bool Mesh::has_skeleton() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void Mesh::set_has_skeleton() {
  _has_bits_[0] |= 0x00000004u;
}
inline void Mesh::clear_has_skeleton() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void Mesh::clear_skeleton() {
  if (skeleton_ != NULL) skeleton_->::protobuf::Joint::Clear();
  clear_has_skeleton();
}
inline const ::protobuf::Joint& Mesh::skeleton() const {
  return skeleton_ != NULL ? *skeleton_ : *default_instance_->skeleton_;
}
inline ::protobuf::Joint* Mesh::mutable_skeleton() {
  set_has_skeleton();
  if (skeleton_ == NULL) skeleton_ = new ::protobuf::Joint;
  return skeleton_;
}
inline ::protobuf::Joint* Mesh::release_skeleton() {
  clear_has_skeleton();
  ::protobuf::Joint* temp = skeleton_;
  skeleton_ = NULL;
  return temp;
}
inline void Mesh::set_allocated_skeleton(::protobuf::Joint* skeleton) {
  delete skeleton_;
  skeleton_ = skeleton;
  if (skeleton) {
    set_has_skeleton();
  } else {
    clear_has_skeleton();
  }
}

// repeated .protobuf.Mesh.Triangle triangles = 4;
inline int Mesh::triangles_size() const {
  return triangles_.size();
}
inline void Mesh::clear_triangles() {
  triangles_.Clear();
}
inline const ::protobuf::Mesh_Triangle& Mesh::triangles(int index) const {
  return triangles_.Get(index);
}
inline ::protobuf::Mesh_Triangle* Mesh::mutable_triangles(int index) {
  return triangles_.Mutable(index);
}
inline ::protobuf::Mesh_Triangle* Mesh::add_triangles() {
  return triangles_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::protobuf::Mesh_Triangle >&
Mesh::triangles() const {
  return triangles_;
}
inline ::google::protobuf::RepeatedPtrField< ::protobuf::Mesh_Triangle >*
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
