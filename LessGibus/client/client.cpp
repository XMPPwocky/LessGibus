// client.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "client.h"


#include <iostream>
#include <fstream>

#define MAX_LOADSTRING 100

class Butt
{
public:
	Butt(void);
	~Butt(void);
};

Butt::Butt(){};
Butt::~Butt() {
	int foo = 1;
}

int APIENTRY _tWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPTSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);
	UNREFERENCED_PARAMETER(hInstance);
	UNREFERENCED_PARAMETER(nCmdShow);

	//SDL_Init(SDL_INIT_VIDEO);
	//atexit(SDL_Quit);
    //SDL_Window* displayWindow;
    //SDL_Renderer* displayRenderer;
    //SDL_RendererInfo displayRendererInfo;
    //SDL_CreateWindowAndRenderer(800, 600, SDL_WINDOW_OPENGL, &displayWindow, &displayRenderer);
    //SDL_GetRendererInfo(displayRenderer, &displayRendererInfo);
    ///*TODO: Check that we have OpenGL */
    //if ((displayRendererInfo.flags & SDL_RENDERER_ACCELERATED) == 0 || 
    //    (displayRendererInfo.flags & SDL_RENDERER_TARGETTEXTURE) == 0) {
    //    /*TODO: Handle this. We have no render surface and not accelerated. */
    //}
    //

    //SDL_Delay(5000);
    //SDL_Quit();
	std::ofstream log;
	log.open("log.txt");

	EntityManager ent_mgr;
	ProcessorManager proc_mgr;

	Entity *butt = new Entity(ent_mgr);
	Entity booty = *butt;

	std::unique_ptr<Butt> anus(new Butt);
	anus = NULL;
	delete butt;

	return 0;


}
