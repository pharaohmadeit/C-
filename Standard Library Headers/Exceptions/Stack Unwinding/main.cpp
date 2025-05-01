//  Demonstrate stack unwinding in C++ 
//  "If you don't catch an exception, stack unwinding occurs. If you never catch the exception, terminate (from the C++ standard library) is called, which in turn calls abort() which kills the application
//  main.cpp
//  fig12_04
//
//  Created by Pharaoh Tornes on 1/26/25.
//
#include <stdexcept>
#include <iostream>

using namespace std;

//  function3 throws runtime error
void function3() {
    cout << "Call inside function 3\n";
    
    //  throw runtime_error exception with no try block to instigate stack unwinding, return control to function2
    throw runtime_error{"runtime_error in function3"};  //  (Thread 1: signal SIGABRT)
}

//  function2 invokes function3
void function2() {
    cout << "function3 is called inside function2\n";
    function3();    //  stack unwinding occurs, return control to function1 (Thread 1: signal SIGABRT)
}

//  function1 invokes function2
void function1() {
    cout << "function2 is called inside function1\n";
    function2();    // stack unwinding occurs, return control to main (Thread 1: signal SIGABRT)
}

//  demonstrate stack unwinding
int main() {
    //  invoke function1
    try {
        cout << "function1 is called inside main\n";
        function1();
    } catch (const runtime_error& error) {
        cout << "Exception occured: " << error.what() << "\nException handled in main\n";
    }
}
