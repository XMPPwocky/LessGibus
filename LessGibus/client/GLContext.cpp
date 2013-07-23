#include "stdafx.h"
#include "GLContext.h"

// shoutout to http://www.nullterminator.net/opengl32.html

GLContext::GLContext(void)
{
	reset();
}


GLContext::~GLContext(void)
{
	purge();
}

void GLContext::init(HWND hWnd)
{
    // remember the window handle (HWND)
	mhWnd = hWnd;

	// get the device context (DC)
	mhDC = GetDC( mhWnd );

	// set the pixel format for the DC
	PIXELFORMATDESCRIPTOR pfd;
	ZeroMemory( &pfd, sizeof( pfd ) );
	pfd.nSize = sizeof( pfd );
	pfd.nVersion = 1;
	pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL |
					PFD_DOUBLEBUFFER;
	pfd.iPixelType = PFD_TYPE_RGBA;
	pfd.cColorBits = 24;
	pfd.cDepthBits = 16;
	pfd.iLayerType = PFD_MAIN_PLANE;
	int format = ChoosePixelFormat( mhDC, &pfd );
	SetPixelFormat( mhDC, format, &pfd );

	// create the render context (RC)
	mhRC = wglCreateContext( mhDC );

	// make it the current render context
	wglMakeCurrent( mhDC, mhRC );
}


void GLContext::purge()
{
    if ( mhRC )
    {
        wglMakeCurrent( NULL, NULL );
        wglDeleteContext( mhRC );
    }
    if ( mhWnd && mhDC )
    {
        ReleaseDC( mhWnd, mhDC );
    }
    reset();
}

void GLContext::reset()
{
    mhWnd = NULL;
    mhDC = NULL;
    mhRC = NULL;
}