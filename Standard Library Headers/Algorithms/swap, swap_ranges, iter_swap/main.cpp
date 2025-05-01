//  C++20's std::ranges Algorithms (Standard Template Library): swap, swap_ranges, iter_swap
//  main.cpp
//  fig14_08
//
//  Created by Pharaoh Tornes on 4/18/25.
//

#include <algorithm>
#include <iterator>
#include <array>
#include <iostream>

void divider (int i);

int main() {
    std::array values1 {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::ostream_iterator <int> output {std::cout, " "};
    
    std::cout << "values1 contains: ";
    std::ranges::copy (values1, output);
    
    std::swap (values1[0], values1[1]);
    
    divider (1);
    
    std::cout << "after std::swap of values1[0] and values1[1]: ";
    std::ranges::copy (values1, output);
    
    divider (1);
    
    //  use iterators to swap elements at locations 0 and 1
    std::iter_swap (values1.begin(), values1.begin() + 1);
    std::cout << "after std::iter_swap of values1[0] and values1[1]: ";
    std::ranges::copy (values1, output);
    
    divider (2);
    
    //  swap values1 and values2
    std::array values2 {10, 9, 8, 7, 6, 5, 4, 3, 2 , 1};
    std::cout << "Before swap_ranges\nvalues1 contains: ";
    std::ranges::copy (values1, output);
    divider (1);
    std::cout << "values2 contains: ";
    std::ranges::copy (values2, output);
    divider (2);
    std::ranges::swap_ranges(values1, values2);
    std::cout << "After swap_ranges\nvalues1 contains: ";
    std::ranges::copy (values1, output);
    std::cout << "values2 contains: ";
    std::ranges::copy (values2, output);
    
    divider(2);
    
    //  swap first five elements of values1 and values2
    std::ranges::swap_ranges(values1.begin(), values1.begin() + 5, values2.begin(), values2.begin() + 5);
    std::cout << "After swap_ranges for 5 elements" << "\nvalues1 contains: ";
    std::ranges::copy (values1, output);
    divider(1);
    std::cout << "values2 contains: ";
    std::ranges::copy (values2, output);
    divider(2);
    
}

void divider (int i) {
    for (int x = 0; x < i; ++x) {
        std::cout << "\n";
    }
}
