#pragma once
#include "../config/ThresholdConfig.h"

class SpeedCalculator {
public:
    virtual int calculate(int sensorVal, const ThresholdConfig& cfg) = 0;
    virtual ~SpeedCalculator() = default;
};
