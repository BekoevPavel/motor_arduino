#include "MotorController.hpp"
#include "DI.hpp"

MotorController::MotorController(Encoder *enc)
{
    _enc = enc;

    //_di = &di1;
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
unsigned long int timeOut1 = 0;

void MotorController::tick()
{
<<<<<<< HEAD
    //_injection();
    //_spark();
    //uint8_t delay =
     _enc->deltaTime();
    //Serial.println("delay: "+String(delay));
=======
    _injection();
    _spark();
    uint16_t delay = _enc->deltaTime();
    // Serial.println("delta: "+String(delay));
    auto res = converter.toUInt8_Array(delay);
    if (millis() - timeOut1 > 600)
    {
        Serial.println("delta: " + String(delay));
        for(int i = 0 ; i < 3; i ++)
        {
            Serial.print(String(res[i])+".");
        }
        Serial.println("");
        //DI::uiProg->send(res, 3);

        timeOut1 = millis();
    }

    // Serial.println("res: "+String(delay));
>>>>>>> dccebb2c60249601675fea6e91a536e405ed23f3
}