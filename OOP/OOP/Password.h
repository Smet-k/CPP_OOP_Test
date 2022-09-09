#include <iostream>

class Password
{
public:
	std::string getPassword()
	{
		return password;
	}

	void setPassword(std::string value)
	{
		password = encode(value);
	}
private:
	std::string password;

	std::string encode(std::string value)
	{
		return value + "123_HASH";
	}
};


