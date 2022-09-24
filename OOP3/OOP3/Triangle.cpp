#pragma warning(disable : 4996)
#include "Triangle.h"
#include <string>
#include <cmath>
Triangle::Triangle()
{
	this->a = 1;
	this->b = 1;
	this->c = 1;
}

Triangle::Triangle(int a, int b, int c)
{
	this->a = a;
	this->b = b;
	this->c = c;
}

int Triangle::Perimeter()
{
	return a + b + c;
}

double Triangle::Square()
{
	double p = Perimeter() / 2.0;
	

	return sqrt(p * (p - a) * (p - b) * (p - c));
}

char* Triangle::toString(char symbol)
{
	char* output = new char[128];
	std::strcpy(output, "\n");

	
	if (a == b && a != c || c == b && c != a || a == c && a != b) 
	{
		int base, side;
		if (a == b) { base = c; }
		if (c == b) { base = a; }
		if (a == c) { base = b; }
	
		for (int j = 0; j < base; j++)
		{
			for (int i = 0; i < base - (j + 1); i++)
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

	int hyp = 0;
	if (a > b && a > c) { hyp = a; }
	if (b > a && b > c) { hyp = b; }
	if (c > b && c > a) { hyp = c; }

	float first = sqrt(pow(a, 2) + pow(b, 2)); float second = sqrt(pow(c, 2) + pow(b, 2)); float third = sqrt(pow(a, 2) + pow(c, 2));
	if (hyp == first || hyp == second || hyp == third)
	{
		int direction;
		do {
			std::cout << "which way do you want to draw - 1. left-right, 2. right left: ";
			std::cin >> direction;
		} while (direction < 1 || direction > 2);
		if (direction == 1) 
		{
			for (int i = 0;i < hyp;i++)
			{
				for (int j = 0;j < i;j++)
				{
					std::strcat(output, std::string(1, symbol).c_str());
				}
				std::strcat(output, "\n");
			}
		}
		else if (direction == 2)
		{
			for (int i = 0;i < hyp;i++)
			{
				for (int j = hyp;j > 0;j--)
				{
					if (j <= i) 
					{
						std::strcat(output, std::string(1, symbol).c_str());
					}
					else 
					{
						std::strcat(output, " ");
					}
				}
				std::strcat(output, "\n");
			}
		}
	}
	return output;
}

std::ostream& operator <<(std::ostream& output, Triangle& source)
{
	output << source.toString();
	return output;
}