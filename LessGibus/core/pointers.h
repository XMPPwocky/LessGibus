#pragma once

#include "stdafx.h"
#include <memory>

using std::shared_ptr;
using std::unique_ptr;

template <class T>
static T* checkptr(T *ptr)
{
	BOOST_ASSERT(ptr != nullptr);
	return ptr;
}