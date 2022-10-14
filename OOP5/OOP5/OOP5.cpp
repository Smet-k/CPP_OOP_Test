#include <iostream>
#include "List.h"
int main()
{
	List<int> myList;


	myList.add(5);
	myList.add(3);
	myList.add(8);
	myList.add(4);
	//myList.remove(3);
	//myList.print();

	myList = myList.Reverse();
	myList.print();

	std::cout << "\n";

	List<int>* mySecondList = myList.OrderBy(false);
	mySecondList->print();

	//  ??? myList.~List();


}

