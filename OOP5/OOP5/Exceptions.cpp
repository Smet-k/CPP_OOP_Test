#pragma warning(disable : 4996)
#include "Exceptions.h"
#include "DateTime.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
//new log 
void write(std::string filename, std::string value)
{
    std::ofstream file;
    file.open(filename, std::ios_base::app);

    if (file.is_open())
    {
        file << value << "\n";
    }

    file.close();
}

char* getName()
{
    DateTime time = time.now();
    char* input = time.toStringForName();
    char* output = new char[128];
    std::strcpy(output, "");

    std::strcat(output, "Log - ");
    std::strcat(output, input);
    std::strcat(output, ".txt");
    return output;
}

Exception::Exception(const char* message)
{
	DateTime time = time.now();
	char* output = time.toString();
	std::string messagestr = message;\

	std::strcat(output, " - ");
	std::strcat(output, (messagestr).c_str());
	this->message = output;
}

DivideByZeroException::DivideByZeroException() : Exception("Error - Could not divide by zero")
{
    std::string name = getName();
    write(name, this->message);
}

StackOverFlowException::StackOverFlowException() : Exception("Error - Item out of bounds")
{
    std::string name = getName();
    write(name, this->message);
}

NullReferenceException::NullReferenceException() : Exception("Error - NullReference")
{
    std::string name = getName();
    write(name, this->message);
}

KeyDublicateException::KeyDublicateException() : Exception("Error - Keys can't repeat")
{
    std::string name = getName();
    write(name, this->message);
}

