#include "stdafx.h"
#include "SDLInputSystem.h"
#include <SignalManager.h>
#include <pointers.h>
#include <coment/World.h>
#include "client_signals.h"
#include "PlayerInputEvent.h"

SDLInputSystem::SDLInputSystem(void)
{

}


SDLInputSystem::~SDLInputSystem(void)
{
}

void SDLInputSystem::onRegistered(void)
{
	SignalManager *signal_manager = checkptr(_world->getManager<SignalManager>());
	std::shared_ptr<boost::signals2::signal<sdl_event_signature>> sdl_events_sig_ptr =
		signal_manager->mutable_signal<sdl_event_signature>("sdl_events");
	sdl_events_sig_ptr->connect(boost::bind(&SDLInputSystem::handleSDLEvent, this, _1));

}

void SDLInputSystem::handleSDLEvent(const SDL_Event &sdl_evt)
{
	PlayerInputEvent player_evt;

	switch (sdl_evt.type)
	{
	case SDL_KEYDOWN:
		// Get the keycode (NOT scancode), look it up in our table of keybinds
		break;
	case SDL_KEYUP:
		// same thing
		break;
	case SDL_MOUSEMOTION:
		// trivial
		break;
	}
}