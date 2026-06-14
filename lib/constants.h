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
    bool A_INVERTED;
    bool B_INVERTED;
};


namespace config{
    constexpr byte SENSOR_PINS[9] = {A0, A1, A2, A3, A4, A5, A6, A7, 2};
    constexpr s_driverConfig DRIVER_CONFIG = {
        .PWMA = 9,
        .AIN1 = 7,
        .AIN2 = 8,
        .PWMB = 3,
        .BIN1 = 5,
        .BIN2 = 4,
        .STBY = 6,
        .A_INVERTED = false,
        .B_INVERTED = false
    };
  
}

namespace tranciever{
    constexpr int TRANSMISSION_INTERVAL = 500;
    constexpr uint8_t CE = 0;
    constexpr uint8_t CS = 0;
    constexpr int CHANNEL = 0;
    constexpr int DATA_RATE = 0;
    constexpr int PA_LEVEL = 0;
    constexpr byte ADDRESS[][6] = {"00001", "00002"};
}

namespace control_constants{

    namespace PID{
        constexpr double KP = 0;
        constexpr double KI = 0;
        constexpr double KD = 0;
    }

    namespace speed{
        constexpr double FF_GAIN = 0;
        constexpr int MIN_SPEED = 0;
        constexpr int MAX_SPEED = 0;
    }

    namespace sensor_weights{
        constexpr double WEIGHTS[8] = {-4.1, -3.4, -2.2, -1.2, 1.2, 2.2, 3.4, 4.1};
        constexpr int TRESHHOLD = 500;
    }
}


