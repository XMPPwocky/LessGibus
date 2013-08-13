#include "ShaderProgram.pb.h"
#include "ShaderProgram.h"
#include "ResourceManager.h"
#include "boost\exception\exception.hpp"
#include <boost/foreach.hpp>
#include "Exception.h"
struct BadShaderException :
	virtual boost::exception, virtual std::exception
{
};



ShaderProgram *load_shaderprogram(ResourceManager &rsrc, const protobuf::ShaderProgram &data);