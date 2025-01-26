//  Demonstrate standard "new" throwing bad_alloc when memory cannot be allocated. Stuff an array of 1000 pointers each aimed at an array of 500,000,000 doubles
//  main.cpp
//  fig12_06
//
//  Created by Pharaoh Tornes on 1/26/25.
//
#include <new>
#include <memory>
#include <array>
#include <format>
#include <iostream> //  bad_alloc class is defined here

using namespace std;

int main() {
    array<unique_ptr<double[]>, 1000> items{};
    
    // aim each unique_ptr at a big block of memory
    try {
        for (int i{0}; auto& item : items) {
            item = make_unique<double[]>(500'000'000);
            cout << format("items[{}] points to 500,000,000 doubles\n", i++);
        }
    } catch (const bad_alloc& memoryAllocationException) {
        cout << format("Exception occured: {}\n", memoryAllocationException.what());
    }
}
