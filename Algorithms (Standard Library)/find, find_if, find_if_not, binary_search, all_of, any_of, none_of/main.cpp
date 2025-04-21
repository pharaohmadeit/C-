//  C++20's std::ranges Algorithms (Standard Template Library): find, find_if, find_if_not, binary_search, all_of, any_of, none_of
//  main.cpp
//  fig14_07
//
//  Created by Pharaoh Tornes on 3/18/25.
//
#include <algorithm>    // algorithm definitions
#include <array>    // array class-template defintion
#include <iterator>
#include <format>
#include <iostream>

void divider(int x);

int main() {
    std::array values {10, 2, 17, 5, 16, 8, 13, 11, 20, 7};
    std::ostream_iterator<int> output {std::cout, " "};
    
    std::cout << "Values contain: ";
    std::ranges::copy(values, output);  //  display output array

    divider(2);
    
    const int find1 {16};
    
    //  locate first occurrence of 16 in values
    if ( auto loc1 { std::ranges::find(values, find1) }; loc1 != values.cend()) {
        std::cout << std::format("Found {} at index: ", find1) << (loc1 - values.cbegin()); //  iterator arithmetic
    }
    else {
        std::cout << std::format("{} not found", find1);
    }
    
    divider(2);
    
    const int find2 {100};
    
    if (auto loc2 {std::ranges::find(values, find2)}; loc2 != values.cend()) {
        std::cout << std::format("Found {} at index: ", find2) << (loc2 - values.cbegin());
    }
    else {
        std::cout << std::format("{} not found", find2);
    }
    
    //  create object to store lambda for later reuse; aka function object
    auto isGreaterThan10{ [](auto x){ return x > 10; } };
    
    // locate first occurence of value greater than 10 in values
    auto loc3 {std::ranges::find_if(values, isGreaterThan10)};
    
    divider(2);
    
    if (loc3 != values.cend()) // found value greater than 10
    {
        std::cout << "First value greater than 10: " << *loc3 << "\nFound at index: " << (loc3 - values.cbegin());
    }
    else    // value greater than 10 not found
    {
        std::cout << "No values greater than 10 were found";
    }
    
    divider(2);
    
    //  sort elements of values in ascending order
    std::ranges::sort(values);
    std::cout << "values after sort: ";
    std::ranges::copy(values, output);
    
    divider(2);
    
    // use binary_search to check whether 13 exists in values; binary_search assumes the collection of elements is already in ascending order; Big O notation, O(log n)
    
    const int find3 {13};
    
    if (std::ranges::binary_search(values, find3)) {
        std::cout << std::format("{} was found in values", find3);
    }
    else {
        std::cout << std::format("{} was not found in values", find3);
    }
    
    divider(1);
    
    // use binary_search to check whether 100 exists in values; Big O notation, O(log n)
    
    const int find4 {100};
    
    if (std::ranges::binary_search(values, find4)) {
        std::cout << std::format("{} was found in values", find4);
    }
    else {
        std::cout << std::format("{} was not found in values", find4);
    }
    
    divider(2);
    
    //  determine whether all of values' elements are greater than 10; Big O notation, O(n)
    if (std::ranges::all_of(values, isGreaterThan10)) {
        std::cout << "All of values' elements are greater than 10";
    }
    else {
        std::cout << "Some values elements are not greater than 10";
    }
    
    divider(1);
    
    // determine whether any of values' elements are greater than 10; Big O notation, O(n)
    if (std::ranges::any_of(values, isGreaterThan10)) {
        std::cout << "Some values are greater than 10";
    }
    else {
        std::cout << "No values elements are greater than 10";
    }
    
    divider(1);
    
    // determine whether none of values' elements are greater than 10; Big O notation, O(n)
    if (std::ranges::none_of(values, isGreaterThan10)) {
        std::cout << "None of values' elements are greater than 10";
    }
    else {
        std::cout << "Some of values' elements are greater than 10";
    }
    
    divider(2);
    
    auto loc4 {std::ranges::find_if_not(values, isGreaterThan10)};
    
    if (loc4 != values.cend()) {
        std::cout << "First value not greater than 10: " << *loc4 << "\nfound at index: " << (loc4 - values.cbegin());
    }
    else {
        std::cout << "Only values greater than 10 were found";
    }
    
    divider(2);
}

void divider(int x) {
    for (int i {0}; i < x; ++i) {
        std::cout << std::endl;
    }
}
