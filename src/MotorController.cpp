#include "MotorController.hpp"
#include "DI.hpp"

MotorController::MotorController(Encoder *enc, int pinInjection, int pinSpark)
{
    _enc = enc;

    _pinWorkInjection = pinInjection;
    _timePinSpark = pinSpark;
    pinMode(_pinWorkInjection, OUTPUT);
    pinMode(_pinWorkSpark, OUTPUT);
}
void MotorController::_injection()
{
    if (_enc->injectionPin())
    {
        Serial.println("Пин впрыска");
        _timePinInjection = millis();
        _startInjection = true;
    }
    if (millis() - _timePinInjection >= _delayInjection && _startInjection)
    {
        _startInjection = false;
        Serial.println("Впрыск"); // сделать впрыск
    }
}
void MotorController::_spark()
{
    if (_enc->sparkPin())
    {
        Serial.println("Пин искры");
        _timePinSpark = millis();
        _startSpark = true;
    }
    if (millis() - _timePinSpark >= _delaySpark && _startSpark)
    {
        _startSpark = false;
        Serial.println("Искра");

        // сделать впрыск
    }
}
unsigned long int timeOut1 = 0;

void MotorController::tick()
{
    _injection();
    //_spark();
    uint16_t delay = _enc->deltaTime();
    // Serial.println("delta: "+String(delay));

    if (millis() - timeOut1 > 600)
    {
        auto res = converter.toUInt8_Array(delay);

        DI::uiProg->send(res, 3);

        timeOut1 = millis();
    }
}