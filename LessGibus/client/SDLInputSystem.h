#pragma once
#include <coment/systems/EntitySystem.h>

// Turn SDL events into PlayerInput signals.
class SDLInputSystem :
	public coment::EntitySystem
{
	boost::signals2::scoped_connection _sdl_events_sig_connection;
	boost::signals2::scoped_connection _player_input_events_sig_connection;

	void handleSDLEvent(const SDL_Event &e);
public:
	SDLInputSystem(void);
	~SDLInputSystem(void);
	void onRegistered(void);

	void processEntities(std::vector<coment::Entity> &e) {}
	void registerComponents() {}
};

