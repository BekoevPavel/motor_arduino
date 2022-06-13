#ifndef encoder_hpp
#define encoder_hpp

#include <Arduino.h>
#define DELAY 10

class Encoder
{
public:
    Encoder(int pin0, int pin1, int pin2)
    {
        _pin0 = pin0;
        _pin1 = pin1;
        _pin2 = pin2;

        pinMode(_pin0, INPUT_PULLUP);
        pinMode(_pin1, INPUT_PULLUP);
        pinMode(_pin2, INPUT_PULLUP);
    }
    // func
public:
    uint16_t getDelay()
    {
        if (_tempDelay >= 8000)
        {
            _deltaTime = 65000;
        }
        // Serial.println("pin0: " + String(digitalRead(_pin0)) + " pin1: " + String(digitalRead(_pin1)) + " pin2: " + String(digitalRead(_pin2)));
        if (!digitalRead(_pin0))
        {
            lastTime = millis();
            _deltaTime = _tempDelay;
        }
        else
        {

            _tempDelay = millis() - lastTime;
        }
        return _deltaTime;
    }
    bool injectionPin()
    {
        if (millis() - _timeActiveInvection >= DELAY && !digitalRead(_pin2))
        {
            _timeActiveInvection = millis();
            return true;
        }
        return false;
    }
    bool sparkPin()
    {
        if (millis() - _timeActiveSpark >= DELAY && !digitalRead(_pin1))
        {

            _timeActiveSpark = millis();
            return true;
        }
        return false;
    }

private:
    int _pin0, _pin1, _pin2;
    unsigned long int lastTime = 0;
    unsigned long int _tempDelay = 0;
    bool _pinActive = false;

    unsigned long int _timeActiveInvection = 0;
    unsigned long int _timeActiveSpark = 0;
    unsigned long int _deltaTime = 0;
};
#endif