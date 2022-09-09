#include <iostream>
#include <vector>
#include "NumberVector.h"

int main()
{
    NumberVector test;
    test.add({1,4,5,2,9,6,1});
    test.print();
    std::cout << "\n";
    test.sort(false);
    test.print();
    test.remove(1);
    std::cout << "\n";
    test.print();
    test.removeNumber(1);
    std::cout << "\n";
    test.print();


    std::cout << test.find(4) << "\n";
    std::cout << test.find(0) << "\n";
}

