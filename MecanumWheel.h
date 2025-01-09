#ifndef MecanumWheel_h
#define MecanumWheel_h

#include "Arduino.h"

class MecanumWheel {
public:
    MecanumWheel(int frontLeft[3], int frontRight[3], int backLeft[3], int backRight[3]);
    void move(float xSpeed, float ySpeed, float rotation);
    void stop();

private:
    int _frontLeft[3];
    int _frontRight[3];
    int _backLeft[3];
    int _backRight[3];
    
    void setMotor(int motor[3], float speed);
};

#endif
