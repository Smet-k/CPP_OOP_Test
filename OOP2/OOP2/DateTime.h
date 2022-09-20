#ifndef DateTime_h
#define DateTime_h
#include "TimeZone.h"
#include <iostream>
#include <iomanip>
#include <stdexcept>
class DateTime
{
public:

	TimeZone timezone;

	int day;

	int month;

	int year;

	int hours;

	int minutes;

	int seconds;

	DateTime();

	DateTime(int day, int month, int year);

	DateTime(int day, int month, int year, int hours, int minutes, int seconds);

	DateTime(int day, int month, int year, int hours, int minutes, int seconds, int timezone);

	static DateTime now();

	static DateTime now(int offset);

	char* toString();

	DateTime addHours(int hours);

	DateTime addMinutes(int minutes);

	DateTime addSeconds(int seconds);

	DateTime addDays(int day);

	DateTime addMonths(int months);

	DateTime addYears(int years);

	DateTime& Check(DateTime input);


	long totalMinutes();

	long totalSeconds();

	long totalDays();

	long totalMonths();

	DateTime max(DateTime input);

	DateTime min(DateTime input);

	DateTime& operator+(const DateTime& input);

	DateTime& operator-(const DateTime& input);

	bool operator>(const DateTime& input);

	bool operator<(const DateTime& input);

	bool operator>=(const DateTime& input);

	bool operator<=(const DateTime& input);

	bool operator==(const DateTime& input);

	bool operator!=(const DateTime& input);

	friend std::ostream& operator <<(std::ostream& output, DateTime& source);

	friend std::istream& operator >>(std::istream& input, DateTime& source);
};


#endif