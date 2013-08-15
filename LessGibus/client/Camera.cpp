#include "stdafx.h"
#include "Camera.h"


Camera::Camera(void)
{
	glutil::ViewScale vs;
	glutil::ViewData vd;
	vd.targetPos = glm::vec3(0,0,0);
	vd.radius = 1.0f;
	vd.orient = glm::quat();
	vd.degSpinRotation = 0.0f;
	vs.largePosOffset = 0.1f;
	vs.smallPosOffset = 0.03f;
	vs.maxRadius = 1.0f;
	vs.minRadius = 0.01f;
	vs.rotationScale = 1.0f;
	vs.largeRadiusDelta = 0.1f;
	vs.smallRadiusDelta = 0.03f;
	pole = std::shared_ptr<glutil::ViewPole>(new glutil::ViewPole(vd, vs));
}


Camera::~Camera(void)
{
}

glm::mat4 Camera::getMatrix(void)
{
	return pole->CalcMatrix();
}