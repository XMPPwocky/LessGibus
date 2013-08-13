#pragma once

class ShaderProgram :
	public boost::noncopyable
{
	GLuint _prog_id;

	std::map<const std::string, GLuint> _uniforms;
	std::map<const std::string, GLuint> _uniform_blocks;

public:
	ShaderProgram(GLuint prog_id,
							 std::map<const std::string, GLuint> uniforms,
							 std::map<const std::string, GLuint> interface_blocks);
	~ShaderProgram(void);

	bool operator==(const ShaderProgram &other);
	GLuint getProgID() 
	{
		return _prog_id;
	}
	GLuint getUniformLocation(const std::string name)
	{
		return _uniforms[name];
	}
	GLuint getUniformBlockIndex(const std::string name)
	{
		return _uniform_blocks[name];
	}

};

