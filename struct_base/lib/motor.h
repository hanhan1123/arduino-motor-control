#ifndef MOTOR_H
#define MOTOR_H

typedef enum {
    MOTOR_MOTION_FORWARD,
    MOTOR_MOTION_REVERSE,
    MOTOR_MOTION_STOPPED
} motor_motion;


typedef struct {
    const int in1;
    const int in2;
    const int en;
} motor;

void motor_forward(motor* m, int speed);
void motor_reverse(motor* m, int speed);
void motor_stopped(motor* m);


#endif