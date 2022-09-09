#include "Point.h"
#include <cmath>

Point::Point()
{
	x = 0;
	y = 0;
}

Point::Point(int inputX, int inputY)
{
	x = inputX;
	y = inputY;
}

int Point::getX()
{
	return x;
}

int Point::getY()
{
	return y;
}

void Point::setX(int input)
{
	x = input;
}

void Point::setY(int input)
{
	y = input;
}

double Point::distance(Point destination)
{
	int first = destination.x - x;
	int second = destination.y - y;

	return sqrt(pow(first, 2) + pow(second, 2));
}

// 1, 1 -> 2,2
// 1,1 -> 10,1