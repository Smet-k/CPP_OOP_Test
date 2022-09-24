#pragma warning(disable : 4996)
#include "Rectangle.h"
#include <string>
Rectangle::Rectangle()
{
	this->a = 1;
	this->b = 1;
}

Rectangle::Rectangle(int a, int b)
{
	this->a = a;
	this->b = b;
}

int Rectangle::Perimeter()
{
	return 2 * (a + b);
}

int Rectangle::Square()
{
	return a * b;
}

char* Rectangle::toString(char symbol)
{
	char* output = new char[128];
	std::strcpy(output, "\n");
	for (int j = 0;j < b;j++)
	{
		for (int i = 0; i < a;i++)
		{
			std::strcat(output, std::string(1, symbol).c_str());
		}
		std::strcat(output, "\n");
	}
	return output;
}

std::ostream& operator <<(std::ostream& output, Rectangle& source)
{
	output << source.toString();
	return output;
}