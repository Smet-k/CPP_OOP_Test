#include "Circle.h"
#include <cmath>
#include <iostream>
Circle::Circle()
{

}

Circle::Circle(Point iP1, Point iP2)
{
	p1 = iP1;
	p2 = iP2;
}

double Circle::perimetr()
{
	return 2 * 3.14 * (p1.distance(p2));
}

double Circle::area()
{
	return pow(3.14 * (p1.distance(p2)), 2);
}

