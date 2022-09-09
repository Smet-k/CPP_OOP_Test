#include <iostream>
//#include "Triangle.h"
//#include "Circle.h"
//#include "Rectangle.h"
#include "Shape.h"
#include <vector>
using namespace std;

class A
{
public:
	std::vector<int> list;

	A()
	{
		list = {};
	}

	void add(int number)
	{
		list.push_back(number);
	}
	void remove(int index)
	{
		std::vector<int> buffer = {};

		for (int i = 0; i < list.size();i++)
		{
			if(i != index){
				buffer.push_back(list[i]);
			}
		}
		list = buffer;
	}

	std::vector<int> get()
	{
		return list;
	}

	void print()
	{
		
		for (int i = 0; i < list.size();i++)
		{
			std::cout << "[" << list[i] << "]" << " ";
		}
	}
};




int main()
{
	Shape shape({ Point(1,1), Point(3,1), Point(3,4), Point(1,4) });
	cout << shape.Perimetr();
}


/*
	(1,3)
	(3,5)
	(5,7)
	(8,4);
	
	1*5 + 3 * 7 + 5 * 4 = 46
	3*3 + 5 * 5 + 7 * 8 = 80

	46 - 90 = -44  / 2
*/