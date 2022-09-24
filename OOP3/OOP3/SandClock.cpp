#pragma warning(disable : 4996)
#include <iostream>
#include "SandClock.h"

SandClock::SandClock()
{
	this->a = 4;
	this->b = 4;
}

SandClock::SandClock(int a, int b)
{
	this->a = a;
	this->b = b;
}

int SandClock::Perimeter()
{
	return (a + b) * 2;
}
double SandClock::Square()
{
	double p = Perimeter() / 2.0;


	return sqrt(p * (p - a) * (p - b) * (p - b)) * 2;
}

char* SandClock::toString(char symbol)
{
	char* output = new char[128];
	std::strcpy(output, "\n");

	for (int j = a; j > 0; j--)
	{
		for (int i = 0; i <= a - (j + 1); i++)
		{
			std::strcat(output, " ");
		}

		for (int i = 0; i < j * 2 + 1; i++)
		{
			std::strcat(output, std::string(1, symbol).c_str());
		}
		std::strcat(output, "\n");
	}

	for (int j = 0; j <= a; j++)
	{
		for (int i = 0; i <= a - (j + 1); i++)
		{
			std::strcat(output, " ");
		}

		for (int i = 0; i < j * 2 + 1; i++)
		{
			std::strcat(output, std::string(1, symbol).c_str());
		}
		std::strcat(output, "\n");
	}
	return output;
}

std::ostream& operator <<(std::ostream& output, SandClock& source)
{
	output << source.toString();
	return output;
}