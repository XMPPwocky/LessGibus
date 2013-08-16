#pragma once
#include <coment/systems/EntityProcessingSystem.h>
#include "Camera.h"
#include "SignalManager.h"
#include "pointers.h"
#include <coment/World.h>
class CameraSystem :
	public coment::EntitySystem
{
	boost::signals2::scoped_connection _get_camera_matrices_sig_connection;
	glm::mat4 _current_worldtocamera_matrix;

	std::map<camera_matrix_type, glm::mat4> camera_matrices(void);
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

