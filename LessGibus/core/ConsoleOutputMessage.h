#pragma once
#include "message.h"
#include <string>

class ConsoleOutputMessage :
	public Message
{
	std::wstring text;
public:
	ConsoleOutputMessage(std::wstring message);
	~ConsoleOutputMessage(void);

	std::wstring getText();
	virtual msgtype_t getType(void);
};

