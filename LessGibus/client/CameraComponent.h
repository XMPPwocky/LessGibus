#pragma once
#include <coment/Component.h>
#include <coment/EntityId.h>

class CameraComponent :
	public coment::Component
{
public:
	// we track this entity. must have a WorldPositionComponent.
	coment::EntityId target;
	bool track_rotation; // if 1, the target must have a WorldOrientationComponent; we will rotate to follow it.
};

