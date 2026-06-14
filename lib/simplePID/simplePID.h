#ifndef _SIMPLEPID_
#define _SIMPLEPID_


class c_simplePID{
public:
    c_simplePID(double kp, double ki, double kd);
    double compute(double error, double setPoint);
    void setTolarence(double tolerance);
    void setIRange(double lowerI, double higherI);
    void setIZone(double IZone);
private:
    double _kp, _ki, _kd;
    double _prevError = 0;
    double _prevFilteredDiff = 0;
    double _prevT = 0;
    double _integral = 0;

    double _tolerance = 0;
    double _IZone = 0;
    double _lowerI = 0;
    double _higherI = 0;

    double calculateP();
    double calculateI();
    double calculateD();

};

#endif