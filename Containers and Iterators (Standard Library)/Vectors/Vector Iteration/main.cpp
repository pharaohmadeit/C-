//  Standard Library Vector class template
//  main.cpp
//  fig13_02
//
//  Created by Pharaoh Tornes on 1/26/25.
//
#include <ranges>
#include <vector>   //  vector class-template definition
#include <format>
#include <iostream>

using namespace std;

//  display value appended to vector and updated vector size and capacity
void showResult(int value, size_t size, size_t capacity) {
    cout << format("appended: {}: size {}: capacity: {}\n", value, size, capacity);
}

int main() {
    
    vector<int> integers{};
    
    cout << "Size of integers: " << integers.size() << "\nCapacity of integers: " << integers.capacity() << "\n\n";
    
    for (int i : views::iota(1,11)) {
        integers.push_back(i);  //  push_back member function is available for vector, deque and list
        showResult(i, integers.size(), integers.capacity());
    }
    
    cout << "\nOutput integers using iterators: ";
    
    for (auto constIterator{integers.cbegin()}; constIterator!= integers.cend(); ++constIterator) {
        cout << *constIterator << ' ';
    }
    
    cout << "\nOutput integers in reverse using iterators: ";
    
    for (auto reverseIterator{integers.crbegin()}; reverseIterator!= integers.crend(); ++reverseIterator) {
        cout << *reverseIterator << ' ';
    }
    
    cout << endl;
    
}
