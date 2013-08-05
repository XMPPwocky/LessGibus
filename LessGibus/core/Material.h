#pragma once
#include "MaterialFileFormat.h"

class Material
{
public:
	Material(MaterialFileFormat &data);
	Material(const Material &original);
	Material &operator=(const Material &original);
	~Material(void);
};

