#pragma once
#include <coment/systems/EntitySystem.h>

// Turn SDL events into PlayerInput signals.
class SDLInputSystem :
	public coment::EntitySystem
{
public:
	SDLInputSystem(void);
	~SDLInputSystem(void);
};

