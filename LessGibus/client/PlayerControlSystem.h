#pragma once
#include <coment/systems/EntitySystem.h>

// Use PlayerInput signals to control an entity

class PlayerControlSystem :
	public coment::EntitySystem
{
public:
	PlayerControlSystem(void);
	~PlayerControlSystem(void);
};

