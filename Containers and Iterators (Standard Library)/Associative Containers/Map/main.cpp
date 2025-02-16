//  Standard library map class template
//  main.cpp
//  fig13_08
//
//  Created by Pharaoh Tornes on 2/15/25.
//
#include <map>
#include <algorithm>
#include <format>
#include <iostream>

using namespace std;

int main() {
    //  create multimap
    multimap<int, double> pairs{};
    cout << format("Number of 15 keys in pairs {}\n", pairs.count(15));
    
    //  insert two pairs
    pairs.insert(make_pair(15, 99.3));
    pairs.insert(make_pair(15, 2.7));
    cout << format("Number of 15 keys in pairs: {}\n\n", pairs.count(15));
    
    //  insert five pairs
    pairs.insert({30, 111.11});
    pairs.insert({10, 22.22});
    pairs.insert({25, 33.333});
    pairs.insert({20, 9.345});
    pairs.insert({5, 77.54});
    
    cout << "Multimap pairs contains:\nKey\tValue\n";
    
    //  Walk through elements of pairs
    for (const auto& mapItem : pairs) {
        cout << format("{}\t{}\n", mapItem.first, mapItem.second);
    }
}
