#include "stdafx.h"
#include "CameraSystem.h"
#include "client_signals.h"
#include <glutil/MousePoles.h>
#include "CameraComponent.h"

CameraSystem::CameraSystem(void) :
	ZFAR(500), ZNEAR(0.5)
{
	glutil::ViewScale vs;
	glutil::ViewData vd;
	vd.targetPos = glm::vec3(0,0,0);
	vd.radius = 4.0f;
	vd.orient = glm::quat();
	vd.degSpinRotation = 0.0f;
	vs.largePosOffset = 1.0f;
	vs.smallPosOffset = 0.3f;
	vs.maxRadius = ZFAR;
	vs.minRadius = ZNEAR;
	vs.rotationScale = 0.5f;
	vs.largeRadiusDelta = 1.0f;
	vs.smallRadiusDelta = 0.3f;
	_pole = std::unique_ptr<glutil::ViewPole>(new glutil::ViewPole(vd, vs));
}


CameraSystem::~CameraSystem(void)
{
}

void CameraSystem::onRegistered(void)
{
	SignalManager *sigmgr = checkptr(_world->getManager<SignalManager>());
	std::shared_ptr<boost::signals2::signal<get_camera_matrices_signature>> cam_sig_ptr =
		sigmgr->mutable_signal<get_camera_matrices_signature>("get_camera_matrices");

	_get_camera_matrices_sig_connection = cam_sig_ptr->connect(boost::bind(&CameraSystem::camera_matrices, this));

}

void CameraSystem::registerComponents(void)
{
	registerComponent<CameraComponent>();
}

void CameraSystem::processEntities(std::vector<coment::Entity> &ents)
{
}

std::map<camera_matrix_type, glm::mat4> CameraSystem::camera_matrices(void)
{
	std::map<camera_matrix_type, glm::mat4> matrices;

	glm::mat4 proj_matrix = glm::perspective(90.0f, 1.0f, ZNEAR, ZFAR);

	matrices[CAMERA_MATRIX_CAMERATOCLIP] = proj_matrix;
	matrices[CAMERA_MATRIX_WORLDTOCAMERA] = _pole->CalcMatrix();
	return matrices;
}