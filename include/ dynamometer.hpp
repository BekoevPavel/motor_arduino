#ifndef dynamometer_hpp
#define dynamometer_hpp

#include <Arduino.h>

class Dynamometer
{
public:
    Dynamometer(int pin)
    {
        _pin = pin;
        pinMode(_pin, INPUT);
    }

    uint8_t tick()
    {
       
        return  250*((float)(analogRead(_pin)*0.001));
    }

    // func
public:
private:
    int _pin = 0;
};
#endif