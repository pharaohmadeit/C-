//  C++20's std::ranges Algorithms (Standard Template Library): remove, remove_if, remove_copy, and remove_copy_if
//  main.cpp
//  fig14_04
//
//  Created by Pharaoh Tornes on 3/2/25.
//

#include <algorithm>    //  algorithm definitions
#include <iterator> //  ostream_iterator; back_inserter
#include <vector>
#include <iostream>

using namespace std;

int main() {
    vector init {10, 2, 15, 4, 10, 6};  //  CTAD; Class Template Argument Deduction
    ostream_iterator<int> output {cout, " "};
    
    //  initialize with copy of init
    vector v1 {init};
    cout << "v1: ";
    ranges::copy(v1, output);
    
    //  remove all 10s from v1 using the Erase-Remove Idiom (use the vector's erase member function to delete the subrange)
    auto removed {std::ranges::remove(v1, 10)}; //  returns a subrange containing an iterator pointing to begin/end of removable elements
    v1.erase(removed.begin(), removed.end());
    //  alternative C++20 algorithm called std::erase or std::erase_if (the container member functions do not support directly support ranges, but the std::erase free function accomplishes this task by combining the steps into a single algorithm call); erase_if receives as its second argument a unary predicate function, i.e. first-order function is passed to a higher-order function
    /*
     std::erase(v1, 10);
     */
    cout << "\nv1 after removing 10s: ";
    ranges::copy(v1, output);
    
    //  initialize with copy of init
    vector v2 {init};
    cout << "\n\nv2: ";
    ranges::copy(v2, output);
    
    //  copy from v2 to c1, removing 10s in the process
    vector<int> c1{};
    ranges::remove_copy(v2, back_inserter(c1), 10); //  back_inserter is container adapter allowing for vector resizing
    cout << "\nc1 after copying v2 without 10s: ";
    ranges::copy(c1, output);
    
    vector v3{init};    //  initialize with copy of init
    cout << "\n\nv3: ";
    ranges::copy(v3, output);
    
    
    /* the difference between std::ranges::remove and std::ranges::remove_if:
     
     remove is looking for a specific value to remove from a range of values
     
     remove_if receives a unary predicate function that looks at the one argument and returns a boolean based on a specified calculation
     
     Notes: A unary predicate function is a function that takes one argument and returns a boolean value. It's a type of predicate in first-order predicate calculus.
     
     */

    //  remove elements greater than 9 from v3
    auto greaterThan9{[](auto x) -> bool {return x > 9;}};  //  lambda using explicit return type -> boolean (true or false)
    auto removed2{ranges::remove_if(v3, greaterThan9)}; //  remove_if is a higher order function which receives a function object to customize behavior and returns an iterator pointing to the elements that are removable
    v3.erase(removed2.begin(), removed2.end()); //  erase actually erases the begin/end iterator elements
    cout << "\nv3 after removing elements greater than 9: ";
    ranges::copy(v3, output);
    
    vector v4{init};    //  initialize with copy of init
    cout << "\n\nv4: ";
    ranges::copy(v4, output);
    
    //  copy elements from v4 to c2, removing elements greater than 9
    vector<int> c2{};
    ranges::remove_copy_if(v4, back_inserter(c2), greaterThan9);    //  remove_copy_if is a higher order function which receives a function object to customize behavior; creates a copy of the results with second argument using the back_inserter container adapter; first argument is the containter in question;
    cout << "\nc2 after copying v4 without elements greater than 9: ";
    ranges::copy(c2, output);
    cout << "\n";
    
}
