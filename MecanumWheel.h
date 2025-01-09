#ifndef MecanumWheel_h
#define MecanumWheel_h

#include "Arduino.h"

class MecanumWheel {
public:
    MecanumWheel(int frontLeft[2], int frontRight[2], int backLeft[2], int backRight[2]);
    void move(float xSpeed, float ySpeed, float rotation);
    void stop();

private:
    int _frontLeft[2];
    int _frontRight[2];
    int _backLeft[2];
    int _backRight[2];
    
    void setMotor(int motor[2], float speed);
};

#endif
