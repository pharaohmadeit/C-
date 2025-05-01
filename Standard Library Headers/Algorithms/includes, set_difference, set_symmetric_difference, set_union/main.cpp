//  C++20's std::ranges Algorithms (Standard Template Library): includes, set_difference, set_intersection, set_symmetric_difference, set_union
//  main.cpp
//  fig14_11
//
//  Created by Pharaoh Tornes on 4/29/25.
//

#include <algorithm>
#include <iterator>
#include <vector>
#include <array>
#include <format>
#include <iostream>

int main() {
    std::array a1 {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::array a2 {4, 5, 6, 7, 8};
    std::array a3 {4, 5, 6, 11, 15};
    std::ostream_iterator <int> output (std::cout, " ");
    
    std::cout << "a1 contains: ";
    std::ranges::copy (a1, output); //  display a1
    std::cout << "\na2 contains: ";
    std::ranges::copy (a2, output); //  display a2
    std::cout << "\na3 contains: ";
    std::ranges::copy (a3, output); //  display a3
    
    //  determine whether a2 is completely contained in a1
    std::cout << std::format("\n\na1 {} a2", std::ranges::includes (a1, a2) ? "includes" : "does not not include");
    
    //  determine whether a3 is completely contained in a1
    std::cout << std::format("\n\n a1 {} a3", std::ranges::includes (a1, a3) ? "includes" : "does not include");
    
    //  determine elements of a1 not in a2
    std::vector <int> difference {};
    std::ranges::set_difference (a1, a2, std::back_inserter(difference));
    std::cout << "\n\nset_difference of a1 and a2 is: ";
    std::ranges::copy (difference, output);
    
    //  determine elements in both a1 and a2
    std::vector <int> intersection {};
    std::ranges::set_intersection (a1, a2, std::back_inserter(intersection));
    std::cout << "\n\nset_intersection of a1 and a2 is: ";
    std::ranges::copy (intersection, output);
    
    // determine elements of a1 that are not in a3 and elements of a3 that are not in a1
    std::vector <int> symmetricDifference {};
    std::ranges::set_symmetric_difference (a1, a3, std::back_inserter(symmetricDifference));
    std::cout << "\n\nset_symmetric_difference of a1 and a3 is: ";
    std::ranges::copy (symmetricDifference, output);
    
    //  determine elements that are in either or both sets
    std::vector <int> unionSet{};
    std::ranges::set_union (a1, a3, std::back_inserter(unionSet));
    std::cout << "\n\nset_union of a1 and a3 is: ";
    std::ranges::copy (unionSet, output);
    std::cout << std::endl;
}
