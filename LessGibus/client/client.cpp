// client.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "client.h"
#include "Mesh.pb.h"
#include "load_mesh.h"
#include "load_shaderprogram.h"
#include "ShaderProgram.h"

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

	

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);

	SDL_Init(SDL_INIT_VIDEO); // Init SDL2 (you should check for errors)

	// Create a window. Window mode MUST include SDL_WINDOW_OPENGL for use with OpenGL.
	SDL_Window *window = SDL_CreateWindow(
		"SDL2/OpenGL Demo", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 640, SDL_WINDOW_OPENGL
		);

	SDL_GLContext glcontext = SDL_GL_CreateContext(window);
	SDL_GL_SetAttribute( SDL_GL_DOUBLEBUFFER, 1 );

	glload::LoadFunctions();

	coment::World world;

	ResourceManager resourceManager;
	world.registerManager<ResourceManager>(resourceManager);
	
	MeshRenderSystem mesh_render_system;
	world.registerSystem<MeshRenderSystem>(mesh_render_system);

	coment::Entity e = world.createEntity();
	MeshComponent *mesh = world.addComponent<MeshComponent>(e);

	std::wfstream log;
	log.open("log.txt");
	
	ResourceManager	*rsrc = world.getManager<ResourceManager>();
	std::string *mdata = (rsrc)->load<std::string>("../tools/example.mesh");
	std::string *sdata = (rsrc)->load<std::string>("../tools/example.prog");

	protobuf::Mesh m;
	m.ParseFromString(*mdata);
	mesh->mesh = std::shared_ptr<Mesh>(load_mesh(m));

	protobuf::ShaderProgram prog;
	prog.ParseFromString(*sdata);
	ShaderProgram program = *load_shaderprogram(*rsrc, prog);

	SDL_Event event; 
	Uint8 done = 0;
	Uint32 last_tick = SDL_GetTicks();
	int win_width, win_height;
	SDL_GetWindowSize(window, &win_width, &win_height);
	//gl::Viewport(0,0,win_height,win_width);
	gl::ClearColor(1.0f, 0.431f, 0.78f, 1.0f); // fugly neon pink
	while(!done)  // Enter main loop.
	{
		gl::Clear(gl::COLOR_BUFFER_BIT);
		gl::UseProgram(program.getProgID());

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
		SDL_GL_SwapWindow(window);

		//SDL_Delay(std::max((Sint32)(1 - delta), 0));              // Pause briefly before moving on to the next cycle.
	} 

	// Once finished with OpenGL functions, the SDL_GLContext can be deleted.
	SDL_GL_DeleteContext(glcontext);  

	// Done! Close the window, clean-up and exit the program. 
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
	
	log << L"hello world!";
	return 0;


}
