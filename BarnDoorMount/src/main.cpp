
/*
  SilentStepStick TMC2208/TMC2209 Example
  Rsense: 0.11 Ohm

  Other examples/libraries can be found here:
  https://github.com/teemuatlut/TMCStepper
  https://github.com/trinamic/TMC-API
  https://github.com/manoukianv/TMC2208Pilot

  Example source code free to use.
  Further information: https://learn.watterott.com/license/
*/

#include <Arduino.h>
#include <jled.h>
#include "BarnDoorMountApp.h"

BarnDoorMountApp app = BarnDoorMountApp();

void setup()
{
  app.setup();
}

void loop()
{
  app.loop();  
}

ISR(TIMER1_COMPA_vect)
{
  PORTB
}