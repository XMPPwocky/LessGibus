#pragma once
class ShaderProgram
{
	GLuint _prog_id;
public:
	ShaderProgram(GLuint prog_id);
	~ShaderProgram(void);

	GLuint getProgID() 
	{
		return _prog_id;
	}
};

