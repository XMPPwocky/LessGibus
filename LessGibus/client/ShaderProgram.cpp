#include "stdafx.h"
#include "ShaderProgram.h"


ShaderProgram::ShaderProgram(GLuint prog_id)
	: _prog_id(prog_id)
{

}


ShaderProgram::~ShaderProgram(void)
{
	gl::DeleteProgram(_prog_id);
}
