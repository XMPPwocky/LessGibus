#include "stdafx.h"
#include "TestException.h"


TestException::TestException(std::wstring text)
{
	message = text;
}


TestException::~TestException(void)
{
}

const wchar_t *TestException::what() {
	return message.c_str();
}