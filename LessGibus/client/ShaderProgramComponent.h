#pragma once

#include <coment/World.h>
#include <coment/Component.h>
#include <vector>
#include <array>
#include <tuple>
#include <memory>
#include "ShaderProgram.h"

class ShaderProgramComponent :
	public coment::Component
{
public:
	std::shared_ptr<ShaderProgram> prog;
};

