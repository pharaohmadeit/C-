//
//  main.cpp
//  fig08_09
//
//  Created by Pharaoh Tornes on 1/19/25.
//
#include <string_view>
#include <string>
#include <format>
#include <iostream>
using namespace std;

int main() {
    string s1{"red"};
    string s2{s1};
    string_view v1{s1};
    cout << format("s1: {}\ns2: {}\nv1: {}\n", s1, s2, v1) << endl;
    
    s1.at(0) = 'R';
    cout << format("s1: {}\ns2: {}\nv1: {}\n", s1, s2, v1) << endl;
    
    cout << format("s1 == v1: {}\ns2 == v1: {}\n\n", s1 == v1, s2 == v1);
    
    v1.remove_prefix(1);
    v1.remove_suffix(1);
    cout << format("s1: {}\nv1: {}\n", s1, v1) << endl;
    
    string_view v2{"C-string"};
    cout << "The characters in v2 are: ";
    for (char c : v2) {
        cout << c << " ";
    }
    
    cout << format("\n\nv2.size(): {}\n", v2.size());
    cout << format("v2.find('-'): {}\n", v2.find('-'));
    cout << format("v2.starts_with('C'): {} \n", v2.starts_with('C'));
    
}

/*
#include <string>
#include <iostream>
using namespace std;
 
int main() {
    string s1{"hello"};
    int i = 100;
    s1.insert(0,to_string(i));
    
    string s2{"100hello"};

    
    string s3{"123.45hello"};
    double convertedDouble{stod(s3)};
    
    int convertedInt{stoi(s1)};
    
    size_t index;
    
    int convertedInt2{stoi(s1, &index, 2)};
    
    cout << to_string(convertedInt) << "\n" << convertedInt2 << "\n" << convertedDouble << endl;
}
*/
