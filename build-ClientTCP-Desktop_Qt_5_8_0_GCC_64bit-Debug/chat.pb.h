// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: chat.proto

#ifndef PROTOBUF_chat_2eproto__INCLUDED
#define PROTOBUF_chat_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 2006000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 2006001 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/generated_enum_reflection.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_chat_2eproto();
void protobuf_AssignDesc_chat_2eproto();
void protobuf_ShutdownFile_chat_2eproto();

class ChattingMessages;

enum ChattingMessages_typeMessage {
  ChattingMessages_typeMessage_TEXT = 1,
  ChattingMessages_typeMessage_FILE = 2
};
bool ChattingMessages_typeMessage_IsValid(int value);
const ChattingMessages_typeMessage ChattingMessages_typeMessage_typeMessage_MIN = ChattingMessages_typeMessage_TEXT;
const ChattingMessages_typeMessage ChattingMessages_typeMessage_typeMessage_MAX = ChattingMessages_typeMessage_FILE;
const int ChattingMessages_typeMessage_typeMessage_ARRAYSIZE = ChattingMessages_typeMessage_typeMessage_MAX + 1;

const ::google::protobuf::EnumDescriptor* ChattingMessages_typeMessage_descriptor();
inline const ::std::string& ChattingMessages_typeMessage_Name(ChattingMessages_typeMessage value) {
  return ::google::protobuf::internal::NameOfEnum(
    ChattingMessages_typeMessage_descriptor(), value);
}
inline bool ChattingMessages_typeMessage_Parse(
    const ::std::string& name, ChattingMessages_typeMessage* value) {
  return ::google::protobuf::internal::ParseNamedEnum<ChattingMessages_typeMessage>(
    ChattingMessages_typeMessage_descriptor(), name, value);
}
// ===================================================================

class ChattingMessages : public ::google::protobuf::Message {
 public:
  ChattingMessages();
  virtual ~ChattingMessages();

  ChattingMessages(const ChattingMessages& from);

  inline ChattingMessages& operator=(const ChattingMessages& from) {
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
  static const ChattingMessages& default_instance();

  void Swap(ChattingMessages* other);

  // implements Message ----------------------------------------------

  ChattingMessages* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const ChattingMessages& from);
  void MergeFrom(const ChattingMessages& from);
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

  typedef ChattingMessages_typeMessage typeMessage;
  static const typeMessage TEXT = ChattingMessages_typeMessage_TEXT;
  static const typeMessage FILE = ChattingMessages_typeMessage_FILE;
  static inline bool typeMessage_IsValid(int value) {
    return ChattingMessages_typeMessage_IsValid(value);
  }
  static const typeMessage typeMessage_MIN =
    ChattingMessages_typeMessage_typeMessage_MIN;
  static const typeMessage typeMessage_MAX =
    ChattingMessages_typeMessage_typeMessage_MAX;
  static const int typeMessage_ARRAYSIZE =
    ChattingMessages_typeMessage_typeMessage_ARRAYSIZE;
  static inline const ::google::protobuf::EnumDescriptor*
  typeMessage_descriptor() {
    return ChattingMessages_typeMessage_descriptor();
  }
  static inline const ::std::string& typeMessage_Name(typeMessage value) {
    return ChattingMessages_typeMessage_Name(value);
  }
  static inline bool typeMessage_Parse(const ::std::string& name,
      typeMessage* value) {
    return ChattingMessages_typeMessage_Parse(name, value);
  }

  // accessors -------------------------------------------------------

  // required .ChattingMessages.typeMessage type = 20;
  inline bool has_type() const;
  inline void clear_type();
  static const int kTypeFieldNumber = 20;
  inline ::ChattingMessages_typeMessage type() const;
  inline void set_type(::ChattingMessages_typeMessage value);

  // optional string sourceRoute = 30;
  inline bool has_sourceroute() const;
  inline void clear_sourceroute();
  static const int kSourceRouteFieldNumber = 30;
  inline const ::std::string& sourceroute() const;
  inline void set_sourceroute(const ::std::string& value);
  inline void set_sourceroute(const char* value);
  inline void set_sourceroute(const char* value, size_t size);
  inline ::std::string* mutable_sourceroute();
  inline ::std::string* release_sourceroute();
  inline void set_allocated_sourceroute(::std::string* sourceroute);

  // optional int32 sizeFile = 40;
  inline bool has_sizefile() const;
  inline void clear_sizefile();
  static const int kSizeFileFieldNumber = 40;
  inline ::google::protobuf::int32 sizefile() const;
  inline void set_sizefile(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:ChattingMessages)
 private:
  inline void set_has_type();
  inline void clear_has_type();
  inline void set_has_sourceroute();
  inline void clear_has_sourceroute();
  inline void set_has_sizefile();
  inline void clear_has_sizefile();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::uint32 _has_bits_[1];
  mutable int _cached_size_;
  ::std::string* sourceroute_;
  int type_;
  ::google::protobuf::int32 sizefile_;
  friend void  protobuf_AddDesc_chat_2eproto();
  friend void protobuf_AssignDesc_chat_2eproto();
  friend void protobuf_ShutdownFile_chat_2eproto();

