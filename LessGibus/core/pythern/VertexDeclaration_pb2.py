# Generated by the protocol buffer compiler.  DO NOT EDIT!
# source: VertexDeclaration.proto

from google.protobuf import descriptor as _descriptor
from google.protobuf import message as _message
from google.protobuf import reflection as _reflection
from google.protobuf import descriptor_pb2
# @@protoc_insertion_point(imports)




DESCRIPTOR = _descriptor.FileDescriptor(
  name='VertexDeclaration.proto',
  package='protobuf',
  serialized_pb='\n\x17VertexDeclaration.proto\x12\x08protobuf\"\x8c\x05\n\x11VertexDeclaration\x12\x39\n\ncomponents\x18\x01 \x03(\x0b\x32%.protobuf.VertexDeclaration.Component\x1a\xbb\x04\n\tComponent\x12<\n\x06\x66ormat\x18\x01 \x02(\x0e\x32,.protobuf.VertexDeclaration.Component.Format\x12L\n\x0einterpretation\x18\x02 \x02(\x0e\x32\x34.protobuf.VertexDeclaration.Component.Interpretation\x12\x0f\n\x07repeats\x18\x03 \x02(\r\x12\x11\n\tattrib_id\x18\x04 \x02(\r\x12\x0c\n\x04name\x18\x05 \x01(\t\"\x85\x02\n\x06\x46ormat\x12\x1f\n\x1b\x46ORMAT_HALF_PRECISION_FLOAT\x10\x01\x12!\n\x1d\x46ORMAT_SINGLE_PRECISION_FLOAT\x10\x02\x12!\n\x1d\x46ORMAT_DOUBLE_PRECISION_FLOAT\x10\x03\x12\x16\n\x12\x46ORMAT_SIGNED_BYTE\x10\x04\x12\x18\n\x14\x46ORMAT_UNSIGNED_BYTE\x10\x05\x12\x17\n\x13\x46ORMAT_SIGNED_SHORT\x10\x06\x12\x19\n\x15\x46ORMAT_UNSIGNED_SHORT\x10\x07\x12\x15\n\x11\x46ORMAT_SIGNED_INT\x10\x08\x12\x17\n\x13\x46ORMAT_UNSIGNED_INT\x10\t\"h\n\x0eInterpretation\x12\x13\n\x0fINTERPRET_FLOAT\x10\x01\x12\x18\n\x14INTERPRET_NORM_FLOAT\x10\x02\x12\x11\n\rINTERPRET_INT\x10\x03\x12\x14\n\x10INTERPRET_DOUBLE\x10\x04')



_VERTEXDECLARATION_COMPONENT_FORMAT = _descriptor.EnumDescriptor(
  name='Format',
  full_name='protobuf.VertexDeclaration.Component.Format',
  filename=None,
  file=DESCRIPTOR,
  values=[
    _descriptor.EnumValueDescriptor(
      name='FORMAT_HALF_PRECISION_FLOAT', index=0, number=1,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='FORMAT_SINGLE_PRECISION_FLOAT', index=1, number=2,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='FORMAT_DOUBLE_PRECISION_FLOAT', index=2, number=3,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='FORMAT_SIGNED_BYTE', index=3, number=4,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='FORMAT_UNSIGNED_BYTE', index=4, number=5,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='FORMAT_SIGNED_SHORT', index=5, number=6,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='FORMAT_UNSIGNED_SHORT', index=6, number=7,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='FORMAT_SIGNED_INT', index=7, number=8,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='FORMAT_UNSIGNED_INT', index=8, number=9,
      options=None,
      type=None),
  ],
  containing_type=None,
  options=None,
  serialized_start=323,
  serialized_end=584,
)

