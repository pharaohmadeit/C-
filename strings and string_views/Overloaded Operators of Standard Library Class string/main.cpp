//
//  main.cpp
//  fig11_01
//
//  Created by Pharaoh Tornes on 1/20/25.
//
#include <string_view>
#include <string>
#include <format>
#include <iostream>

using namespace std;

int main() {
    
    string s1{"happy"};
    string s2{" birthday"};
    string s3;
    string_view v{"hello"};
    
    cout << format(R"(s1: "{}"; s2: "{}"; s3: "{}"; v:"{}")", s1, s2, s3, v) << endl;
    
    //  test overloaded equality and relational operators
    cout << "The results of comparing s2 and s1:\n"
    << format("s2 == s1: {}\n", s2 == s1)
    << format("s2 != s1: {}\n", s2 != s1)
    << format("s2 > s1: {}\n", s2 > s1)
    << format("s2 < s1: {}\n", s2 < s1)
    << format("s2 >= s1: {}\n", s2 >= s1)
    << format("s2 <= s1: {}\n", s2 <= s1);
    
    cout << "\nTesting s3.empty():\n";
    
    //  test string member function empty
    if (s3.empty()) {
        cout << "s3 is empty; assigning s1 to s3;\n";
        s3 = s1;
        cout << format("s3 is \"{}\"\n\n", s3);
    }
    
    //  test overloading string concatenation assignment operator
    s1 += s2;
    cout << format("s1 += s2 yields s1 = {}", s1);
    
    //  test string concatenation with a C string
    s1 += " to you";
    cout << format("s1 += \" to you\" yields s1 = {}", s1);
    
    //  testing string concatenation with a C++14 string-object literal
    s1 += ", have a great day!"s; //    s after " for string-object literal
    
    //  test string member function substr
    cout << format("{} {}\n{}\n\n", "The substring of s1 starting at location 0 for", "14 characters, s1.substr(0, 14), is:", s1.substr(0, 14));
    
    cout << format("{} {}\n{}\n\n", "The substring of s1 starting at", "location 15, s1.substr(0, 14), is:", s1.substr(15));
    
    //  test copy constructor
    string s4{s1};
    cout << format("s4 = {}\n\n", s4);
    
    //  test overloaded copy assignment (=) operator with self-assignment
    cout << "assigning s4 to s4\n";
    s4 = s4;
    cout << format("s4 = {}\n\n", s4);
    
    //  test string's string_view constructor
    cout << "";
    string s5{v};
    cout << format("s5 is {}\n\n", s5);
    
    //  test using overloaded subscript operator to create lvalue
    s1[0] = 'H';
    s1[6] = 'B';
    cout << format("{}:\n{}\n\n", "after s1[0] = 'H' and s1[6] = 'B', s1 is", s1);
    
    //  test index out of range with string member function "at"
    try {
        cout << "Attempt to assign 'd' to s1.at(100) yields:\n";
        s1.at(100) = 'd';   //  attempt error (subscript out of range)
    } catch (const out_of_range& exception) {
        cout << format("An exception occurred: {}\n", exception.what());    // catch exception
    }
}
