#ifndef MotorController_hpp
#define MotorController_hpp

#include <Arduino.h>
#include "encoder.hpp"
#include "converter.hpp"

class MotorController
{
public:
    MotorController(Encoder *enc);

    // func
public:
    void tick();

    void setDelayInjectoin(unsigned long int delay)
    {

        _delayInjection = delay;
        Serial.println("delay injection: " + String(_delayInjection));
    }
    void setDelaySpark(unsigned long int delay)
    {
        _delaySpark = delay;
        Serial.println("delay spark: " + String(_delaySpark));
    }

private:
    void _injection(); // впрыск
    void _spark();     // искра

    Encoder *_enc;
    unsigned long int _delayInjection = 0;
    unsigned long int _delaySpark = 0;

    unsigned long int _timePinInjection = 0;
    unsigned long int _timePinSpark = 0;

    bool _startInjection = false;
    bool _startSpark = false;
   
    Converter converter;

};
#endif