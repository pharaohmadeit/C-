//    C++20's std::ranges Algorithms (Standard Template Library): fill, fill_n, generate, generate_n
//  main.cpp
//  fig14_02
//
//  Created by Pharaoh Tornes on 2/18/25.
//
#include <array>
#include <algorithm>
#include <iterator>
#include <iostream>

using namespace std;

//  return the next letter (starting with A) using a postincrementer
char nextLetter() {
    static char letter{'A'};
    return letter++;
}

int main() {
    //  initialize an array of 10 chars and an ostream_iterator
    array<char, 10> chars{};
    ostream_iterator<char> output{cout, " "};
    
    //  fills chars with '5's
    ranges::fill(chars, '5');

    cout << "chars after filling with 5s: ";
    ranges::copy(chars, output);
    
    //  fill first five elements of chars with 'A's
    ranges::fill_n(chars.begin(), 5, 'A');
    
    cout << "\nchars after filling five elements with 'A's: ";
    ranges::copy(chars, output);
    
    //  generate values for all elements of chars with nextLetter
    ranges::generate(chars, nextLetter);
    
    cout << "\nchars after generating letters A-J: ";
    ranges::copy(chars, output);
    
    //  generate values for first five elements of chars with nextLetter
    ranges::generate_n(chars.begin(), 5, nextLetter);
    
    // generate values for first three elements of chars with a lambda that takes no arguments but returns a value; using static variable allows the compiler to remembers its value between calls
    ranges::generate_n(chars.begin(), 3, [](){static char letter{'A'}; return letter++;});
    
    cout << "\nchars after generating A-C into elements 0-2: ";
    ranges::copy(chars, output);
    cout << "\n";
    
}
