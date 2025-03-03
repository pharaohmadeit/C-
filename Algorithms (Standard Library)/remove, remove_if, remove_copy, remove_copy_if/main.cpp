//  C++20 <algorithm> remove, remove_if, remove_copy, and remove_copy_if
//  main.cpp
//  fig14_04
//
//  Created by Pharaoh Tornes on 3/2/25.
//

#include <algorithm>    //  algorithm definitions
#include <iterator> //  ostream_iterator; back inserter
#include <vector>
#include <iostream>

using namespace std;

int main() {
    vector init {10, 2, 15, 4, 10, 6};  //  CTAD; Class Template Argument Deduction
    ostream_iterator<int> output {cout, " "};
    
    //  initialize with copy of init
    vector v1 {init};
    cout << "v1: ";
    ranges::copy(v1, output);
    
    //  remove all 10s from v1
    auto removed {std::ranges::remove(v1, 10)}; //  returns iterator pointing to begin/end of removable elements
    v1.erase(removed.begin(), removed.end());
    cout << "\nv1 after removing 10s: ";
    ranges::copy(v1, output);
    
    vector v2 {init};   //  initialize with copy of init
    cout << "\n\nv2: ";
    ranges::copy(v2, output);
    
    //  copy from v2 to c1, removing 10s in the process
    vector<int> c1{};
    ranges::remove_copy(v2, back_inserter(c1), 10);
    cout << "\nc1 after copying v2 without 10s: ";
    ranges::copy(c1, output);
    
    vector v3{init};    //  initialize with copy of init
    cout << "\n\nv3: ";
    ranges::copy(v3, output);
    
    //  remove elements greater than 9 from v3
    auto greaterThan9{[](auto x) -> bool {return x > 9;}};
    auto removed2{ranges::remove_if(v3, greaterThan9)};
    v3.erase(removed2.begin(), removed2.end());
    cout << "\nv3 after removing elements greater than 9: ";
    ranges::copy(v3, output);
    
    vector v4{init};    //  initialize with copy of init
    cout << "\n\nv4: ";
    ranges::copy(v4, output);
    
    //  copy elements from v4 to c2, removing elements greater than 9
    vector<int> c2{};
    ranges::remove_copy_if(v4, back_inserter(c2), greaterThan9);
    cout << "\nc2 after copying v4 without elements greater than 9: ";
    ranges::copy(c2, output);
    cout << "\n";
    
}
