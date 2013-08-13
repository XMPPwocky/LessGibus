#include "stdafx.h"
#include "load_shaderprogram.h"
#include "utf8.h"
#include <boost/filesystem.hpp>

namespace fs = boost::filesystem;

ShaderProgram *load_shaderprogram(ResourceManager &rsrc, const protobuf::ShaderProgram &data)
{
	GLuint program = gl::CreateProgram();
	std::vector<GLuint> shaders;
	for (google::protobuf::RepeatedPtrField<protobuf::ShaderProgram::Shader>::const_iterator i = data.shaders().begin();
		i != data.shaders().end();
		i++)
	{
		fs::path filename = (*i).filename();
		
		std::string * shader_text = rsrc.load<std::string>(AssetDirectoryPath / filename);
		const char * shader_text_cstr = shader_text->c_str();

		GLenum shader_type;

		switch((*i).type())
		{
		case protobuf::ShaderProgram::COMPUTE_SHADER:
			shader_type = gl::COMPUTE_SHADER; break;
		case protobuf::ShaderProgram::VERTEX_SHADER:
			shader_type = gl::VERTEX_SHADER; break;
		case protobuf::ShaderProgram::TESS_CONTROL_SHADER:
			shader_type = gl::TESS_CONTROL_SHADER; break;
		case protobuf::ShaderProgram::TESS_EVALUATION_SHADER:
			shader_type = gl::TESS_EVALUATION_SHADER; break;
		case protobuf::ShaderProgram::GEOMETRY_SHADER:
			shader_type = gl::GEOMETRY_SHADER; break;
		case protobuf::ShaderProgram::FRAGMENT_SHADER:
			shader_type = gl::FRAGMENT_SHADER; break;
		default:
			shader_type = gl::COMPUTE_SHADER; // prevent compiler error
			BadShaderException e;
			BOOST_THROW_EXCEPTION(e << string_info("Unknown shader type!"));
			break;
		}

		GLuint shader = gl::CreateShader(shader_type);
		gl::ShaderSource(shader, 1, &shader_text_cstr, nullptr);
		gl::CompileShader(shader);
		GLint status;
		gl::GetShaderiv(shader, gl::COMPILE_STATUS, &status);
		if (status == gl::FALSE_)
		{
			BadShaderException e;
			BOOST_THROW_EXCEPTION(e << string_info("Shader compilation failed!"));
			// TODO: get the actual error message
		}
		shaders.push_back(shader);
	}

	BOOST_FOREACH(GLuint shader, shaders)
	{
		gl::AttachShader(program, shader);
	}

	gl::LinkProgram(program);
	GLint status;
	gl::GetProgramiv(program, gl::LINK_STATUS, &status);
	if (status == gl::FALSE_)
	{
		BadShaderException e;
		BOOST_THROW_EXCEPTION(e << string_info("Program linking failed!"));
		// TODO: get the actual error message
	}

	BOOST_FOREACH(GLuint shader, shaders)
	{
		gl::DetachShader(program, shader);
		gl::DeleteShader(shader);
	}

	return new ShaderProgram(program);
}