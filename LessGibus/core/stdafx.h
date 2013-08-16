// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"
#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
#include <Windows.h>


// TODO: reference additional headers your program requires here
#include <iostream>
#include <string>

#include <glload/gl_3_3.hpp>


#include <boost/signals2.hpp>
#include <boost/filesystem.hpp>
#include <boost/exception/all.hpp>
#include <boost/exception/error_info.hpp>
#include <boost/assert.hpp>
#include <boost/any.hpp>
