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

void ConnectController::send(uint8_t *data, int _lenght)
{
    int lenght = _lenght;
    // Serial.println("");
    // for (int i = 0; i < _lenght; i++)
    // {
    //     Serial.print(String(data[i]) + ".");
    // }
    // Serial.println("");
    client.write(data, lenght);
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
        if (mass[0] == (uint8_t)1) // Прослушка значения для Injection (Впрыск)
        {
            DI::motorController->setDelayInjectoin(mass[1]);
        }
        if (mass[0] == (uint8_t)2)  // Прослушка значения для Spark (Искра)
        {
            DI::motorController->setDelaySpark(mass[1]);
        }

        Serial.println("");
    }
    return {};

    tick();
}