#include <iostream>
#include <string>
#include <vector>
using namespace std;

class User
{
public:

	User();

	User(char* iName, char* iSurname, char* iPassword,
		char* iCountry, int iDay, int iMonth, int iYear);

	~User();
	char* getBirthday();
	void setBirthday(int day, int month, int year);

	char* getName();
	void setName(char* input);

	char* getSurname();
	void setSurname(char* input);

	char* getPassword();
	void setPassword(char* input);

	char* getCountry();
	void setCountry(char* input);

	void reg();

private:
	int cd = 31;
	int cm = 8;
	int cy = 2022;
	char* username;
	char* name;
	char* surname;
	char* birthday;
	char* bd,bm,by;
	char* country;
	char* password;
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


};