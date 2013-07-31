#pragma once
#include "Mesh.h"

#include <coment/Component.h>
#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>
#include <vector>
#include <array>
#include <tuple>
#include <memory>

struct MeshComponent :
	public coment::Component
{
	std::shared_ptr<Mesh> mesh;
};