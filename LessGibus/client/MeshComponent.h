#pragma once

#include <coment/Component.h>
#include <vector>
#include <array>
#include <tuple>
#include <memory>

struct MeshComponent :
	public coment::Component
{
	std::shared_ptr<glmesh::Mesh> mesh;
};