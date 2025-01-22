//
//  Employee.hpp
//  fig10_26
//
//  Created by Pharaoh Tornes on 1/21/25.
//
#pragma once
#include <string_view>
#include <string>
#include "CompensationModel.hpp"

using namespace std;

class Employee final {
public:
    
    Employee(string_view name, CompensationModel* modelPtr);
    
    void setCompensationModel(CompensationModel* modelPtr);
    void setName(string_view name);
    
    string getName() const;
    
    double earnings() const;
    string toString() const;
    
private:
    
    string m_name{};
    CompensationModel* m_modelPtr{};
};
