#include <iostream>
#include "Shop.h"
#include "Admin.h"
#include "RegularUser.h"
#include "Moderator.h"
Shop::Shop()
{
	users.push_back(new Admin);
	users.push_back(new Moderator);
}

void Shop::login()
{
	int userType;
	std::cout << "Choose role:\n1 - Admin,\n2 - Moderator\n3 - User\n: ";
	std::cin >> userType;

	switch(userType)
	{
		case 1:
			while (!users[userType - 1]->login())
			{
				std::cout << "Incorrect password. Please, try again\n";
			}

			loggedUser = users[userType - 1];
			break;
		case 2: 
			while(!users[userType - 1]->login())
			{
				std::cout << "Incorrect password. Please, try again\n";
			}

			loggedUser = users[userType - 1];
			break;
		case 3: 
			bool isFound = false;

			while(!isFound)
			{
				std::string userName;
				std::cout << "Enter username: ";
				std::cin >> userName;

				std::string userPassword;
				std::cout << "Enter password: ";
				std::cin >> userPassword;

			

				for (int i = 2;i < users.size();i++) 
				{
					RegularUser* user = dynamic_cast<RegularUser*>(users[i]);
					isFound = user->login(userName.c_str(), userPassword.c_str());
					if(isFound)
					{
						loggedUser = users[i];
						break;
					}
			
				}
				break;
			}
	}
}

void Shop::registration()
{
	
	registered.registration();
	
	users.push_back(&registered);

}