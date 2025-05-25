#include "lib/motor/Motor.h"
#include "lib/controller/Controller.h"
#include "lib/config/ThresholdConfig.h"
#include "lib/decision/HysteresisDirectionDecider.h"
#include "lib/decision/SoftRampSpeedCalculator.h"

#define FSR_HIGH 466
#define FSR_LOW 0

#define MOTOR_MODULE_INPUT3_PIN 12
#define MOTOR_MODULE_INPUT4_PIN 13
#define MOTOR_MODULE_ENABLE_B_PIN 3
#define THIGH_FSR A0

#define MOTOR_MODULE_INPUT1_PIN 7
#define MOTOR_MODULE_INPUT2_PIN 8
#define MOTOR_MODULE_ENABLE_A_PIN 9
#define HEEL_FSR A1

HysteresisDirectionDecider hysteresisDir;
SoftRampSpeedCalculator rampSpeed;

ThresholdConfig thighCfg = {
    .low_threshold = 150,
    .high_threshold = 350
};

ThresholdConfig heelCfg = {
    .low_threshold = 100,
    .high_threshold = 300
};

Motor thighMotor(MOTOR_MODULE_INPUT3_PIN, MOTOR_MODULE_INPUT4_PIN, MOTOR_MODULE_ENABLE_B_PIN);
Controller thighController(thighMotor, thighCfg, &hysteresisDir, &rampSpeed);


Motor heelMotor(MOTOR_MODULE_INPUT1_PIN, MOTOR_MODULE_INPUT2_PIN, MOTOR_MODULE_ENABLE_A_PIN);
Controller heelController(heelMotor, heelCfg, &hysteresisDir, &rampSpeed);

void setup() {
    Serial.begin(19200);
    thighController.setupMotor();
    heelController.setupMotor();
}

void loop() {
    int thighVal = analogRead(THIGH_FSR);
    int heelVal = analogRead(HEEL_FSR);
    thighController.act(thighVal);
    heelController.act(heelVal);
}
