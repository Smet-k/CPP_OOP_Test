#ifndef Base8_h
#define Base8_h
class Base8
{
public:

	int value;

	Base8();

	Base8(int value);

	int ToBase2();

	int ToBase10();

	const char* ToBase16();
};

#endif