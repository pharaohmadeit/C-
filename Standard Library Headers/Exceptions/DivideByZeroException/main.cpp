//
//  main.cpp
//  fig12_01
//
//  Created by Pharaoh Tornes on 1/24/25.
//
#include "DivideByZeroException.hpp"
#include <format>
#include <iostream>
#include <stdexcept>

using namespace std;


//  perform division only if the denominator is not zero
double quotient (double numerator, double denominator) {
    //  throw DivideByZeroException if attemping to divide by zero
    if (denominator == 0) {
        throw DivideByZeroException{};
    }
    
    return numerator / denominator;
}

int main() {
    int number1{0}; //  user-specified numerator
    int number2{0}; // user-specified denominator
    
    cout << "Enter two integers (end-of-file to end): ";
    
    //
    while (cin >> number1 >> number2) {
        /*  try block contains code that might throw exception, but the catch will prevent code execution if it occurs*/
        try {
            double result = quotient(number1, number2);
            cout << format("The quotient is: {}\n", result);
        }
        //  catch by reference only to prevent "slicing" which creates a copy of the base class of the called object
        catch (const DivideByZeroException& exception) {
            cout << format("Exception occurred: {}\n", exception.what());
        }
    }
}
