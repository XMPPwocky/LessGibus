// client.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "client.h"

#include <iostream>
#include <fstream>

#define MAX_LOADSTRING 100

int APIENTRY _tWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPTSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);
	UNREFERENCED_PARAMETER(hInstance);
	UNREFERENCED_PARAMETER(nCmdShow);
	
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);

	SDL_Init(SDL_INIT_VIDEO); // Init SDL2 (you should check for errors)

	// Create a window. Window mode MUST include SDL_WINDOW_OPENGL for use with OpenGL.
	SDL_Window *window = SDL_CreateWindow(
		"SDL2/OpenGL Demo", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 640, SDL_WINDOW_OPENGL
		);

	// Create an OpenGL context associated with the window.
	SDL_GLContext glcontext = SDL_GL_CreateContext(window);
	SDL_GL_SetAttribute( SDL_GL_DOUBLEBUFFER, 1 );
	// Now, regular OpenGL functions ...
	glMatrixMode(GL_PROJECTION|GL_MODELVIEW);
	glLoadIdentity();

	// ... can be used alongside SDL2.
	float x = 0.0, y = 30.0;

	// make our world
	coment::World world;

	MeshRenderSystem mesh_render_system(window, &glcontext);
	world.registerSystem(mesh_render_system);

	coment::Entity e = world.createEntity();
	MeshComponent *mesh = world.addComponent<MeshComponent>(e);

	VertexDeclaration foo;
	foo._components = (VertexDeclaration::POSITION | VertexDeclaration::COLOR1);
	int bx = foo.size();
	int cx = foo.offset(VertexDeclaration::COLOR1);
	SDL_Event event; 
	Uint8 done = 0;
	Uint32 last_tick = SDL_GetTicks();
	while(!done)  // Enter main loop.
	{

		Uint32 curr_tick = SDL_GetTicks();
		Uint32 delta = (curr_tick - last_tick);
		last_tick = curr_tick;

		while(SDL_PollEvent(&event))      // Check for events.
		{
			if(event.type == SDL_QUIT || event.type == SDL_QUIT)
				done = 1;
		}

		world.loopStart();
		world.setDelta(delta/(1000.0f));
		world.update();


				
		//SDL_Delay(std::max((Sint32)(1 - delta), 0));              // Pause briefly before moving on to the next cycle.
	} 

	// Once finished with OpenGL functions, the SDL_GLContext can be deleted.
	SDL_GL_DeleteContext(glcontext);  

	// Done! Close the window, clean-up and exit the program. 
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
	std::wfstream log;
	log.open("log.txt");
	log << L"hello world!";
	return 0;


}
