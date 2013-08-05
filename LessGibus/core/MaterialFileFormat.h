#pragma once
#include <vector>
#include <string>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/serialization/vector.hpp>

#include "VertexDeclaration.h"
class MaterialFileFormat
{
public:
	MaterialFileFormat(void);
	~MaterialFileFormat(void);

	friend class boost::serialization::access;
	
	template<class Archive>
	void serialize(Archive & ar, const unsigned int version)
	{
		ar & BOOST_SERIALIZATION_NVP(shader_inputs)
			& BOOST_SERIALIZATION_NVP(shader_filenames)
			& BOOST_SERIALIZATION_NVP(texture_filenames);
	}

	VertexDeclaration vertex_shader_inputs;
	std::vector<std::string> shader_filenames;

};

BOOST_CLASS_VERSION(MaterialFileFormat, 1);