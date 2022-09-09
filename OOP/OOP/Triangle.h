#include "Point.h"

class Triangle
{
private:
	Point p1;

	Point p2;

	Point p3;

	Triangle();

	bool isTriangle();
public:

	Triangle(Point iP1, Point iP2, Point iP3);

	double perimetr();

	double area();

};

