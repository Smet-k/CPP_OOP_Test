#ifndef ICollection_h
#define ICollection_h
#include "Element.h"

template<class T>
class ICollection
{
public:
	Element<T>* first;
	Element<T>* next;
	Element<T>* last;

	ICollection<T>()
	{
		this->first = NULL;
		this->last = NULL;
	}

	virtual void add(T date){}
	virtual T operator [](int index) { return 0; }

	virtual T get(int index) { return 0; }

	virtual int length() = 0;
};

#endif