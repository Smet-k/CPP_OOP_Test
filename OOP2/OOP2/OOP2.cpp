#include <iostream>
#include "DateTime.h"

using namespace std;


int main()
{
	DateTime dt{ DateTime::now() };

	//DateTime(int day, int month, int year, int hours, int minutes, int seconds);
	DateTime dt2{ 2, 9, 2022, 15, 10, 0};
	


	DateTime Result = dt.substract(dt2);
	cout << Result.toString() << "\n";
	/*
	Result = dt.add(dt2);
	cout << Result.toString() << "\n";
	Result = dt.max(dt2);
	cout << Result.toString() << "\n";
	Result = dt.min(dt2);
	cout << Result.toString() << "\n";
	Result = dt.addYears(1);
	cout << Result.toString() << "\n";
	Result = dt.addMonths(2);
	cout << Result.toString() << "\n";
	Result = dt.addDays(7);
	cout << Result.toString() << "\n";
	Result = dt.addHours(1);
	cout << Result.toString() << "\n";
	Result = dt.addMinutes(30);
	cout << Result.toString() << "\n";
	Result = dt.addSeconds(20);
	cout << Result.toString() << "\n";
	*/
	//cout << dt2.toString() << "\n";
}

