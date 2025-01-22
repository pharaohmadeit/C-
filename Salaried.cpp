//
//  Salaried.cpp
//  fig10_26
//
//  Created by Pharaoh Tornes on 1/21/25.
//
#include "Salaried.hpp"
#include <format>
#include <stdexcept>

using namespace std;

Salaried::Salaried(double salary) : m_salary{salary} {
    if (m_salary < 0.0) {
        throw invalid_argument("Weekly salary must be >= 0.0");
    }
}

double Salaried::earnings() const {return m_salary;}

string Salaried::toString() const {
    return format("salary: ${:.2f}", m_salary);
}
