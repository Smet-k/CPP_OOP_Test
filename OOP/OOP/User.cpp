#include "User.h"
#include <string.h>

User::User()
{

}

User::User(char* iName, char* iSurname, char* iPassword, char* iCountry, int iDay, int iMonth, int iYear)
{
	name = iName;
	surname = iSurname;
	password = iPassword;
	country = iCountry;
	setBirthday(iDay, iMonth, iYear);
}



User::~User()
{
	if(birthday != nullptr)
	{
		delete birthday;
	}
	if (name != nullptr)
	{
		delete name;
	}
	if (surname != nullptr)
	{
		delete surname;
	}
	if (password != nullptr)
	{
		delete password;
	}
	if (country != nullptr)
	{
		delete country;
	}
}

void User::reg()
{
	int bd, bm, by;
	string tmp;
	while (true) {
		cout << "Enter your birthday in format dd mm yyyy: \n";
		cin >> bd >> bm >> by;
		if (countAge(bd, bm, by) == true)
		{
			break;
		}
		else
		{
			cout << "You should be 14 or older to register.\n";
		}
	}
	cout << "Enter your name: ";
	cin >> name;
	cout << "Enter your surname: ";
	cin >> surname;
	cout << "Enter your country: ";
	cin >> country;
	cout << "Create a password: ";
	cin >> password;
}

char* User::getBirthday()
{
	return birthday;
}

void User::setBirthday(int day, int month, int year)
{
	birthday += char(day);
	birthday += '/';
	birthday += char(month);
	birthday += '/';
	birthday += char(year);
}

char* User::getName()
{
	return name;
}

void User::setName(char* input)
{
	name = input;
}

char* User::getSurname()
{
	return surname;
}

void User::setSurname(char* input)
{
	surname = input;
}

char* User::getPassword()
{
	return password;
}

void User::setPassword(char* input)
{
	password = input;
}

char* User::getCountry()
{
	return name;
}

void User::setCountry(char* input)
{
	name = input;
}
