#pragma once
#include "../config/ThresholdConfig.h"

enum MotorMotion {
    MOTOR_MOTION_FORWARD,
    MOTOR_MOTION_REVERSE,
    MOTOR_MOTION_STOPPED
};

class DirectionDecider {
public:
    virtual MotorMotion decide(int sensorVal, const ThresholdConfig& cfg) = 0;
    virtual ~DirectionDecider() = default;
};
