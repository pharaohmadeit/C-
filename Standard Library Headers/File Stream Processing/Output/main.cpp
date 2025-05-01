//
//  main.cpp
//  fig08_10
//
//  Created by Pharaoh Tornes on 1/19/25.
//
#include <fstream>
#include <filesystem> // contains file stream processing types
#include <format>
#include <cstdlib> // exit function prototype
#include <iostream>
using namespace std;

int main() {
    
    // open file; if possible implicitly converts to TRUE
    if (ofstream output{"clients.txt", ios::out}) {
        cout << "Enter the account, name, balance.\n" << "Enter end-of-file to end input.\n? ";
        
        int account;
        string name;
        double balance;
        
        // cin converts to TRUE if all three fields
        while (cin >> account >> name >> balance) {
            //use the ofstream output just like cout to write to file
            output << format("{} {} {}\n", account, name, balance);
            cout << "? ";
        }
        // File automatically closes using RAII (Resource Acquisition Is Initialization)
    }
    // if file can't be opened, program should catch the exception and exit
    else {
        cerr << "File could not be opened\n";
        // returns nonzero integer to main()
        exit(EXIT_FAILURE);
    }
}
