#include "stdafx.h"
#include "ShaderProgram.h"


ShaderProgram::ShaderProgram(GLuint prog_id,
							 std::map<const std::string, GLuint> uniforms,
							 std::map<const std::string, GLuint> interface_blocks,
							 std::map<const std::string, GLuint> vertex_attribs)
	: _prog_id(prog_id), _uniforms(uniforms), _uniform_blocks(interface_blocks), _vertex_attribs(vertex_attribs)
{

}


ShaderProgram::~ShaderProgram(void)
{
	gl::DeleteProgram(_prog_id);
}

bool ShaderProgram::operator==(const ShaderProgram &other)
{
	return (_prog_id == other._prog_id);
}