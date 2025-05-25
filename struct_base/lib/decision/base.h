#ifndef DECISION_BASE_H
#define DECISION_BASE_H

typedef enum {
    MOTOR_MOTION_FORWARD,
    MOTOR_MOTION_REVERSE,
    MOTOR_MOTION_STOPPED
} motor_motion;

typedef struct {
    int low_threshold;
    int high_threshold;
} ThresholdConfig;

typedef motor_motion (*direction_decider_fn)(int sensor_val, ThresholdConfig* cfg);
typedef int (*speed_calculator_fn)(int sensor_val, ThresholdConfig* cfg);

#endif
