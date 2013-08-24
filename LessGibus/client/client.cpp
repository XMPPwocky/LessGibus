// client.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "client.h"
#include "Mesh.pb.h"
#include "load_mesh.h"
#include "load_shaderprogram.h"
#include "ShaderProgram.h"
#include "ShaderProgramComponent.h"
#include "camera_matrix_type.h"
#include "CameraSystem.h"
#include "client_signals.h"
#include "SDLInputSystem.h"

#include <iostream>
#include <fstream>
#include "pointers.h"
#include "SignalManager.h"

using boost::signals2::signal;
using std::shared_ptr;

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
		"LessGibus", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 640, SDL_WINDOW_OPENGL
		);

	//SDL_SetRelativeMouseMode(SDL_TRUE);

	SDL_GLContext glcontext = SDL_GL_CreateContext(window);
	SDL_GL_SetAttribute( SDL_GL_DOUBLEBUFFER, 1 );

	glload::LoadFunctions();

	gl::Enable(gl::DEPTH_TEST);
	gl::DepthFunc(gl::LEQUAL);

	SDL_Event event;
	coment::World world;

	ResourceManager resourceManager;
	world.registerManager<ResourceManager>(resourceManager);
	SignalManager signalManager;
	world.registerManager<SignalManager>(signalManager);

	SDLInputSystem sdl_input_system;
	world.registerSystem<SDLInputSystem>(sdl_input_system);
	RenderingSystem render_system;
	world.registerSystem<RenderingSystem>(render_system);
	CameraSystem camera_system;
	world.registerSystem<CameraSystem>(camera_system);

	coment::Entity e = world.createEntity();

	MeshComponent *mesh = checkptr(world.addComponent<MeshComponent>(e));
	ShaderProgramComponent *shaderprog = checkptr(world.addComponent<ShaderProgramComponent>(e));

	std::wfstream log;
	log.open("log.txt");
	
	ResourceManager	*rsrcmgr = checkptr(world.getManager<ResourceManager>());
	SignalManager *sigmgr = checkptr(world.getManager<SignalManager>());
	

	std::shared_ptr<const std::string> mdata = rsrcmgr->load<std::string>("../tools/example.mesh");
	std::shared_ptr<const std::string> sdata = rsrcmgr->load<std::string>("../tools/example.shad");



	protobuf::ShaderProgram prog;
	prog.ParseFromString(*sdata);
	(shaderprog)->prog = std::shared_ptr<ShaderProgram>(load_shaderprogram(*rsrcmgr, prog));

	protobuf::Mesh m;
	m.ParseFromString(*mdata);
	mesh->mesh = std::shared_ptr<Mesh>(load_mesh(m, shaderprog->prog->getVertexAttribLocations()));


	
	std::shared_ptr<boost::signals2::signal<sdl_event_signature>> sdl_sig_ptr =
		sigmgr->mutable_signal<sdl_event_signature>("sdl_events");

	boolean done = false;
	uint32_t last_tick = SDL_GetTicks();
	int win_width, win_height;
	SDL_GetWindowSize(window, &win_width, &win_height);
	//gl::Viewport(0,0,win_height,win_width);
	gl::ClearColor(1.0f, 0.431f, 0.78f, 1.0f); // fugly neon pink

	while(!done)  // Enter main loop.
	{
		uint32_t curr_tick = SDL_GetTicks();
		uint32_t delta = (curr_tick - last_tick);
		last_tick = curr_tick;


		while(SDL_PollEvent(&event))      // Check for events.
		{
			if(event.type == SDL_QUIT || event.type == SDL_QUIT)
				done = true;

			(*sdl_sig_ptr)(event);
		}

		world.loopStart();
		world.setDelta(delta/(1000.0f));
		world.update();

		SDL_GL_SwapWindow(window);

		//SDL_Delay(std::max((Sint32)(10 - delta), 0));              // Pause briefly before moving on to the next cycle.
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
