#pragma once
#include <vector>
#include <string>
#include "VertexDeclaration.pb.h"

class UnloadedMaterial
{
public:
	UnloadedMaterial(void);
	~UnloadedMaterial(void);

	protobuf::VertexDeclaration vertex_shader_inputs;
	std::vector<std::string> shader_filenames;

};
