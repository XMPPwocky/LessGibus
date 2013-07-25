#pragma once
#include <exception>
#include <string>

class TestException :
	public std::exception
{
	std::wstring message;
public:
	TestException(std::wstring message = L"?");
	virtual ~TestException(void);
	virtual const wchar_t *what(void);
};

