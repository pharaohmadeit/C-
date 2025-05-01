//
//  Agglo.cpp
//  Agglomeration
//
//  Created by Pharaoh Tornes on 1/22/25.
//
#include "Agglo.hpp"
#include <span>
#include <memory>
#include <algorithm>
#include <utility>
#include <sstream>
#include <stdexcept>
#include <format>

using namespace std;

//  Agglo constructor to create an Agglo of size elements containing 0
Agglo::Agglo(size_t size) : m_size{size}, m_ptr{make_unique<int[]>(size)} {
    
    cout << "Agglo(size_t) constructor\n";
    
}

//  Agglo constructer that accepts an initializer list
Agglo::Agglo(initializer_list<int> list) : m_size{list.size()}, m_ptr{make_unique<int[]>(list.size())} {
    
    cout << "Agglo(initializer_list) constructor\n";
    
    //  copy list argument's elements into m_ptr's underlying int array; m_ptr.get() returns the int array's starting memory location
    
    copy(begin(list), end(list), m_ptr.get());
    
}


//  copy constructor: must a reference to a Agglo
Agglo::Agglo(const Agglo& original) : m_size{original.size()}, m_ptr{make_unique<int[]>(original.size())} {
    cout << "Agglo copy constructor\n";
    
    //  copying the referenced object's elements into m_ptr's underlying int array
    const span<const int> source{original.m_ptr.get(), original.size()};
    copy(begin(source), end(source), m_ptr.get());
}

//  copy assignment operator impemented with "copy-and-swap idiom"; guarentees that original object won't be modified incase memory allocation fails
Agglo& Agglo::operator = (const Agglo &right) {
    cout << "Agglo copy assignment operator\n";
    Agglo temp{right};
    swap(*this, temp);  // exchanges contents and pointers of both objects
    return *this;
}

//  move constructor: must receieve an rvalue reference (&&) to an Agglo
Agglo::Agglo(Agglo&& original) noexcept (true) : m_size{std::exchange(original.m_size, 0)}, m_ptr{std::move(original.m_ptr)} { // noexcept (true) is used since we are moving existing resources, i.e. it already exists, we're just moving it |  std::exchange swaps the values of the first and second argument but returns old value first; i.e. original.m_size class member is initialized to 0 but the old original size is returned | moves original.m_ptr into m_ptr which results in only one unique pointer to that chunk of data
    cout << "Agglo move assignment operator\n";
}

//  move assignment operator
Agglo& Agglo::operator = (Agglo&& right) noexcept (true) {
    cout << "Agglo move assignment operator\n";
    
    if (this != &right) { //    avoid self-assignment
        // move right's data into this Agglo
        m_size = std::exchange(right.m_size, 0); //indicate right is empty
        m_ptr = std::move(right.m_ptr);
    }
    return *this;   //  enables x = y = z, for example
}

Agglo::~Agglo() {
    cout << "\nAgglo destructor\n";
}

string Agglo::toString() const {
    const span<const int> items{m_ptr.get(), m_size};
    ostringstream output;
    
    output << "{";
    
    //  insert each item in the dynamic array into the ostringstream
    for (size_t count{0}; const auto& item : items) {
        ++count;
        output << item << (count < m_size ? ", " : "");
    }
    
    output << "}";
    
    return output.str();
}

bool Agglo::operator == (const Agglo& right) const noexcept {
    const span<const int> lhs{m_ptr.get(), size()};
    const span<const int> rhs{right.m_ptr.get(), right.size()};
    
    return std::equal(begin(lhs), end(lhs), begin(rhs), end(rhs));
}

int& Agglo::operator [] (size_t index) {
    //  check for index out-of-range error
    if (index >= this->m_size) {    //  pointer to mutable Agglo
        throw out_of_range{"Index out of range"};
    }
    
    return m_ptr[index];
}

const int& Agglo::operator [] (size_t index) const {
    if (index >= this->m_size) {    // pointer to immutable Agglo const
        throw out_of_range{"Index out of range"};
    }
    else {
        return m_ptr[index];
    }
}

Agglo& Agglo::operator ++ () {
    //  use a span and for_each to increment every element
    const span<int> items{m_ptr.get(), m_size};
    for_each(begin(items), end(items), [](auto& item){++item;});
    return *this;
}

Agglo Agglo::operator ++ (int) {
    Agglo temp(*this);
    ++(*this);  // call to Agglo::operator++()
    return temp;    //  return the temporary copy made before incrementing
}

Agglo& Agglo::operator += (int value) {
    //  use a span and for_each to increment every element
    const span<int> items{m_ptr.get(), m_size};
    for_each(begin(items), end(items), [value](auto& item){item += value;});
    return *this;
}

//  overloaded input operator for Agglo
istream& operator >> (istream& in, Agglo& a) {
    span<int> items{a.m_ptr.get(), a.m_size};
    
    for (auto& item : items) {
        in >> item;
    }
    
    return in;
}

//  overloaded output operator for class Agglo
ostream& operator << (ostream& out, const Agglo& a) {
    out << a.toString();
    return out; //  enables cout << x << y;
}

void swap(Agglo& a, Agglo& b) noexcept {
    std::swap(a.m_size,b.m_size);   // swap size_t using std:swap
    a.m_ptr.swap(b.m_ptr); //swap using unique_ptr swap member function
}
