#pragma once
#include "stdafx.h"
#include "ShaderProgram.pb.h"
#include "ShaderProgram.h"
#include "ResourceManager.h"


#include "Exception.h"
struct BadShaderException :
	virtual boost::exception, virtual std::exception
{
};



ShaderProgram *load_shaderprogram(ResourceManager &rsrc, const protobuf::ShaderProgram &data);