#include "MecanumWheel.h"

MecanumWheel::MecanumWheel(int frontLeft[3], int frontRight[3], int backLeft[3], int backRight[3]) {
    memcpy(_frontLeft, frontLeft, sizeof(_frontLeft));
    memcpy(_frontRight, frontRight, sizeof(_frontRight));
    memcpy(_backLeft, backLeft, sizeof(_backLeft));
    memcpy(_backRight, backRight, sizeof(_backRight));
    for (int i = 0; i < 3; i++) {
        pinMode(_frontLeft[i], OUTPUT);
        pinMode(_frontRight[i], OUTPUT);
        pinMode(_backLeft[i], OUTPUT);
        pinMode(_backRight[i], OUTPUT);
    }
}

void MecanumWheel::move(float xSpeed, float ySpeed, float rotation) {
    float frontLeftSpeed = ySpeed + xSpeed + rotation;
    float frontRightSpeed = ySpeed - xSpeed - rotation;
    float backLeftSpeed = ySpeed - xSpeed + rotation;
    float backRightSpeed = ySpeed + xSpeed - rotation;

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

void MecanumWheel::setMotor(int motor[3], float speed) {
    int dirPin1 = motor[0];
    int dirPin2 = motor[1];
    int pwmPin = motor[2];
    
    if (speed > 0) {
        digitalWrite(dirPin1, HIGH);
        digitalWrite(dirPin2, LOW);
    } else if (speed == 0) {
        digitalWrite(dirPin1, LOW);
        digitalWrite(dirPin2, LOW);
    } else {
        digitalWrite(dirPin1, LOW);
        digitalWrite(dirPin2, HIGH);
        speed = -speed;
    }
    analogWrite(pwmPin, constrain(speed, 0, 255));
}
