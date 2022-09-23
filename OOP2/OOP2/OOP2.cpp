#include <iostream>
#include <iomanip>
#include <stdexcept>
#include "DateTime.h"
using namespace std;



int main()
{

	DateTime dt1 = DateTime::now(-1);

	cout << dt1;

	cout << "\n";

	cout << dt1;

	cout << "\n";



	DateTime dt = DateTime::now();

	cout << dt;
	
}

