#pragma once
#include "DirectionDecider.h"

class HysteresisDirectionDecider : public DirectionDecider {
public:
    MotorMotion decide(int val, const ThresholdConfig& cfg) override;
};
