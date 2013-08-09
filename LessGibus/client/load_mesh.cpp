#include "stdafx.h"
#include "load_mesh.h"
#include "Mesh.pb.h"
#include "VertexDeclaration.pb.h"
#include "BadDataException.h"
#include "Exception.h"

#include <boost/foreach.hpp>
#include <boost/exception/exception.hpp>

using namespace protobuf;

glmesh::Mesh *load_mesh(const protobuf::Mesh &data)
{
	glmesh::AttributeList attribs;
	const auto cats = data.vertices_format().components();

	google::protobuf::RepeatedPtrField<VertexDeclaration_Component>::const_iterator i;

	int num = 0;
	for (i = cats.begin();
		i != cats.end();
		i++)
	{
		num++;
		(*i).interpretation();

		glmesh::VertexDataType vdt;
		glmesh::AttribDataType adt;
		switch( (*i).format() )
		{
		case VertexDeclaration_Component::INTERPRET_FLOAT:
			adt = glmesh::ADT_FLOAT;
			break;
		case VertexDeclaration_Component::INTERPRET_NORM_FLOAT:
			adt = glmesh::ADT_NORM_FLOAT;
			break;
		case VertexDeclaration_Component::INTERPRET_INT:
			adt = glmesh::ADT_INTEGER;
			break;
		case VertexDeclaration_Component::INTERPRET_DOUBLE:
			adt = glmesh::ADT_DOUBLE;
			break;
		default:
			adt = glmesh::ADT_INTEGER; // prevent compiler error
			BadDataException e;
			e << wstring_info(L"Bad VertexDeclaration!");
			BOOST_THROW_EXCEPTION(e);

		}

		switch( (*i).interpretation() )
		{
		case VertexDeclaration_Component::FORMAT_HALF_PRECISION_FLOAT:
			vdt = glmesh::VDT_HALF_FLOAT;
			break;
		case VertexDeclaration_Component::FORMAT_SINGLE_PRECISION_FLOAT:
			vdt = glmesh::VDT_SINGLE_FLOAT;
			break;
		case VertexDeclaration_Component::FORMAT_DOUBLE_PRECISION_FLOAT:
			vdt = glmesh::VDT_DOUBLE_FLOAT;
			break;
		case VertexDeclaration_Component::FORMAT_SIGNED_BYTE:
			vdt = glmesh::VDT_SIGN_BYTE;
			break;
		case VertexDeclaration_Component::FORMAT_UNSIGNED_BYTE:
			vdt = glmesh::VDT_UNSIGN_BYTE;
			break;
		case VertexDeclaration_Component::FORMAT_SIGNED_SHORT:
			vdt = glmesh::VDT_SIGN_SHORT;
			break;
		case VertexDeclaration_Component::FORMAT_UNSIGNED_SHORT:
			vdt = glmesh::VDT_UNSIGN_SHORT;
			break;
		case VertexDeclaration_Component::FORMAT_SIGNED_INT:
			vdt = glmesh::VDT_SIGN_INT;
			break;
		default:
			vdt = glmesh::VDT_UNSIGN_INT; // prevent compiler error
			BadDataException e;
			e << wstring_info(L"Bad VertexDeclaration!");
			BOOST_THROW_EXCEPTION(e);
		}
		
		attribs.push_back(glmesh::AttribDesc(
			(*i).attrib_id(),
			(*i).repeats(),
			vdt,
			adt));

	}

	return nullptr; //new glmesh::Mesh();
}