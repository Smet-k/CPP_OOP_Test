#include <iostream>
#include <vector>
#include "NumberVector.h"

void NumberVector::add(int value)
{
	collection.push_back(value);
}

void NumberVector::add(std::vector<int> value)
{
	for (int i = 0;i < value.size();i++) 
	{
		collection.push_back(value[i]);
	}
}

void NumberVector::remove(int id)
{
	std::vector<int> temp = {};
	for(int i = 0;i < collection.size();i++)
	{
		if(i != id)
		{
			temp.push_back(collection[i]);
		}
	}
	collection = temp;
}

void NumberVector::removeNumber(int number)
{
	std::vector<int> temp = {};
	for (int i = 0;i < collection.size();i++)
	{
		if (collection[i] != number)
		{
			temp.push_back(collection[i]);
		}
	}
	collection = temp;
}

bool NumberVector::find(int input)
{
	for (int i = 0;i < collection.size() - 1;i++) 
	{
		if(collection[i] == input)
		{
			return true;
		}
	}
	return false;
}

void NumberVector::print()
{
	for(int i = 0;i < collection.size();i++)
	{
		std::cout << "id:" << i << " - " << collection[i] << "\n";
	}
}

void NumberVector::sort(bool minmax)
{	
	if(minmax == true)
	{
		for (int j = 0;j < collection.size();j++)
		{
			for (int i = 0;i < collection.size() - 1;i++)
			{
				if (collection[i] > collection[i + 1])
				{
					int buffer = collection[i + 1];
					collection[i + 1] = collection[i];
					collection[i] = buffer;
				}
			}
		}
	}
	else
	{
		for (int j = 0;j < collection.size();j++)
		{
			for (int i = 0;i < collection.size() - 1;i++)
			{
				if (collection[i] < collection[i + 1])
				{
					int buffer = collection[i];
					collection[i] = collection[i + 1];
					collection[i + 1] = buffer;
				}
			}
		}
	}
}