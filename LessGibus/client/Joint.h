#pragma once
#include <glm.hpp>
#include <gtc/quaternion.hpp>

#include <gl/GL.h>

struct Joint
{
	Joint *parent;
	glm::vec3 position;
	glm::quat orientation;
	typedef GLushort id;
};