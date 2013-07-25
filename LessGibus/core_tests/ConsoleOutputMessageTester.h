#pragma once
#include "../core/ConsoleOutputMessage.h"
#include "Tester.h"

class ConsoleOutputMessageTester :
		public Tester
{
public:
	ConsoleOutputMessageTester(void);
	~ConsoleOutputMessageTester(void);

	void test(void); 
	std::wstring getTestName (void) const;
};

