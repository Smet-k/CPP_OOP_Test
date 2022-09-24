#include <iostream>
#include "Rectangle.h"
#include "Rhombus.h"
#include "Triangle.h"
#include "SandClock.h"
#include "Hexagon.h"
using namespace std;

int main()
{
    Rectangle Rt = {5,4 };

    Rhombus Rh = { 6,2,2 };

    Triangle t = {8,4,4};

    Triangle t2 = { 6,8,10 };

    SandClock Sc = { 8,4 };

    Hexagon H = { 6 };

    cout << H.toString('*');

    cout << Rh.toString('X');

    cout << Rt.toString('*');

    cout << t.toString('*');

    cout << t2.toString('*');

    cout << Sc.toString('*');

   // cout << a.toString('*');

}

