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

void printStatistics(const string& s) {
    cout << format("s.capacity: {}\ns.max_size: {}\ns.size: {}\ns.empty: {}", s.capacity(), s.max_size(), s.size(), s.empty());
}

int main() {

    //
{
    string string1;
    
    cout << "Statistics before input:\n";
    printStatistics(string1);
    
    
    for (int i{0}; i < 2; ++i) {
        cout << "\n\nEnter a string: ";
        cin >> string1;
        cout << format("The string entered was {}\n", string1);
        cout << "Statistics after input:\n";
        printStatistics(string1);
    }
    
    string1 += "1234567890abcdefghijklmnopqrstuvwxyz1234567890";
    cout << format("\n\nstring is now: {}\n", string1);
    cout << "Statistics after concatenation:\n";
    printStatistics(string1);
    
    string1.resize(string1.size() + 10);
    cout << format("\n\nStatistics after resizing to add 10 character: \n", string1);
    printStatistics(string1);
    cout << "\n" << string1;
    
    
    cout << endl;
}

    //
    
    {
    
    const string s{"noon is 12pm; midnight is not"};
    cout << "Original string: " << s << endl;
    
    cout << format("s.find(\"is\"): {}\ns.rfind(\"is\"): {}\n", s.find("is"), s.rfind("is"));
    
    auto location{s.find_first_of("misop")};
    cout << format("s.find_first_of(\"misop\") found {} at {}\n", s.at(location), location);
    
    location = s.find_last_of("misop");
    cout << format("s.find_last_of(\"misop\") found {} at {}\n", s.at(location), location);
    
    location = s.find_first_not_of("noi spm");
    cout << format("s.find_first_not_of(\"noi spm\") found {} at {}", s.at(location), location);
    
    location = s.find_first_not_of("12 noi spm");
    cout << format("s.find_first_not_of(\"12 noi spm\") found {} at {}", s.at(location), location);
    
    location = s.find_first_not_of("noon is 12pm; midnight is not");
    
    if (location == string::npos) {
        cout << format("\n{}: not found\n", "s.find_first_not_of(\"noon is 12pm; midnight is not\")");
    }

    cout << endl;
    
}
   
    //
    
{
    
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

    //
    
}
