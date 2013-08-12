#include "stdafx.h"
#include "load_mesh.h"
#include "Mesh.pb.h"
#include "Mesh.h"
#include "BadDataException.h"
#include "Exception.h"

#include <boost/foreach.hpp>
#include <boost/exception/exception.hpp>
#include <boost/lexical_cast.hpp>

Mesh *load_mesh(const protobuf::Mesh &data)
{
	
	
	//// put mesh data in a VBO
	const google::protobuf::RepeatedPtrField<protobuf::Mesh::Vertex> vertices = data.vertices();
	std::string VBO_data;

	const size_t POSITION_SIZE = sizeof(float) * 3;
	const size_t TEXCOORD_SIZE = sizeof(float) * 3;
	const size_t NORMAL_SIZE = sizeof(float) * 3;

	const unsigned int POSITION_VERTEXATTRIB = 0;
	const unsigned int TEXCOORD_VERTEXATTRIB = 1;
	const unsigned int NORMAL_VERTEXATTRIB = 2;



	const bool has_position = vertices.Get(0).has_position();
	const bool has_texcoord = vertices.Get(0).has_texcoord();
	const bool has_normal = vertices.Get(0).has_normal();

	size_t POSITION_OFFSET = 0;
	size_t TEXCOORD_OFFSET = POSITION_OFFSET + (has_position ? POSITION_SIZE : 0);
	size_t NORMAL_OFFSET = TEXCOORD_OFFSET + (has_texcoord ? TEXCOORD_SIZE : 0);

	const size_t VBO_element_size = 
		(has_position ? POSITION_SIZE : 0) +
		(has_texcoord ? TEXCOORD_SIZE : 0) +
		(has_normal ? NORMAL_SIZE : 0);

	for (google::protobuf::RepeatedPtrField<protobuf::Mesh::Vertex>::const_iterator i = vertices.begin();
		i != vertices.end();
		i++)
	{
		std::string this_vertex;
		this_vertex.reserve(VBO_element_size);

		BOOST_ASSERT(has_position == (*i).has_position());
		BOOST_ASSERT(has_texcoord == (*i).has_texcoord());
		BOOST_ASSERT(has_normal == (*i).has_normal());

		if ( has_position )
		{
			float position_data[3];
			position_data[0] = (*i).position().x();
			position_data[1] = (*i).position().y();
			position_data[2] = (*i).position().z();

			char *v = reinterpret_cast<char *>(position_data);

			this_vertex.replace(POSITION_OFFSET, TEXCOORD_OFFSET, reinterpret_cast<char *>(position_data), sizeof(float)*3);
		}

		if ( has_texcoord )
		{
			float texcoord_data[(sizeof(float)*3)];
			texcoord_data[0] = (*i).texcoord().x();
			texcoord_data[1] = (*i).texcoord().y();
			texcoord_data[2] = (*i).texcoord().z();

			this_vertex.replace(TEXCOORD_OFFSET, NORMAL_OFFSET, reinterpret_cast<char *>(texcoord_data), sizeof(float)*3);
		}
		
		if ( has_normal )
		{
			float normal_data[(sizeof(float)*3)];
			normal_data[0] = (*i).normal().x();
			normal_data[1] = (*i).normal().y();
			normal_data[2] = (*i).normal().z();

			this_vertex.replace(NORMAL_OFFSET, VBO_element_size, reinterpret_cast<char *>(normal_data), sizeof(float)*3);
		}


		VBO_data.append(this_vertex);

	}
	GLuint VBO;
	gl::GenBuffers(1, &VBO);
	gl::BindBuffer(gl::ARRAY_BUFFER, VBO);
	gl::BufferData(gl::ARRAY_BUFFER,
		VBO_data.size(),
		VBO_data.data(),
		gl::STATIC_DRAW);
    
	// and triangles in an element buffer
	std::vector<UINT32> triangles_data;
	triangles_data.reserve(data.triangles_size()*3);
	const auto tris = data.triangles();
	for (google::protobuf::RepeatedPtrField<protobuf::Mesh::Triangle>::const_iterator i = tris.begin(); i != tris.end(); i++)
	{
		triangles_data.push_back((*i).vert1());
		triangles_data.push_back((*i).vert2());
		triangles_data.push_back((*i).vert3());
	}
	GLuint elembuffer;
	gl::GenBuffers(1, &elembuffer);
	gl::BindBuffer(gl::ELEMENT_ARRAY_BUFFER, elembuffer);
	gl::BufferData(gl::ELEMENT_ARRAY_BUFFER,
		triangles_data.size() * sizeof(UINT32),
		triangles_data.data(),
		gl::STATIC_DRAW);


	// and the format in a VAO
	GLuint VAO;
	gl::GenVertexArrays(1, &VAO);
	// gl::BindBuffer(gl::ARRAY_BUFFER, VBO); // already done
	gl::BindVertexArray(VAO);
	gl::BindBuffer(gl::ELEMENT_ARRAY_BUFFER, elembuffer); // make sure the element buffer is used
	
	{
		if (has_position)
		{
			gl::EnableVertexAttribArray(POSITION_VERTEXATTRIB);
			gl::VertexAttribPointer(
				POSITION_VERTEXATTRIB,
				3,
				gl::FLOAT,
				gl::FALSE_,
				VBO_element_size,
				(GLvoid *)POSITION_OFFSET
			);
		}
		
		if (has_texcoord)
		{
			gl::EnableVertexAttribArray(TEXCOORD_VERTEXATTRIB);
			gl::VertexAttribPointer(
				TEXCOORD_VERTEXATTRIB,
				3,
				gl::FLOAT,
				gl::FALSE_,
				VBO_element_size,
				(GLvoid *)TEXCOORD_OFFSET
			);
		}
		if (has_normal) 
		{
			gl::EnableVertexAttribArray(NORMAL_VERTEXATTRIB);
			gl::VertexAttribPointer(
				NORMAL_VERTEXATTRIB,
				3,
				gl::FLOAT,
				gl::FALSE_,
				VBO_element_size,
				(GLvoid *)NORMAL_OFFSET
			);
		}
	}

	// unbind buffer
	gl::BindBuffer(gl::ARRAY_BUFFER, 0);
	
	//TODO: handle joints/skinning

	std::vector<GLuint> buffers;
	buffers.push_back(VBO);
	buffers.push_back(elembuffer);


	return new Mesh(VAO, triangles_data.size(), 0, buffers, true);
}