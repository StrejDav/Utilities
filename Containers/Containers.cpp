// Containers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Vector.h"

int main()
{
    Vector<int> vec(1);
    vec.push_back(5);
    vec.push_back(10);
    vec.push_back(15);
    vec.push_back(15);
    vec.push_back(15);
    vec.push_back(15);
    vec.push_back(15);
    vec.push_back(15);
    vec.push_back(15);
    vec.push_back(15);
    vec.pop_back();
    vec.pop_back();
    vec.pop_back();
    vec.pop_back();
    vec.pop_back();
    vec.pop_back();
    vec.pop_back();

    Vector<int> vecB(vec);
    //vecB = vec;
    vecB.push_back(-5);
    vecB.push_back(-10);
    vecB.push_back(-15);
    vecB.push_back(-20);

    vecB.swap(vec);

    std::cout << vecB[2] << "\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
