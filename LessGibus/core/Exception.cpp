#include "stdafx.h"
#include "Exception.h"


Exception::Exception(std::wstring msg)
{
	m_msg = msg;
}


Exception::~Exception(void)
{
}

const wchar_t *Exception::what(void)
{
	return m_msg.c_str();
}