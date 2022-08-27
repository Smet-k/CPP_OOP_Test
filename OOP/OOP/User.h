#include <iostream>
#include <string>
#include <vector>
using namespace std;

class User
{
public:
	void reg()
	{
		string tmp;
		cout << "Enter your birthday(yr/mm/dd): ";
		cin >> birthday;
		birthdayCheck(birthday);
		cout << "Enter your name: ";
		cin >> name;
		cout << "Enter your surname: ";
		cin >> surname;
		cout << "Enter your country: ";
		cin >> country;
		cout << "Create a password: ";
		cin >> tmp;
		setPassword(tmp);

	}




private:
	string username;
	string name;
	string surname;
	string birthday;
	string country;
	string password;

	bool birthdayCheck(string input)
	{
		string word = "";
		vector<string> date;
		

		for(int j = 0;j < input.size();j++)
		{
			if(input[j] != '/')
			{
				word += input[j];
			}
			else
			{
				date.push_back(word);
				word = "";
			}
		}
		return false;
	}

	void setPassword(string value)
	{
		password = value;
	}
};