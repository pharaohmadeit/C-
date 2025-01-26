//  Demonstrate rethrowing an exception
//  main.cpp
//  fig12_03
//
//  Created by Pharaoh Tornes on 1/25/25.
//

#include <iostream>
#include <exception>

using namespace std;

void throwException() {
    try {
        cout << "Function throwException throws an exception\n";
        throw exception{};
    }
    catch (const exception&) {
        cout << "   Exception handled in function throwException" << "\n    Function throw Exception rethrows exception";
        throw;
    }
    
    cout << "This shouldn't print\n";
}

int main() {
    //  call throwException
    try {
        cout << "main invokes function throwException\n";
        throwException();
        cout << "This shouldn't print\n";
    }
    catch (const exception&) {
        cout << "\n\n" << "Exception handled in main\n";
    }
    cout << "Program control continues after catch in main\n";
}
