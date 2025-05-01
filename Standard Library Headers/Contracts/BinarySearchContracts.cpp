//  Binary Search with C++26 Contracts Precondtions
//  Godbolt Compiler | x86-64 gcc (contracts) | Flags: "-std=c++2a -fcontracts -fcontract-build-level=audit"

#include <contracts>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

template<typename T>
int binarySearch(const vector<T>& items, const T& key)
  [[pre: items.size() > 0]]  // default precondition
  [[pre audit: is_sorted(items.begin(), items.end())]] // audit precondtion only occurs if compiler flag is activated
{
  size_t low{0};
  size_t high{items.size() - 1};
  size_t middle{(low + high + 1) / 2};
  int loc{-1};

  do {
    if (key == items[middle]) {
      loc = middle;
    }
    else if (key < items[middle]) {
      high = middle - 1;
    }
    else {
      low = middle + 1;
    }

    middle = (low + high + 1) / 2;
  } while ((low <= high) && (loc == -1));

  return loc;
}

int main() {
  vector v1{10, 20, 30, 40, 50, 60, 70, 80, 90};
  int result1{binarySearch(v1, 70)};
  cout << "70 was " << (result1 != -1 ? "" : "not ") << "found in v1\n";

  vector v2{60, 70, 80, 90, 10, 20, 30, 40, 50};
  int result2{binarySearch(v2, 60)};
  cout << "60 was " << (result2 != -1 ? "" : "not ") << "found in v2\n";
}
