//
//  Agglo.hpp
//  Agglomeration
//
//  Created by Pharaoh Tornes on 1/22/25.
//
#pragma once
#include <initializer_list>
#include <memory>
#include <iostream>

using namespace std;

class Agglo final {
    
    friend istream& operator>>(istream& in, Agglo& a);
    
    friend void swap(Agglo& a, Agglo& b) noexcept;
    
public:
    //  construct an Agglo of size elements; marked explict to prevent compiler-time implict conversion
    explicit Agglo(size_t size);
    
    // construct an Agglo with a brace-initializer list of ints
    explicit Agglo(initializer_list<int> list);
    
    Agglo(const Agglo& original);   //  copy constructor
    Agglo& operator = (const Agglo& right);   //  copy assignment operator
    
    Agglo(Agglo&& original) noexcept;   //  move constructor
    Agglo& operator = (Agglo&& right) noexcept;   // move assignment
    
    ~Agglo();   //  destructor; the goal is ~Agglo() = default;
    
    size_t size() const noexcept {return m_size;};  //  return size; implemented in the header file
    string toString() const;  //  string representation
    
    //  equality operator; compiler autogenerates !=
    bool operator == (const Agglo& right) const noexcept;
    
    //  subscript operator for non-const objects returns modifiable lvalue
    int& operator [] (size_t index);
    
    //  subscript operator for non-const objects returns modifiable lvalue
    const int& operator [] (size_t index) const;
    
    //  convert Agglo to a bool value: true if non-empty; false if empty
    explicit operator bool() const noexcept {return size() != 0;}
    //static_cast<bool>(someAgglo)
    
    //  preincrement every element, then return updated Agglo
    Agglo& operator ++ ();
    
    //  postincrement every element, and return copy of original Agglo
    Agglo operator ++ (int);    // dummy (int) parameter is a complier hack to differentiate preincrement and postincrement
    
    //  add value to every element, then return updated Agglo
    Agglo& operator+=(int value);
    
private:
    size_t m_size{};    //  pointer-based array size
    unique_ptr<int[]> m_ptr;    // smart pointer to integer array
};

//  overloaded operator<< is not a friend--does not access private data
ostream& operator<<(ostream& out, const Agglo& a);
