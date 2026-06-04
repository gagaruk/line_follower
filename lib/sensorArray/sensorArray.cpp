#include "sensorArray.h"
#include <Arduino.h>

void c_sensorArray::init(){
    for(int i = 0; i<8; i++){
        pinMode(_pins[i], INPUT);
    }
    pinMode(_pins[8], OUTPUT);
    digitalWrite(_pins[8],HIGH);

    for(int i=0; i<8; i++){
    _vals[i] = analogRead(_pins[i]);
  }

}

void c_sensorArray::updateVals(){  
    for(int i=0; i<8; i++){
    _vals[i] = analogRead(_pins[i]);
  }
}

int* c_sensorArray::getRawVals(){
    return _vals;
}

double c_sensorArray::getWeightedSum(){
    double sum = 0;

    for(int i=0; i<8; i++){
        sum+= _vals[i] * _weights[i];
    }
    return sum;
}

double c_sensorArray::getWeightedAverage(){
    double rawSum = 0;
    double weightedSum = getWeightedSum();

    for(int i; i<8; i++){
        rawSum+= _vals[i];
    }
    return weightedSum/rawSum;

}
