#pragma warning(disable : 4996)
#include "Moderator.h"
#include <iostream>
#include <string.h>

bool Moderator::login()
{
	//if (!passwordChanged) {	std::strcpy(password, "12345");	}
	std::string userPassword;
	
	std::cout << "Enter Moderator password: ";
	std::cin >> userPassword;

	return !std::strcmp(password,userPassword.c_str());
}

void Moderator::changePassword()
{
	std::string userPassword;
	std::cout << "Enter Moderator password: ";
	std::cin >> userPassword;

	passwordChanged = true;
	std::strcpy(password, userPassword.c_str());
}

Moderator::~Moderator()
{
	delete[] password;
}