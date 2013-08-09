// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
// Windows Header Files:
#include <windows.h>

// C RunTime Header Files
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>


// TODO: reference additional headers your program requires here
#pragma warning(push)

#include <glload/gl_3_3.hpp>
#include <glload/gl_load.hpp>
#include <glmesh/glmesh.h>

#pragma warning(pop)

#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>