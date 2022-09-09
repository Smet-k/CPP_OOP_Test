#include <vector>
#include "Shape.h"

Shape::Shape()
{

}

Shape::Shape(std::vector<Point> input)
{
	points = input;
}

float Shape::Perimetr()
{
	float P = 0;
	for(int i = 0;i < points.size();i++)
	{
		if (i != points.size() - 1) 
		{
			P += points[i].distance(points[i + 1]);
		}
		else
		{
			P += points[i].distance(points[0]);
		}
	}
	return P;
}

float Shape::Area()
{
	float x_sum = 0, y_sum = 0;

	for (int i = 0;i < points.size() - 1;i++)
	{
		x_sum += points[i].getX() * points[i + 1].getY();
	}

	for (int i = 0;i < points.size() - 1;i++)
	{
		y_sum += points[i].getY() * points[i + 1].getX();
	}

	return (x_sum - y_sum) / 2;
}