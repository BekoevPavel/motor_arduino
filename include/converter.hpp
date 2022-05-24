#ifndef converter_hpp
#define converter_hpp

#include <Arduino.h>

// lenght return 3
class Converter
{
public:
    Converter()
    {
    }

    // func
public:
    uint8_t *toUInt8_Array(uint16_t input)
    {

        uint8_t *bytesArray = _toByte_Array(input);

        uint8_t *result = _byteToUnt_array(bytesArray);

        return result;
    }

private:
    uint8_t *_toByte_Array(uint16_t input)

    {
        uint16_t temp = input;
        static uint8_t result[16] = {};
        static uint8_t tempArray[16] = {};
        for (int i = 0; i < 16; i++)
        {

            tempArray[i] = temp % 2;
            temp /= 2;
        }
        for (int i = 15; i > 0; i--)
        {
            result[i] = tempArray[15 - i];
        }
        if (input > 32767)
        {
            result[0] = 1;
        }

        return result;
    }

    uint8_t *_byteToUnt_array(uint8_t *bytes)
    {
        uint8_t firstArray[8] = {};
        uint8_t lastArray[8] = {};
        for (int i = 0; i < 8; i++)
        {

            firstArray[i] = bytes[i];
        }
        for (int i = 0; i < 8; i++)
        {
            lastArray[i] = bytes[i + 8];
        }
        // Serial.println("");
        //  first cut print
        for (int i = 0; i < 8; i++)
        {
            // Serial.print(String(firstArray[i]) + ".");
        }
        // Serial.println("");
        //  last cut print
        for (int i = 0; i < 8; i++)
        {
            // Serial.print(String(lastArray[i]) + ".");
        }
        //--------------------------------------
        uint8_t resultFirst = 0;
        uint8_t resultLast = 0;
        for (int i = 7; i >= 0; i--)
        {
            auto res = lastArray[abs(i - 7)] * pow(2, i);

            resultLast = resultLast + res;
        }
        for (int i = 7; i >= 0; i--)
        {
            auto res = firstArray[abs(i - 7)] * pow(2, i);
            resultFirst = resultFirst + res;
        }

        uint8_t *result = new uint8_t[3];
        result[0] = 228;
        result[1] = resultFirst;
        result[2] = resultLast;

        return result;
    }
};
#endif