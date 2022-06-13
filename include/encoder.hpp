#ifndef encoder_hpp
#define encoder_hpp

#include <Arduino.h>
#define DELAY 10

class Encoder
{
public:
    Encoder(int pin0, int pin1, int pin2, int pin3)
    {
        _pin0 = pin0;
        _pin1 = pin1;
        _pin2 = pin2;
        _pin3 = pin3;
        pinMode(_pin0, INPUT_PULLUP);
        pinMode(_pin1, INPUT_PULLUP);
        pinMode(_pin2, INPUT_PULLUP);
        pinMode(_pin3, INPUT_PULLUP);
    }
    // func
public:
    uint16_t deltaTime()
    {

<<<<<<< HEAD
        if (digitalRead(_pin0) == 0 || digitalRead(_pin1) == 0 || digitalRead(_pin2) == 0 || digitalRead(_pin3) == 0)
=======
        int activatedSensor = _activatedSensor();

        if (activatedSensor != -1)
>>>>>>> dccebb2c60249601675fea6e91a536e405ed23f3
        {
            if (activatedSensor != _lastActivatedSensor)
            {

<<<<<<< HEAD
            _deltaTime = millis() - _timeLastPin;
            _timeLastPin = millis();
            Serial.println("click" + String(millis()) + " - " + String(_deltaTime));
=======
                _deltaTime = millis() - _timeLastPin;
                //Serial.println("delta: " + String(_deltaTime));
                _timeLastPin = millis();

                _lastActivatedSensor = activatedSensor;
            }
>>>>>>> dccebb2c60249601675fea6e91a536e405ed23f3
        }

        return _deltaTime;
    }
    bool injectionPin()
    {
        if (millis() - _timeActiveInvection >= DELAY && !digitalRead(_pin3))
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
    int _activatedSensor()
    {
        if (!digitalRead(_pin0))
        {
            return 0;
        }
        if (!digitalRead(_pin1))
        {
            return 1;
        }
        if (!digitalRead(_pin2))
        {
            return 2;
        }
        if (!digitalRead(_pin3))
        {
            return 0;
        }
        return -1;
    }

    int _pin0, _pin1, _pin2, _pin3;
    unsigned long int _timeLastPin = 0;
    unsigned long int _timeActiveInvection = 0;
    unsigned long int _timeActiveSpark = 0;
    unsigned long int _deltaTime = 0;
<<<<<<< HEAD
    bool _detectPin = false;
=======
    int _lastActivatedSensor = -1;
>>>>>>> dccebb2c60249601675fea6e91a536e405ed23f3
};
#endif