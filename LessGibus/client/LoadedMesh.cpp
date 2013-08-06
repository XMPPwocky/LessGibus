#include "stdafx.h"
#include "LoadedMesh.h"
#include "UnloadedMesh.h"
#include "get_file_contents.h"

BoundMesh::~BoundMesh()
{
}

template <>
BoundMesh::ptr ResourceManager::loadResource(std::string name)
{
	std::string data = get_file_contents(name.c_str());

	BoundMesh::ptr mesh = nullptr;

	return mesh;
}
