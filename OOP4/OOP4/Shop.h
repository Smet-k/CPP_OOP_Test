#include <vector>
#include "User.h"
#include "RegularUser.h"

class Shop
{
private: 
	std::vector<User*> users;
	User* loggedUser;
	RegularUser registered;
public:
	Shop();
	void login();
	void registration();
};