#include <iostream>
#ifndef Base10_h
#define Base10_h
class Base10
{
public:

	int value;

	Base10();

	Base10(int value);

	int ToBase2();

	int ToBase8();

	const char* ToBase16();
};

#endif