#pragma warning(disable : 4996)
#include <iostream>
#include "DateTime.h"
#include <string>
#include <ctime>
#include <time.h>

DateTime::DateTime()
{
	day = 1;
	month = 1;
	year = 1;
	hours = 0;
	minutes = 0;
	seconds = 0;

}

DateTime::DateTime(int day, int month, int year)
{
	this->day = day;
	this->month = month;
	this->year = year;
	this->hours = 0;
	this->minutes = 0;
	this->seconds = 0;
}

DateTime::DateTime(int day, int month, int year, int hours, int minutes, int seconds)
{
	this->day = day;
	this->month = month;
	this->year = year;
	this->hours = hours;
	this->minutes = minutes;
	this->seconds = seconds;
}

DateTime DateTime::now()
{
	time_t now = time(0);
	tm* tmNow = gmtime(&now);
	DateTime output;

	output.day = tmNow->tm_mday;
	output.month = tmNow->tm_mon + 1;
	output.year = tmNow->tm_year + 1900;
	output.hours = tmNow->tm_hour + 3;
	output.minutes = tmNow->tm_min;
	output.seconds = tmNow->tm_sec;

	return output;
}

char* DateTime::toString()
{
	char* output = new char[128];

	std::strcat(output, std::to_string(day).c_str());
	std::strcat(output, "/");
	std::strcat(output, std::to_string(month).c_str());
	std::strcat(output, "/");
	std::strcat(output, std::to_string(year).c_str());
	std::strcat(output, " ");
	std::strcat(output, std::to_string(hours).c_str());
	std::strcat(output, ":");
	std::strcat(output, std::to_string(minutes).c_str());
	std::strcat(output, ":");
	std::strcat(output, std::to_string(seconds).c_str());

	return output;
}


