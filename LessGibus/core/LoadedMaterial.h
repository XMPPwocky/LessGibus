#pragma once
#include "UnloadedMaterial.h"

class LoadedMaterial
{
public:
	LoadedMaterial(UnloadedMaterial &data);
	LoadedMaterial(const LoadedMaterial &original);
	LoadedMaterial &operator=(const LoadedMaterial &original);
	~LoadedMaterial(void);
};

