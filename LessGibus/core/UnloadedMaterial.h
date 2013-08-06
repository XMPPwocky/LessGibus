#pragma once
#include <vector>
#include <string>


#include "VertexDeclaration.h"
class UnloadedMaterial
{
public:
	UnloadedMaterial(void);
	~UnloadedMaterial(void);

	VertexDeclaration vertex_shader_inputs;
	std::vector<std::string> shader_filenames;

};
