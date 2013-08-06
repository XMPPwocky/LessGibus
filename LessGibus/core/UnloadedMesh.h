#pragma once

#include "Joint.h"
#include "VertexDeclaration.h"
#include "UnloadedMaterial.h"
#include <vector>
#include <string>

static const int MAX_JOINTS_PER_MODEL = 4;

class UnloadedMesh
{
	typedef unsigned int vert_id;
	UnloadedMaterial *material;

	std::vector<std::wstring> texture_filenames;


	VertexDeclaration vertices_format;
	std::string vertex_data;

	std::vector<Joint> joints;
	std::vector<vert_id[3]> triangles;

};
