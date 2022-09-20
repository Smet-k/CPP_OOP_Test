#include <iostream>
#include <iomanip>
#include <stdexcept>
#include "DateTime.h"
using namespace std;

// polymorphism
	/*
protected:
	const char* name;

public:
	void action()
	{
		std::cout << "Player" << name << "\n";
	}
};

class FirstPlayer : public Player
{
public:
	FirstPlayer()
	{
		this->name = "FirstPlayer";
	}
	*/


int main()
{
	//DateTime::DateTime(int day, int month, int year, int hours, int minutes, int seconds)
	DateTime dt = {12, 12, 2022, 12, 12, 12, -1};

	cout << dt.timezone.offset;
	
}

