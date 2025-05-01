//  C++20's std::ranges Algorithms (Standard Template Library): lower_bound, upper_bound, equal_range
//  main.cpp
//  fig14_12
//
//  Created by Pharaoh Tornes on 4/29/25.
//

#include <algorithm>
#include <iterator>
#include <array>
#include <iostream>

int main() {
    std::array values {2, 2, 4, 4, 4, 6, 6, 6, 6, 8};
    std::ostream_iterator <int> output (std::cout, " ");
    
    std::cout << "values contains: ";
    std::ranges::copy (values, output);
    
    //  determine lower-bound insertion point for 6 in values
    auto lower6 {std::ranges::lower_bound (values, 6)};
    std::cout << "\n\nLower bound of 6 is index: " << (lower6 - values.begin());
    
    //  determine upper-bound insertion point for 6 in values
    auto upper6 {std::ranges::upper_bound (values, 6)};
    std::cout << "\nUpper bound of 6 is index: " << (upper6 - values.begin());
    
    //  use equal_range to determine the lower and upper bound of 6
    auto [first, last] {std::ranges::equal_range(values, 6)};
    std::cout << "\n\nUsing equal_range:\n    Lower bound of 6 is index: " << (first - values.begin());
    std::cout << "\n    Upper bound of 6 is index: " << (last - values.begin());
    
    //  determine lower-bound insertion point for 3 in values
    auto lower3 {std::ranges::lower_bound (values, 3)};
    std::cout << "\n\nUse lower_bound to locate the first point at which 3 can be inserted in order";
    std::cout << "\n    Lower bound of 3 is index: " << (lower3 - values.begin());
    
    //  determine upper-bound insertion point for 7 in values
    auto upper7 {std::ranges::lower_bound (values, 7)};
    std::cout << "\n\nUse upper_bound to locate the last point at which 7 can be inserted in order";
    std::cout << "\n    Upper bound of 7 is index: " << (upper7 - values.begin());
    
    std::cout << std::endl;
}
