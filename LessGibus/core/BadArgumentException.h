#pragma once
#include "Exception.h"
#include <string>

class BadArgumentException :
	public Exception
{
	std::wstring m_msg;
public:
	BadArgumentException(std::wstring msg = L"?");
	virtual ~BadArgumentException(void);
	virtual const wchar_t *what(void);
};

