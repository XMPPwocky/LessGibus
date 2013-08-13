// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: Material.proto

#ifndef PROTOBUF_Material_2eproto__INCLUDED
#define PROTOBUF_Material_2eproto__INCLUDED

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
#include "ShaderProgram.pb.h"
// @@protoc_insertion_point(includes)

namespace protobuf {

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_Material_2eproto();
void protobuf_AssignDesc_Material_2eproto();
void protobuf_ShutdownFile_Material_2eproto();

class Material;
class Material_Texture;

// ===================================================================

class Material_Texture : public ::google::protobuf::Message {
 public:
  Material_Texture();
  virtual ~Material_Texture();

  Material_Texture(const Material_Texture& from);

  inline Material_Texture& operator=(const Material_Texture& from) {
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
  static const Material_Texture& default_instance();

  void Swap(Material_Texture* other);

  // implements Message ----------------------------------------------

  Material_Texture* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Material_Texture& from);
  void MergeFrom(const Material_Texture& from);
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

  // required string name = 1;
  inline bool has_name() const;
  inline void clear_name();
  static const int kNameFieldNumber = 1;
  inline const ::std::string& name() const;
  inline void set_name(const ::std::string& value);
  inline void set_name(const char* value);
  inline void set_name(const char* value, size_t size);
  inline ::std::string* mutable_name();
  inline ::std::string* release_name();
  inline void set_allocated_name(::std::string* name);

  // required string filepath = 2;
  inline bool has_filepath() const;
  inline void clear_filepath();
  static const int kFilepathFieldNumber = 2;
  inline const ::std::string& filepath() const;
  inline void set_filepath(const ::std::string& value);
  inline void set_filepath(const char* value);
  inline void set_filepath(const char* value, size_t size);
  inline ::std::string* mutable_filepath();
  inline ::std::string* release_filepath();
  inline void set_allocated_filepath(::std::string* filepath);

  // @@protoc_insertion_point(class_scope:protobuf.Material.Texture)
 private:
  inline void set_has_name();
  inline void clear_has_name();
  inline void set_has_filepath();
  inline void clear_has_filepath();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::std::string* name_;
  ::std::string* filepath_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(2 + 31) / 32];

  friend void  protobuf_AddDesc_Material_2eproto();
  friend void protobuf_AssignDesc_Material_2eproto();
  friend void protobuf_ShutdownFile_Material_2eproto();

  void InitAsDefaultInstance();
  static Material_Texture* default_instance_;
};
// -------------------------------------------------------------------

class Material : public ::google::protobuf::Message {
 public:
  Material();
  virtual ~Material();

  Material(const Material& from);

  inline Material& operator=(const Material& from) {
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
  static const Material& default_instance();

  void Swap(Material* other);

  // implements Message ----------------------------------------------

  Material* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Material& from);
  void MergeFrom(const Material& from);
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

  typedef Material_Texture Texture;

  // accessors -------------------------------------------------------

  // optional string shaderprog_path = 1;
  inline bool has_shaderprog_path() const;
  inline void clear_shaderprog_path();
  static const int kShaderprogPathFieldNumber = 1;
  inline const ::std::string& shaderprog_path() const;
  inline void set_shaderprog_path(const ::std::string& value);
  inline void set_shaderprog_path(const char* value);
  inline void set_shaderprog_path(const char* value, size_t size);
  inline ::std::string* mutable_shaderprog_path();
  inline ::std::string* release_shaderprog_path();
  inline void set_allocated_shaderprog_path(::std::string* shaderprog_path);

  // repeated .protobuf.ShaderParam shader_params = 2;
  inline int shader_params_size() const;
  inline void clear_shader_params();
  static const int kShaderParamsFieldNumber = 2;
  inline const ::protobuf::ShaderParam& shader_params(int index) const;
  inline ::protobuf::ShaderParam* mutable_shader_params(int index);
  inline ::protobuf::ShaderParam* add_shader_params();
  inline const ::google::protobuf::RepeatedPtrField< ::protobuf::ShaderParam >&
      shader_params() const;
  inline ::google::protobuf::RepeatedPtrField< ::protobuf::ShaderParam >*
      mutable_shader_params();

