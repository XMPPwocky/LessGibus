#pragma once
#include "testexception.h"
class TestFailedException :
	public TestException
{
	char *message;
public:
	TestFailedException(char *message);
	~TestFailedException(void);
	char *what(void);
};

void FAIL(char *message);