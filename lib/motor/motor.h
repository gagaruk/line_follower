#ifndef _MOTOR_H_
#define _MOTOR_H_

class c_motor(){
public:
    c_motor(int pin1, int pin2, int pwm);
    void init();
    void setSpeed(int speed);
    void setInverted(bool isInverted);
    void setMaxSpeed(200)
private:
    bool _inverted = false;
    int speed = 0;
    int _pin1, _pin2, _pwm;
};
#endif