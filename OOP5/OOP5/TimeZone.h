#ifndef TimeZone_h
#define TimeZone_h



class TimeZone
{
public:
	const char* name;
	int offset;

	TimeZone(int offset);

	TimeZone();
};
#endif