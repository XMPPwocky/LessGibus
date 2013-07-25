// core_tests.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include "ConsoleOutputMessageTester.h"
#include "TestFailedException.h"
#include <array>

const unsigned int NUM_TESTS = 1;
typedef std::array<Tester *, NUM_TESTS> test_array_t;
test_array_t TESTS = 
{
	new ConsoleOutputMessageTester(),
};
int _tmain(int argc, _TCHAR* argv[])
{
	unsigned int failed = 0;

	test_array_t::iterator i;
	try {
		for (i = TESTS.begin(); i != TESTS.end(); i++) {
			(**i).test();
			std::cout << "[PASS]\t" << ((**i).getTestName())<< "\n";
		}
	}
	catch (TestFailedException& e) {
		failed++;
		std::cout << "[FAIL]\t" << ((**i).getTestName()) << ":\t" << e.what() << "\n";
	}

	if (failed == 0) {
		std::cout << "All tests passed!\n";
	}
	else {
		std::cout << failed << " tests of " << NUM_TESTS << " failed.\n";
	}
	getc(stdin);

	return (failed == 0 ? 0 : 1);

}

