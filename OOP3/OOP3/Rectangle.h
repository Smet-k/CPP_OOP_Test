#include <iostream>
#include "Figure.h"
class Rectangle : Figure
{
public:
	Rectangle();

	Rectangle(int a, int b);

	int Perimeter();
	int Square();

	char* toString(char symbol = '*');

	friend std::ostream& operator <<(std::ostream& output, Rectangle& source);
};