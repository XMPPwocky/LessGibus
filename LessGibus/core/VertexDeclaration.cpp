#include "stdafx.h"
#include "VertexDeclaration.h"

const size_t VertexDeclaration::cs[] =
{
    12,
    16, 16, 16, 16, 16, 16, 16, 16,
    12, 12, 12, 12, 12, 12, 12, 12,
    12, 12, 12,
    4, 4,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};

size_t VertexDeclaration::size() const {


  size_t size = 0;
  uint32_t components = _components;
  while (components) {
	unsigned long foo;
	_BitScanForward(&foo, components);
    size += cs[foo];
    components &= (components - 1); 
  }

  return size;
}

size_t VertexDeclaration::offset(VertexDeclaration::Components component) const
{
  size_t size = 0;
  uint32_t components = _components;
  size_t i = 0;
  unsigned long foo = 0;
  while (_BitScanForward(&foo, components) && components && ((1 << foo) < component)) {
    size += cs[foo];
    components &= (components - 1); 
  }

  return size;
}

