//  Standard library stack adaptor class
//  main.cpp
//  fig13_10
//
//  Created by Pharaoh Tornes on 2/15/25.
//
#include <stack>    //  stack adaptor definition
#include <list> //  list class-template defintion
#include <vector>   //  vector class-template definition
#include <ranges>
#include <iostream>

using namespace std;

//  pushElements generic lambda to push values onto a stack
auto pushElements = [](auto& stack) {
    for (auto i : views::iota(0,10)) {
        stack.push(i);  //  push element onto a stack
        cout << stack.top() << ' '; //  view (and display) top element
    }
};

//  popElements generic lambda to pop elements off a stack
auto popElements = [](auto& stack) {
    while (!stack.empty()) {
        cout << stack.top() << ' '; //  view (and display) top element
        stack.pop();    //  remove top element
        
    }
};

int main() {
    stack<int> dequeStack{};    //  uses a deque by default
    stack<int, vector<int>> vectorStack{};  //  use a vector
    stack<int, list<int>> listStack{};  //  use a list
    
    // push the values 0-9 onto each stack
    cout << "Pushing onto dequeStack: ";
    pushElements(dequeStack);
    cout << "\nPushing onto vectorStack: ";
    pushElements(vectorStack);
    cout << "\nPushing onto listStack: ";
    pushElements(listStack);
    
    //  display and remove elements from each stack
    cout << "\n\nPopping from dequeStack: ";
    popElements(dequeStack);
    cout << "\nPopping from vectorStack: ";
    popElements(vectorStack);
    cout << "\nPopping from listStack: ";
    popElements(listStack);
    cout << "\n";
    
    
}
