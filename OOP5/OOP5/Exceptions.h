#ifndef Exceptions_h
#define Exceptions_h


#include <iostream>

// exceptions for - get() - StackOverFlowException (out of stack)
//                  remove() - NullReferenceException (removing something out of bounds)
//                  KeyDublicateException - in dictionary - dublicating keys

class Exception
{

public:
	const char* message;
	Exception(const char* message);
};

class DivideByZeroException : public Exception
{
public:
	DivideByZeroException();
};

class StackOverFlowException : public Exception
{
public:
	StackOverFlowException();
};

class NullReferenceException : public Exception
{
public:
	NullReferenceException();
};

class KeyDublicateException : public Exception
{
public:
	KeyDublicateException();
};
#endif