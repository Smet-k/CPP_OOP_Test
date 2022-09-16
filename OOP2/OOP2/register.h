#include <iostream>
#include "user.h"

class Registration : public User
{
public:

	const char* name;

	const char* surname;

	~Registration()
	{
		delete name;
		delete surname;
	}


	void setName(const char* input)
	{
		name = input;
	}

	void setSurname(const char* input)
	{
		surname = input;
	}

	const char* getName()
	{
		return name;
	}

	const char* getSurname()
	{
		return surname;
	}

	void registerUser(const char* username, const char* password, 
		const char* name, const char* surname)
	{
		setUsername(username);
		setPassword(password);
		setName(name);
		setSurname(surname);
	}
};