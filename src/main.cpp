#include <Arduino.h>
#include <DI.hpp>
#include <converter.hpp>

// old values
// byte oldValueK = PINK;
// byte oldValueF = PINF;

// timeouts
unsigned long int timeOut = 0;

void initDI()
{
  // 1(5) - искра , 3(7) - Впрыск
  DI::enc = new Encoder(4, 5, 6, 7);
  DI::motorController = new MotorController(DI::enc, 22, 23);
  DI::uiProg = new ConnectController();
}

void setup()
{
  Serial.begin(9600);

  initDI();

  // DDRK = 0x00;
  // PORTK = B11111111;
  // DDRF = 0x00;

  // PORTF = B11111111;

  // DDRC = B11111111;
  // PORTC = B11111111;

  DI::motorController->setDelayInjectoin(2000);
  DI::motorController->setDelaySpark(1000);
}

void loop()
{
  DI::motorController->tick();
  //  if (millis() - timeOut > 10)
  //  {

  //   if (oldValueK != PINK || oldValueF != PINF)
  //   {

  //     oldValueK = PINK;
  //     oldValueF = PINF;

  //     uint8_t data[2] = {oldValueF, oldValueK};
  //     di->uiProg->send(data);
  //   }

  //   timeOut = millis();
  // }

  // DI::uiProg->listen();
}