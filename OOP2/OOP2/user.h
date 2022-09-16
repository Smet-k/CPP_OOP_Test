#include <iostream>

class User
{
public:
	const char* username;

	const char* password;

	~User()
	{
		delete username;
		delete password;
	}

	void setUsername(const char* input)
	{
		username = input;
	}

	void setPassword(const char* input)
	{
		password = input;
	}

	const char* getUsername()
	{
		return username;
	}

	const char* getPassword()
	{
		return password;
	}
};