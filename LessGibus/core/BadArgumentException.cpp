#include "stdafx.h"
#include "BadArgumentException.h"


BadArgumentException::BadArgumentException(std::wstring message)
{
	text = message;
}


BadArgumentException::~BadArgumentException(void)
{
}


const wchar_t *BadArgumentException::what(void) {
	return text.c_str();
}