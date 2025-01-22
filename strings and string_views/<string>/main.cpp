//
//  main.cpp
//  fig08_07
//
//  Created by Pharaoh Tornes on 1/19/25.
//
#include <string>
#include <format>
#include <iostream>
using namespace std;

int main() {
    string string1{"The values in any left subtree"
                    "\nare less than the value in the"
                    "\nparent node and the values in"
                    "\nany right subtree are greater"
                    "\nthan the value in the parent node"};
    
    cout << format("Original string:\n{}\n\n", string1);
    
    string1.erase(62);
    cout << format("string1 after erase:\n{}\n\n", string1);
    
    size_t position{string1.find(" ")};

    //    replace all spaces with period
    while (position != string::npos) {
        string1.replace(position, 1, ".");
        position = string1.find(" ", position + 1);
    }
    cout << format("After first replacement:\n{}\n\n", string1);
    
    position = string1.find(".");

    //    replace all periods with two semicolons
    //    NOTE: this will overwrite characters
    while (position != string::npos) {
        string1.replace(position, 2, "xxxxx;;yyy", 5, 2);
        position = string1.find(".", position + 2);
    }
    cout << format("After second replacement:\n{}\n\n", string1);
}
