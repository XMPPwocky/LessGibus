#pragma once
#include <exception>

class BadArgumentException :
	public std::exception
{
	char *text;
public:
	BadArgumentException(char *msg);
	virtual ~BadArgumentException(void);

	virtual char *what(void);
};

