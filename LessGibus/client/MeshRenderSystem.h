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
class MeshRenderSystem :
	public coment::EntitySystem
{
	glm::mat4 m_projection;

	typedef std::list<coment::Entity> SceneGraph;

	SceneGraph _scenegraph;
protected:

//	void begin();
//	void end();
	void onAdded(const coment::Entity &e);
	void onRemoved(const coment::Entity &e);
public:
	MeshRenderSystem();
	void registered();
	void processEntities(std::vector<coment::Entity>& entities);
};

