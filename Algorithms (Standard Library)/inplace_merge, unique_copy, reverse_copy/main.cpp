//  C++20's std::ranges Algorithms (Standard Template Library): inplace_merge, unique_copy, reverse_copy
//  main.cpp
//  fig14_10
//
//  Created by Pharaoh Tornes on 4/23/25.
//

#include <algorithm>
#include <iterator>
#include <vector>
#include <array>
#include <iostream>

int main() {
    std::array a1 {1, 3, 5, 7, 9, 1, 3, 5, 7, 9};
    std::ostream_iterator <int> output {std::cout, " "};
    
    std::cout << "array a1 contains: ";
    std::ranges::copy (a1, output);
    
    //  merge first half of a1 with second half of a1 such that a1 contains sorted set of elements after merge
    std::ranges::inplace_merge (a1, a1.begin() + 5);
    std::cout << "\n" << "After inplace_merge, a1 contains: ";
    std::ranges::copy (a1, output);
    
    //  copy only unique elements of a1 into results1
    std::vector <int> results1 {};
    std::ranges::unique_copy (a1, std::back_inserter(results1));
    std::cout << "\nAfter unique_copy, results1 contains: ";
    std::ranges::copy (results1, output);
    
    //  copy elements of a1 into results2 in reverse order
    std::vector <int> results2 {};
    std::ranges::reverse_copy (a1, std::back_inserter(results2));
    std::cout << "\nAfter reverse_copy, results2 contains: ";
    std::ranges::copy (results2, output);
    std::cout << std::endl;
}
