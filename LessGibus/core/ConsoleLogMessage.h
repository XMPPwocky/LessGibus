#pragma once
#include "message.h"
#include <string>
class ConsoleLogMessage :
	public Message
{
public:
	ConsoleLogMessage(std::string text);
	virtual ~ConsoleLogMessage(void);
	std::string getBody();
private:
	std::string body;
};

