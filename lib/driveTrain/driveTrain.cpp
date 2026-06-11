#include "driveTrain.h"
#include "motor.cpp"


c_driveTrain::c_driveTrain(c_motor& left, c_motor& right): _left(left),_right(right) {}

void c_driveTrain::stop(){
    _left.setSpeed(0);
    _right.setSpeed(0);
}

void c_driveTrain::setDifferentialSpeed(int baseSpeed, int turn){
    int leftSpeed = baseSpeed - turn;
    int rightSpeed = baseSpeed + turn;

    //it is assumed that both motors are the same-  in pwm resolution and max speed
    int speedLimit = _left.getSpeedLimit();

    if(leftSpeed > speedLimit || rightSpeed > speedLimit){
        int maxSpeed = max(abs(leftSpeed), abs(rightSpeed));

        leftSpeed *= speedLimit/maxSpeed;
        rightSpeed *= speedLimit/maxSpeed;

    }
}

void c_driveTrain::hardTurn(int turn){
    _left.setSpeed(-turn);
    _right.setSpeed(turn);
}

void c_driveTrain::stop(){
    _left.setSpeed(0);
    _right.setSpeed(0);
}