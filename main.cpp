// RUN: g++ -std=c++17 -Wall main.cpp & ./a.out 

#include "gc_pointer.h"
#include "LeakTester.h"

int main()
{   
    Pointer<int> p = new int(19);
    p = new int(21);
    p = new int(28);

    Pointer<int>p2(p);

    return 0;
}