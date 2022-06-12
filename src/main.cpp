#include <Arduino.h>
#include <DI.hpp>

// old values
byte oldValueK = PINK;
byte oldValueF = PINF;

// timeouts
unsigned long int timeOut = 0;

DI *di;
void initDI()
{

  auto &di1 = DI::getInstance();
  di = &di1;

  di->enc = new Encoder(4, 5, 6, 7);
  di->motorController = new MotorController(di->enc);
  di->uiProg = new ConnectController();

  pinMode(2, INPUT_PULLUP);
}

void setup()
{
  Serial.begin(9600);
  initDI();
  //pinMode(6,INPUT_PULLUP);

  // DDRK = 0x00;
  // PORTK = B11111111;
  // DDRF = 0x00;

  // PORTF = B11111111;

  // DDRC = B11111111;
  // PORTC = B11111111;

  unsigned long int ff = 547655 * 0.0001;
  uint8_t ff1 = ff;
  Serial.println(String(ff1));
}

void loop()
{
  di->motorController->tick();


  // if (millis() - timeOut > 10)
  // {

  //   if (oldValueK != PINK || oldValueF != PINF)
  //   {

  //     oldValueK = PINK;
  //     oldValueF = PINF;

  //     uint8_t data[2] = {oldValueF, oldValueK};
  //     di->uiProg->send(data);
  //   }

  //   timeOut = millis();
  // }

  //di->uiProg->listen();
}