//
//  main.cpp
//  fig08_11
//
//  Created by Pharaoh Tornes on 1/19/25.
//
#include <fstream>
#include <filesystem>
#include <format>
#include <cstdlib>
#include <iostream>
using namespace std;

int main() {
    if (ifstream input{"/Users/pharaohtornes/Documents/Computer Science/C++/CPlusPlus20FundamentalsLiveLessons-master/examples/lesson08/fig08_11/fig08_11/clients.txt", ios::in}) {
        cout << format("{:<10}{:<13}{:>7}\n", "Account", "Name", "Balance");
        
        int account;
        string name;
        double balance;
        
        while (input >> account >> name >> balance) {
            cout << format("{:<10}{:<13}{:>7.2f}\n", account, name, balance);
        }
        
    } else {
        cerr << "File could not be opened\n";
        exit(EXIT_FAILURE);
    }
}

/*
 
 File-Position pointers
 
 istream seekg
    -Get pointer - byte number for next input
 
 istream seekp
    -Put pointer - byte number for next output
    -reposition the file-position pointer
 
 input.seekg(0);
    -repositions get pointer to beginning of file
 
 input.clear();
    -clear end-of-file indicator so you can re-read from input
 
 optional second argument indicates seek direction
 ios::beg
    -the default: position from beginning
 ios::cur
    -position relative to current position
 ios::end
    -position backward from end
 
 fileObject.seekg(n)
    -nth byte from ios::beg
 
 fileObject.seekg(n, ios::cur);
    -n bytes forward
 fileObject.seekg(n, ios::end);
    -n bytes from end
 fileObject.seekg(0, ios::end);
    -move to end
 
 seekp also works with ofstream
 
 tellg()
    return current get pointer location
 tellp()
    return current put pointer location
 */
