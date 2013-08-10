#pragma once

#include <coment/World.h>
#include <coment/Component.h>
#include <vector>
#include <array>
#include <tuple>
#include <memory>
#include "Mesh.h"

struct MeshComponent :
	public coment::Component
{
	std::shared_ptr<Mesh> mesh;
};