#include <Arduino.h>
#include "motor.h"

void motor_forward(motor* m, int speed) {
    analogWrite(m->en, speed);
    digitalWrite(m->in1, HIGH);
    digitalWrite(m->in2, LOW);
}

void motor_reverse(motor* m, int speed) {
    analogWrite(m->en, speed);
    digitalWrite(m->in1, LOW);
    digitalWrite(m->in2, HIGH);
}

void motor_stopped(motor* m) {
    analogWrite(m->en, 0);
    digitalWrite(m->in1, LOW);
    digitalWrite(m->in2, LOW);
}