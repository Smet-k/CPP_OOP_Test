#include <vector>
#include "Point.h"

class Shape
{
private:
	Shape();

public:
	std::vector<Point> points;

	Shape(std::vector<Point> input);

	float Perimetr();

	float Area();

};