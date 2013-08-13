#pragma once
#include <coment/managers/Manager.h>
#include "Camera.h"

class CameraManager :
	public coment::Manager
{
	std::map<const std::string, Camera::ptr> _cams;

public:
	CameraManager(void);
	virtual ~CameraManager(void);

	void setCamera(const std::string &name, Camera::ptr cam);
	Camera::ptr getCamera(const std::string &name);
};

