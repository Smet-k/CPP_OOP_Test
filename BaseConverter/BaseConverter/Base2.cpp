#pragma warning(disable : 4996)
#include "Base2.h"
#include <string>
Base2::Base2()
{
	value = 0;
}

Base2::Base2(int value)
{
	this->value = value;
}

int Base2::ToBase10()
{
    int pow = 1;
    int output = 0;
    while (value > 0)
    {
        int last = value % 10;
        if (last == 1)
        {
            output += pow;
        }

        value /= 10;
        pow *= 2;
    }
    return output;
}

int Base2::ToBase8()
{
    int output = 0,pow = 1;;
    while (value > 0)
    {
        int last = value % 10;
        if (last == 1)
        {
            output += pow;
        }

        value /= 10;
        pow *= 2;
    }
    int input = output;
    output = 0;
    int output_local = 0;
    int value_local = input;
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

    if (input % 8 == 0)
    {
        output *= 10;
    }

    return output;
}

const char* Base2::ToBase16()
{
    char* outputstr = new char[128];
    std::strcpy(outputstr, "");
    int output = 0, pow = 1;
    while (value > 0)
    {
        int last = value % 10;
        if (last == 1)
        {
            output += pow;
        }

        value /= 10;
        pow *= 2;
    }
    int input = output;
    output = 0;
    int output_local = 0;
    int input_local = input;
    while (input_local > 0)
    {
        output_local *= 100;
        output_local += input_local % 16;
        input_local /= 16;
        if (input_local < 16)
        {
            output_local *= 100;
            output_local += input_local;
            input_local = 0;
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

    if (input % 16 == 0)
    {
        output *= 10;
    }

    return outputstr;
}