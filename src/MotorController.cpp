#include "MotorController.hpp"
#include "DI.hpp"
#define L_PIN 9

#define i_PIN 8
#define k_pin 7
MotorController::MotorController(Encoder *enc, int pinInjection, int pinSpark)
{
    _enc = enc;

    _pinWorkInjection = pinInjection;
    _timePinSpark = pinSpark;
    pinMode(_pinWorkInjection, OUTPUT);
    pinMode(_pinWorkSpark, OUTPUT);
    _injectionController = new InjectionController(L_PIN);
    _sparkController = new SparkController(i_PIN, k_pin);
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

        // TODO Сделать прием задержки из UI
        _injectionController->startInjection();
    }
    _injectionController->tick();
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
        _sparkController->startSpark(_sparkTime);

        // сделать впрыск
    }
    _sparkController->tick();
}
unsigned long int timeOut1 = 0;

void MotorController::tick()
{
    _injection();
    _spark();
    uint16_t delay = _enc->getDelay();

    if (millis() - timeOut1 > 600)
    {
        auto res = _converter.intToBytes(delay);

        DI::uiProg->send(228, res, 3);

        timeOut1 = millis();
    }
}