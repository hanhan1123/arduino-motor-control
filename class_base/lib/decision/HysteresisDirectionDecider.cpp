#include "HysteresisDirectionDecider.h"

MotorMotion HysteresisDirectionDecider::decide(int val, const ThresholdConfig& cfg) {
    if (val > cfg.high_threshold) return MOTOR_MOTION_FORWARD;
    if (val < cfg.low_threshold) return MOTOR_MOTION_REVERSE;
    return MOTOR_MOTION_STOPPED;
}
