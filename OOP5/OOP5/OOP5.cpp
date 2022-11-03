#include <iostream>
#include "List.h"
#include "Queue.h"
#include "Stack.h"
#include "Dictionary.h"
#include "Exceptions.h"

int divide(int a, int b)
{
	if (b == 0) 
	{ 
		throw Exception("divide(int a, int b)"); 
	}
	return a / b;
}


int main()
{

	List < std::string > myKeys;
	List<int> myValue;
	Stack<int> myStack;
	Dictionary<std::string, int> dic;
	//Exceptions handling

	
	dic.add("key1", 2);
	dic.add("key2", 5);
	myValue = dic.getValues();
	myKeys = dic.getKeys();
	myValue.print();
	myKeys.print();
	/*
	try 
	{
		std::cout << myList.get(2);
		
	}
	catch (StackOverFlowException i)
	{
		std::cout << i.message << "\n";
	}


	try
	{
		myList.remove(5);
	}
	catch (NullReferenceException i)
	{
		std::cout << i.message << "\n";
	}


	try
	{	
	dic.add("key", 1);
	dic.add("key", 2);
	}
	catch (KeyDublicateException i)
	{
		std::cout << i.message << "\n";
	}

	try
	{
		dic.remove(5);
	}
	catch (NullReferenceException i)
	{
		std::cout << i.message << "\n";
	}

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

