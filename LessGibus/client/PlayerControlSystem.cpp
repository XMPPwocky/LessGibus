#include "stdafx.h"
#include "PlayerControlSystem.h"
#include <SignalManager.h>
#include <pointers.h>
#include "client_signals.h"

PlayerControlSystem::PlayerControlSystem(void)
{
}


PlayerControlSystem::~PlayerControlSystem(void)
{
}

void PlayerControlSystem::onRegistered()
{
	SignalManager *sig_mgr_ptr = checkptr(_world->getManager<SignalManager>());
	_player_input_events_sig_connection = sig_mgr_ptr->mutable_signal<player_input_event_signature>("player_input_events")
		->connect(boost::bind(&PlayerControlSystem::handleInput, this, _1));
}

void PlayerControlSystem::processEntities(std::vector<coment::Entity> &entities)
{
}

void PlayerControlSystem::registerComponents()
{
}

void PlayerControlSystem::handleInput(const PlayerInputEvent &e)
{
	// Do things here! Hooray!
	if (e.keyboard)
	{
		// move the player or something
	}
	if (e.mousemotion)
	{
		// look around or whatever
	}
}