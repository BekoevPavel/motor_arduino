#ifndef spark_hpp
#define spark_hpp

#include <Arduino.h>

#define STEPS_ON_TURN 800
class SparkController
{
public:
    SparkController(int pin, int pin2)
    {
        _pin1 = pin;
        _pin2 = pin2;
        pinMode(_pin1, OUTPUT);
        pinMode(_pin2, OUTPUT);
    }
    void startSpark(int delay)
    {
        if (_canTick == false)
        {
            _startTime = millis();
            _delay = delay;
            _canTick = true;
            digitalWrite(_pin1, HIGH);
            digitalWrite(_pin2, HIGH);
        }
        tick();
    }
    void tick()
    {
        if (_canTick == true && millis() - _startTime >= _delay)
        {
            digitalWrite(_pin1, LOW);
            digitalWrite(_pin2, LOW);
            _canTick = false;
            _startTime = 0;
            Serial.println("Конец искры");
        }
    }

private:
    int _delay = 0;
    unsigned long int _startTime = 0;

    int _pin1 = 0;
    int _pin2 = 0;
    bool _canTick = false;
};
#endif