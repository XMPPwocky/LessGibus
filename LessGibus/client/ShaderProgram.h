#pragma once

class ShaderProgram :
	public boost::noncopyable
{
	GLuint _prog_id;

	std::map<const std::string, GLuint> _uniforms;
	std::map<const std::string, GLuint> _uniform_blocks;
	std::map<const std::string, GLuint> _vertex_attribs;

public:
	ShaderProgram(GLuint prog_id,
							 std::map<const std::string, GLuint> uniforms,
							 std::map<const std::string, GLuint> interface_blocks,
							 std::map<const std::string, GLuint> vertex_attribs);
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

	const std::map<const std::string, GLuint> &getVertexAttribLocations()
	{
		return _vertex_attribs;
	}
};

