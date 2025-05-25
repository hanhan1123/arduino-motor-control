#ifndef DECISION_THIGH_H
#define DECISION_THIGH_H

#include "base.h"

motor_motion hysteresis_fsr_decision(int val, ThresholdConfig* cfg);
int soft_ramp_speed_transform(int sensor_val, ThresholdConfig* cfg);

#endif