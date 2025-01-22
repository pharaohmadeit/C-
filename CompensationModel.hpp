//
//  CompensationModel.hpp
//  fig10_26
//
//  Created by Pharaoh Tornes on 1/21/25.
//
#pragma once
#include <string>

using namespace std;

class CompensationModel {
public:
    virtual ~CompensationModel() = default;
    virtual double earnings() const = 0;
    virtual string toString() const = 0;
};
