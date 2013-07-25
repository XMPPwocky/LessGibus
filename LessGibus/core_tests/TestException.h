#pragma once
#include <exception>

class TestException :
	public std::exception
{
public:
	TestException(void);
	virtual ~TestException(void);
};

