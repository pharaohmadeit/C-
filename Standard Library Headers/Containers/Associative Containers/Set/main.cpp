//  Standard library set class template
//  main.cpp
//  fig13_07
//
//  Created by Pharaoh Tornes on 2/15/25.
//
#include <set>  //  set class-template defintion
#include <algorithm>    //  copy algorithm
#include <iterator> //  ostream_iterator
#include <format>
#include <iostream>

using namespace std;

int main() {
    set<double, less<double>> doubles{2.1, 4.2, 9.5, 2.1, 3.7};   //  Class Template Argument Deduction: the compiler deduces the set type <set>; CTAD
    
    ostream_iterator<double> output{cout, " "};
    cout << "doubles contains: ";
    ranges::copy(doubles, output);  //  copy doubles set to standard output stream
    
    //  insert 13.8 in doubles; insert returns pair in which p.first represents location of 13.8 in doubles as an iterator and p.second represents whether 13.8 was inserted as a bool
    auto p{doubles.insert(13.8)};   //  value not in set
    cout << format("\n{} {} inserted\n", *(p.first), (p.second ? "was" : "was not"));
    cout << "doubles contains: ";
    ranges::copy(doubles, output);
    
    //  insert 9.5 in doubles
    p = doubles.insert(9.5);    //  value already in set; assigning a new value returned by this new call to insert
    cout << format("\n{} {} inserted\n", *(p.first), (p.second ? "was" : "was not"));
    cout << "doubles contains: ";
    ranges::copy(doubles, output);
    cout << "\n";
}
