// tools.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	std::wstring program = argv[0]; // what we were invoked as
	std::wcout << L"Invoked wrongly!";
	return -1;
}

