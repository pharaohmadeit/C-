//  Division By Zero with C++26 Contracts Precondtions
//  Godbolt Compiler | x86-64 gcc (contracts) | Flags: "-std=c++2a -fcontracts -fcontract-build-level=audit"
//  x86-64 gcc (Contracts) -> https://godbolt.org/z/3caEK6x1K

#include <contracts>
#include <iostream>

using namespace std;

//  function prototype
double quotient(double numerator, double denominator)
  [[pre: denominator != 0.0]];  //  C++26 Contract Precondition

int main() 
{
  cout << "quotient(100, 7): " << quotient(100, 7) << "\nquotient(100, 0): " << quotient(100, 0) << 'n';
}

//  perform division
double quotient(double numerator, double denominator) 
{
  return numerator / denominator;
}
