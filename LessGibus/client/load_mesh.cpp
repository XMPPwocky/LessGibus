#include "stdafx.h"
#include "load_mesh.h"
#include "Mesh.pb.h"
#include "Mesh.h"
#include "Declarations.pb.h"
#include "BadDataException.h"
#include "Exception.h"

#include <boost/foreach.hpp>
#include <boost/exception/exception.hpp>
#include <boost/lexical_cast.hpp>

Mesh *load_mesh(const protobuf::Mesh &data)
{
	glmesh::AttributeList attribs;
	const auto cats = data.vertices_format().attributes();
	google::protobuf::RepeatedPtrField<protobuf::VertexDeclaration_VertexAttrib>::const_iterator i;

	int num = 0;
	for (i = cats.begin();
		i != cats.end();
		i++)
	{
		num++;

		glmesh::VertexDataType vdt;
		glmesh::AttribDataType adt;
		switch( (*i).type().interpretation() )
		{
		case protobuf::DataType::INTERPRET_FLOAT:
			adt = glmesh::ADT_FLOAT;
			break;
		case protobuf::DataType::INTERPRET_NORM_FLOAT:
			adt = glmesh::ADT_NORM_FLOAT;
			break;
		case protobuf::DataType::INTERPRET_INT:
			adt = glmesh::ADT_INTEGER;
			break;
		case protobuf::DataType::INTERPRET_DOUBLE:
			adt = glmesh::ADT_DOUBLE;
			break;
		default:
			adt = glmesh::ADT_INTEGER; // prevent compiler error
			BadDataException e;
			e << wstring_info(L"Bad VertexDeclaration!");
			BOOST_THROW_EXCEPTION(e);

		}

		switch( (*i).type().format() )
		{
		case protobuf::DataType::FORMAT_HALF_PRECISION_FLOAT:
			vdt = glmesh::VDT_HALF_FLOAT;
			break;
		case protobuf::DataType::FORMAT_SINGLE_PRECISION_FLOAT:
			vdt = glmesh::VDT_SINGLE_FLOAT;
			break;
		case protobuf::DataType::FORMAT_DOUBLE_PRECISION_FLOAT:
			vdt = glmesh::VDT_DOUBLE_FLOAT;
			break;
		case protobuf::DataType::FORMAT_SIGNED_BYTE:
			vdt = glmesh::VDT_SIGN_BYTE;
			break;
		case protobuf::DataType::FORMAT_UNSIGNED_BYTE:
			vdt = glmesh::VDT_UNSIGN_BYTE;
			break;
		case protobuf::DataType::FORMAT_SIGNED_SHORT:
			vdt = glmesh::VDT_SIGN_SHORT;
			break;
		case protobuf::DataType::FORMAT_UNSIGNED_SHORT:
			vdt = glmesh::VDT_UNSIGN_SHORT;
			break;
		case protobuf::DataType::FORMAT_SIGNED_INT:
			vdt = glmesh::VDT_SIGN_INT;
			break;
		default:
			vdt = glmesh::VDT_UNSIGN_INT; // prevent compiler error
			BadDataException e;
			e << wstring_info(L"Bad VertexDeclaration!");
			BOOST_THROW_EXCEPTION(e);
		}
		
		attribs.push_back(glmesh::AttribDesc(
			((*i).attrib_id()),
			(*i).type().repeats(),
			vdt,
			adt));

	}

	glmesh::VertexFormat vfmt(attribs);
	
	//// put mesh data in a VBO
	std::string mesh_vertex_data = data.vertices_data();

	GLuint VBO;
	gl::GenBuffers(1, &VBO);
	gl::BindBuffer(gl::ARRAY_BUFFER, VBO);
	gl::BufferData(gl::ARRAY_BUFFER,
		mesh_vertex_data.size(),
		mesh_vertex_data.data(),
		gl::STATIC_DRAW);
    
	// and triangles in an element buffer
	std::vector<UINT32> triangles_data;
	triangles_data.reserve(data.triangles_size()*3);
	const auto tris = data.triangles();
	for (google::protobuf::RepeatedPtrField<protobuf::Triangle>::const_iterator i = tris.begin(); i != tris.end(); i++)
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
	vfmt.BindAttributes(0);

	// unbind buffer
	gl::BindBuffer(gl::ARRAY_BUFFER, 0);
	
	//TODO: handle joints/skinning

	std::vector<GLuint> buffers;
	buffers.push_back(VBO);
	buffers.push_back(elembuffer);


	return new Mesh(VAO, triangles_data.size(), 0, buffers, true);
}