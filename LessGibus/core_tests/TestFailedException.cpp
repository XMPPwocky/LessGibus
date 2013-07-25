#include "stdafx.h"
#include "TestFailedException.h"


TestFailedException::TestFailedException(std::wstring text)
{
	message = text;
}


TestFailedException::~TestFailedException(void)
{
}

const wchar_t *TestFailedException::what() {
	return message.c_str();
}

void FAIL(std::wstring message) {
	throw TestFailedException(message);
}