#include "controller.h"

void controller_act(controller* c, int sensor_val) {
    ThresholdConfig cfg = c->cfg;
    motor_motion m = c->dir_decision(sensor_val, &cfg);
    int speed = c->speed(sensor_val, &cfg);

    switch (m) {
        case MOTOR_MOTION_FORWARD:
            motor_forward(&(c->m), speed);
            break;
        case MOTOR_MOTION_REVERSE:
            motor_reverse(&(c->m), speed);
            break;
        case MOTOR_MOTION_STOPPED:
        default:
            motor_stopped(&(c->m));
            break;
    }
}
