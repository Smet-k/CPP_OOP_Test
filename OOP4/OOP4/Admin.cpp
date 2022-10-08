#include <iostream>
#include "Admin.h"
#include <string.h>
bool Admin::login()
{
	std::string userPassword;

	std::cout << "Enter admin password: ";
	std::cin >> userPassword;

	return !std::strcmp(password,userPassword.c_str());
}

Admin::~Admin()
{
	delete[] password;
}