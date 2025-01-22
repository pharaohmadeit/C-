//
//  main.cpp
//  fig11_02
//
//  Created by Pharaoh Tornes on 1/22/25.
//
#include <memory>    //     provides smart pointer tools for memory management
#include <iostream>

using namespace std;

class Integer {

public:
    //  Constructor
    Integer(int i) : value{i} {
        cout << "Constructor for Integer " << value << "\n";
    }
    
    //  Destructor
    ~Integer() {
        cout << "\nDestructor for Integer " << value << "\n";
    }
    
    //  Integer value getter
    int getValue() const {return value;}
    
private:
    int value{0};
};

//  use unique_ptr to manipulate Integer object
int main() {
    cout << "Creating a unique_ptr object that points to an Integer\n\n";
    
    //  "aim" unique_ptr object at a new Integer object
    auto ptr{make_unique<Integer>(7)};
    
    //  use unique_ptr to call Integer member function
    cout << "\nInteger value: " << ptr->getValue() << "\n\nmain() ends (ptr goes out of scope and calls object's destructor)\n";
}
