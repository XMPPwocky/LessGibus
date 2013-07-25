#pragma once
#include "../core/ConsoleOutputMessage.h"
#include "Tester.h"

class ConsoleOutputMessageTester :
		public Tester
{
public:
	ConsoleOutputMessageTester(void);
	~ConsoleOutputMessageTester(void);

	bool test(void); 
	std::string getTestName(void);
};

