#include "Dictionary.h"
#include "ICurrency.h"
#include <string.h>
#include <iostream>
#include "ILogger.h"
#include "List.h"
template<class T, class U>
class Converter
{
public:
	Dictionary<ICurrency, KeyValuePair<ICurrency, double>> currencies;

	Converter()
	{
		//Помилка в способі задавання або в комп'ютері - хочу обговорити на парі
		currencies.add(DollarCurrency(), KeyValuePair<ICurrency, double>(EuroCurrency(), 1.2));

		currencies.add(DollarCurrency(), KeyValuePair<ICurrency, double>(UAHCurrency(), 36.06));

		currencies.add(UAHCurrency(), KeyValuePair<ICurrency, double>(DollarCurrency(), 0.028));

		currencies.add(UAHCurrency(), KeyValuePair<ICurrency, double>(EuroCurrency(), 0.036));

		currencies.add(EuroCurrency(), KeyValuePair<ICurrency, double>(DollarCurrency(), 0.83)); // ?????

		currencies.add(EuroCurrency(), KeyValuePair<ICurrency, double>(UAHCurrency(), 32.02));

	}

	double Convert(double value, char* symbol1, char* symbol2)
	{
		ConsoleLogger::StaticPath::path.Log("Convert");
		double output = 0;
		int size = currencies.length();
		for (int i = 0;i < size;i++)
		{

			//Error - Data pulled out of Currencies is corrupted so result of if is completely random
			if (strcmp(currencies.first->key.currency_symbol, symbol1) <= 0 && strcmp(currencies.first->value.key.currency_symbol, symbol2) <= 0)
			{
				output = value * currencies.first->value.value;
			}

			currencies.first = currencies.first->next;
			
		}
		return output;
	}

};