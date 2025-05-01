//  C++20's std::ranges algorithms: shuffle, count, count_if, min_element, max_element, minmax_element, transform
//  main.cpp
//  fig14_06
//
//  Created by Pharaoh Tornes on 3/13/25.
//

#include <algorithm>
#include <iterator>
#include <array>
#include <random>
#include <iostream>

int main() {
    std::array a1 { 1, 2, 3, 4, 5, 6 , 7 , 8, 9, 10 };
    std::ostream_iterator <int> output { std::cout, " " };
    
    std::cout << "a1: ";
    std::ranges::copy ( a1, output );
    
    //  create random-number engine and use it to help shuffle a1
    std::default_random_engine randomEngine { std::random_device{}() };
    std::ranges::shuffle ( a1, randomEngine ); //  randomly order elements
    std::cout << "\na1 shuffled: ";
    std::ranges::copy ( a1, output );
    
    std::array a2 { 100, 2, 8, 1, 40, 3, 8, 8, 9, 10 };
    std::cout << "\n\na2: ";
    std::ranges::copy ( a2, output );
    
    //  count number of elements in a2 with value 8
    auto result1 { std::ranges::count( a2, 8 ) };
    std::cout << "\nCount of 8s in a2: " << result1;
    
    //  count number of elements in a2 that are greater than 9
    auto result2 { std::ranges::count_if ( a2, [](auto x){ return x > 9; } ) };
    std::cout << "\nCount of numbers greater than 9: " << result2;
    
    //  locate minimum element in a2; requires a forward ranges as an argument; stores an iterator pointing at the first occurrence of the element; result variable is scopped within if statement parenthesis;
    if ( auto result { std::ranges::min_element ( a2 ) }; result != a2.end() ) {
        std::cout << "\n\na2 minimum element: " << *result; //  dereference the iterator to return value of the element
    }
    
    // locate maximum element in a2; max_element returns the iterator position pointing to the first instanse of the maximum element
    if ( auto result { std::ranges::max_element ( a2 ) }; result != a2.end() ) {
        std::cout << "\na2 maximum element: " << *result;
    }
    
    //  locate minimum and maximum elements in a2; max returns the iterator position pointing to the last instance of the maximum element
    //  Structured Bindings introduced in C++17 (also known as unpacking the elements of some object, for example: arrays, standard pair objects, standard tuple objects)
    auto [ min, max ] { std::ranges::minmax_element ( a2 ) };
    std::cout << "\na2 minimum and maximum elements: " << *min << " and " << *max;
    
    //  calculate cube of each element in a1; place results in cubes
    std::array <int, a1.size()> cubes {};
    std::ranges::transform ( a1, cubes.begin(), [](auto x) { return x * x * x; } );
    std::cout << "\n\na1 values cubed: ";
    std::ranges::copy ( cubes, output );
    std::cout << "\n";
}