  // repeated .protobuf.Material.Texture textures = 3;
  inline int textures_size() const;
  inline void clear_textures();
  static const int kTexturesFieldNumber = 3;
  inline const ::protobuf::Material_Texture& textures(int index) const;
  inline ::protobuf::Material_Texture* mutable_textures(int index);
  inline ::protobuf::Material_Texture* add_textures();
  inline const ::google::protobuf::RepeatedPtrField< ::protobuf::Material_Texture >&
      textures() const;
  inline ::google::protobuf::RepeatedPtrField< ::protobuf::Material_Texture >*
      mutable_textures();

  // @@protoc_insertion_point(class_scope:protobuf.Material)
 private:
  inline void set_has_shaderprog_path();
  inline void clear_has_shaderprog_path();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::std::string* shaderprog_path_;
  ::google::protobuf::RepeatedPtrField< ::protobuf::ShaderParam > shader_params_;
  ::google::protobuf::RepeatedPtrField< ::protobuf::Material_Texture > textures_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(3 + 31) / 32];

  friend void  protobuf_AddDesc_Material_2eproto();
  friend void protobuf_AssignDesc_Material_2eproto();
  friend void protobuf_ShutdownFile_Material_2eproto();

  void InitAsDefaultInstance();
  static Material* default_instance_;
};
// ===================================================================


// ===================================================================

// Material_Texture

