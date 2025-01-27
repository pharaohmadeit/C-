//
//  main.cpp
//  fig06_13
//
//  Created by Pharaoh Tornes on 1/17/25.
//
#include <numeric>
#include <ranges>
#include <array>
#include <format>
#include <iostream>
using namespace std;

int main() {
    auto showValues {
        [](auto& values, const string& message) {
            cout << format("{}: ", message);
            
            for (const auto& value : values) {
                cout << format("{} ", value);
            }
            
            cout << "\n\n";
        }
    };
    
    //iota generates integers 1-10 using lazy programming, meaning it doesn't exist until it's called
    auto values1{views::iota(1, 11)};
    showValues(values1, "Generate integers 1-10");
    
    //filter
    auto values2{values1 | views::filter([](const auto& x) {return x % 2 ==0;})};
    showValues(values2, "Filtering even integers");
    
    //map with views::transform
    auto value3{values2 | views::transform([](const auto& x) {return x * x;})};
    showValues(value3, "Mapping even integers to squares");
    
    //filter & mapping with a pipeline operator |
    auto values4{values1 | views::filter([](const auto& x) {return x % 2 ==0;}) | views::transform([](const auto& x) {return x * x;})};
    showValues(values4, "Square of even integers");
    
    //sum with numeric::accumulate
    cout << format("Sum of squares of even integers 2-10: {}\n\n", accumulate(begin(values4), end(values4), 0));
    
    //filtering and mapping an existing container's elements; data isn't lazy but process pipeline is still lazy, meaning it doesn't process until it's called
    constexpr array numbers{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    auto values5{numbers | views::filter([](const auto& x) {return x % 2 == 0;})
                         | views::transform([](const auto& x){return x * x;})};
    showValues(values5, "Square of even integers in array numbers");
    
}
