#include "connect.hpp"
#include "DI.hpp"
ConnectController::ConnectController()
{
    Ethernet.begin(mac, ip);
    di->getInstance();

    delay(1000);

    Serial.println("Connecting...");

    if (client.connect(server, tcp_port))
    { // Connection to server.js
        Serial.println("Connected to server.js");
        client.println();
    }
    else
    {
        Serial.println("connection failed");
    }
}

void ConnectController::send(uint8_t *data)
{
    int lenght = sizeof(data) / sizeof(uint8_t);
    client.write(data, lenght);
}

void ConnectController::tick()
{
    if (!client.connected())
    {
        Serial.println();
        Serial.println("disconnecting.");
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
            Serial.println("click");
        }
        if (mass[0] == (uint8_t)1)
        {
            di->motorController->setDelayInjectoin(mass[1]);
        }
        if(mass[0] == (uint8_t)2)
        {
            di->motorController->setDelaySpark(mass[1]);
        }
        Serial.println("");
    }
    return {};

    tick();
}