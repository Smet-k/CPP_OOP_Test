#include <iostream>
#include <string>
#include <vector>
using namespace std;

class User
{
public:
	void reg()
	{
		int bd, bm, by;
		string tmp;
		while (true) {
			cout << "Enter your birthday in format dd mm yyyy: \n";
			cin >> bd >> bm >> by;
			if(countAge(bd, bm, by) == true)
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
		cin >> tmp;
		setPassword(tmp);

	}




private:
	int cd = 31;
	int cm = 8;
	int cy = 2022;
	string username;
	string name;
	string surname;
	string bd,bm,by;
	string country;
	string password;

	bool countAge(int bd, int bm, int by)
	{
		int  d, m, y;
		int md[12] = { 31,28,31,30,31,30,31,31,30,31,30,31};
		y = cy - by;
		if (cm < bm)
		{
			y--;
			m = 12 - (bm - cm);
		}
		else
		{
			m = cm - bm;
		}
		if(cd < bd)
		{
			m--;
			d = md[cm - 1] - (bd - cd);
		}
		else
		{
			d = cd - bd;
		}
		if (y < 14) { return false; }
		return true;
	}


	void setPassword(string value)
	{
		password = value;
	}
};