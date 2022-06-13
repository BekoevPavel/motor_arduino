#include " dynamometer.hpp"
#include "DI.hpp"
void Dynamometer::tick()
{
    U = _getU();
    if (millis() - _timeOut > 300)
    {

        uint8_t *sendArray = new uint8_t[1];
        sendArray[0] = U;

        DI::uiProg->send(229, sendArray, 2);

        _timeOut = millis();
    }

    _getU();
}