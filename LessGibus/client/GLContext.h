#pragma once

#include <gl/GL.h>
#include <gl/GLU.h>


class GLContext
{
public:

    GLContext();
    ~GLContext();
	void reset();
	void init(HWND hWnd);

private:

	void purge();

    HWND mhWnd;
    HDC mhDC;
    HGLRC mhRC;

};
