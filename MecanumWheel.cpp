#include "MecanumWheel.h"

MecanumWheel::MecanumWheel(int frontLeft[2], int frontRight[2], int backLeft[2], int backRight[2]) {
    memcpy(_frontLeft, frontLeft, sizeof(_frontLeft));
    memcpy(_frontRight, frontRight, sizeof(_frontRight));
    memcpy(_backLeft, backLeft, sizeof(_backLeft));
    memcpy(_backRight, backRight, sizeof(_backRight));
    for (int i = 0; i < 2; i++) {
        pinMode(_frontLeft[i], OUTPUT);
        pinMode(_frontRight[i], OUTPUT);
        pinMode(_backLeft[i], OUTPUT);
        pinMode(_backRight[i], OUTPUT);
    }
}

void MecanumWheel::move(float xSpeed, float ySpeed, float rotation) {
    float frontLeftSpeed = ySpeed + xSpeed - rotation;
    float frontRightSpeed = ySpeed - xSpeed + rotation;
    float backLeftSpeed = ySpeed - xSpeed - rotation;
    float backRightSpeed = ySpeed + xSpeed + rotation;

    setMotor(_frontLeft, frontLeftSpeed);
    setMotor(_frontRight, frontRightSpeed);
    setMotor(_backLeft, backLeftSpeed);
    setMotor(_backRight, backRightSpeed);
}

void MecanumWheel::stop() {
    setMotor(_frontLeft, 0);
    setMotor(_frontRight, 0);
    setMotor(_backLeft, 0);
    setMotor(_backRight, 0);
}

void MecanumWheel::setMotor(int motor[2], float speed) {
    int dirPin = motor[0];
    int pwmPin = motor[1];
    
    if (speed > 0) {
        digitalWrite(dirPin, HIGH);
    } else {
        digitalWrite(dirPin, LOW);
        speed = -speed;
    }
    analogWrite(pwmPin, constrain(speed, 0, 255));
}
