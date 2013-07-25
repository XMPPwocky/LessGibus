#pragma once
#include "messagechannel.h"
class ConsoleMessageChannel :
	public MessageChannel
{
public:
	ConsoleMessageChannel(void);
	~ConsoleMessageChannel(void);
};

