#ifndef Queue_h
#define Queue_h
#include "ICollection.h"


//LILO
template<class T>
class Queue : ICollection<T>
{
public:
	void add(T data) override
	{
		Element<T>* item = new Element<T>;
		item->value = data;
		item->next = this->first;
		this->first = item;
	}

	T operator [](int index) override
	{
		return get(index);
	}

	int length() override
	{
		Element<T>* current = this->first;

		if (current == NULL)
		{
			return 0;
		}

		int count = 1;

		while (current->next != NULL)
		{
			count++;
			current = current->next;
		}

		return count;
	}



	void print()
	{
		int size = this->length() - 1;
		for (int i = size;i >= 0;i--)
		{
			std::cout << " [" << get(i) << "] ";
		}

	}

	
	//Stack<T>/*error*/ToStack()
	//{
	//	return NULL;
	//}
	
	//List<T>/*error*/ ToList()
	//{
	//	return NULL;
	//}

	

	T get(int index) override
	{
		if (index == 0)
		{
			return this->first->value;
		}
		else
		{
			Element<T>* current = this->first;
			for (int i = 0; i < index; i++)
			{
				current = current->next;
			}
			return current->value;
		}
	}


};




#endif