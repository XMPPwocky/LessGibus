#pragma once
#include <glload/gl_3_3.hpp>
#include <vector>
#include "GLBuffers.h"

struct Mesh
{
	// do we destroy the VAO when we are destroyed?
	bool _own_VAO;

	GLuint _VAO;
	GLBuffers _owned_buffers;

	GLsizei _numtris;
	GLsizei _base_vertex;
public:
	Mesh(
		GLuint VAO,
		GLsizei numtris,
		GLsizei base_vertex = 0,
		std::vector<GLuint> owned_buffers = std::vector<GLuint>(),
		bool own_VAO = true);
	~Mesh(void);
};

