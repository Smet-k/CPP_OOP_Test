#pragma warning(disable : 4996)
#include <string>
#include "Base8.h"


Base8::Base8()
{
	value = 0;
}

Base8::Base8(int value)
{
	this->value = value;
}

int Base8::ToBase2()
{
    int output = 0, pow = 1;
    while (value > 0)
    {
        int last = value % 10;
        output += last * pow;
        pow *= 8;
        value /= 10;
    }
    int input = output;
    output = 0;
    int output_local = 0;
    int input_local = input;
    while (pow * 2 < input)
    {
        pow *= 2;
    }

    while (pow > 0)
    {
        output *= 10;
        if (pow <= input)
        {
            output += 1;
            input -= pow;
        }
        pow /= 2;
    }

    return output;
}

int Base8::ToBase10()
{
    int output = 0, pow = 1;
    while (value > 0)
    {
        int last = value % 10;
        output += last * pow;
        pow *= 8;
        value /= 10;
    }
   return output;
}

const char* Base8::ToBase16()
{
    char* outputstr = new char[128];
    std::strcpy(outputstr, "");
    int pow = 1, output = 0;
    while (value > 0)
    {
        int last = value % 10;
        output += last * pow;
        pow *= 8;
        value /= 10;
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