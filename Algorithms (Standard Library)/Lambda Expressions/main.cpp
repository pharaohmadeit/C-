//  Lambda Expressions
//  main.cpp
//  fig14_01
//
//  Created by Pharaoh Tornes on 2/18/25.
//
#include <algorithm>    //  copy and for_each
#include <iterator> //  ostream_iterator
#include <array>
#include <iostream>

int main() {
    //  initialize an array of ints using CTAD (class template argument deduction)
    std::array values{1, 2, 3, 4};
    std::ostream_iterator<int> output{std::cout, " "};
    
    // using ranges namespace copy algorithm to output the array to the standard output stream
    std::cout << "values contains: ";
    std::ranges::copy(values, output);
    
    //  output each element multiplied by two; use for_each with a lambda expression
    std::cout << "\nDisplay each element multiplied by two: ";
    std::ranges::for_each(values, [](auto i) {std::cout << i * 2 << " ";});
    
    //  add each element to sum; use lambda expression and capture the sum by reference in the introducer so it can be summed within the body of the lambda with the iterator in the parameter list
    int sum{0};
    std::ranges::for_each(values, [&sum](auto i) {sum += i;});
    std::cout << "\nSum of value's elements is: " << sum << "\n";
    
}
