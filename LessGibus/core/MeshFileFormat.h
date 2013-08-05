#pragma once
#include "glm_serializers.h"

#include "Mesh.h"
#include "Joint.h"

#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/serialization/vector.hpp>
#include <string>

class MeshFileFormat
{
	friend class boost::serialization::access;
	
	template<class Archive>
	void serialize(Archive & ar, const unsigned int version)
	{
		ar & shader_names;
		ar & texture;

		ar & vertices_format;
		ar & vertex_data;
		ar & joints;
		ar & triangles;
	}


	std::vector<std::wstring> shader_names;
	std::wstring texture;

	VertexDeclaration vertices_format;
	std::string vertex_data;

	std::vector<Joint> joints;
	std::vector<Mesh::vert_id[3]> triangles;

	
public:
};
BOOST_CLASS_TRACKING(MeshFileFormat, false);
BOOST_CLASS_VERSION(MeshFileFormat, 1);