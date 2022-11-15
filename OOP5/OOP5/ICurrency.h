#pragma warning(disable : 4996)
#ifndef ICurrency_h
#define ICurrency_h
#include <string>
#include "ILogger.h"
class ICurrency
{

public:
	virtual char* ToString() {
		return new char[1];
	}

	char* currency_symbol;

	ICurrency()
	{}

	ICurrency(char* _prefix)
	{
		currency_symbol = _prefix;
	}
};

class DollarCurrency : public ICurrency
{
public:

	char symbol = 'D';
	DollarCurrency() : ICurrency(&symbol)
	{}

	char* ToString() override
	{
		char* output = new char[128];
		std::strcpy(output, "\n");

		//std::strcat(output, (currsymbol));
		std::strcat(output, " - ");

		return output;
	}

};


class EuroCurrency : public  ICurrency
{
public:
	char symbol = 'E';
	EuroCurrency() : ICurrency(&symbol)
	{}
	char* ToString() override
	{
		char* output = new char[128];
		std::strcpy(output, "\n");

		std::strcat(output, (currency_symbol));
		std::strcat(output, " - ");

		return output;
	}
};

class UAHCurrency : public ICurrency
{
public:
	char symbol = 'U';
	UAHCurrency() : ICurrency(&symbol)
	{}

	char* ToString() override
	{
		char* output = new char[128];
		std::strcpy(output, "\n");

		std::strcat(output, ("UAH"));
		//std::strcat(output, );

		return output;
	}
};

#endif