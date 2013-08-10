#include "stdafx.h"
#include "Mesh.h"

Mesh::Mesh(
	GLuint VAO,
	GLsizei numtris,
	GLsizei base_vertex ,
	std::vector<GLuint> owned_buffers,
	bool own_VAO)
	: _owned_buffers(owned_buffers),
	_VAO(VAO),
	_own_VAO(own_VAO),
	_numtris(numtris),
	_base_vertex(base_vertex)
{
}


Mesh::~Mesh(void)
{
	if (_own_VAO)
		gl::DeleteVertexArrays(1, &_VAO);
}

