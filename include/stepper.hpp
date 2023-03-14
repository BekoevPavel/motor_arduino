#ifndef stepper_hpp
#define stepper_hpp

#include <Arduino.h>
#include <GyverStepper.h>

#define STEPS_ON_TURN 800
class MyStepper
{
public:
    MyStepper(int en, int pul, int dir)
    {

        _en = en;
        _pul = pul;
        _dir = dir;

        _stepper = new GStepper<STEPPER2WIRE>(800, _pul, _dir, _en);
    }

    // func
public:
    void move(int speed)
    {
        if (_speed != speed)
        {
            Serial.println("start");
            _started = false;
        }
        if (!_started)
        {
            _stepper->brake();
            _stepper->setRunMode(KEEP_SPEED);
            _stepper->setAcceleration(0);
            _stepper->setSpeed(speed);
            _started = true;
        }
        _speed = speed;
    }
    void stop()
    {
        _started = false;
        // _target = 0;

        _stepper->brake();
    }
    void tick();

    void setTarget(uint8_t target)
    {
        _target = target;
    }

    uint8_t getTarget()
    {
        return _target;
    }

private:
    bool _started = false;
    int _en = 0;
    int _pul = 0;
    int _dir = 0;
    int _target = 0;
    int _speed = 0;

    GStepper<STEPPER2WIRE> *_stepper;
};
#endif