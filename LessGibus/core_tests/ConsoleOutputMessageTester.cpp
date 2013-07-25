#include "stdafx.h"
#include "ConsoleOutputMessageTester.h"
#include "TestFailedException.h"

#include <iostream>
#include <memory>

ConsoleOutputMessageTester::ConsoleOutputMessageTester(void)
{
}


ConsoleOutputMessageTester::~ConsoleOutputMessageTester(void)
{
}

void ConsoleOutputMessageTester::test(void) {
	std::unique_ptr<ConsoleOutputMessage> foo(new ConsoleOutputMessage(L"hello world"));
	if (!foo) {
		FAIL("Couldn't allocate memory!");
	}

	ConsoleOutputMessage msg = *foo;

	if (msg.getText() != L"hello world") {
		FAIL("getText() didn't return constructor");
	}

}

std::string ConsoleOutputMessageTester::getTestName() const {
	return "ConsoleOutputMessage";
}