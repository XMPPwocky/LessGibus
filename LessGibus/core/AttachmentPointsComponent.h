#pragma once
#include "stdafx.h"

#include <glm/glm.hpp>

#include <coment\Component.h>
#include <map>

struct AttachmentPoint
{
	// if no parent then use either this entities' PositionComponent or, if that's not present, world origin
	boost::optional<std::string> parent; 

	// turn points in attachment space into points in the parent's space
	glm::mat4 transform;
};

struct AttachmentPointsComponent :
	public coment::Component
{
public:
	std::map<std::string, std::shared_ptr<AttachmentPoint>> points;
};

