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
		FAIL(L"Couldn't allocate memory!");
	}

	ConsoleOutputMessage msg = *foo;

	if (msg.getText() != L"hello world") {
		FAIL(L"getText() didn't return constructor");
	}

}

std::wstring ConsoleOutputMessageTester::getTestName() const {
	return L"ConsoleOutputMessage";
}