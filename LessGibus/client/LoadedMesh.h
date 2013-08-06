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

class UnloadedMesh;

// A mesh that has been loaded into VAOs, VBOs, etc
class LoadedMesh
{
public:
	LoadedMesh(const UnloadedMesh &data);
	LoadedMesh(const LoadedMesh &original);
	~LoadedMesh();
	LoadedMesh &operator=(const LoadedMesh &original);

	std::vector<Joint> joints;

	VertexDeclaration vertices_format;
	GLuint vertex_buffer;
	
	GLuint elem_buffer;

	typedef std::shared_ptr<LoadedMesh> ptr;

};

