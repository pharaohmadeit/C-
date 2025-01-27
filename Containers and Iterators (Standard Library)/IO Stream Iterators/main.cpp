//  Use istream_iterator for Standard Library Input and ostream_iterator for Standard Library Output
//  main.cpp
//  fig13_01
//
//  Created by Pharaoh Tornes on 1/26/25.
//
#include <iterator>
#include <iostream>

using namespace std;

int main() {
    cout << "Enter two integers: ";
    
    //  create istream_iterator for reading int values from cin
    istream_iterator<int> inputInt{cin};
    
    const int number1{*inputInt};   //  read int from standard input
    ++inputInt; //  move iterator to next input value
    const int number2{*inputInt};   //  read int from standard input
    
    //  create ostream_iterator for writing int values to cout
    ostream_iterator<int> outputInt{cout};
    
    cout << "The sum is: ";
    *outputInt = number1 + number2;
    cout << endl;
}
