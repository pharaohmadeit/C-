//  Vector element-manipulation member functions
//  main.cpp
//  fig13_03
//
//  Created by Pharaoh Tornes on 1/26/25.
//
#include <algorithm>    //  copy algorithm
#include <iterator> // input/output stream iterator
#include <ranges>    //    ranged-based operations
#include <vector>
#include <format>
#include <iostream>

using namespace std;

int main() {
    vector values{1, 2, 3, 4, 5};   //  class template argument deduction
    vector<int> integers{values.cbegin(), values.cend()};   //  vector constructor receives iterators as arguments, which gives ability to iterate through individual elements and pass by value
    ostream_iterator<int> output{cout, " "};    //  second argument is a delimiter string for output stream iterator
    
    cout << "integers contains: ";
    copy(integers.cbegin(), integers.cend(), output);   //  common ranges copy algorithm, output the container without a for-loop

    //    front and back member-functions are very important
    cout << format("\nfront: {}\nback: {}\n\n", integers.front(), integers.back());
    
    integers[0] = 7;    //  square bracket doesn't conduct bounds checking
    integers.at(2) = 10;    // at member function validates index number and will throw exception
    
    //  insert 22 as the second element; const_iterator as first argument
    integers.insert(integers.cbegin() + 1, 22);
    
    cout << "Contents of vector integers after changes: ";
    ranges::copy(integers, output); //  automatically knows how to iterate through first argument; second argument is the output
    
    //  erase first element
    integers.erase(integers.cbegin());
    cout << "\n\nintegers after erasing first element: ";
    ranges::copy(integers, output);
    
    //  erase remaining elements
    integers.erase(integers.cbegin(), integers.cend());
    cout << format("\nErased all elements: integers{} empty\n", integers.empty() ? "is" : "is not");
    
    //  insert elements from the vector values
    integers.insert(integers.cbegin(), values.cbegin(), values.cend());
    cout << "\nContents of vector integers before clear: ";
    ranges::copy(integers, output);
    
    //  empty integers; clear empties a collection
    integers.clear();
    cout << format("\nAfter clear, integers {} empty\n", integers.empty() ? "is" : "is not");
}
