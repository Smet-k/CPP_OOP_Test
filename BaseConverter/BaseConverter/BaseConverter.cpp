#include <iostream>
#include "Base2.h"
#include "Base8.h"
#include "Base10.h"
#include "Base16.h"
int main()
{
    Base16 input = {"1A"};

    std::cout << input.ToBase8();

    //std::cout << input.ToBase16();
}

