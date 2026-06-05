#ifndef _COMMUNICATOR_
#define _COMMUNICATOR_

#include <RF24.h>
#include <nRF24L01.h>

class c_communicator{
public:
    c_communicator(uint8_t ce, uint8_t cns, int baudrate, int transInterval);
    void init(byte writingAddress, byte readingAddress);
    void disableComms();

    void logSensorVals(const int*data, int size);
    void logTelemetry(double error);
    
    bool checkNewPIDConstants(double &kp, double &ki,double &kd);

private:
    RF24 _radio;
    uint8_t _ce, _cns;
    int _baudrate;
    int _transInterval;
    bool _enabled = false;
    unsigned long _prevTrans_t = 0;
};

#endif