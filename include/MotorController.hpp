#ifndef MotorController_hpp
#define MotorController_hpp

#include <Arduino.h>
#include "encoder.hpp"
#include "converter.hpp"
#include "injection.hpp"
#include "spark.hpp"
class MotorController
{
public:
    MotorController(Encoder *enc, int pinInjection, int pinSpark);

    // func
public:
    void tick();

    void setDelayInjectoin()
    {

        //_delayInjection = delay;
        Serial.println("delay injection: " + String(_delayInjection));
    }
    void setDelaySpark(unsigned long int delay)
    {
        _delaySpark = delay;
        Serial.println("delay spark: " + String(_delaySpark));
    }

    void setSparkTime(int time)
    {
        _sparkTime = time;
    }
    void setInjectionTime(int time)
    {
        Serial.println("Задержка зажигания" + String(time));
        _injectionTime = time;
        _injectionController->setInjectionTime(time);
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

    int _pinWorkInjection, _pinWorkSpark;

    Converter _converter;
    InjectionController *_injectionController;
    SparkController *_sparkController;
    int _injectionTime = 100;
    int _sparkTime = 200;
};
#endif