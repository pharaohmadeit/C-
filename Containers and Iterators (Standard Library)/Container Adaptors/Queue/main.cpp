//  Standard libary queue adaptor class template; (FIFO) first-in, first-out
//  main.cpp
//  fig13_11
//
//  Created by Pharaoh Tornes on 2/15/25.
//
#include <queue>
#include <list>
#include <vector>
#include <iostream>

using namespace std;

int main() {
    // queue with doubles
    queue<double> values{};
    
    //  push elements onto queue values
    values.push(3.2);
    values.push(9.8);
    values.push(5.4);
    
    cout << "Popping from values: ";
    
    // pop elements from queue
    while (!values.empty()) {
        cout << values.front() << ' '; //  view front element
        values.pop();   //  remove element
    }
    
    cout << "\n";
    
}
