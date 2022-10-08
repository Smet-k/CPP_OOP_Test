#pragma once
#include <iostream>
#include "User.h"

class Moderator : public User
{
private:
	bool passwordChanged = false;
	char* password = new char[5]{ '1','2','3','4','5' };
public:
	bool login();
	void changePassword();
	~Moderator();
};