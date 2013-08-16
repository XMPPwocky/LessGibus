#include "stdafx.h"
#include "CameraSystem.h"
#include "client_signals.h"


CameraSystem::CameraSystem(void)
{
}


CameraSystem::~CameraSystem(void)
{
}

void CameraSystem::onRegistered(void)
{
	SignalManager &sigmgr = ptr_to_reference(_world->getManager<SignalManager>());
	std::shared_ptr<boost::signals2::signal<get_camera_matrices_signature>> cam_sig_ptr =
		sigmgr.mutable_signal<get_camera_matrices_signature>("get_camera_matrices");


	_get_camera_matrices_sig_connection = cam_sig_ptr->connect(boost::bind(&CameraSystem::camera_matrices, this));
}

void CameraSystem::registerComponents(void)
{
}
void CameraSystem::processEntities(std::vector<coment::Entity> &ents)
{
}

std::map<camera_matrix_type, glm::mat4> CameraSystem::camera_matrices(void)
{
	std::map<camera_matrix_type, glm::mat4> matrices;
	matrices[CAMERA_MATRIX_CAMERATOCLIP] = glm::perspective(90.0f, 1.0f, 0.01f, 1.0f);
	matrices[CAMERA_MATRIX_WORLDTOCAMERA] = _current_worldtocamera_matrix;
	return matrices;
}