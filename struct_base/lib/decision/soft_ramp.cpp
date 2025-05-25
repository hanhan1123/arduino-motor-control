#include <Arduino.h>
#include "decision/soft_ramp.h"

motor_motion hysteresis_fsr_decision(int val, ThresholdConfig* cfg) {
    if (val > cfg->high_threshold) return MOTOR_MOTION_FORWARD;
    if (val < cfg->low_threshold) return MOTOR_MOTION_REVERSE;
    return MOTOR_MOTION_STOPPED;
}

int adaptive_soft_ramp(int currentSpeed, int targetSpeed, int rampUpStep, int rampDownStep) {
    if (currentSpeed < targetSpeed) {
        return min(currentSpeed + rampUpStep, targetSpeed);
    } else if (currentSpeed > targetSpeed) {
        return max(currentSpeed - rampDownStep, targetSpeed);
    } else { 
        return currentSpeed;
    }
}

int soft_ramp_speed_transform(int sensor_val, ThresholdConfig* cfg) {
    static int current_speed = 0;
    const int rampUp = 3;
    const int rampDown = 10;
    int target_speed = 0;

    if (sensor_val < cfg->low_threshold) {
        target_speed = map(constrain(sensor_val, 0, cfg->low_threshold),
                           0, cfg->low_threshold,
                           255, 0);
    } else if (sensor_val > cfg->high_threshold) {
        target_speed = map(constrain(sensor_val, cfg->high_threshold, 466),
                           cfg->high_threshold, 466,
                           0, 255);
    } else {
        target_speed = 0;
    }

    current_speed = adaptive_soft_ramp(current_speed, target_speed, rampUp, rampDown);
    return current_speed;
}
