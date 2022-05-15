#ifndef connect_hpp
#define connect_hpp

#include <Arduino.h>
#include <Ethernet2.h>
#include <SPI.h>

class ConnectController
{
public:
    ConnectController();

    // func
public:
    void send(uint8_t *data, int _lenght);

    uint8_t *listen();

private:
    void tick();
    byte mac[6] = {0xBE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED};
    byte ip[4] = {192, 168, 0, 177};
    byte server[4] = {192, 168, 0, 2}; // Touchberry Pi Server
    int tcp_port = 2400;
    EthernetClient client;


};
#endif