//  C++20's std::ranges Algorithms (Standard Template Library): min, max, minmax (std::minmax and std::ranges::minmax)
//  main.cpp
//  fig14_13
//
//  Created by Pharaoh Tornes on 4/29/25.
//

#include <algorithm>
#include <iterator>
#include <array>
#include <iostream>

int main() {
    std::array items {3, 100, 52, 77, 22, 31, 1, 98, 13, 40};
    std::ostream_iterator <int> output {std::cout, " "};
    
    std::cout << "Minimum of 12 and 7 is: " << std::min (12, 7)
    << "\nMaxmimum of 17 and 7 is: " << std::max (12,7)
    << "\nMinimum of 'G' and 'Z' is '" << std::min ('G', 'Z') << "'"
    << "\nMaxmimum of 'G' and 'Z' is '" << std::max ('G', 'Z') << "'"
    << "\nMinimum of 'z' and 'Z' is '" << std::min ('z', 'Z') << "'";
    
    //  determine which argument is the min and which is the max
    auto [smaller, larger] {std::minmax (12, 7)};
    std::cout << "\n\nMinimum of 12 and 7 is: " << smaller
    << "\nMaximum of 12 and 7 is: " << larger;
    
    std::cout << "\nitems: ";
    std::ranges::copy (items, output);
    
    auto [smallest, largest] {std::ranges::minmax (items)};
    std::cout << "\nMinimum value in items is: " << smallest
    << "\nMaximum value in items is: " << largest << "\n";
}
