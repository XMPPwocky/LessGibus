#pragma once
#include <exception>
#include <string>

class BadArgumentException :
	public std::exception
{
	std::wstring text;
public:
	BadArgumentException(std::wstring message = L"?");
	virtual ~BadArgumentException(void);

	virtual const wchar_t *what(void);
};

