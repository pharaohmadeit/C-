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

int main() {
    auto showValues {
        [](auto& values, const std::string& message) {
            std::cout << std::format("{}: ", message);
            
            for (const auto& value : values) {
                std::cout << std::format("{} ", value);
            }
            
            std::cout << "\n\n";
        }
    };
    
    //  std::views::iota generates integers 1-10 using lazy programming, meaning it doesn't exist until it's called
    auto values1{std::views::iota(1, 11)};
    showValues(values1, "Generate integers 1-10");
    
    //  filter using the pipeline operator; std::views::filter accepts a functions as an argument
    auto values2{values1 | std::views::filter([](const auto& x) {return x % 2 ==0;})};
    showValues(values2, "Filtering even integers");
    
    //  map with std::views::transform using the pipeline operator
    auto value3{values2 | std::views::transform([](const auto& x) {return x * x;})};
    showValues(value3, "Mapping even integers to squares");
    
    //  filter & mapping with a pipeline operator in succession
    auto values4 {values1 | std::views::filter([](const auto& x) {return x % 2 ==0;}) | std::views::transform([](const auto& x) {return x * x;})};
    showValues(values4, "Square of even integers");
    
    //  sum with std::numeric::accumulate
    std::cout << std::format("Sum of squares of even integers 2-10: {}\n\n", std::accumulate(std::begin(values4), std::end(values4), 0));
    
    //  filtering and mapping an existing container's elements; data initialization isn't lazy but process pipeline is still lazy, meaning it doesn't process until it's called
    constexpr std::array numbers{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    auto values5{numbers | std::views::filter([](const auto& x) {return x % 2 == 0;})
                         | std::views::transform([](const auto& x){return x * x;})};
    showValues(values5, "Square of even integers in array numbers");
    
}
