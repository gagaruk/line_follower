#ifndef _MOTOR_H_
#define _MOTOR_H_

class c_motor{
public:
    c_motor(uint8_t pin1, uint8_t pin2, uint8_t pwmPin);
    void init();
    void setSpeed(int speed);
    void setInverted(bool isInverted);
    void setSpeedLimit(int limit);
private:
    bool _inverted = false;
    int speed = 0;
    uint8_t _pin1;
    uint8_t _pin2;
    uint8_t _pwmPin;
    uint8_t _maxSpeed=255;
};
#endif