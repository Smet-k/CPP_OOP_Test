#pragma warning(disable : 4996)
#include <iostream>
#include "TimeZone.h"
#include <string>
TimeZone::TimeZone()
{
	offset = 3;
	name = "UTC+3";
}


TimeZone::TimeZone(int offset)
{
	char* output = new char[128];
	std::strcpy(output, "\n");
	if (offset > 13) { offset = 13; }

	if (offset < -14) { offset = -14; }
	this->offset = offset;

	if (this->offset > 0)
	{
		std::strcat(output, "UTC+");
		std::strcat(output, std::to_string(offset).c_str());
		name = output;
	}
	if (this->offset < 0)
	{
		std::strcat(output, "UTC");
		std::strcat(output, std::to_string(offset).c_str());
		name = output;
	}
	if (this->offset == 0) { name = "UTC"; }


}
