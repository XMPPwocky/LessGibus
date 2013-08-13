#include "stdafx.h"
#include "CameraManager.h"


CameraManager::CameraManager(void) :
	Manager()
{
}


CameraManager::~CameraManager(void)
{
}

Camera::ptr CameraManager::getCamera(const std::string &name)
{
	return _cams[name];
}

void CameraManager::setCamera(const std::string &name, Camera::ptr cam)
{
	_cams[name] = cam;
}