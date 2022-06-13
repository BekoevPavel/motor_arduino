#ifndef dynamometer_hpp
#define dynamometer_hpp

#include <Arduino.h>
#include "converter.hpp"


class Dynamometer
{
public:
    Dynamometer(int pin)
    {
        _pin = pin;
        pinMode(_pin, INPUT);
    }

    uint8_t _getU()
    {

        return 250 * ((float)(analogRead(_pin) * 0.001));
    }

    // func
public:
    void tick();
    uint8_t U = 0;

private:
    unsigned long int _timeOut = 0;
    int _pin = 0;
    
    Converter _converter;
};
#endif