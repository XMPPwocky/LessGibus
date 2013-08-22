#include "stdafx.h"
#include "load_mesh.h"
#include "Mesh.pb.h"
#include "Mesh.h"
#include "BadDataException.h"
#include "Exception.h"


Mesh *load_mesh(const protobuf::Mesh &data, const std::map<const std::string, GLuint> &attrib_locations)
{
	
	
	// put mesh data in a VBO
	std::string VBO_data;

	// make a buffer and bind it
	GLuint VBO;
	gl::GenBuffers(1, &VBO);
	gl::BindBuffer(gl::ARRAY_BUFFER, VBO);


	const google::protobuf::RepeatedPtrField<protobuf::Mesh::VertexAttrib> vertexattribs = data.vertexattribs();
	size_t VBO_element_size = 0;
	std::map<GLuint, ptrdiff_t> attrib_offsets;
	for (google::protobuf::RepeatedPtrField<protobuf::Mesh::VertexAttrib>::const_iterator i = vertexattribs.begin();
		i != vertexattribs.end();
		i++)
	{
		GLuint curr_location = attrib_locations.at((*i).name());

		// do interleaving/alignment
		// first: how do we need to align this attribute
		ptrdiff_t curr_align; // align to curr_align bytes

		if ((*i).data_type().has_alignment())
		{
			curr_align = static_cast<ptrdiff_t>((*i).data_type().alignment());
		}
		else {
			curr_align = static_cast<ptrdiff_t>((*i).data_type().bytes_per_repeat());
			if ((*i).data_type().repeats() != 0) {
				curr_align = curr_align * 4; // align to 4 * base data type
			}
		}

		// are we aligned?
		if (int misalignment = (VBO_element_size % curr_align)) // ASSIGMENT AND COMPARISON! INTENTIONAL!
		{
			// we are, indeed, misaligned by misalignment bytes
			VBO_element_size += (curr_align - misalignment); // align us
		}

		attrib_offsets[curr_location] = VBO_element_size;

		// add the size of this
		VBO_element_size += static_cast<size_t>(
			(*i).data_type().bytes_per_repeat() * (*i).data_type().repeats());
		

	}



    
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
	// glEnableVertexArray and glVertexAttribPointer and such things

	// unbind buffer
	gl::BindBuffer(gl::ARRAY_BUFFER, 0);
	
	//TODO: handle joints/skinning

	std::vector<GLuint> buffers;
	buffers.push_back(VBO);
	buffers.push_back(elembuffer);


	return new Mesh(VAO, triangles_data.size(), 0, buffers, true);
}