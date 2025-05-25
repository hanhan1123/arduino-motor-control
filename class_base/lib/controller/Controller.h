#pragma once
#include "../motor/Motor.h"
#include "../config/ThresholdConfig.h"
#include "../decision/DirectionDecider.h"
#include "../decision/SpeedCalculator.h"

class Controller {
public:
    Controller(Motor motor,
               ThresholdConfig cfg,
               DirectionDecider* dirDecider,
               SpeedCalculator* speedCalc);

    void act(int sensorVal);
    void setupMotor() const;

private:
    Motor motor_;
    ThresholdConfig cfg_;
    DirectionDecider* dirDecider_;
    SpeedCalculator* speedCalc_;
};