_VERTEXDECLARATION_COMPONENT_INTERPRETATION = _descriptor.EnumDescriptor(
  name='Interpretation',
  full_name='protobuf.VertexDeclaration.Component.Interpretation',
  filename=None,
  file=DESCRIPTOR,
  values=[
    _descriptor.EnumValueDescriptor(
      name='INTERPRET_FLOAT', index=0, number=1,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='INTERPRET_NORM_FLOAT', index=1, number=2,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='INTERPRET_INT', index=2, number=3,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='INTERPRET_DOUBLE', index=3, number=4,
      options=None,
      type=None),
  ],
  containing_type=None,
  options=None,
  serialized_start=586,
  serialized_end=690,
)


_VERTEXDECLARATION_COMPONENT = _descriptor.Descriptor(
  name='Component',
  full_name='protobuf.VertexDeclaration.Component',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='format', full_name='protobuf.VertexDeclaration.Component.format', index=0,
      number=1, type=14, cpp_type=8, label=2,
      has_default_value=False, default_value=1,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='interpretation', full_name='protobuf.VertexDeclaration.Component.interpretation', index=1,
      number=2, type=14, cpp_type=8, label=2,
      has_default_value=False, default_value=1,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='repeats', full_name='protobuf.VertexDeclaration.Component.repeats', index=2,
      number=3, type=13, cpp_type=3, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='attrib_id', full_name='protobuf.VertexDeclaration.Component.attrib_id', index=3,
      number=4, type=13, cpp_type=3, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='name', full_name='protobuf.VertexDeclaration.Component.name', index=4,
      number=5, type=9, cpp_type=9, label=1,
      has_default_value=False, default_value=unicode("", "utf-8"),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
    _VERTEXDECLARATION_COMPONENT_FORMAT,
    _VERTEXDECLARATION_COMPONENT_INTERPRETATION,
  ],
  options=None,
  is_extendable=False,
  extension_ranges=[],
  serialized_start=119,
  serialized_end=690,
)

_VERTEXDECLARATION = _descriptor.Descriptor(
  name='VertexDeclaration',
  full_name='protobuf.VertexDeclaration',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='components', full_name='protobuf.VertexDeclaration.components', index=0,
      number=1, type=11, cpp_type=10, label=3,
      has_default_value=False, default_value=[],
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
  ],
  extensions=[
  ],
  nested_types=[_VERTEXDECLARATION_COMPONENT, ],
  enum_types=[
  ],
  options=None,
  is_extendable=False,
  extension_ranges=[],
  serialized_start=38,
  serialized_end=690,
)

_VERTEXDECLARATION_COMPONENT.fields_by_name['format'].enum_type = _VERTEXDECLARATION_COMPONENT_FORMAT
_VERTEXDECLARATION_COMPONENT.fields_by_name['interpretation'].enum_type = _VERTEXDECLARATION_COMPONENT_INTERPRETATION
_VERTEXDECLARATION_COMPONENT.containing_type = _VERTEXDECLARATION;
_VERTEXDECLARATION_COMPONENT_FORMAT.containing_type = _VERTEXDECLARATION_COMPONENT;
_VERTEXDECLARATION_COMPONENT_INTERPRETATION.containing_type = _VERTEXDECLARATION_COMPONENT;
_VERTEXDECLARATION.fields_by_name['components'].message_type = _VERTEXDECLARATION_COMPONENT
DESCRIPTOR.message_types_by_name['VertexDeclaration'] = _VERTEXDECLARATION

class VertexDeclaration(_message.Message):
  __metaclass__ = _reflection.GeneratedProtocolMessageType

  class Component(_message.Message):
    __metaclass__ = _reflection.GeneratedProtocolMessageType
    DESCRIPTOR = _VERTEXDECLARATION_COMPONENT

    # @@protoc_insertion_point(class_scope:protobuf.VertexDeclaration.Component)
  DESCRIPTOR = _VERTEXDECLARATION

  # @@protoc_insertion_point(class_scope:protobuf.VertexDeclaration)


# @@protoc_insertion_point(module_scope)
