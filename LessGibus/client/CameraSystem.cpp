#include "stdafx.h"
#include "CameraSystem.h"
#include "client_signals.h"


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
	SignalManager &sigmgr = ptr_to_reference(_world->getManager<SignalManager>());
	std::shared_ptr<boost::signals2::signal<get_camera_matrices_signature>> cam_sig_ptr =
		sigmgr.mutable_signal<get_camera_matrices_signature>("get_camera_matrices");

	_get_camera_matrices_sig_connection = cam_sig_ptr->connect(boost::bind(&CameraSystem::camera_matrices, this));

	std::shared_ptr<boost::signals2::signal<sdl_event_signature>> sdl_sig_ptr =
		sigmgr.mutable_signal<sdl_event_signature>("sdl_events");
	_sdl_events_sig_connection = sdl_sig_ptr->connect(boost::bind(&CameraSystem::handleSDLEvent, this, _1));

}

void CameraSystem::registerComponents(void)
{
}
void CameraSystem::processEntities(std::vector<coment::Entity> &ents)
{
}

void CameraSystem::handleSDLEvent(SDL_Event &e)
{
	switch (e.type)
	{
	case SDL_MOUSEMOTION:
		if (_pole->IsDragging())
		{
		accum_translation.x -= e.motion.xrel;
		accum_translation.y -= e.motion.yrel;
		
		_pole->MouseMove(accum_translation);
		}


		break;
	case SDL_MOUSEBUTTONDOWN:
		if (e.button.button == SDL_BUTTON_LEFT)
			_pole->MouseClick(glutil::MB_LEFT_BTN, true, 0, glm::ivec2( accum_translation.x, accum_translation.y ));
		break;
	case SDL_MOUSEBUTTONUP:
		if (e.button.button == SDL_BUTTON_LEFT)
			_pole->MouseClick(glutil::MB_LEFT_BTN, false, 0, glm::ivec2( accum_translation.x, accum_translation.y ));
		break;
	case SDL_KEYDOWN:
		switch (e.key.keysym.scancode)
		{
		case SDL_SCANCODE_W:
			_pole->CharPress('w'); break;
		case SDL_SCANCODE_A:
			_pole->CharPress('a'); break;
		case SDL_SCANCODE_S:
			_pole->CharPress('s'); break;
		case SDL_SCANCODE_D:
			_pole->CharPress('d'); break;
		}
		break;
	case SDL_MOUSEWHEEL:
		_pole->MouseWheel(e.wheel.y, 0, glm::ivec2()); 
		break;
		
	default:
		// no-op
		break;
	}
}

std::map<camera_matrix_type, glm::mat4> CameraSystem::camera_matrices(void)
{
	std::map<camera_matrix_type, glm::mat4> matrices;

	glm::mat4 proj_matrix = glm::perspective(90.0f, 1.0f, ZNEAR, ZFAR);

	matrices[CAMERA_MATRIX_CAMERATOCLIP] = proj_matrix;
	matrices[CAMERA_MATRIX_WORLDTOCAMERA] = _pole->CalcMatrix();
	return matrices;
}