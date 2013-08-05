#pragma once
#include <cstdint>
#include <intrin.h>
#include <boost/archive/text_oarchive.hpp>

#include <boost/archive/text_iarchive.hpp>

struct VertexDeclaration {
private:
	friend class boost::serialization::access;

	template<class Archive>
	void serialize(Archive & ar, const unsigned int version)
	{
		ar & _components;
	}
public:
    enum Components {
      POSITION    = (1 << 0),
      COLOR0      = (1 << 1),
      COLOR1      = (1 << 2),
      COLOR2      = (1 << 3),
      COLOR3      = (1 << 4),
      COLOR4      = (1 << 5),
      COLOR5      = (1 << 6),
      COLOR6      = (1 << 7),
      COLOR7      = (1 << 8),
      TEXCOORD0   = (1 << 9),
      TEXCOORD1   = (1 << 10),
      TEXCOORD2   = (1 << 11),
      TEXCOORD3   = (1 << 12),
      TEXCOORD4   = (1 << 13),
      TEXCOORD5   = (1 << 14),
      TEXCOORD6   = (1 << 15),
      TEXCOORD7   = (1 << 16),
      NORMAL      = (1 << 17),
      TANGENT     = (1 << 18),
      BITANGENT   = (1 << 19),
      BONEINDICES = (1 << 20),
      BONEWEIGHTS = (1 << 21)
    };
	static const size_t cs[32];
    size_t size() const;
	size_t offset(Components) const;
    uint32_t _components;
};

BOOST_CLASS_VERSION(VertexDeclaration, 1);