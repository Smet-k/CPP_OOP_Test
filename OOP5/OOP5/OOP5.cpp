#include <iostream>
#include "List.h"
#include "Queue.h"
#include "Stack.h"
#include "Dictionary.h"

int main()
{

	List<int> myList;
	myList.add(5);
	myList.add(3);
	myList.add(8);
	myList.add(4);

	myList.print();
	std::cout << "\n";

	Stack<int> myStack;
	myStack.add(5);
	myStack.add(3);
	myStack.add(8);
	myStack.add(4);

	myStack.print();
	std::cout << "\n";

	Stack<int> stack = myList.ToStack();
	stack.print();
	std::cout << "\n";

	//List<int> list = myStack.ToList();
	//list.print();
	std::cout << "\n";
	/*
	KeyValuePair<std::string, int> seventh;
	seventh.key = "seventh";
	seventh.value = 7;

	Dictionary<std::string, int> dic;
	dic.add("second", 5);
	dic.add("first", 1);
	dic.add("third", 10);
	//dic.add(fourth);
	Dictionary<std::string, int> dic2;
	dic2.add("fourth", 24);
	dic2.add("fifth", 16);
	dic2.add("sixth", 5);

	Dictionary<std::string, int> dic3;
	dic + dic2;
	//std::cout << dic["second"] << "\n";
	//std::cout << dic["fourth"] << "\n";
	//std::cout << dic.length() << "- length \n";

	dic  + seventh;

	char* test = dic.toString();
	std::cout << test;
	//Queue<int> myList2;
	*/
	
}

