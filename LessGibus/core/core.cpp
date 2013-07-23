// core.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "core.h"


// This is an example of an exported variable
CORE_API int ncore=0;

// This is an example of an exported function.
CORE_API int fncore(void)
{
	return 42;
}

// This is the constructor of a class that has been exported.
// see core.h for the class definition
Ccore::Ccore()
{
	return;
}
