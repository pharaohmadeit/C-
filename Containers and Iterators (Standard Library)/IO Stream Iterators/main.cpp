//  Use istream_iterator for Standard Library Input and ostream_iterator for Standard Library Output
//  main.cpp
//  fig13_01
//
//  Created by Pharaoh Tornes on 1/26/25.
//
#include <iterator>
#include <iostream>

int main() {
    std::cout << "Enter two integers: ";
    
    //  create istream_iterator for reading int values from cin
    std::istream_iterator<int> inputInt{std::cin};
    
    const int number1{*inputInt};   //  read int from standard input
    ++inputInt; //  move iterator to next input value
    const int number2{*inputInt};   //  read int from standard input
    
    //  create ostream_iterator for writing int values to cout
    std::ostream_iterator<int> outputInt{std::cout};
    
    std::cout << "The sum is: ";
    *outputInt = number1 + number2;
    std::cout << std::endl;
}
