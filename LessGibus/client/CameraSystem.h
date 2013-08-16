#pragma once
#include <coment/systems/EntityProcessingSystem.h>
#include "Camera.h"
#include "SignalManager.h"
#include "pointers.h"
#include <coment/World.h>
class CameraSystem :
	public coment::EntitySystem
{
	const GLfloat ZFAR; // FIXME: this should be a cvar
	const GLfloat ZNEAR; // and so should this

	boost::signals2::scoped_connection _get_camera_matrices_sig_connection;
	boost::signals2::scoped_connection _sdl_events_sig_connection;
	glm::mat4 _current_worldtocamera_matrix;

	std::unique_ptr<glutil::ViewPole> _pole; // FIXME: this should be on an ENTITY!
	glm::ivec2 accum_translation; // and so should this

	// signal handlers
	std::map<camera_matrix_type, glm::mat4> camera_matrices(void);
	void handleSDLEvent(SDL_Event &e);
protected:
	void onAdded(void);
	void onRemoved(void);
public:
	CameraSystem(void);
	~CameraSystem(void);
	void onRegistered();
	void registerComponents();
	void processEntities(std::vector<coment::Entity>& entities);
};

