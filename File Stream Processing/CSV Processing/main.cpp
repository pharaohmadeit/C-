//  Reading a dataset from CSV file, then analyzing it.
//  main.cpp
//  fig08_15
//
//  Created by Pharaoh Tornes on 1/19/25.
//
#include <rapidcsv.h>

#include <algorithm>
#include <cmath>

#include <numeric>
#include <ranges>
#include <format>

#include <vector>
#include <string>

#include <iostream>

using namespace std;
using namespace rapidcsv;

int main() {
    //  load dataset
    Document titanic{"/Users/pharaohtornes/Documents/Computer Science/C++/CPlusPlus20FundamentalsLiveLessons-master/examples/lesson08/fig08_15/fig08_15/titanic.csv", LabelParams{}, SeparatorParams{}, ConverterParams{true}};
    
    //  GetColumn returns column's data as a vector of the appropriate type
    auto survived{titanic.GetColumn<int>("survived")};
    auto sex{titanic.GetColumn<string>("sex")};
    auto age{titanic.GetColumn<double>("age")};
    auto pclass{titanic.GetColumn<int>("pclass")};
    
    //  display first five rows
    cout << format("First five rows:\n{:<10}{:<8}{:<6}{}\n", "survived", "sex", "age", "class");
    
    for (size_t i{0}; i < 5; ++i) {
        cout << format("{:<10}{:<8}{:6.1f}{}\n", survived.at(i), sex.at(i), age.at(i), pclass.at(i));
    }
    
    //  display last five rows
    cout << format("\nLast five rows:\n{:<10}{:<8}{:<6}{}\n", "survived", "sex", "age", "class");
    const auto count{titanic.GetRowCount()};
    for (size_t i{count - 5}; i < count; ++i) {
        cout << format("{:<10}{:<8}{:6.1f}{}\n", survived.at(i), sex.at(i), age.at(i), pclass.at(i));
    }
    
    // use C++20 ranges to eliminate missing values from age column
    auto removeNaN{age | views::filter([](const auto& x){return !isnan(x);})};
    vector<double> cleanAge{begin(removeNaN), end(removeNaN)};
    
    sort(begin(cleanAge), end(cleanAge));
    size_t size{cleanAge.size()};
    double median{};
    
    //  calculate median: if even calculate the average of the middle two elements
    if (size % 2 == 0) {
        median = (cleanAge.at(size / 2 - 1) + cleanAge.at(size / 2)) / 2;
    }
    else {
        median = cleanAge.at(size / 2);
    }
    cout << "\nDescriptive statistics for the age columnm:\n"
    << format("Passengers with age data: {}\n", size)
    << format("Average age: {:2f}\n", accumulate(begin(cleanAge), end(cleanAge), 0.0) / size)
    << format("Minimum age: {:.2f}\n", cleanAge.front())
    << format("Maximum age: {:.2f}\n", cleanAge.back())
    << format("Median age: {:.2f}\n", median);
    
    //  nested lambda expression which will count number of passengers by class
    auto countClass{
        
        [](const auto& column, const int classNumber)
        {return ranges::count_if(column,
        
        [classNumber](int x)
        {return classNumber == x;});}
    };
    
    constexpr int firstClass{1};
    constexpr int secondClass{2};
    constexpr int thirdClass{3};
    const auto firstCount{countClass(pclass, firstClass)};
    const auto secondCount{countClass(pclass, firstClass)};
    const auto thirdCount{countClass(pclass, thirdClass)};
    
    cout << "\nPassenger counts by class:\n" << format("1st: {}\n2nd: {}\n3rd: {}\n\n", firstCount, secondCount, thirdCount);
    
    const auto survivorCount{
        ranges::count_if(survived, [](auto x){return x;})
    };
    
    cout << format("Survived count: {}\nDied count: {}\n", survivorCount, survived.size() - survivorCount);
    cout << format("Percent who survived: {:.2f}%\n\n", 100.0 * survivorCount / survived.size());
    
    int survivingMales{0};
    int survivingFemales{0};
    int surviving1st{0};
    int surviving2nd{0};
    int surviving3rd{0};
    
    
    for (size_t i{0}; i < survived.size(); ++i) {
        if (survived.at(i)) {
            sex.at(i) == "female" ? ++survivingFemales : ++survivingMales;
            
            if (firstClass == pclass.at(i)) {
                ++surviving1st;
            }
            else if (secondClass == pclass.at(i))
            {
                ++surviving2nd;
            }
            else {
                ++surviving3rd;
            }
        }
    }
    
    cout << format("Female survivor percentage: {:2f}%\n", 100.0 * survivingFemales / survivorCount)
    << format("Male survivor percentage: {:2f}%\n\n", 100.0 * survivingMales / survivorCount)
    << format("1st class survivor percentage: {:.2f}%\n", 100.0 * surviving1st / survivorCount)
    << format("2nd class survivor percentage: {:.2f}%\n", 100.0 * surviving2nd / survivorCount)
    << format("3rd class survivor percentage: {:.2f}%\n", 100.0 * surviving3rd / survivorCount);
    
    cout << endl;
    
}
