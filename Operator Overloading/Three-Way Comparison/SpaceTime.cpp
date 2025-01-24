//
//  SpaceTime.cpp
//  "SpaceTime" is an experimental user-defined class solely demonstrating the use of the C++20 three-way comparison (spaceship) operator
//
//  Created by Pharaoh Tornes on 1/23/25.
//
#include <compare>
#include <string>
#include <format>
#include <iostream>

using namespace std;

class Time {
public:
    //  constructor
    Time(int hr, int min, int sec) noexcept : m_hr{hr}, m_min{min}, m_sec{sec} {}
    
    //  insert additional conditional logic to implement modular arithmetic, 12/24-hour conversion ->
    
    
    string toString() const {
        return format("hr={}, min={}, sec={}", m_hr, m_min, m_sec);
    }

    
    //  <=> operator overloading automatically supports equality/relational operators
    auto operator <=> (const Time& t) const noexcept = default;
    
private:
    int m_hr{0};
    int m_min{0};
    int m_sec{0};
};

int main() {
    const Time t1(12, 15, 30);
    const Time t2(12, 15, 30);
    const Time t3(6, 30, 0);
    
    cout << format("t1: {}\nt2: {}\nt3: {}\n\n", t1.toString(), t2.toString(), t3.toString());
    
    //  using the equality and relational operators
    cout << format("t1 == t2: {}\n", t1 == t2); //  (t1 <=> t2) == 0
    cout << format("t1 != t2: {}\n", t1 != t2); // (t1 <=> t2) != 0
    cout << format("t1 < t2: {}\n", t1 < t2);
    cout << format("t1 <= t2: {}\n", t1 <= t2);
    cout << format("t1 > t2: {}\n", t1 > t2);
    cout << format("t1 >= t2: {}\n\n", t1 >= t2);
    
    cout << format("t1 == t3: {}\n", t1 == t3);
    cout << format("t1 != t3: {}\n", t1 != t3);
    cout << format("t1 < t3: {}\n", t1 < t3);
    cout << format("t1 <= t3: {}\n", t1 <= t3);
    cout << format("t1 > t3: {}\n", t1 > t3);
    cout << format("t1 >= t3 {}\n", t1 >= t3);
    
    //  using <=> to perform comparisons
    if ((t1 <=> t2) == 0) {
        cout << "t1 is equal to t2\n";
    }
    if ((t1 <=> t3) > 0) {
        cout << "t1 is greater than t3\n";
    }
    if ((t1 <=> t2) < 0) {
        cout << "t3 is less than t1\n";
    }
}
