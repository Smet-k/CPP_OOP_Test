#ifndef KeyValuePair_h
#define KeyValuePair_h
template<class T, class U>
class KeyValuePair
{
public:
	T key;
	U value;

	KeyValuePair<T, U>* next;

	KeyValuePair()
	{}

	KeyValuePair(T _key, U _value)
	{
		this->key = _key;
		this->value = _value;
	}
};

#endif 
