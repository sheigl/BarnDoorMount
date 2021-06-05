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
  app.onTimer1Interrupt();
}