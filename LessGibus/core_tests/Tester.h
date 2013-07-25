#pragma once
#include <string> 

class Tester
{
public:
	Tester(void);
	virtual ~Tester(void);
	virtual void test(void) =0;
	virtual std::string getTestName(void) =0;
};

