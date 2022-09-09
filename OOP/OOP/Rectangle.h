#include "Point.h"

class Rectangle
{
private:
	Point p1;

	Point p2;

	Point p3;

	Point p4;

	Rectangle();

	bool isRectangle();
public:

	Rectangle(Point iP1, Point iP2, Point iP3, Point iP4);

	Rectangle(int width, int height);

	double perimetr();

	double area();


};
