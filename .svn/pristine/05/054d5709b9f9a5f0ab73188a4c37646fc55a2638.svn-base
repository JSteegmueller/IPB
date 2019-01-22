#include "ArduinoTimer.h"
#include "arduino.h"
#include "App_Base.h"

#define ARDUINOTIMER_ENDLESS 0xFF

ArduinoTimer::ArduinoTimer()
{
  myID = 0;
  intervalTimeMicroSec = 0;
  nextTime             = 0;
  ersterAufruf         = true;
  swapsRemaining       = ARDUINOTIMER_ENDLESS;
}

void ArduinoTimer::setIntervalTimeMicroSec(unsigned long int intervalTimeMicroSec, unsigned int nTimes)
{
  if (nTimes == 0)
  {
    swapsRemaining = ARDUINOTIMER_ENDLESS;
  }
  else
  {
    swapsRemaining = nTimes;
  }

  this->intervalTimeMicroSec = intervalTimeMicroSec;
  
  if (nTimes == 0)
  {
     ersterAufruf = true;
  }
  else
  {
     ersterAufruf = false;
     unsigned long int microSeconds = micros();
     nextTime = microSeconds + intervalTimeMicroSec;
  }
}

int ArduinoTimer::checkSwapChange()
{
  if (intervalTimeMicroSec == 0) return 0;

  if (ersterAufruf)
  {
    ersterAufruf = false;
    unsigned long int microSeconds = micros();
    nextTime = microSeconds + intervalTimeMicroSec;
    return 0;
  }
  else if (isTimeMicrosecOver(nextTime)) 
  {
    nextTime += intervalTimeMicroSec;
    if (swapsRemaining != ARDUINOTIMER_ENDLESS)
    {
      if (swapsRemaining > 0) swapsRemaining--;
    }
    return 1;
  }
  else
  {
    return 0;
  }
}

//static// // klappt auch bei Ueberlauf !  Siehe .\Timerueberlauf.txt
bool ArduinoTimer::isTimeMicrosecOver(unsigned long int timeMicroSec)
{
  long int delta = micros() - timeMicroSec;
  return (delta >= 0); // klappt auch bei Ueberlauf !  Siehe .\Timerueberlauf.txt
}
