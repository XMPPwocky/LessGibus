#pragma once
#include <glutil/MousePoles.h>

enum camera_matrix_type
{
	CAMERA_MATRIX_WORLDTOCAMERA,
	CAMERA_MATRIX_CAMERATOCLIP
};

class Camera
{

public:
	std::shared_ptr<glutil::ViewPole> pole;
	Camera(void);
	~Camera(void);

	glm::mat4 getMatrix();

	typedef std::shared_ptr<Camera> ptr;
};

