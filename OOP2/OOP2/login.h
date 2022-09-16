#include <iostream>

class Login : public User
{
public:
	void logIn(const char* username, const char* password)
	{
		setUsername(username);
		setPassword(password);
	}
};