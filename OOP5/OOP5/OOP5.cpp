#include <iostream>
#include "List.h"
#include "Dictionary.h"
#include <string.h>
#include "ICurrency.h"
#include "Converter.h"
#include "DateTime.h"
#include "ILogger.h"

// Casts
// Static
// Dynamic

//((First*)players[0])->first;

ConsoleLogger ConsoleLogger::StaticPath::path = ConsoleLogger();
int main()
{
	//Код не виправлений - потрібна допомога на парі
	ConsoleLogger logger;
	


	Converter<DollarCurrency, DollarCurrency> conv = {};

	char symbol1 = 'D';
	char symbol2 = 'E';
	float output = conv.Convert(1, &symbol1, &symbol2);
	std::cout << output;
	std::cout << "\n";


	/*
	//to fix: Main - Dictionary 
	Dictionary<std::string,int> dic;

	//to fix: Main - Dictionary - Add
	dic.add("test", 1);
	dic.add("test2", 2);
	dic.remove(0);
	std::cout << logger.GetStackTrace();

	//ConsoleLogger logger;
	//logger.Log("test");
    //std::cout << logger.GetStackTrace();
    */

}

