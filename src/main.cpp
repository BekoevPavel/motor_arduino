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

  DI::enc = new Encoder(4, 5, 6, 7);
  DI::motorController = new MotorController(DI::enc);
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

  // unsigned long int ff = 547655 * 0.0001;
  Converter conv;
  uint16_t input = 1321;
  auto res = conv.toUInt8_Array(input);
  Serial.println("start:");
  for (int i = 0; i < 3; i++)
  {
    Serial.print(String(res[i]) + ".");
  }
  // Serial.println("first: " + String(res[1]) + " last: " + String(res[2]));
  // // uint8_t data[2] = res;
  // di->uiProg->send(res, 3);
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

  DI::uiProg->listen();
}