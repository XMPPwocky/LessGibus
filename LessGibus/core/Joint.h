#pragma once
#include <glm.hpp>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <gtc/quaternion.hpp>


struct Joint
{
public:
	glm::mat4 jointspace_transform;
	glm::mat4 worldspace_to_jointspace_transform;
	typedef GLuint id;
	Joint *parent;
};