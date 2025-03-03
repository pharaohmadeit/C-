//  Algorithms equal, mismatch and lexicographical_compare.
//  main.cpp
//  fig14_03
//
//  Created by Pharaoh Tornes on 2/22/25.
//
#include <algorithm>
#include <iomanip>
#include <iterator>
#include <array>
#include <string>
#include <format>
#include <iostream>

using namespace std;

int main() {
    //  initialize three arrays
    array a1{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    array a2{a1};   //  initialize a2 with copy of a1
    array a3{1, 2, 3, 4, 1000, 6, 7, 8, 9, 10};
    ostream_iterator<int> output{cout, " "};
    
    cout << "a1 contains: ";
    ranges::copy(a1, output);
    cout << "\na2 contains: ";
    ranges::copy(a2, output);
    cout << "\na3 contains: ";
    ranges::copy(a3, output);
    
    //  compare a1 amd a2 for equality
    cout << format("\n\na1 is equal to a2: {}\n", ranges::equal(a1, a2));
    
    //  compare a1 and a3 for equality
    cout << format("\n\na1 is equal to a3: {}", ranges::equal(a1, a3));
    
    //  check for mismatch between a1 and a3
    auto location{ranges::mismatch(a1, a3)};
    cout << format("\na1 and a3 mismatch at index {} ({} vs {})\n", (location.in1 - a1.cbegin()), *location.in1, *location.in2);
    
    string s1{"HELLO"};
    string s2{"BYE BYE"};
    
    //  perform lexicographical comparison of c1 and c2
    cout << format("\"{}\" < \"{}\": {}\n", s1, s2, ranges::lexicographical_compare(s1, s2));
    
    cout << "\n";
    
    
}
