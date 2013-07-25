#pragma once
#include "testexception.h"
#include <string>
class TestFailedException :
	public TestException
{
	std::wstring message;
public:
	TestFailedException(std::wstring message = L"?");
	~TestFailedException(void);
	const wchar_t *what(void);
};

void FAIL(std::wstring message);