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

	signal_manager->mutable_signal<sdl_event_signature>("sdl_events")
		->connect(boost::bind(&SDLInputSystem::handleSDLEvent, this, _1));


}

void SDLInputSystem::handleSDLEvent(const SDL_Event &sdl_evt)
{
	PlayerInputEvent player_evt;

	switch (sdl_evt.type)
	{
	case SDL_KEYDOWN:
	case SDL_KEYUP: // two events in one handler!
		{
			PlayerInputEvent::KeyboardEventInfo kbd_info;
			kbd_info.pressed = sdl_evt.type == SDL_KEYDOWN;
			kbd_info.edge = 1;

			// Get the keycode (NOT scancode), look it up in our table of keybinds
			auto i = default_keybinds.find(sdl_evt.key.keysym.sym);
			if (i != default_keybinds.end())
			{
				// this key is bound to something
				Keybinding bind = (*i).second;
 				kbd_info.key = bind;
				player_evt.keyboard = kbd_info;
			}


			break;
		}
	case SDL_MOUSEMOTION:
		PlayerInputEvent::MouseMotionEventInfo mouse_info;
		mouse_info.delta = glm::ivec2(sdl_evt.motion.xrel, sdl_evt.motion.yrel);
		mouse_info.absolute = glm::ivec2(sdl_evt.motion.x, sdl_evt.motion.y);
		player_evt.mousemotion = mouse_info;
		break;
	}

	SignalManager *signal_manager = checkptr(_world->getManager<SignalManager>());
	(*signal_manager->mutable_signal<player_input_event_signature>("player_input_events"))(player_evt); // fire event
}
