#pragma once
#include "boost\exception\exception.hpp"
struct BadDataException :
	virtual boost::exception, virtual std::exception
{
};

