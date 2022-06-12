#include "MotorController.hpp"
#include "DI.hpp"
MotorController::MotorController(Encoder *enc)
{
    _enc = enc;
    di->getInstance();
}
void MotorController::_injection()
{
    if (_enc->injectionPin())
    {
        _timePinInjection = millis();
        _startInjection = true;
    }
    if (millis() - _timePinInjection >= _delayInjection && _startInjection)
    {
        _startInjection = false;
        // сделать впрыск
    }
}
void MotorController::_spark()
{
    if (_enc->sparkPin())
    {
        _timePinSpark = millis();
        _startSpark = true;
    }
    if (millis() - _timePinSpark >= _delaySpark && _startSpark)
    {
        _startSpark = false;
        // сделать впрыск
    }
}

void MotorController::tick()
{
    //_injection();
    //_spark();
    //uint8_t delay =
     _enc->deltaTime();
    //Serial.println("delay: "+String(delay));
}