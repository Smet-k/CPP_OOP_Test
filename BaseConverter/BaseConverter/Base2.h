#ifndef Base2_h
#define Base2_h

class Base2
{
public:

	int value;

	Base2();
	
	Base2(int value);

	int ToBase10();

	int ToBase8();

	const char* ToBase16();

};

#endif