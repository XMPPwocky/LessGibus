// core_tests.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include "ConsoleOutputMessageTester.h"
#include "TestFailedException.h"
#include <array>

const unsigned int NUM_TESTS = 0;
typedef std::array<Tester *, NUM_TESTS> test_array_t;
test_array_t TESTS = 
{
};
int _tmain(int argc, _TCHAR* argv[])
{
	unsigned int failed = 0;

	test_array_t::iterator i;
	try {
		for (i = TESTS.begin(); i != TESTS.end(); i++) {
			(**i).test();
			std::wcout << L"[PASS]\t" << ((**i).getTestName())<< L"\n";
		}
	}
	catch (TestFailedException& e) {
		failed++;
		std::wcout << L"[FAIL]\t" << ((**i).getTestName()) << L":\t" << e.what() << L"\n";
	}

	if (failed == 0) {
		std::wcout << L"All tests passed!\n";
	}
	else {
		std::wcout << failed << L" tests of " << NUM_TESTS << L" failed.\n";
	}
	getc(stdin);

	return (failed == 0 ? 0 : 1);

}

