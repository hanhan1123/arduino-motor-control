#include <Arduino.h>
#include "lib/controller.h"
#include "lib/decision/soft_ramp.h"

#define MOTOR_MODULE_INPUT3_PIN 12
#define MOTOR_MODULE_INPUT4_PIN 13
#define MOTOR_MODULE_ENABLE_B_PIN 3
#define THIGH_FSR A0


#define MOTOR_MODULE_INPUT1_PIN 7
#define MOTOR_MODULE_INPUT2_PIN 8
#define MOTOR_MODULE_ENABLE_A_PIN 9
#define HEEL_FSR A1

ThresholdConfig thigh_cfg = {
    .low_threshold = 150,
    .high_threshold = 350
};

ThresholdConfig heel_cfg = {
    .low_threshold = 100,
    .high_threshold = 300
};

controller thigh_controller = {
    .m = {MOTOR_MODULE_INPUT3_PIN, MOTOR_MODULE_INPUT4_PIN, MOTOR_MODULE_ENABLE_B_PIN},
    .cfg = thigh_cfg,
    .dir_decision = hysteresis_fsr_decision,
    .speed = soft_ramp_speed_transform
};


controller heel_controller = {
    .m = {MOTOR_MODULE_INPUT1_PIN, MOTOR_MODULE_INPUT2_PIN, MOTOR_MODULE_ENABLE_A_PIN},
    .cfg = heel_cfg,
    .dir_decision,
    .speed = soft_ramp_speed_transform
};

void setup() {
    Serial.begin(19200);
    pinMode(MOTOR_MODULE_INPUT3_PIN, OUTPUT);
    pinMode(MOTOR_MODULE_INPUT4_PIN, OUTPUT);
    pinMode(MOTOR_MODULE_ENABLE_B_PIN, OUTPUT);

    pinMode(MOTOR_MODULE_INPUT1_PIN, OUTPUT);
    pinMode(MOTOR_MODULE_INPUT2_PIN, OUTPUT);
    pinMode(MOTOR_MODULE_ENABLE_A_PIN, OUTPUT);
}

void loop() {
    int sensor_thigh_val = analogRead(THIGH_FSR);
    int sensor_heel_val = analogRead(THIGH_FSR);


    controller_act(&thigh_controller, sensor_thigh_val);
    controller_act(&heel_controller, sensor_heel_val);
}
