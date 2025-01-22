//
//  Salaried.hpp
//  fig10_26
//
//  Created by Pharaoh Tornes on 1/21/25.
//
#pragma once
#include "CompensationModel.hpp"

class Salaried final : public CompensationModel {
public:
    explicit Salaried(double salary);
    double earnings() const override;
    string toString() const override;
private:
    double m_salary{0.0};
};
