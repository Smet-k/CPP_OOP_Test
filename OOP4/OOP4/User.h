#ifndef User_h
#define User_h
class User
{
public:
	virtual bool login() = 0;
	virtual void registration() {}
	virtual void changePassword(){}
	
	virtual ~User(){};
};

#endif