#pragma once
#include "Joint.h"
#include "VertexDeclaration.h"
#include <gl/GL.h>
#include <glm.hpp>
#include <gtc/quaternion.hpp>
#include <array>
#include <tuple>
#include <vector>

struct Mesh
{
public:
	static const int MAX_JOINTS_PER_VERTEX = 4;
	// inspired by Doom 3's MD5Mesh format
	struct Material
	{
		GLuint shader_program;
		GLuint texture;
	};

	struct Triangle
	{
		GLsizei v1, v2, v3;
	};

	Material mat;

	std::vector<Joint> joints;

	VertexDeclaration vertices_format;
	std::vector<unsigned int> vertex_buffer;

	std::vector<Triangle> triangles;

};

