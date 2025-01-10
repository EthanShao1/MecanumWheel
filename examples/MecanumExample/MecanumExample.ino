#include <MecanumWheel.h>

// 馬達腳位{控制腳位1, 控制腳位2, PWM 腳位}
int frontLeftMotor[] = {43, 41, 2};
int frontRightMotor[] = {40, 42, 5};
int backLeftMotor[] = {46, 44, 4};
int backRightMotor[] = {45, 47, 3};

// 初始化
MecanumWheel mecanum(frontLeftMotor, frontRightMotor, backLeftMotor, backRightMotor);

void setup() {
}

void loop() {
    // 前進
    mecanum.move(0, 75, 0);
    delay(1000);

    // 後退
    mecanum.move(0, -75, 0);
    delay(1000);

    // 左移
    mecanum.move(-75, 0, 0);
    delay(1000);

    // 右移
    mecanum.move(75, 0, 0);
    delay(1000);

    // 順時鐘旋轉
    mecanum.move(0, 0, 75);
    delay(1000);

    // 逆時鐘旋轉
    mecanum.move(0, 0, -75);
    delay(1000);

    // 右前
    mecanum.move(75, 75, 0);
    delay(1000);

    // 左後
    mecanum.move(-75, -75, 0);
    delay(1000);

    // 左前
    mecanum.move(-75, 75, 0);
    delay(1000);

    // 右後
    mecanum.move(75, -75, 0);
    delay(1000);

    // 停止
    mecanum.stop();
    delay(1000);
}
