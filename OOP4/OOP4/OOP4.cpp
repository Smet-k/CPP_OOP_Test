#include <iostream>
#include "Shop.h"
#include "Moderator.h"

int main()
{
	Shop shop;
	
	std::string answer;

	while(true)
	{
		std::cout << "Choose an option: \n";
		std::cout << "1.Login \n";
		std::cout << "2.Register\n";
		std::cout << ":";
		std::cin >> answer;
		if (answer == "1") { shop.login(); }
		if (answer == "2") { shop.registration(); }
	
	
	}
}

