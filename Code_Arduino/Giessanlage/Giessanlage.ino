#include "App_Minimal.h"
App_Minimal dieApp;

void setup()
{
  Serial.begin(9600);
  dieApp.setup();
}

void loop()
{
  dieApp.loop();
}


