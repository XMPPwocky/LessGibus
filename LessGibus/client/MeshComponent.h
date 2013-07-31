#pragma once
#include "Mesh.h"

#include <coment/Component.h>
#include <glm.hpp>
#include <gtc/quaternion.hpp>
#include <vector>
#include <array>
#include <tuple>
#include <memory>

struct MeshComponent :
	public coment::Component
{
	std::shared_ptr<Mesh> mesh;
};