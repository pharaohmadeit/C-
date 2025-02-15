//  Standard Template Library multiset class template
//  main.cpp
//  fig13_06
//
//  Created by Pharaoh Tornes on 2/15/25.
//
#include <set>  //  multiset class-template definition
#include <algorithm>    //  copy algorithm
#include <iterator> //  ostream_iterator
#include <format>
#include <ranges>
#include <vector>
#include <iostream>

using namespace std;

int main() {
    multiset<int, less<int>> ints{};    //  multiset of int values; multiset object angle brackets contains two types: type of elements, the comparator function object which is used by the container to determine sort order
    cout << format("15s in ints: {}\n", ints.count(15));
    
    cout << "\nInserting two 15s into ints\n";
    ints.insert(15);
    ints.insert(15);
    cout << format("15s in ints: {}\n\n", ints.count(15));
    
    //  search for 15 and 20 in ints; find returns an interator
    for (int i : {15, 20}) {
        if (auto result{ints.find(i)}; result != ints.end()) {
            cout << format("Found {} in ints\n", i);
        }
        else {
            cout << format("Did not find {} in ints\n", i);
        }
    }
    
    //  search for 15 and 20 in ints; contains returns a bool
    for (int i : {15, 20}) {
        if (ints.contains(i)) {
            cout << format("Found {} in ints\n", i);
        }
        else {
            cout << format("Did not find {} in ints\n", i);
        }
    }
    
    //  insert unordered elements of vector values into ordered multiset ints
    const vector values{7, 22, 9, 1, 18, 30, 100, 22, 85, 13};
    ints.insert(values.cbegin(), values.cend());
    cout << "\nAfter insert, ints contains:\n";
    ranges::copy(ints, ostream_iterator<int>{cout, " "});
    
    //  determine lower and upper bound of 22 in ints
    cout << format("\n\nlower_bound(22): {}\nupper_bound(22): {}\n\n", *ints.lower_bound(22), *ints.upper_bound(22));
    
    //  use equal_range to determine lower and upper bound of 22 in ints
    auto p{ints.equal_range(22)};
    cout << format("lower_bound(22): {}\nupper_bound(22): {}\n", *(p.first), *(p.second));
    
}
