//  Standard library map template
//  main.cpp
//  fig13_09
//
//  Created by Pharaoh Tornes on 2/15/25.
//
#include <map>  //  map class-template defintion
#include <format>
#include <iostream>

using namespace std;

int main () {
    //  create a map; duplicate keys are ignored
    map<int, double> pairs{{15, 2.7}, {30, 111.11}, {5, 1010.1}, {10, 22.22}, {25, 33.333}, {5, 77.54}, {20, 9.345}, {15, 99.3}};
    
    //  walk through elements of pairs
    cout << "pairs contains:\nKey\tValue\n";
    for (const auto& pair: pairs) {
        cout << format("{}\t{}\n", pair.first, pair.second);
    }
    
    //  use subscripting to change value for key 25 and 40
    pairs[25] = 9999.99;
    pairs[40] = 8765.43;
    
    //  walk through elements of pairs
    cout << "\nAfter updates, pairs contains:\nKey\tValue\n";
    for (const auto& pair: pairs) {
        cout << format("{}\t{}\n", pair.first, pair.second);
    }
}
