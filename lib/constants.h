#pragma once
#include <Arduino.h>

struct s_driverConfig{
    uint8_t PWMA;
    uint8_t AIN1;
    uint8_t AIN2;
    uint8_t PWMB;
    uint8_t BIN1;
    uint8_t BIN2;
    uint8_t STBY;
    bool A_inverted;
    bool B_inverted;
};


namespace config{
    constexpr byte sensorPins[9] = {A0, A1, A2, A3, A4, A5, A6, A7, 2};
    constexpr s_driverConfig driverConfig = {
        .PWMA = 9,
        .AIN1 = 7,
        .AIN2 = 8,
        .PWMB = 3,
        .BIN1 = 5,
        .BIN2 = 4,
        .STBY = 6,
        .A_inverted = false,
        .B_inverted = false
    };
  
}

namespace tranciever{
    constexpr int transmissonInterval = 500;
    constexpr uint8_t CE = 0;
    constexpr uint8_t CS = 0;
    constexpr int channel = 0;
    constexpr int dataRate = 0;
    constexpr int PALevel = 0;
    constexpr byte address[][6] = {"00001", "00002"};
}

namespace control_constants{

    namespace PID{
        constexpr double kp = 0;
        constexpr double ki = 0;
        constexpr double kd = 0;
    }

    namespace speed{
        constexpr double FFGain = 0;
        constexpr int minSpeed= 0;
        constexpr int maxSpeed= 0;
    }

    namespace sensor_weights{
        constexpr double sensorWeights[8] = {-4.1, -3.4, -2.2, -1.2, 1.2, 2.2, 3.4, 4.1};
        constexpr int treshhold= 500;
    }
}


