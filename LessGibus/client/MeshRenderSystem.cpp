#include "stdafx.h"
#include "MeshRenderSystem.h"

MeshRenderSystem::MeshRenderSystem(SDL_Window* displayWindow,
    SDL_GLContext *glctx) :
		EntityProcessingSystem()
{
	m_window = displayWindow;
	m_glctx = glctx;

	m_projection = glm::perspective(90.0, 1.0, 0.1, 100.0);
}

void MeshRenderSystem::registered()
{
	registerComponent<MeshComponent>();
}


void MeshRenderSystem::begin()
{
	int win_width, win_height;
	SDL_GetWindowSize(m_window, &win_width, &win_height);
	glViewport(0,0,win_height,win_width);
	//glMatrixMode(GL_MODELVIEW);                     // Select The Modelview Matrix
   // glLoadIdentity();                           // Reset The Modelview Matrix
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//glOrtho(-320,320,320,-320,0,1);
	//gluPerspective(90, 1, 0.1, 100);	
	glLoadMatrixf(glm::value_ptr(m_projection));
	glMatrixMode(GL_MODELVIEW);


	glClearColor(0,0,0,1); // Use OpenGL commands, see the OpenGL reference.
	glClear(GL_COLOR_BUFFER_BIT); // clearing screen
}
void MeshRenderSystem::process(const coment::Entity& entity)
{
		// Note that the glBegin() ... glEnd() OpenGL style used below is actually 
		// obsolete, but it will do for example purposes. For more information, see
		// SDL_GL_GetProcAddress() or find an OpenGL extension loading library.
		glBegin(GL_TRIANGLES); // drawing a multicolored triangle
		glColor3f(1.0f,0.0f,0.0f); glVertex3f(0, 1.0, -1);
		glColor3f(0.0f,1.0f,0.0f); glVertex3f(1.0, -1.0, -1);
		glColor3f(0.0f,0.0f,1.0f); glVertex3f(-1.0, -1.0, -1);
		glEnd();	
}
void MeshRenderSystem::end()
{
	SDL_GL_SwapWindow(m_window);
}