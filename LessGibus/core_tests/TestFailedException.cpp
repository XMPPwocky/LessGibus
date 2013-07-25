#include "stdafx.h"
#include "TestFailedException.h"


TestFailedException::TestFailedException(char *text)
{
	message = text;
}


TestFailedException::~TestFailedException(void)
{
}

char *TestFailedException::what() {
	return message;
}

void FAIL(char *message) {
	throw TestFailedException(message);
}