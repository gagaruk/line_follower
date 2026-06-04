#ifndef _LINESENSOR_H_
#define _LINESENSOR_H_

class c_sensorArray{
public:
    template <size_t N, size_t M>
    c_sensorArray(const int (&pins)[N], const double (&weights)[M]) 
        : _pins(pins), _weights(weights) 
    {
        // This check happens at compile time!
        static_assert(N == 8, "Hardware Error: Sensor array must have exactly 8 pins.");
        static_assert(N == M, "Configuration Error: Pins and weights count must match.");
    }

    void init();
    void updateVals();
    int* getRawVals();
    double getWeightedAverage();
    
private:
    const int* _pins;
    const double* _weights;
    int _vals[8];
    double getWeightedSum();
};

#endif