DateTime DateTime::Check(DateTime input)
{
	int md[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

	DateTime output = input;
	
	if (output.year >= 0 && output.month > 0 && output.day > 0 && output.hours >= 0 && output.minutes >= 0 && output.seconds >= 0) {
		// add
		while (output.seconds >= 60)
		{
			output.seconds = output.seconds - 60;
			output.minutes = output.minutes + 1;
		}
		while (output.minutes >= 60)
		{
			output.minutes = output.minutes - 60;
			output.hours = output.hours + 1;
		}
		while (output.hours >= 24)
		{
			output.hours = output.hours - 24;
			output.day = output.day + 1;
		}

		while (output.day > md[output.month - 1] && output.month <= 12)
		{
			output.day = output.day - md[output.month - 1];
			if (output.day < 1)
			{
				output.day = 1;
			}
			output.month = month + 1;
		}
		while (output.month > 12)
		{
			output.month = output.month - 12;
			output.year = output.year + 1;
		}

		while (output.day > md[output.month - 1] && output.month <= 12)
		{
			output.day = output.day - md[output.month - 1];
			if (output.day < 1)
			{
				output.day = 1;
			}
			output.month = month + 1;
		}
	}
	else {
		// substract
		while (output.seconds < 0)
		{
			output.seconds = output.seconds + 60;
			output.minutes = output.minutes - 1;
		}
		while (output.minutes < 0)
		{
			output.minutes = output.minutes + 60;
			output.hours = output.hours - 1;
		}
		while (output.hours < 0)
		{
			output.hours = output.hours + 24;
			output.day = output.day - 1;
		}
		while (output.day <= 0 && output.month <= 12)
		{
			output.month = month - 1;
			output.day = output.day + md[output.month - 1];
			if (output.day < 1)
			{
				output.day = 1;
			}
		}
		while (output.month <= 0)
		{
			output.month = output.month + 12;
			output.year = output.year - 1;
		}
	}
	return output;
}


DateTime DateTime::addHours(int hours)
{
	DateTime output;

	int input = this->hours + hours;

	output.day = day;
	output.month = month;
	output.year = year;
	output.hours = input;
	output.minutes = minutes;
	output.seconds = seconds;

	return Check(output);
}

DateTime DateTime::addMinutes(int minutes)
{
	DateTime output;

	output.day = day;
	output.month = month;
	output.year = year;
	output.hours = hours;
	output.minutes = this->minutes + minutes;
	output.seconds = seconds;

	return Check(output);
}


DateTime DateTime::addSeconds(int seconds)
{
	DateTime output;

	output.day = day;
	output.month = month;
	output.year = year;
	output.hours = hours;
	output.minutes = minutes;
	output.seconds = this->seconds + seconds;

	return Check(output);
}

DateTime DateTime::addYears(int years)
{
	DateTime output;

	output.day = day;
	output.month = month;
	output.year = this->year + years;
	output.hours = hours;
	output.minutes = minutes;
	output.seconds = seconds;

	return Check(output);
}

DateTime DateTime::addMonths(int months)
{
	DateTime output;

	output.day = day;
	output.month = this->month + months;
	output.year = year;
	output.hours = hours;
	output.minutes = minutes;
	output.seconds = seconds;

	return Check(output);
}

DateTime DateTime::addDays(int days)
{
	DateTime output;

	output.day = this->day + days;
	output.month = month;
	output.year = year;
	output.hours = hours;
	output.minutes = minutes;
	output.seconds = seconds;

	return Check(output);
}

long DateTime::totalMinutes()
{
	long result = 60 * hours + minutes;
	while(seconds >= 60)
	{
		result++;
	}

	return result;
}

long DateTime::totalSeconds()
{
	return hours * 3600 + minutes * 60 + seconds;
}

long DateTime::totalDays()
{
	return day + month * 30 + year * 365;

};

long DateTime::totalMonths()
{
	long result = month + year * 12;
	while(day > 30)
	{
		result++;
	}

	return result;
}
// date 1 day - 12 , date 2 day - 10 = 22
DateTime DateTime::add(DateTime input)
{
	long osecond, ominute, ohour, oday, omonth;

	DateTime dt2 = input;

	osecond = seconds + dt2.seconds;
	ominute = minutes + dt2.minutes;
	ohour = hours + dt2.hours;
	oday = day + dt2.day;
	omonth = month + dt2.month;
	DateTime output { oday, omonth, year, ohour, ominute, osecond };
	
	
	return Check(output);
} 

//DateTime(int day, int month, int year, int hours, int minutes, int seconds);

DateTime DateTime::max(DateTime input)
{
	DateTime dt1 = input;
	DateTime dt2 = { day, month, year, hours, minutes, seconds };
	if (dt2.year > dt1.year || dt2.year < dt1.year)
	{
		if (dt2.year > dt1.year)
		{
			return dt2;
		}
		else
		{
			return dt1;
		}
	}
	else if (dt2.month > dt1.month || dt1.month > dt2.month)
	{
		if (dt2.month > dt1.month)
		{
			return dt2;
		}
		else
		{
			return dt1;
		}
	}
	else if (dt2.day > dt1.day || dt1.day > dt2.day)
	{
		if (dt2.day > dt1.day)
		{
			return dt2;
		}
		else
		{
			return dt1;
		}
	}
	else if (dt2.hours > dt1.hours || dt1.hours > dt2.hours)
	{
		if (dt2.hours > dt1.hours)
		{
			return dt2;
		}
		else
		{
			return dt1;
		}
	}
	else if (dt2.minutes > dt1.minutes || dt1.minutes > dt2.minutes)
	{
		if (dt2.minutes > dt1.minutes)
		{
			return dt2;
		}
		else
		{
			return dt1;
		}
	}
	else if (dt2.seconds > dt1.seconds || dt1.seconds > dt2.seconds)
	{
		if (dt2.seconds > dt1.seconds)
		{
			return dt2;
		}
		else
		{
			return dt1;
		}
	}
	return dt2;
}


DateTime DateTime::min(DateTime input)
{
	DateTime dt1 = input;
	DateTime dt2 = { day, month, year, hours, minutes, seconds };
	if (dt2.year < dt1.year || dt1.year < dt2.year)
	{
		if (dt2.year < dt1.year)
		{
			return dt2;
		}
		else
		{
			return dt1;
		}
	}
	else if (dt2.month < dt1.month || dt1.month < dt2.month)
	{
		if (dt2.month < dt1.month)
		{
			return dt2;
		}
		else
		{
			return dt1;
		}
	}
	else if (dt2.day < dt1.day || dt1.day < dt2.day)
	{
		if (dt2.day < dt1.day)
		{
			return dt2;
		}
		else
		{
			return dt1;
		}
	}
	else if (dt2.hours < dt1.hours || dt1.hours < dt2.hours)
	{
		if (dt2.hours < dt1.hours)
		{
			return dt2;
		}
		else
		{
			return dt1;
		}
	}
	else if (dt2.minutes < dt1.minutes || dt1.minutes < dt2.minutes)
	{
		if (dt2.minutes < dt1.minutes)
		{
			return dt2;
		}
		else
		{
			return dt1;
		}
	}
	else if (dt2.seconds < dt1.seconds || dt1.seconds < dt2.seconds)
	{
		if (dt2.seconds < dt1.seconds)
		{
			return dt2;
		}
		else
		{
			return dt1;
		}
	}
	return dt2;
}


DateTime DateTime::substract(DateTime input)
{
	long osecond, ominute, ohour, oday, omonth;

	DateTime dt2 = input;

	osecond = seconds - dt2.seconds;
	ominute = minutes - dt2.minutes;
	ohour = hours - dt2.hours;
	oday = day - dt2.day;
	omonth = month - dt2.month;
	DateTime output{ oday, omonth, year, ohour, ominute, osecond };


	return Check(output);
}