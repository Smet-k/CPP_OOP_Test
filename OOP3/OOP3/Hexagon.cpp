#pragma warning(disable : 4996)
#include "Hexagon.h"
#include <string>
#include <cmath>

Hexagon::Hexagon()
{
	a = 2;

}

Hexagon::Hexagon(int a)
{
	this->a = a;
}

int Hexagon::Perimeter()
{
	return a * 6;
}
double Hexagon::Square()
{
	return ((3 * sqrt(3)) / 2) * a;
}

std::ostream& operator <<(std::ostream& output, Hexagon& source)
{
	output << source.toString();
	return output;
}

char* Hexagon::toString(char symbol)
{
	char* output = new char[128];
	std::strcpy(output, "\n");

	int spaces = a - 1;
	int stars = 1;
	for (int j = 0; j < a * 2 - 1; j++)
	{
		for (int i = 0; i < spaces; i++)
		{
			std::strcat(output, " ");
		}


		for (int i = 0; i < stars; i++)
		{
			std::strcat(output, std::string(1, symbol).c_str());
		}

		for (int i = 0; i < a - 1; i++)
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


