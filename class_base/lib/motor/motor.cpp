#include "Motor.h"

Motor::Motor(int in1, int in2, int en)
    : in1_(in1), in2_(in2), en_(en) {}

void Motor::setupPins() const {
    pinMode(in1_, OUTPUT);
    pinMode(in2_, OUTPUT);
    pinMode(en_, OUTPUT);
}

void Motor::forward(int speed) const {
    analogWrite(en_, speed);
    digitalWrite(in1_, HIGH);
    digitalWrite(in2_, LOW);
}

void Motor::reverse(int speed) const {
    analogWrite(en_, speed);
    digitalWrite(in1_, LOW);
    digitalWrite(in2_, HIGH);
}

void Motor::stop() const {
    analogWrite(en_, 0);
    digitalWrite(in1_, LOW);
    digitalWrite(in2_, LOW);
}
