#pragma once
#include "message.h"
#include "core.h"
#include <string>
class CORE_API ConsoleLogMessage :
	public Message
{
public:
	ConsoleLogMessage(std::string text);
	virtual ~ConsoleLogMessage(void);
	std::string getBody();
private:
	std::string body;
};

