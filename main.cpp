// RUN: g++ -std=c++17 -Wall main.cpp & ./a.out 

#include <vector>
#include "gc_pointer.h"
#include "LeakTester.h"


int main()
{   
    Pointer<int> p = new int(19);       // default constructor
    p = new int(21);                    // Assignment operature
    p = new int(28);                    // Assignment operature
    Pointer<int>p2(p);                  // copy constructor
    Pointer<int> p3 = p;                // copy constructor
    p3=p2;                              // Assignment opearuture
    Pointer<int>p4 = p2;                // copy constructor

    // cout << "refContainer size: " << p.refContainerSize() << endl;
    // p.showlist();

    int mem_size = 10;
    Pointer<int, 10> sp = new int[mem_size]();       // default constructor
    sp = new int[5]();    // Issue 1. size is not fixed.

    // cout << "refContainer size: " << sp.refContainerSize() << endl;
    // sp.showlist();

    // Pointer<int> dp = new int(19);
    // dp = new int[5];  // Issue 2...

    std::vector<Pointer<int> > vp;
    vp.emplace_back(new int(50));
    vp.emplace_back(new int(100));

    // cout << "refContainer size: " << p.refContainerSize() << endl;
    // p.showlist();

    return 0;
}