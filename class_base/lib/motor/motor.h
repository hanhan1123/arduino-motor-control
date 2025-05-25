#pragma once
#include <Arduino.h>

class Motor {
public:
    Motor(int in1, int in2, int en);
    void setupPins() const;
    void forward(int speed) const;
    void reverse(int speed) const;
    void stop() const;
private:
    int in1_, in2_, en_;
};