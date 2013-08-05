#include "stdafx.h"
#include "Mesh.h"
#include "MeshFileFormat.h"
#include "get_file_contents.h"

Mesh::~Mesh()
{
}

template <>
std::shared_ptr<Mesh> ResourceManager::loadResource(std::string name)
{
	std::string data = get_file_contents(name.c_str());

	std::shared_ptr<Mesh> mesh = nullptr;

	return mesh;
}
