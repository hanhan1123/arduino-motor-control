#pragma once
#include "SpeedCalculator.h"

class SoftRampSpeedCalculator : public SpeedCalculator {
public:
    SoftRampSpeedCalculator();
    int calculate(int sensorVal, const ThresholdConfig& cfg) override;

private:
    int currentSpeed;
    int adaptiveSoftRamp(int currentSpeed, int targetSpeed, int rampUpStep, int rampDownStep);
};
