#pragma once
#include "MeshComponent.h"
#include <SDL.h>
#include <SDL_video.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>
#include <coment/Entity.h>
#include <coment/systems/EntityProcessingSystem.h>

class MeshRenderSystem :
	public coment::EntityProcessingSystem
{
	SDL_Window *m_window;
	SDL_GLContext *m_glctx;
	glm::mat4 m_projection;
protected:

	void begin();
	void end();
public:
	MeshRenderSystem(SDL_Window* displayWindow,
		SDL_GLContext* ctx);
	void registered();
	void process(const coment::Entity& entity);
};

