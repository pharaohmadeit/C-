//
//  Commission.cpp
//  fig10_26
//
//  Created by Pharaoh Tornes on 1/21/25.
//

#include "Commission.hpp"
#include <format>
#include <stdexcept>

using namespace std;

Commission::Commission(double grossSales, double commissionRate) : m_grossSales{grossSales}, m_commisionRate{commissionRate} {
    if (m_grossSales < 0.0) {
        throw invalid_argument("Gross sales must be >= 0.0");
    }
    if (0.0 >= m_commisionRate >= 1.0) {
        throw invalid_argument("Commission rate must be > 0.0 and < 1.0");
    }
}

double Commission::earnings() const {return m_commisionRate * m_grossSales;}

string Commission::toString() const {
    return format("gross sales: ${:.2f}; commission rate: {:.2f}", Commission::m_grossSales, Commission::m_commisionRate);
}
