//
//  Class definition of DivideByZeroException.hpp
//  fig12_01
//
//  Created by Pharaoh Tornes on 1/24/25.
//
#include <stdexcept>

using namespace std;

//  DivideByZeroException objects should be thrown by functions upon detecting division-by-zero
class DivideByZeroException : public runtime_error {
    
public:
    //  constructor specified default error message
    DivideByZeroException() : runtime_error("attempted to divide by zero") {}
};
