#pragma warning (disable:4996)
#include "RegularUser.h"
#include <string.h>
#include <iostream>

bool RegularUser::login()
{
	std::string userName;
	std::cout << "Enter username: ";
	std::cin >> userName;

	std::string userPassword;
	std::cout << "Enter Moderator password: ";
	std::cin >> userPassword;

	return login(userName.c_str(), userPassword.c_str());
}

bool RegularUser::login(const char* username, const char* password)
{

	return !std::strcmp(this->username, username) && !std::strcmp(this->password, password);
		   
}
/*
	char* username;
	char* password;
	char* name;
	char* surname;
	char* phone;
*/
void RegularUser::registration()
{
	std::string input;

	std::cout << "Enter your username: ";
	std::cin >> input;
	//v1
	username = new char[input.length() + 1];
	std::strcpy(username, input.c_str());

	//v2
	std::cout << "Enter your password: ";
	std::cin >> input;
	password = new char[input.length() + 1];
	std::strcpy(password, input.c_str());
	//password = input.c_str();


	std::cout << "Enter your name: ";
	std::cin >> input;
	name = new char[input.length() + 1];
	std::strcpy(name, input.c_str());
	//name = input.c_str();

	std::cout << "Enter your surname: ";
	std::cin >> input;
	surname = new char[input.length() + 1];
	std::strcpy(surname, input.c_str());
	//surname = input.c_str();

	std::cout << "Enter your phone number: ";
	std::cin >> input;
	phone = new char[input.length() + 1];
	std::strcpy(phone, input.c_str());
	//phone = input.c_str();
	

	
}

void RegularUser::changePassword()
{
	std::string userPassword;
	std::cout << "Enter Moderator password: ";
	std::cin >> userPassword;

	std::strcpy(password, userPassword.c_str());
}

RegularUser::~RegularUser()
{
	delete username;
	delete password;
	delete name;
	delete surname;
	delete phone;
}