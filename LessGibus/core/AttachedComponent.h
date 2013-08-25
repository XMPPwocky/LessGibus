#pragma once

#include <coment/Component.h>
#include <coment/Entity.h>

struct AttachedComponent :
	public coment::Component
{
	coment::Entity attached_to;
	std::string attachment_point;
};

