#pragma once
#include "stdafx.h"

class GLBuffers
	: public boost::noncopyable
{
	std::vector<GLuint> _buffers;
public:
	GLBuffers::GLBuffers(unsigned int numbuffers);
	GLBuffers(std::vector<GLuint> buffers = std::vector<GLuint>());
	(const GLuint) &operator[](const size_t index);
	~GLBuffers(void);
	const std::vector<GLuint> get_buffers(void) const;
};

