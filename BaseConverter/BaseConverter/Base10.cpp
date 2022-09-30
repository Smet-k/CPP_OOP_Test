#pragma warning(disable : 4996)
#include "Base10.h"
#include <iostream>
#include <string>

Base10::Base10()
{
	value = 0;
}

Base10::Base10(int value)
{
	this->value = value;
}

int Base10::ToBase2()
{
    int output = 0;
    int pow = 1;
    while (pow * 2 <= value)
    {
        pow *= 2;
    }

    while (pow > 0)
    {
        output *= 10;
        if (pow <= value)
        {
            output += 1;
            value -= pow;
        }
        pow /= 2;
    }

    return output;
}

int Base10::ToBase8()
{
    int value_local = value;
    int output = 0;
    int output_local = 0;
    while (value_local > 0)
    {
        output_local *= 10;
        output_local += value_local % 8;
        value_local /= 8;
        if (value_local < 8)
        {
            output_local *= 10;
            output_local += value_local;
            value_local = 0;
        }

    }

    while (output_local > 0)
    {
        output *= 10;
        output += output_local % 10;
        output_local /= 10;
    }

    if (value % 8 == 0)
    {
        output *= 10;
    }

    return output;
}

const char* Base10::ToBase16()
{
    char* outputstr = new char[128];
    std::strcpy(outputstr, "");
    int output_local = 0,output = 0, value_local = value;
    while (value_local > 0)
    {
        output_local *= 100;
        output_local += value_local % 16;
        value_local /= 16;
        if (value_local < 16)
        {
            output_local *= 100;
            output_local += value_local;
            value_local = 0;
        }
    }

    while (output_local > 0)
    {
        int last = output_local % 100;

        switch (last)
        {
        case 10: std::strcat(outputstr, std::string(1, 'A').c_str()); break;
        case 11: std::strcat(outputstr, std::string(1, 'B').c_str()); break;
        case 12: std::strcat(outputstr, std::string(1, 'C').c_str()); break;
        case 13: std::strcat(outputstr, std::string(1, 'D').c_str()); break;
        case 14: std::strcat(outputstr, std::string(1, 'E').c_str()); break;
        case 15: std::strcat(outputstr, std::string(1, 'F').c_str()); break;
        default: std::strcat(outputstr, std::string(1, last + 48).c_str()); break;
        }

        output_local /= 100;
    }

    if (value % 16 == 0)
    {
        output *= 10;
    }

    return outputstr;
}