#include "stdafx.h"
#include "GLBuffers.h"

GLBuffers::GLBuffers(unsigned int numbuffers)
{
	_buffers.reserve(numbuffers);
	gl::GenBuffers(numbuffers, _buffers.data());
}

GLBuffers::GLBuffers(std::vector<GLuint> buffers)
	: _buffers(buffers)
{
}

const std::vector<GLuint> GLBuffers::getBuffers(void) const
{
	return _buffers;
}

const GLuint &GLBuffers::operator[](const size_t index)
{
	return _buffers[index];
}

GLBuffers::~GLBuffers(void)
{
	gl::DeleteBuffers(_buffers.size(), _buffers.data());
}
