#include <MecanumWheel.h>

// 馬達腳位{控制腳位1, 控制腳位2, PWM 腳位}
int frontLeftMotor[] = {43, 41, 2};
int frontRightMotor[] = {40, 42, 5};
int backLeftMotor[] = {46, 44, 4};
int backRightMotor[] = {45, 47, 3};

float currentX = 0, currentY = 0, currentRotation = 0;

// 初始化
MecanumWheel mecanum(frontLeftMotor, frontRightMotor, backLeftMotor, backRightMotor);

void setup() {
}

void loop() {
    moveSet(0, 200, 0);
}

void moveSet(float targetX, float targetY, float targetRotation) {
    currentX = smoothSpeed(currentX, targetX, 5);
    currentY = smoothSpeed(currentY, targetY, 5);
    currentRotation = smoothSpeed(currentRotation, targetRotation, 5);

    mecanum.move(currentX, currentY, currentRotation);
    delay(10);
}
float smoothSpeed(float current, float target, float maxChange) {
    if (abs(target - current) <= maxChange) {
        return target;
    } else if (target > current) {
        return current + maxChange;
    } else {
        return current - maxChange;
    }
}
