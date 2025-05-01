//
//  main.cpp
//  fig05_16
//
//  Created by Pharaoh Tornes on 1/17/25.
//
#include <iostream>
using namespace std;

void useLocal();
void useStaticLocal();
void useGlobal();

int x{1};

int main() {
    cout << "global x in main is " << x << "\n";
    
    const int x{5};
    
    cout << "local x in main's outer scope is " << x << "\n";
    
    {
        const int x{7};
        
        cout << "local x in main's inner scope is " << x << "\n";
    }
    
    cout << "local x in main's outer scope is " << x << "\n";
    
    useLocal();
    useStaticLocal();
    useGlobal();
    useLocal();
    useStaticLocal();
    useGlobal();
    
    cout << "\nlocal x in main is " << x << "\n\n";
}

void useLocal() {
    int x{25};
    
    cout << "\nlocal x is " << x << " on entering useLocal\n";
    ++x;
    cout << "local x is " << x << " on exiting useLocal\n";
}

void useStaticLocal() {
    int x{50};
    
    cout << "\nlocal x is " << x << " on entering useStaticLocal\n";
    ++x;
    cout << "local x is " << x << " on exiting useStaticLocal\n";
}

void useGlobal() {
    cout << "\nglobal x is " << x << " on entering useGlobal\n";
    x *= 10;
    cout << "global x is " << x << " on exiting useGlobal\n";
}
