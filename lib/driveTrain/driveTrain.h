#ifndef _DRIVETRAIN_
#define _DRIVETRAIN_

#include "motor.h"

class c_driveTrain{
public:
    c_driveTrain(c_motor& right, c_motor& left);
    void setDifferentialSpeed(int baseSpeed, int turn);
    void hardTurn(int turn);
    void stop();

private:
    c_motor& _left;
    c_motor& _right;
};

#endif
