//
//  main.cpp
//  fig08_06
//
//  Created by Pharaoh Tornes on 1/18/25.
//
#include <string>
#include <format>
#include <iostream>
using namespace std;

int main() {
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
}
