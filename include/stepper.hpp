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
        _stepper->brake();
        _stepper->setRunMode(KEEP_SPEED);
        _stepper->setSpeed(speed);
    }
    void stop()
    {
        _stepper->brake();
    }
    void tick()
    {
        _stepper->tick();
    }

private:
    int _en = 0;
    int _pul = 0;
    int _dir = 0;

    GStepper<STEPPER2WIRE> *_stepper;
};
#endif