#include "SoftRampSpeedCalculator.h"
#include <Arduino.h>

SoftRampSpeedCalculator::SoftRampSpeedCalculator() : currentSpeed(0) {}

int SoftRampSpeedCalculator::calculate(int sensorVal, const ThresholdConfig& cfg) {
    const int rampUp = 3;
    const int rampDown = 10;
    int targetSpeed = 0;

    if (sensorVal < cfg.low_threshold) {
        targetSpeed = map(constrain(sensorVal, 0, cfg.low_threshold),
                          0, cfg.low_threshold, 255, 0);
    } else if (sensorVal > cfg.high_threshold) {
        targetSpeed = map(constrain(sensorVal, cfg.high_threshold, 466),
                          cfg.high_threshold, 466, 0, 255);
    } else {
        targetSpeed = 0;
    }

    currentSpeed = adaptiveSoftRamp(currentSpeed, targetSpeed, rampUp, rampDown);
    return currentSpeed;
}

int SoftRampSpeedCalculator::adaptiveSoftRamp(int currentSpeed, int targetSpeed, int rampUpStep, int rampDownStep) {
    if (currentSpeed < targetSpeed) {
        return min(currentSpeed + rampUpStep, targetSpeed);
    } else if (currentSpeed > targetSpeed) {
        return max(currentSpeed - rampDownStep, targetSpeed);
    } else {
        return currentSpeed;
    }
}