// required string name = 1;
inline bool Material_Texture::has_name() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void Material_Texture::set_has_name() {
  _has_bits_[0] |= 0x00000001u;
}
inline void Material_Texture::clear_has_name() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void Material_Texture::clear_name() {
  if (name_ != &::google::protobuf::internal::kEmptyString) {
    name_->clear();
  }
  clear_has_name();
}
inline const ::std::string& Material_Texture::name() const {
  return *name_;
}
inline void Material_Texture::set_name(const ::std::string& value) {
  set_has_name();
  if (name_ == &::google::protobuf::internal::kEmptyString) {
    name_ = new ::std::string;
  }
  name_->assign(value);
}
inline void Material_Texture::set_name(const char* value) {
  set_has_name();
  if (name_ == &::google::protobuf::internal::kEmptyString) {
    name_ = new ::std::string;
  }
  name_->assign(value);
}
inline void Material_Texture::set_name(const char* value, size_t size) {
  set_has_name();
  if (name_ == &::google::protobuf::internal::kEmptyString) {
    name_ = new ::std::string;
  }
  name_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* Material_Texture::mutable_name() {
  set_has_name();
  if (name_ == &::google::protobuf::internal::kEmptyString) {
    name_ = new ::std::string;
  }
  return name_;
}
inline ::std::string* Material_Texture::release_name() {
  clear_has_name();
  if (name_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = name_;
    name_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void Material_Texture::set_allocated_name(::std::string* name) {
  if (name_ != &::google::protobuf::internal::kEmptyString) {
    delete name_;
  }
  if (name) {
    set_has_name();
    name_ = name;
  } else {
    clear_has_name();
    name_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  }
}

// required string filepath = 2;
inline bool Material_Texture::has_filepath() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void Material_Texture::set_has_filepath() {
  _has_bits_[0] |= 0x00000002u;
}
inline void Material_Texture::clear_has_filepath() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void Material_Texture::clear_filepath() {
  if (filepath_ != &::google::protobuf::internal::kEmptyString) {
    filepath_->clear();
  }
  clear_has_filepath();
}
inline const ::std::string& Material_Texture::filepath() const {
  return *filepath_;
}
inline void Material_Texture::set_filepath(const ::std::string& value) {
  set_has_filepath();
  if (filepath_ == &::google::protobuf::internal::kEmptyString) {
    filepath_ = new ::std::string;
  }
  filepath_->assign(value);
}
inline void Material_Texture::set_filepath(const char* value) {
  set_has_filepath();
  if (filepath_ == &::google::protobuf::internal::kEmptyString) {
    filepath_ = new ::std::string;
  }
  filepath_->assign(value);
}
inline void Material_Texture::set_filepath(const char* value, size_t size) {
  set_has_filepath();
  if (filepath_ == &::google::protobuf::internal::kEmptyString) {
    filepath_ = new ::std::string;
  }
  filepath_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* Material_Texture::mutable_filepath() {
  set_has_filepath();
  if (filepath_ == &::google::protobuf::internal::kEmptyString) {
    filepath_ = new ::std::string;
  }
  return filepath_;
}
inline ::std::string* Material_Texture::release_filepath() {
  clear_has_filepath();
  if (filepath_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = filepath_;
    filepath_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void Material_Texture::set_allocated_filepath(::std::string* filepath) {
  if (filepath_ != &::google::protobuf::internal::kEmptyString) {
    delete filepath_;
  }
  if (filepath) {
    set_has_filepath();
    filepath_ = filepath;
  } else {
    clear_has_filepath();
    filepath_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  }
}

// -------------------------------------------------------------------

// Material

// optional string shaderprog_path = 1;
inline bool Material::has_shaderprog_path() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void Material::set_has_shaderprog_path() {
  _has_bits_[0] |= 0x00000001u;
}
inline void Material::clear_has_shaderprog_path() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void Material::clear_shaderprog_path() {
  if (shaderprog_path_ != &::google::protobuf::internal::kEmptyString) {
    shaderprog_path_->clear();
  }
  clear_has_shaderprog_path();
}
inline const ::std::string& Material::shaderprog_path() const {
  return *shaderprog_path_;
}
inline void Material::set_shaderprog_path(const ::std::string& value) {
  set_has_shaderprog_path();
  if (shaderprog_path_ == &::google::protobuf::internal::kEmptyString) {
    shaderprog_path_ = new ::std::string;
  }
  shaderprog_path_->assign(value);
}
inline void Material::set_shaderprog_path(const char* value) {
  set_has_shaderprog_path();
  if (shaderprog_path_ == &::google::protobuf::internal::kEmptyString) {
    shaderprog_path_ = new ::std::string;
  }
  shaderprog_path_->assign(value);
}
inline void Material::set_shaderprog_path(const char* value, size_t size) {
  set_has_shaderprog_path();
  if (shaderprog_path_ == &::google::protobuf::internal::kEmptyString) {
    shaderprog_path_ = new ::std::string;
  }
  shaderprog_path_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* Material::mutable_shaderprog_path() {
  set_has_shaderprog_path();
  if (shaderprog_path_ == &::google::protobuf::internal::kEmptyString) {
    shaderprog_path_ = new ::std::string;
  }
  return shaderprog_path_;
}
inline ::std::string* Material::release_shaderprog_path() {
  clear_has_shaderprog_path();
  if (shaderprog_path_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = shaderprog_path_;
    shaderprog_path_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void Material::set_allocated_shaderprog_path(::std::string* shaderprog_path) {
  if (shaderprog_path_ != &::google::protobuf::internal::kEmptyString) {
    delete shaderprog_path_;
  }
  if (shaderprog_path) {
    set_has_shaderprog_path();
    shaderprog_path_ = shaderprog_path;
  } else {
    clear_has_shaderprog_path();
    shaderprog_path_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  }
}

// repeated .protobuf.ShaderParam shader_params = 2;
inline int Material::shader_params_size() const {
  return shader_params_.size();
}
inline void Material::clear_shader_params() {
  shader_params_.Clear();
}
inline const ::protobuf::ShaderParam& Material::shader_params(int index) const {
  return shader_params_.Get(index);
}
inline ::protobuf::ShaderParam* Material::mutable_shader_params(int index) {
  return shader_params_.Mutable(index);
}
inline ::protobuf::ShaderParam* Material::add_shader_params() {
  return shader_params_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::protobuf::ShaderParam >&
Material::shader_params() const {
  return shader_params_;
}
inline ::google::protobuf::RepeatedPtrField< ::protobuf::ShaderParam >*
Material::mutable_shader_params() {
  return &shader_params_;
}

// repeated .protobuf.Material.Texture textures = 3;
inline int Material::textures_size() const {
  return textures_.size();
}
inline void Material::clear_textures() {
  textures_.Clear();
}
inline const ::protobuf::Material_Texture& Material::textures(int index) const {
  return textures_.Get(index);
}
inline ::protobuf::Material_Texture* Material::mutable_textures(int index) {
  return textures_.Mutable(index);
}
inline ::protobuf::Material_Texture* Material::add_textures() {
  return textures_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::protobuf::Material_Texture >&
Material::textures() const {
  return textures_;
}
inline ::google::protobuf::RepeatedPtrField< ::protobuf::Material_Texture >*
Material::mutable_textures() {
  return &textures_;
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

#endif  // PROTOBUF_Material_2eproto__INCLUDED