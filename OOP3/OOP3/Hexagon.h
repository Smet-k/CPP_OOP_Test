#include <iostream>
#include "Figure.h"

class Hexagon : Figure
{
public:
	Hexagon();

	Hexagon(int a);

	int Perimeter();
	double Square();

	char* toString(char symbol = '*');

	friend std::ostream& operator <<(std::ostream& output, Hexagon& source);
};