#include "motor.h"
#include <Arduino.h>

c_motor::c_motor(uint8_t pin1, uint8_t pin2, uint8_t pwmPin)
    : _pin1(pin1), _pin2(pin2), _pwmPin(pwmPin){

}

void c_motor::init(){
    pinMode(_pin1, OUTPUT);
    pinMode(_pin2, OUTPUT);
    pinMode(_pwmPin, OUTPUT);
}

void c_motor::setSpeed(int speed){
    int direction = _inverted ? -1 : 1;
    int finalSpeed= constrain(speed*direction, -_maxSpeed, _maxSpeed);

    digitalWrite(_pin1, (finalSpeed>=0) ? HIGH : LOW);
    digitalWrite(_pin2, (speed>= 0) ? LOW : HIGH);
    analogWrite(_pwmPin, abs(finalSpeed));
}   

void c_motor::setInverted(bool isInverted){
    _inverted=isInverted;
}

void c_motor::setSpeedLimit(int limit){
    _maxSpeed = limit;
}