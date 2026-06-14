#include "simplePID.h"
#include <Arduino.h>

c_simplePID::c_simplePID(double kp, double ki, double kd) :
    _kp(kp), _ki(ki), _kd(kd){}

void c_simplePID::setTolarence(double tolerance){
    _tolerance= tolerance;
}

void c_simplePID::setIZone(double Izone){
    _IZone = Izone;
}

void c_simplePID::setIRange(double lowerI, double higherI){
    _lowerI = lowerI;
    _higherI = higherI;
}

double c_simplePID::compute(double error, double setPoint){
    unsigned long current_time = millis();
    
    double dt = (current_time-_prevT)/1000.0;
    if(dt==0) return 0;

    double currentDiff = error - _prevError;
    double filteredDiff = (_prevFilteredDiff*0.7) + (currentDiff*0.3);
    _prevFilteredDiff = filteredDiff;
    
    _integral += error*dt;

    double p = _kp * error;
    double i = _ki * _integral;
    double d = _kd * filteredDiff/dt;

    _prevError = error; 
    _prevT = current_time;


    return p+i+d;
}
