#include "stdafx.h"
#include "ConsoleInputMessage.h"


ConsoleInputMessage::ConsoleInputMessage(std::wstring msg)
{
	text = msg;
}


ConsoleInputMessage::~ConsoleInputMessage(void)
{
}

std::wstring ConsoleInputMessage::getText(void)
{
	return text;
}

msgtype_t ConsoleInputMessage::getType(void) {
	return MSGTYPE_CONSOLEINPUT;
}