//  C++20's std::ranges Algorithms (Standard Template Library): gcd, lcm, iota, reduce, partial_sum
//  main.cpp
//  fig14_14
//
//  Created by Pharaoh Tornes on 5/05/25.
//

#include <functional>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <array>
#include <iostream>

int main() {
    std::ostream_iterator <int> output (std::cout, " ");
    
    //  calculate the greatest common divisor of two integers
    std::cout << "std::gcd(75, 20): " << std::gcd (75, 20) << "\nstd::gcd(75, 13): " << std::gcd (75, 13);
    
    //  calculate the least common multiple of two integers
    std::cout << "\n\nstd::lcm(3, 5): " << std::lcm (3, 5) << "\nstd::lcm(12, 9): " << std::lcm (12, 9);
    
    //  fill an array with integers using the std::iota algorithm
    std::array <int, 5> ints {};
    std::iota(ints.begin(), ints.end(), 1);
    std::cout << "\n\nints: ";
    std::ranges::copy (ints, output);
    
    //  reduce elements of a container to a single value
    //  the difference between std::accumulate and std::reduce is that the former processes in sequential order while the former can optimize performance during parallelism
    std::cout << "\n\nsum of ints: " << std::reduce(ints.begin(), ints.end()) << "\nproduct of ints: " << std::reduce (ints.begin(), ints.end(), 1, std::multiplies<>{});
    
    //  calculate the partial sums of ints' elements
    std::cout << "\n\nints: ";
    std::ranges::copy (ints, output);
    std::cout << "\n\npartial_sum of ints using std::plus by default: ";
    std::partial_sum(ints.begin(), ints.end(), output);
    std::cout << "\npartial_sum of ints using std::multiplies: ";
    std::partial_sum(ints.begin(), ints.end(), output, std::multiplies{});
    std::cout << "\n";
}
