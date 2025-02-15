//
//  main.cpp
//  fig13_04
//
//  Created by Pharaoh Tornes on 2/14/25.
//
#include <list> // doubly linked list data structure
#include <algorithm>
#include <format>
#include <iterator>
#include <iostream>

using namespace std;

//  printList function template defintion has a function type parameter; printList can receive as its argument any list of elements; const reference & ensures we cannot modify the contents of the list we are printing; test if list is empty; uses output iterator (ostream_iterator) and copy algorithm to output list elements to standard output stream;
template <typename T>
void printList(const list<T>& items) {
        if (items.empty()) {    //  list is empty
            cout << "List is empty";
        }
        else {
            ostream_iterator<T> output{cout, " "};
            ranges::copy(items, output);
        }
}

int main() {
    list<int> values{}; //  create list of ints
    
    //  insert items in values
    values.push_front(1);
    values.push_front(2);
    values.push_back(4);
    values.push_back(3);
    
    //  display contents of values
    cout << "values contain: ";
    printList(values);
    
    //  sort member function; increasing order by default; sort the doubly linked list
    values.sort();
    cout << "\nvalues after sorting contains: ";
    printList(values);
    
    //  insert elements of ints into otherValues
    vector ints{2, 6, 4, 8};
    list<int> otherValues{};    //  create list of ints
    otherValues.insert(otherValues.cbegin(), ints.cbegin(), ints.cend());
    cout << "\nAfter insert, otherValues contains: ";
    
    //  remove otherValues elements and insert at end of values; splice member function: takes the entire contents of one list object and add them to another list object, deleting them from the original list object
    values.splice(values.cend(), otherValues);
    cout << "\nAfter splice, values contains: ";
    printList(values);
    
    //  sort values
    values.sort();
    cout << "\nAfter sort, values contains: ";
    printList(values);
    
    //  insert elements of ints into otherValues
    otherValues.insert(otherValues.cbegin(), ints.cbegin(), ints.cend());
    otherValues.sort();
    cout << "\nAfter insert and sort, otherValues contains: ";
    printList(otherValues);
    
    //  remove otherValues elements and insert into values in sorted order
    values.merge(otherValues);
    cout << "\nAfter merge:\n   values contains: ";
    printList(values);
    cout << "\n   otherValues contains: ";
    printList(otherValues);
    
    values.pop_front(); //  remove element from front
    values.pop_back();  //  remove element from back
    cout << "\nAfter pop_front and pop_back:\n   values contains: ";
    printList(values);
    
    values.unique();    //  remove duplicate elements; reduced contiguous values into a single value
    cout << "After unique, values contains: ";
    printList(values);
    
    values.swap(otherValues);   //  swap elements of values and otherValues; underneath the hood swap is swapping the pointers of the containters including internal state information associated with the list objects
    cout << "\nAfter swap:\n    values contains: ";
    printList(values);
    cout << "\n   otherValues contains: ";
    printList(otherValues);
    
    //  replace contents of values with elements of otherValues
    values.assign(otherValues.cbegin(), otherValues.cend());
    cout << "\nAfter assign, values contains: ";
    printList(values);
    
    //  remove otherValues elements and insert into values in sorted order
    values.merge(otherValues);
    cout << "\nAfter merge, values contains: ";
    printList(values);
    
    //  remove all 4s
    values.remove(4);
    cout << "\nAfter merge, values contains: ";
    printList(values);
    cout << "\n";
}
