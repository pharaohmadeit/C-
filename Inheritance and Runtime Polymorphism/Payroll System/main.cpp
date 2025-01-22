//
//  main.cpp
//  fig10_26
//
//  Created by Pharaoh Tornes on 1/21/25.
//
#include "Commission.hpp"
#include "Salaried.hpp"
#include "Employee.hpp"
#include <vector>
#include <format>
#include <iostream>

using namespace std;



int main() {
    
    Salaried salaried{70'000};
    Employee salariedEmployee{"Pharaoh Tornes", &salaried};
    
    Commission commission{1'000'000, 0.06};
    Employee comissionEmployee{"Malik Tornes", &commission};
    
    vector employees{salariedEmployee, comissionEmployee};
    
    for (const Employee& employee : employees) {
        cout << format("name: {}\n{}\nearned: ${:.2f}\n\n", employee.getName(), employee.toString(), employee.earnings());
    }
    
    
}
