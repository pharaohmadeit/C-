//
//  Class definition of DivideByZeroException.hpp
//  fig12_01
//
//  Created by Pharaoh Tornes on 1/24/25.
//
#include <stdexcept>

using namespace std;

//    Inherit the C++ standard library runtime_error base class and derive a custom exception class
//    C++ Core Guidelines recommends clearly naming problem so such an exception is less likely to be confused with exceptions thrown by other libaries
class DivideByZeroException : public runtime_error {
    
public:
    //  constructor specified default error message
    DivideByZeroException() : runtime_error("attempted to divide by zero") {}
};
