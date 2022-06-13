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

<<<<<<< HEAD
  auto &di1 = DI::getInstance();
  di = &di1;

  di->enc = new Encoder(4, 5, 6, 7);
  di->motorController = new MotorController(di->enc);
  di->uiProg = new ConnectController();

  pinMode(2, INPUT_PULLUP);
=======
  DI::enc = new Encoder(4, 5, 6, 7);
  DI::motorController = new MotorController(DI::enc);
  DI::uiProg = new ConnectController();
>>>>>>> dccebb2c60249601675fea6e91a536e405ed23f3
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
<<<<<<< HEAD
  di->motorController->tick();


  // if (millis() - timeOut > 10)
  // {
=======
  DI::motorController->tick();
  //  if (millis() - timeOut > 10)
  //  {
>>>>>>> dccebb2c60249601675fea6e91a536e405ed23f3

  //   if (oldValueK != PINK || oldValueF != PINF)
  //   {

  //     oldValueK = PINK;
  //     oldValueF = PINF;

  //     uint8_t data[2] = {oldValueF, oldValueK};
  //     di->uiProg->send(data);
  //   }

  //   timeOut = millis();
  // }

<<<<<<< HEAD
  //di->uiProg->listen();
=======
  DI::uiProg->listen();
>>>>>>> dccebb2c60249601675fea6e91a536e405ed23f3
}