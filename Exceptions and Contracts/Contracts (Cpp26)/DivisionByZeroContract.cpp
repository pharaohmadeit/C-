//  x86-64 gcc (contracts) -> https://godbolt.org/z/3caEK6x1K
//  Division by zero with a precondition (Contracts)
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
