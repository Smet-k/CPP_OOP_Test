#include "Point.h"

class Circle
{
private:
	Point p1;

	Point p2;

	Circle();

public:

	Circle(Point iP1, Point iP2);

	//Circle();

	double perimetr();

	double area();


};

