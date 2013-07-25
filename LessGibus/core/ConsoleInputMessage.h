#pragma once
#include "message.h"
#include <string>

class ConsoleInputMessage :
	public Message
{
	std::wstring text;
public:
	ConsoleInputMessage(std::wstring msg);
	~ConsoleInputMessage(void);

	std::wstring getText(void);
	virtual msgtype_t getType(void);
};

