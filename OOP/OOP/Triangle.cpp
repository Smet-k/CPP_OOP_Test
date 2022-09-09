#include "Triangle.h"
#include <cmath>

Triangle::Triangle()
{

}

Triangle::Triangle(Point iP1, Point iP2, Point iP3)
{
	p1 = iP1;
	p2 = iP2;
	p3 = iP3;
}

double Triangle::perimetr()
{
	if (isTriangle()) {
		double first = p1.distance(p2);
		double second = p2.distance(p3);
		double third = p3.distance(p1);
		
		return first + second + third;
	}
	return 0;
}

double Triangle::area()
{
	if (isTriangle()) {
		double s = perimetr() / 2;
		double first = p1.distance(p2);
		double second = p2.distance(p3);
		double third = p3.distance(p1);
		return sqrt(s * (s - first) * (s - second) * (s - third));
	}
	return 0;
}

bool Triangle::isTriangle()
{
	if(p1.distance(p2) + p2.distance(p3) >  p3.distance(p1)
	&& p2.distance(p3) + p3.distance(p1) >  p1.distance(p2)
	&& p3.distance(p1) + p1.distance(p2) >  p2.distance(p3))
	{ 
		return true;
	}
	return false;
}