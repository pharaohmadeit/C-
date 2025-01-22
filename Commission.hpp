//
//  Commission.hpp
//  fig10_26
//
//  Created by Pharaoh Tornes on 1/21/25.
//
#pragma once
#include "CompensationModel.hpp"

class Commission final : public CompensationModel {
public:
    Commission(double grossSales, double commissionRate);
    double earnings() const override;
    string toString() const override;
private:
    double m_grossSales{0.0};
    double m_commisionRate{0.0};
};
