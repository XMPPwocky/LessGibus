#pragma once
#include "Joint.h"
#include "VertexDeclaration.h"
#include "ResourceManager.h"
#include "Material.h"
#include <glm.hpp>
#include <gtc/quaternion.hpp>
#include <array>
#include <tuple>
#include <vector>

#include <Shlwapi.h>

class MeshFileFormat;

class Mesh
{
public:
	Mesh(const MeshFileFormat &data);
	Mesh(const Mesh &original);
	~Mesh();
	Mesh &operator=(const Mesh &original);

	static const int MAX_JOINTS_PER_VERTEX = 4;


	std::vector<Joint> joints;

	VertexDeclaration vertices_format;
	typedef glm::uint vert_id;
	GLuint vertex_buffer;
	
	GLuint elem_buffer;

};

