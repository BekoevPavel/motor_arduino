#include "stepper.hpp"
#include "DI.hpp"
unsigned long int timeOut5 = 0;
bool _renge(uint8_t val1, uint8_t val2)
{
    if (abs(val1 - val2) < 16)
    {
        return true;
    }
    return false;
}
void MyStepper::tick()
{
    // if (millis() - timeOut5 > 1000)
    // {
    //     Serial.println("U: " + String(DI::dynamometer->U) + " target: " + String(_target));

    //     timeOut5 = millis();
    // }

    if (_renge(DI::dynamometer->U, _target))
    {
        //Serial.println("stop");
        stop();
    }
    else if (DI::dynamometer->U > _target)
    {

        //Serial.println("left");
        move(STEPS_ON_TURN);
    }
    else if (DI::dynamometer->U < _target)
    {
        //Serial.println("right");
        move(-STEPS_ON_TURN);
    }

    _stepper->tick();
}
