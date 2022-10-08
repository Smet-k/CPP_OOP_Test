#include "User.h"

class Admin : public User
{
private:
	const char* password = { "123456789" };
public:
	bool login();

	~Admin();
};