#ifndef KeyValuePair_h
#define KeyValuePair_h

template<class T, class U>
class KeyValuePair
{
public:
	T key;
	U value;

	KeyValuePair<T, U>* next;
};

#endif 
