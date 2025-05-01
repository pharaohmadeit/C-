//  C++20's std::ranges Algorithms (Standard Template Library): replace, replace_if, replace_copy and replace_copy_if
//  main.cpp
//  fig14_05
//
//  Created by Pharaoh Tornes on 3/7/25.
//

#include <algorithm>    //  ranges algorithms
#include <iterator>
#include <array>
#include <iostream>

using namespace std;

int main() {
    ostream_iterator<int> output {cout, " "};
    
    array a1 {10, 2, 15, 4, 10, 2};
    cout << "a1: ";
    ranges::copy (a1, output);
    
    //  replace all 10s in a1 with 100
    ranges::replace(a1, 10, 100);
    cout << "\na1 after replacing 10s with 100s: ";
    ranges::copy(a1, output);
    
    //  initialize c1 with an array of the same size as a2
    array a2 {10, 2, 15, 4, 10, 6};
    array<int, a2.size()> c1 {};
    cout << "\n\na2: ";
    ranges::copy(a2, output);
    
    //  copy from a2 to c1, replacing 10s with 100s
    ranges::replace_copy(a1, c1.begin(), 10, 100);
    cout << "\nc1 after copying a1 by replacing 10s with 100s: ";
    ranges::copy(c1, output);
    
    array a3 {10, 2, 15, 4, 10, 6};
    cout << "\n\na3: ";
    ranges::copy(a3, output);
    
    //  replace values greater than 9 in a3 with 100
    auto greaterThan9 { [](auto x){return x > 9;} };
    ranges::replace_if(a3, greaterThan9, 100);
    cout << "\na3 after replacing values greater than 9 with 100s: ";
    ranges::copy(a3, output);
    
    array a4 {10, 2, 15, 4, 10, 6};
    array<int, a4.size()> c2 {};
    cout << "\n\na4: ";
    ranges::copy(a4, output);
    
    //  copy a4 to c2, replacing elements greater than 9 with 100
    ranges::replace_copy_if(a4, c2.begin(), greaterThan9, 100);
    cout << "\nc2 after replacing a4's values greater than 9 with 100s: ";
    ranges::copy(c2, output);
    cout << "\n";
    
}
