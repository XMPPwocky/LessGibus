#pragma once
class Camera
{
public:
	Camera(void);
	~Camera(void);

	glm::mat4 getMatrix();

	typedef std::shared_ptr<Camera> ptr;
};

