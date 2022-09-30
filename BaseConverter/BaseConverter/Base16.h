#ifndef Base16_h
#define Base16_h
#include <iostream>

class Base16
{
public:
	


	std::string value;

	int intvalue;

	Base16();

	Base16(std::string value);

	int ToBase2();

	int ToBase8();

	int ToBase10();
};

#endif