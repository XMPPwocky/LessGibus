// tools.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	std::ofstream butt("test.txt");
	MeshFileFormat f;
	boost::archive::xml_oarchive oa(butt, boost::archive::no_header);
	oa << BOOST_SERIALIZATION_NVP(f);
	std::wstring program = argv[0]; // what we were invoked as
	std::wcout << L"Invoked wrongly!";
	return -1;
}

