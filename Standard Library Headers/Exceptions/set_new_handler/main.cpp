//  Demonstrate set_new_handler when memory cannot be allocated.
//  main.cpp
//  fig12_07
//
//  Created by Pharaoh Tornes on 1/26/25.
//
#include <new>  //  set_new_handler is defined here
#include <memory>
#include <array>
#include <format>
#include <iostream>

using namespace std;

//  handle memory allocation failure
void customNewHandler() {
    cerr << "customerNewHandler was called\n";
    exit(EXIT_FAILURE);
}

int main() {
    array<unique_ptr<double[]>, 1000> items{};
    
    //  specify that customNewHandler should be called on a memory allocation failure
    set_new_handler(customNewHandler);
    
    //  aim each unique_ptr at a big block of memory
    for (int i{0}; auto& item : items) {
        item = make_unique<double[]>(500'000'000);
        cout << format("items[{}] points to 500,000,000 doubles\n", i++);
    }
}
