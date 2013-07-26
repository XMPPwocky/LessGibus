#include "stdafx.h"
#include "BadArgumentException.h"

BadArgumentException::BadArgumentException(std::wstring msg) :
	Exception(msg)
{
	m_msg = msg;
}


BadArgumentException::~BadArgumentException(void)
{
}

const wchar_t *BadArgumentException::what(void)
{
	return m_msg.c_str();
}