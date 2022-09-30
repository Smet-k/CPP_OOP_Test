#include "Base16.h"
#include <iostream>
#include <string.h>
#include <cmath>
int Base16::ToBase10()
{   
    int output = 0, number;
    for(int i = 0; i < value.size();i++)
    {
        if(isdigit(value[i]))
        {
            output += (int(value[i])-48) * pow(16, value.size() - 1 - i);
        }
        else
        {
            switch (value[i])
            {
            case 'A': number = 10; break;
            case 'B': number = 11; break;
            case 'C': number = 12; break;
            case 'D': number = 13; break;
            case 'E': number = 14; break;
            case 'F': number = 15; break;
            default: number = 0; break;
            }

            output += number * pow(16, value.size() - 1 - i);
        }
    }
    return output;
}

Base16::Base16()
{
	value = "0";
}

Base16::Base16(std::string value)
{
	this->value = value;
    intvalue = ToBase10();
}

int Base16::ToBase2()
{
    int output = 0;
    int pow = 1;
    while (pow * 2 <= intvalue)
    {
        pow *= 2;
    }

    while (pow > 0)
    {
        output *= 10;
        if (pow <= intvalue)
        {
            output += 1;
            intvalue -= pow;
        }
        pow /= 2;
    }

    return output;
    
}

int Base16::ToBase8()
{
    int value_local = intvalue;
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

    if (intvalue % 8 == 0)
    {
        output *= 10;
    }

    return output;

}

