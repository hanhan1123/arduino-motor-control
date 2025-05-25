#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "motor.h"
#include "decision/base.h"

typedef struct {
    motor m;
    ThresholdConfig cfg;
    direction_decider_fn dir_decision;
    speed_calculator_fn speed;
} controller;

void controller_act(controller* c, int sensor_val);

#endif
