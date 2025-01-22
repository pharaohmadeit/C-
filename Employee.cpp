//
//  Employee.cpp
//  fig10_26
//
//  Created by Pharaoh Tornes on 1/21/25.
//
#include "Employee.hpp"
#include "Commission.hpp"
#include <string_view>
#include <string>
#include <format>
#include <stdexcept>

using namespace std;

Employee::Employee(string_view name, CompensationModel* modelPtr) : m_name{name}, m_modelPtr{modelPtr} {}

void Employee::setCompensationModel(CompensationModel* modelPtr) {
    m_modelPtr = modelPtr;
}

void Employee::setName(string_view name) {
    m_name = name;
}

string Employee::getName() const {
    return m_name;
}

double Employee::earnings() const {
    return m_modelPtr->earnings();
}

string Employee::toString() const {
    return m_modelPtr->toString();
}
