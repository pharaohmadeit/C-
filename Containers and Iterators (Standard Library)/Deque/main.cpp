//
//  main.cpp
//  fig13_05
//
//  Created by Pharaoh Tornes on 2/14/25.
//
#include <deque>    //  "double-ended queue" "first-in or first-out" queue of elements; deque class-template definition
#include <algorithm>    //  copy algorithm
#include <iterator> //  ostream_iterator
#include <iostream>

using namespace std;

int main() {
    //  create deque of doubles
    deque<double> values;
    ostream_iterator<double> output{cout, " "};
    
    //  insert elements in values
    values.push_front(2.2);
    values.push_front(3.5);
    values.push_back(1.1);
    
    cout << "values contains: ";
    
    //  use subscript operator to obtain elements of values
    for (size_t i{0}; i < values.size(); ++i) {
        cout << values[i] << ' ';
    }
    
    //  remove first element
    values.pop_front();
    cout << "\nAfter pop_front, values contains: ";
    ranges::copy(values, output);
    
    //  use subscript operator to modify element at location 1
    values[1] = 5.4;
    cout << "\nAfter values[1] = 5.4, values contains: ";
    ranges::copy(values, output);
    cout << "\n";
}

