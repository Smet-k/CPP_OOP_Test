#pragma warning(disable : 4996)
#include <iostream>
#include "Rhombus.h"

Rhombus::Rhombus()
{
	a = 2;
	b = 2;
	c = 2;
}

Rhombus::Rhombus(int a, int b, int c)
{
	this->a = a;
	this->b = b;
	this->c = c;
}

int Rhombus::Perimeter()
{
	return a * 4;
}
double Rhombus::Square()
{
	return b * c / 2;
}

char* Rhombus::toString(char symbol)
{
	char* output = new char[128];
	std::strcpy(output, "\n");

	int spaces = a - 1;
	int stars = 1;
	for (int j = 0; j < a * 2; j++)
	{
		for (int i = 0; i < spaces; i++)
		{
			std::strcat(output, " ");
		}


		for (int i = 0; i < stars; i++)
		{
			std::strcat(output, std::string(1, symbol).c_str());
		}



		if (j < a - 1)
		{
			spaces--;
			stars += 2;
		}
		else
		{
			spaces++;
			stars -= 2;
		}
		std::strcat(output, "\n");
	}
	return output;
}

std::ostream& operator <<(std::ostream& output, Rhombus& source)
{
	output << source.toString();
	return output;
}