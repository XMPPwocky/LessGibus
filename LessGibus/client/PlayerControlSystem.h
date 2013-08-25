#pragma once

#include "stdafx.h"
#include <coment/systems/EntitySystem.h>
#include <coment/World.h>
#include "PlayerInputEvent.h"

// Use PlayerInput signals to control an entity

class PlayerControlSystem :
	public coment::EntitySystem
{
	boost::signals2::scoped_connection _player_input_events_sig_connection;
	void handleInput(const PlayerInputEvent &e);

public:
	PlayerControlSystem(void);
	~PlayerControlSystem(void);
	void processEntities(std::vector<coment::Entity> &entities);
	void registerComponents();
	void onRegistered();
};

