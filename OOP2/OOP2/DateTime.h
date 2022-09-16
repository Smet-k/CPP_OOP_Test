#ifndef DateTime_h
#define DateTime_h

class DateTime
{
public:

	int day;

	int month;

	int year;

	int hours;

	int minutes;

	int seconds;

	DateTime();

	DateTime(int day, int month, int year);

	DateTime(int day, int month, int year, int hours, int minutes, int seconds);

	static DateTime now();

	char* toString();

	DateTime addHours(int hours);

	DateTime addMinutes(int minutes);

	DateTime addSeconds(int seconds);

	DateTime addDays(int day);

	DateTime addMonths(int months);

	DateTime addYears(int years);

	DateTime Check(DateTime input);


	long totalMinutes();

	long totalSeconds();

	long totalDays();

	long totalMonths();


	DateTime add(DateTime input); // date 1 day - 12 , date 2 day - 10 = 22

	DateTime max(DateTime input);

	DateTime min(DateTime input);

	DateTime substract(DateTime input);
};


#endif