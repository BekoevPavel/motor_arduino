#ifndef converter_hpp
#define converter_hpp

#include <Arduino.h>

// lenght return 3
class Converter
{
public:
    Converter(){};

    // func
public:
    uint8_t *intToBytes(uint16_t input)
    {
        uint8_t first = (uint8_t)(input / 256);
        uint8_t last = input - first * 256;

        uint8_t * result = new  uint8_t[2];

        result[0] = first;
        result[1] = last;
        // Serial.println("v - "+String(input));
        // Serial.println("v0 - "+String(result[0]));
        // Serial.println("v1 - "+String(result[1]));

        return result;
    }
    uint16_t byteToInt(uint8_t firstByte, uint8_t lastByte)
    {
        return lastByte + (firstByte * 256);
    }

private:
};
#endif