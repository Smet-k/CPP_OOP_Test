#ifndef Dictionary_h
#define Dictionary_h
#pragma warning(disable : 4996)
#include "KeyValuePair.h"
#include <string>
#include "Exceptions.h"
// + overload
// merge / add

template<class T, class U>
class Dictionary
{
	KeyValuePair<T, U>* first;

	KeyValuePair<T, U>* last;

public:
	Dictionary<T, U>()
	{
		first = NULL;
		last = NULL;
	}
	Dictionary<T, U>(KeyValuePair<T, U>* first, KeyValuePair<T, U>* last)
	{
		this->first = first;
		this->last = last;
	}

	bool keyExists(T key)
	{
		int size = length();
		KeyValuePair<T, U>* current = this->first;
		for(int i = 0;i < size;i++)
		{
			if(current->key == key)
			{
				return true;;
			}
			current = current->next;
		}
		return false;
	}

	void add(T key,U value)
	{
		// if key already exists - error
		// toString: key - value; \n
		// sort (by value)
		if (keyExists(key)) { throw KeyDublicateException();}

		if (!this->first)
		{
			this->first = new KeyValuePair<T,U>;
			this->first->value = value;
			this->first->key = key;
			this->first->next = NULL;
			this->last = this->first;
		}
		else
		{
			if (this->first == this->last)
			{
				this->last = new KeyValuePair<T, U>;
				this->last->value = value;
				this->last->key = key;
				this->last->next = NULL;
				this->first->next = this->last;
			}
			else
			{
				KeyValuePair<T, U>* item = new KeyValuePair<T, U>;
				item->value = value;
				item->key = key;
				item->next = NULL;
				this->last->next = item;
				this->last = item;
			}
		}
	}

	void remove(int index)
	{
		if (index > this->length()) { throw NullReferenceException(); }

		KeyValuePair<T, U>* nextToCurrent = this->first;
		KeyValuePair<T, U>* current = this->first;
		KeyValuePair<T, U>* beforeCurrent = this->first;

		if (index == 0)
		{
			nextToCurrent = this->first->next;
			this->first->value = nextToCurrent->value;
			this->first->key = nextToCurrent->key;
			this->first->next = nextToCurrent->next;
		}
		else
		{
			int size = length();
			for (int i = 0; i < index; i++)
			{
				beforeCurrent = current;
				current = current->next;
			}

			if (index < size - 1)
			{
				nextToCurrent = current->next;

				current->value = nextToCurrent->value;
				current->key = nextToCurrent->key;
				current->next = nextToCurrent->next;
			}
			else
			{
				current = beforeCurrent;
				nextToCurrent = current->next;

				current->next = nextToCurrent->next;
			}

		}
		delete nextToCurrent;
	}

	char* toString()
	{
		KeyValuePair<T, U>* current = this->first;
		int size = length();
		char* output = new char[128];
		std::strcpy(output, "\n");
		for (int i = 0;i < size;i++)
		{
			// toString: key - value; \n
			//std::strcat(output, (current->key + " - " , current->value , "\n")); //std::string(1, symbol).c_str());
			std::strcat(output, (current->key).c_str());
			std::strcat(output, " - ");
			std::strcat(output, std::to_string(current->value).c_str());
			std::strcat(output, ". \n");
			current = current->next;
		}
		return output;
	
	}

	void add(KeyValuePair<T,U> input)
	{
		if (keyExists(input.key)) { throw KeyDublicateException();}

		if (!this->first)
		{
			this->first = new KeyValuePair<T, U>;
			this->first->value = input.value;
			this->first->key = input.key;
			this->first->next = NULL;
			this->last = this->first;
		}
		else
		{
			if (this->first == this->last)
			{
				this->last = new KeyValuePair<T, U>;
				this->last->value = input.value;
				this->last->key = input.key;
				this->last->next = NULL;
				this->first->next = this->last;
			}
			else
			{
				KeyValuePair<T, U>* item = new KeyValuePair<T, U>;
				item->value = input.value;
				item->key = input.key;
				item->next = NULL;
				this->last->next = item;
				this->last = item;
			}
		}
	}

	void remove(KeyValuePair<T, U>* keyPair)
	{
		KeyValuePair<T, U>* current = this->first;
		int size = length();
		for (int i = 0; i < size; i++)
		{
			if (current->key == keyPair->key) { remove(i); break; }
			current = current->next;
		}
	}

	U operator [](T index)
	{
		return this->get(index);
	}

	Dictionary<T, U>* operator +(KeyValuePair<T,U> input)
	{
		add(input);

		return this;
	}

	Dictionary<T, U>* operator +(Dictionary<T, U> input)
	{
		last->next = input.first;
		last = input.last;
		
		return this;
	}
	//finish this
	Dictionary<T, U> operator =(Dictionary<T,U>* input)
	{
		Dictionary<T, U> output;
		int size = input->length();
		for(int i = 0;i < size;i++)
		{
			output.add(input->getPair(i));
		}
		return output;
	}
	int length()
	{
		KeyValuePair<T,U>* current = this->first;

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

	Dictionary<T, U> OrderBy(bool asc = true)
	{
		int size = this->length();

		Dictionary<T, U> input = { this->first,this->last };
		Dictionary<T, U> output = {};
		if (asc)
		{
			for (int j = 0;j < size - 1;j++)
			{
				int size2 = this->length();
				KeyValuePair<T, U>* nextToCurrent = input.first;
				KeyValuePair<T, U>* current = input.first;
				int min = 2147483647;
				int index = 0;
				for (int i = 0;i < size2;i++)
				{
					if (min > current->value)
					{
						min = current->value;
						index = i;
					}
					current = current->next;
				}
				output.add(getPair(index));
				input.remove(index);
			}
			output.add(getPair(0));
		}
		else
		{
			for (int j = 0;j < size - 1;j++)
			{
				int size2 = this->length();
				KeyValuePair<T, U>* nextToCurrent = input.first;
				KeyValuePair<T, U>* current = input.first;
				int max = -2147483648;
				int index = 0;
				for (int i = 0;i < size2;i++)
				{
					if (max < current->value)
					{
						max = current->value;
						index = i;
					}
					current = current->next;
				}
				output.add(getPair(index));
				input.remove(index);
			}
			output.add(getPair(0));
		}
		Dictionary<T, U> linkOutput = { output.first,output.last };
		return linkOutput;
	}

	List<T> getKeys()
	{
		Dictionary<T, U> input(this->first,this->last);
		List<T> output;
		int size = input.length();
		for (int i = 0;i < size;i++)
		{
			KeyValuePair<T, U> current = getPair(i);
			output.add(current.key);
		}

		return output;
	}

	List<U> getValues()
	{
		Dictionary<T, U> input(this->first, this->last);
		List<U> output;
		int size = input.length();
		for (int i = 0;i < size;i++)
		{
			KeyValuePair<T, U> current = getPair(i);
			output.add(current.value);
		}

		return output;
	}
private:
	U get(T index)
	{
		int size = length();
		KeyValuePair<T,U>* current = this->first;
		for (int i = 0; i < size; i++)
		{
			if (index == current->key)
			{
				return current->value;
			}
			current = current->next;
		}
		return -1;
	}

	KeyValuePair<T,U> getPair(int index)
	{
		int size = length();
		KeyValuePair<T, U>* current = this->first;
		for (int i = 0; i < size; i++)
		{
			if (index == i)
			{
				return {current->key,current->value};
			}
			current = current->next;
		}
		return {"empty",0};
	}


};

#endif