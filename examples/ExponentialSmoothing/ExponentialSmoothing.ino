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
    moveSet(0, 200, 0, 0.1);
}

void moveSet(float targetX, float targetY, float targetRotation, float alpha) {
    currentX = smoothSpeed(currentX, targetX, alpha);
    currentY = smoothSpeed(currentY, targetY, alpha);
    currentRotation = smoothSpeed(currentRotation, targetRotation, alpha);

    mecanum.move(currentX, currentY, currentRotation);
    delay(10);
}
float smoothSpeed(float current, float target, float alpha) {
    return alpha * target + (1 - alpha) * current;
}
