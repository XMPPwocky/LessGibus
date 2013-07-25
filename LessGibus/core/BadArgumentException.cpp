#include "stdafx.h"
#include "BadArgumentException.h"


BadArgumentException::BadArgumentException(char *msg)
{
	text = msg;
}


BadArgumentException::~BadArgumentException(void)
{
}


char *BadArgumentException::what(void) {
	return text;
}