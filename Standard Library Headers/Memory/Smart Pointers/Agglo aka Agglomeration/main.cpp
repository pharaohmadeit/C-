//
//  main.cpp
//  "Agglo" aka Agglomeration, an experimental one dimensional C++ array data class of type int, inspired by Python's numPy-like operator overloading.
//
//  Created by Pharaoh Tornes on 1/22/25.
//
#include "Agglo.hpp"
#include <utility>
#include <stdexcept>
#include <iostream>

using namespace std;

//  free function to return a Agglo by value
Agglo getAggloByValue() {
    Agglo localInts{10, 20, 30};
    return localInts; //    return by value creates an rvalue
}

int main() {
    Agglo ints1(7); //  initialize 7-element Agglo; note () rather than {}
    Agglo ints2(10); //  initialize 10-element Agglo; note () rather than {}
    
    //  print int1 size and contents
    cout << "\nints1 size: " << ints1.size() << "\ncontents: " << ints1; // uses overloaded (<<)
    
    //  print int2 size and contents
    cout << "\nints2 size: " << ints2.size() << "\ncontents: " << ints2; // uses overloaded (<<)
    
    //  input and print ints1 and ints2
    cout << "\n\nEnter 17 integers: ";
    cin >> ints1 >> ints2;  //   uses overloaded (>>);
    
    cout << "\nints1: " << ints1 << "\nints2: " << ints2;
    
    //  use overloaded inequality (!=) operator
    cout << "\n\nEvaluating: ints1 != ints2\n";
    if (ints1 != ints2) {
        cout << "ints1 and ints2 are not equal\n\n";
    }
    
    //  create Agglo ints3 by copying ints1
    Agglo ints3{ints1};
    
    //  print int3 size and contents
    cout << "\nints3 size: " << ints3.size() << "\ncontents: " << ints3;
    
    //  use overloaded copy assignment (=) operator
    cout << "\n\nAssigning ints2 to ints1:\n";
    ints1 = ints2; //   note target Agglo is smaller
    cout << "\nints1: " << ints1 << "\nints2: " << ints2;
    
    //  use overloaded equality (==) operator
    cout << "\n\nEvaluating: ints1 == ints2\n";
    if (ints1 == ints2) {   //  ints1.operator==(ints2) | operator==(ints1, ints2)
        cout << "ints1 and ints2 are equal\n\n";
    }
    
    //  use overloaded subscript operator to create an rvalue
    cout << "ints1[5] is " << ints1[5];
    
    //  use overloaded subscript operator to create an lvalue
    cout << "\n\nAssigning 1000 to ints1[5]\n";
    ints1[5] = 1000;
    cout << "ints1: " << ints1 << endl;
    
    //  attempt to use out-of-range subscript
    try {
        cout << "\nAttempt to assign 1000 to ints1[15]\n";
        ints1[15] = 1000;
    }
    catch (const out_of_range& exception) {
        cout << "An exception occured: " << exception.what() << endl;
    }
    
    //  initialize ints4 with contents of the Agglo returned by getAggloByValue; print size and contents
    
    cout << "\nInitialize ints4 with temporary Agglo object\n";
    Agglo ints4{getAggloByValue()};
    
    //  print int4 size and contents
    cout << "\nints4 size: " << ints4.size() << "\ncontents: " << ints4;
    
    //  convert ints4 to an rvalue reference with std::move and use the result to initialize Agglo ints5
    cout << "\nInitialize ints5 with the result of std::move(ints4)\n";
    Agglo ints5{std::move(ints4)};  //  move constructor called
    
    cout << "\nints5 size: " << ints5.size() << "\ncontents: " << ints5;
    cout << "\n\nSize of ints4 is now: " << ints4.size();   // DON'T DO THIS. ONLY DEMONSTRATION. RETURNS 0;
    
    //  move contents of ints5 into int4
    cout << "\n\nMove ints5 into ints4 via move assignment\n";
    ints4 = std::move(ints5);   //  invoke move assignment
    
    cout << "\nints4 size: " << ints4.size() << "\ncontents: " << ints4;
    cout << "\n\nSize of ints5 is now: " << ints5.size();
    
    //  check if ints5 is empty by contextually converting it to a bool
    if (ints5) {    //  ints5.operator bool()
        cout << "\n\nints5 contains elements\n";
    }
    else {
        cout << "\n\nints5 is empty\n";
    }
    
    //  add one to every element of ints4 using preincrement
    cout << "\nints4: " << ints4;
    cout << "\npreincementing ints4: " << ++ints4;
    
    //  add one to every element of ints4 using ppostincrement
    cout << "\npostincementing ints4: " << ints4;
    cout << "\nints4 now contains: " << ints4++;    //  ints4.operator++(0)
    
    //  add a value to every element of ints4 using +=
    cout << "\n\nAdd 7 to every ints4 element: " << (ints4 += 7) << "\n\n";
    
}
 
