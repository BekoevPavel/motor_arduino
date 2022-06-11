#ifndef injection_hpp
#define injection_hpp

#include <Arduino.h>

#define STEPS_ON_TURN 800
class InjectionController
{
public:
    InjectionController(int pin)
    {
        _pin = pin;
        pinMode(_pin, OUTPUT);
        digitalWrite(_pin, LOW);
    }
    void startInjection(int delay)
    {
        if (_canTick == false)
        {
            _startTime = millis();
            _delay = delay;
            _canTick = true;
            digitalWrite(_pin, HIGH);
        }
      
    }
    void tick()
    {
        if (_canTick == true && millis() - _startTime >= _delay)
        {
            digitalWrite(_pin, LOW);
            _canTick = false;
            _startTime = 0;
            Serial.println("Конец впрыска");
        }
    }

private:
    int _delay = 0;
    unsigned long int _startTime = 0;

    int _pin = 0;
    bool _canTick = false;
};
#endif