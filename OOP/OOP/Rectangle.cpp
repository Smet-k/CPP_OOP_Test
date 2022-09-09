#include "Rectangle.h"

Rectangle::Rectangle()
{

}

Rectangle::Rectangle(Point iP1,Point iP2, Point iP3, Point iP4)
{
	p1 = iP1;
	p2 = iP2;
	p3 = iP3;
	p4 = iP4;
}

Rectangle::Rectangle(int iWidth, int iHeight)
{
	p1 = Point(0,0);
	p2 = Point(iWidth,0);
	p3 = Point(iWidth, iHeight);
	p4 = Point(0, iHeight);
}

double Rectangle::perimetr()
{
	if (isRectangle()) {
		double first = p1.distance(p2);
		double second = p2.distance(p3);

		return (first + second) * 2;
	}

	return 0;
}

double Rectangle::area()
{
	if (isRectangle()) {
		double first = p1.distance(p2);
		double second = p2.distance(p3);

		return first * second;
	}

	return 0;
}

bool Rectangle::isRectangle()
{
	return p1.getX() == p4.getX()
		&& p1.getY() == p2.getY()
		&& p2.getX() == p3.getX()
		&& p3.getY() == p4.getY();
}

/*
P1: x = 1, y = 1
P2: x = 3, y = 1
P3: x = 3, y = 4
P4: x = 1, y = 4
*/