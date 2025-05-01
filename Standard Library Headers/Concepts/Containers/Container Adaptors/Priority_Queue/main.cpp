//  Standard libary priority_queue adaptor class
//  main.cpp
//  fig13_12
//
//  Created by Pharaoh Tornes on 2/15/25.
//
#include <queue>    //  priority_queue adaptor defintion
#include <iostream>

using namespace std;

int main() {
    // create priority_queue with doubles
    priority_queue<double> priorities{};
    
    //  push elements onto priorities
    priorities.push(3.2);
    priorities.push(9.8);
    priorities.push(5.4);
    
    cout << "Popping from values: ";
    
    // pop elements from priority_queue
    while (!priorities.empty()) {
        cout << priorities.top() << ' '; //  view top element
        priorities.pop();   //  remove top element
    }
    
    cout << "\n";
    
}
