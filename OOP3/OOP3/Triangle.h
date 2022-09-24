#include <iostream>
#include "Figure.h"

class Triangle : Figure
{
public:
	Triangle();

	Triangle(int a, int b,int c);

	int Perimeter();
	double Square();

	char* toString(char symbol = '* ');

	friend std::ostream& operator <<(std::ostream& output, Triangle& source);
};