#include <Arduino.h>
#include <DI.hpp>
#include <converter.hpp>
#include "stepper.hpp"

#define EN 13
#define DIR 12
#define PUL 11

#define DYNAMOMETR_PIN A0
#define STOP_STEPPER_PIN 19
// old values
// byte oldValueK = PINK;
// byte oldValueF = PINF;

// timeouts
unsigned long int timeOut = 0;

void initDI()
{
  // 1(3) - искра , 3(5) - Впрыск
  DI::enc = new Encoder(17, 18, 20);
  DI::motorController = new MotorController(DI::enc, 22, 23);
  DI::uiProg = new ConnectController();
  DI::stepper = new MyStepper(EN, PUL, DIR);
  DI::dynamometer = new Dynamometer(DYNAMOMETR_PIN, STOP_STEPPER_PIN);
}
InjectionController *injectionController = new InjectionController(9);
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

  // DI::motorController->setDelayInjectoin(2000);
  DI::motorController->setDelaySpark(2000);

  DI::motorController->setInjectionTime(1000);
  DI::motorController->setSparkTime(5);
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
  DI::dynamometer->tick();

  DI::uiProg->listen();
  DI::stepper->tick();
}