#include <iostream>
#include "Figure.h"

class Rhombus:Figure
{
public:
	Rhombus();

	Rhombus(int a, int b, int c);

	int Perimeter();
	double Square();

	char* toString(char symbol = '*');

	friend std::ostream& operator <<(std::ostream& output, Rhombus& source);
};