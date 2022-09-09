#include <vector>


class NumberVector
{
private:
	std::vector<int> collection;
public:
	

	void add(int value);

	void add(std::vector<int> value);

	void remove(int id);
	
	void removeNumber(int number);

	bool find(int input);

	void print();

	void sort(bool minmax);

};