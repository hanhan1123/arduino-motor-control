#include "Controller.h"

Controller::Controller(Motor motor,
                       ThresholdConfig cfg,
                       DirectionDecider* dirDecider,
                       SpeedCalculator* speedCalc)
    : motor_(motor), cfg_(cfg), dirDecider_(dirDecider), speedCalc_(speedCalc) {}

void Controller::setupMotor() const {
    motor_.setupPins();
}

void Controller::act(int sensorVal) {
    MotorMotion motion = dirDecider_->decide(sensorVal, cfg_);
    int speed = speedCalc_->calculate(sensorVal, cfg_);

    switch (motion) {
        case MOTOR_MOTION_FORWARD:
            motor_.forward(speed);
            break;
        case MOTOR_MOTION_REVERSE:
            motor_.reverse(speed);
            break;
        case MOTOR_MOTION_STOPPED:
            motor_.stop();
            break;
    }
}