  void InitAsDefaultInstance();
  static ChattingMessages* default_instance_;
};
// ===================================================================


// ===================================================================

// ChattingMessages

// required .ChattingMessages.typeMessage type = 20;
inline bool ChattingMessages::has_type() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void ChattingMessages::set_has_type() {
  _has_bits_[0] |= 0x00000001u;
}
inline void ChattingMessages::clear_has_type() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void ChattingMessages::clear_type() {
  type_ = 1;
  clear_has_type();
}
inline ::ChattingMessages_typeMessage ChattingMessages::type() const {
  // @@protoc_insertion_point(field_get:ChattingMessages.type)
  return static_cast< ::ChattingMessages_typeMessage >(type_);
}
inline void ChattingMessages::set_type(::ChattingMessages_typeMessage value) {
  assert(::ChattingMessages_typeMessage_IsValid(value));
  set_has_type();
  type_ = value;
  // @@protoc_insertion_point(field_set:ChattingMessages.type)
}

// optional string sourceRoute = 30;
inline bool ChattingMessages::has_sourceroute() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void ChattingMessages::set_has_sourceroute() {
  _has_bits_[0] |= 0x00000002u;
}
inline void ChattingMessages::clear_has_sourceroute() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void ChattingMessages::clear_sourceroute() {
  if (sourceroute_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    sourceroute_->clear();
  }
  clear_has_sourceroute();
}
inline const ::std::string& ChattingMessages::sourceroute() const {
  // @@protoc_insertion_point(field_get:ChattingMessages.sourceRoute)
  return *sourceroute_;
}
inline void ChattingMessages::set_sourceroute(const ::std::string& value) {
  set_has_sourceroute();
  if (sourceroute_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    sourceroute_ = new ::std::string;
  }
  sourceroute_->assign(value);
  // @@protoc_insertion_point(field_set:ChattingMessages.sourceRoute)
}
inline void ChattingMessages::set_sourceroute(const char* value) {
  set_has_sourceroute();
  if (sourceroute_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    sourceroute_ = new ::std::string;
  }
  sourceroute_->assign(value);
  // @@protoc_insertion_point(field_set_char:ChattingMessages.sourceRoute)
}
inline void ChattingMessages::set_sourceroute(const char* value, size_t size) {
  set_has_sourceroute();
  if (sourceroute_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    sourceroute_ = new ::std::string;
  }
  sourceroute_->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:ChattingMessages.sourceRoute)
}
inline ::std::string* ChattingMessages::mutable_sourceroute() {
  set_has_sourceroute();
  if (sourceroute_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    sourceroute_ = new ::std::string;
  }
  // @@protoc_insertion_point(field_mutable:ChattingMessages.sourceRoute)
  return sourceroute_;
}
inline ::std::string* ChattingMessages::release_sourceroute() {
  clear_has_sourceroute();
  if (sourceroute_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    return NULL;
  } else {
    ::std::string* temp = sourceroute_;
    sourceroute_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
    return temp;
  }
}
inline void ChattingMessages::set_allocated_sourceroute(::std::string* sourceroute) {
  if (sourceroute_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete sourceroute_;
  }
  if (sourceroute) {
    set_has_sourceroute();
    sourceroute_ = sourceroute;
  } else {
    clear_has_sourceroute();
    sourceroute_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  }
  // @@protoc_insertion_point(field_set_allocated:ChattingMessages.sourceRoute)
}

// optional int32 sizeFile = 40;
inline bool ChattingMessages::has_sizefile() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void ChattingMessages::set_has_sizefile() {
  _has_bits_[0] |= 0x00000004u;
}
inline void ChattingMessages::clear_has_sizefile() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void ChattingMessages::clear_sizefile() {
  sizefile_ = 0;
  clear_has_sizefile();
}
inline ::google::protobuf::int32 ChattingMessages::sizefile() const {
  // @@protoc_insertion_point(field_get:ChattingMessages.sizeFile)
  return sizefile_;
}
inline void ChattingMessages::set_sizefile(::google::protobuf::int32 value) {
  set_has_sizefile();
  sizefile_ = value;
  // @@protoc_insertion_point(field_set:ChattingMessages.sizeFile)
}


// @@protoc_insertion_point(namespace_scope)

#ifndef SWIG
namespace google {
namespace protobuf {

template <> struct is_proto_enum< ::ChattingMessages_typeMessage> : ::google::protobuf::internal::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::ChattingMessages_typeMessage>() {
  return ::ChattingMessages_typeMessage_descriptor();
}

}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_chat_2eproto__INCLUDED
