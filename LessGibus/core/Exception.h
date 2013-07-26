#pragma once
#include <exception>
#include <string>

class Exception :
	public std::exception
{
	std::wstring m_msg;
public:
	Exception(std::wstring msg = L"?");
	virtual ~Exception(void);
	virtual const wchar_t *what(void);
};

