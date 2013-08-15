#pragma once
#include "MeshComponent.h"
#include <SDL.h>
#include <SDL_video.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <coment/Entity.h>
#include <coment/World.h>
#include <coment/systems/EntityProcessingSystem.h>
#include "MeshComponent.h"
#include "Mesh.h"
#include <list>
class RenderingSystem :
	public coment::EntitySystem
{
	//layout(std140) uniform GlobalMatrices
	//{
	//	mat4 worldToCameraMatrix;
	//	mat4 cameraToClipMatrix;
	//	mat4 worldToClipMatrix;
	//};
	static const GLuint GLOBAL_MATRICES_BINDING = 0;
	static const unsigned int NUM_GLOBAL_MATRICES = 3;


	static const unsigned int DRAW_DISTANCE = 4096; // TODO: find out how low we can practically set this (in METERS)
	GLuint _matrices_ubo;

	typedef std::list<coment::Entity> SceneGraph;
	SceneGraph _scenegraph;
protected:

//	void begin();
//	void end();
	void onAdded(const coment::Entity &e);
	void onRemoved(const coment::Entity &e);
public:
	RenderingSystem();
	~RenderingSystem();
	void onRegistered();
	void registerComponents();
	void processEntities(std::vector<coment::Entity>& entities);
};

