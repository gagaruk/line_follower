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
<<<<<<< HEAD
    bool A_inverted;
    bool B_inverted;
=======
    bool A_INVERTED;
    bool B_INVERTED;
>>>>>>> 9fec693 (constants file)
};


namespace config{
<<<<<<< HEAD
    constexpr byte sensorPins[9] = {A0, A1, A2, A3, A4, A5, A6, A7, 2};
    constexpr s_driverConfig driverConfig = {
=======
    constexpr byte SENSOR_PINS[9] = {A0, A1, A2, A3, A4, A5, A6, A7, 2};
    constexpr s_driverConfig DRIVER_CONFIG = {
>>>>>>> 9fec693 (constants file)
        .PWMA = 9,
        .AIN1 = 7,
        .AIN2 = 8,
        .PWMB = 3,
        .BIN1 = 5,
        .BIN2 = 4,
        .STBY = 6,
<<<<<<< HEAD
        .A_inverted = false,
        .B_inverted = false
=======
        .A_INVERTED = false,
        .B_INVERTED = false
>>>>>>> 9fec693 (constants file)
    };
  
}

namespace tranciever{
<<<<<<< HEAD
    constexpr int transmissonInterval = 500;
    constexpr uint8_t CE = 0;
    constexpr uint8_t CS = 0;
    constexpr int channel = 0;
    constexpr int dataRate = 0;
    constexpr int PALevel = 0;
    constexpr byte address[][6] = {"00001", "00002"};
=======
    constexpr int TRANSMISSION_INTERVAL = 500;
    constexpr uint8_t CE = 0;
    constexpr uint8_t CS = 0;
    constexpr int CHANNEL = 0;
    constexpr int DATA_RATE = 0;
    constexpr int PA_LEVEL = 0;
    constexpr byte ADDRESS[][6] = {"00001", "00002"};
>>>>>>> 9fec693 (constants file)
}

namespace control_constants{

    namespace PID{
<<<<<<< HEAD
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
=======
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
>>>>>>> 9fec693 (constants file)
    }
}


