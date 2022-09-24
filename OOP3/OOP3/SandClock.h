#include <iostream>
#include "Figure.h"

class SandClock:Figure
{
public:
	SandClock();

	SandClock(int a, int b);

	int Perimeter();
	double Square();

	char* toString(char symbol = '*');

	friend std::ostream& operator <<(std::ostream& output, SandClock& source);
};