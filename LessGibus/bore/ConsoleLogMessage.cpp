#include "stdafx.h"
#include "ConsoleLogMessage.h"


ConsoleLogMessage::ConsoleLogMessage(std::string text)
{
	body = text;
}


ConsoleLogMessage::~ConsoleLogMessage(void)
{
}

std::string ConsoleLogMessage::getBody() {
	return body;
}