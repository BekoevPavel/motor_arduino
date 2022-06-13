#ifndef dynamometer_hpp
#define dynamometer_hpp

#include <Arduino.h>
#include "converter.hpp"

class Dynamometer
{
public:
    Dynamometer(int pin, int pinStop)
    {
        _pin = pin;
        _pinStop = pinStop;

        pinMode(_pin, INPUT);
        pinMode(_pinStop, INPUT_PULLUP);
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
    void findStopMoment();
   
    unsigned long int _timeOut = 0;
    int _pin = 0;
    int _pinStop = 0;
    bool stoped = true;

    Converter _converter;
};
#endif