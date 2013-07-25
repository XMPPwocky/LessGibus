#include "stdafx.h"
#include "ConsoleOutputMessage.h"


ConsoleOutputMessage::ConsoleOutputMessage(std::wstring message)
{
	text = message;
}


ConsoleOutputMessage::~ConsoleOutputMessage(void)
{
}

std::wstring ConsoleOutputMessage::getText(void)
{
	return text;
}

msgtype_t ConsoleOutputMessage::getType(void) {
	return MSGTYPE_CONSOLEOUTPUT;
}