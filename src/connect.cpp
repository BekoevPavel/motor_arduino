#include "connect.hpp"
#include <DI.hpp>

ConnectController::ConnectController()
{
    Ethernet.begin(mac, ip);

    delay(1000);
    Serial.println("ip: " + String(Ethernet.localIP()));

    Serial.println("Connecting...");

    if (client.connect(server, tcp_port))
    { // Connection to server.js
        Serial.println("Connected to UI");
        client.println();
    }
    else
    {
        Serial.println("Connection failed");
    }
}

void ConnectController::send(uint8_t sendID, uint8_t *data, int _lenght)
{

    // функция отправки по ID
    uint8_t *sendArray = new uint8_t[_lenght];
    sendArray[0] = sendID;
    for (int i = 0; i < _lenght; i++)
    {

        sendArray[i + 1] = data[i];
    }

    client.write(sendArray, _lenght);
}

void ConnectController::tick()
{
    if (!client.connected())
    {
        Serial.println();
        Serial.println("Disconnecting.");
        client.stop();
        for (;;)
            ;
    }
}

uint8_t *ConnectController::listen()
{

    if (client.available())
    {
        uint8_t mass[] = {0, 0, 0};
        int lenght = sizeof(mass) / sizeof(uint8_t);
        client.read(mass, lenght);

        if (mass[0] == (uint8_t)3)
        {
            Serial.println("click2");
        }
        if (mass[0] == (uint8_t)15) // Прослушка значения для Injection (Впрыск)
        {
            uint16_t sparkDelay = _converter.byteToInt(mass[1], mass[2]);
            DI::motorController->setDelayInjectoin(sparkDelay);
            Serial.println("value Y: " + String(sparkDelay));
            Serial.println("впрыск");
        }
        if (mass[0] == (uint8_t)13) // Прослушка значения для Spark (Искра)
        {
            uint16_t sparkDelay = _converter.byteToInt(mass[1], mass[2]);
            DI::motorController->setDelaySpark(sparkDelay);
            Serial.println("value Y: " + String(sparkDelay));
            Serial.println("зажигание");
        }
       
        if (mass[0] == (uint8_t)11)
        {

            DI::stepper->setTarget(_converter.byteToInt(mass[1], mass[2]));
            Serial.println();
            Serial.println("мотор");
            // Задать напряжения потенциометра для остановки для мотора
        }
        if (mass[0] == (uint8_t)14)
        {
            uint16_t sparkDelay = _converter.byteToInt(mass[1], mass[2]);
            DI::motorController->setDelaySpark(sparkDelay);
            Serial.println("авто-value Y: " + String(sparkDelay));
            Serial.println("авто-зажигание");
        }

        Serial.println("");
    }
    return {};

    tick();
}