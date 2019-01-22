#include "TimeBlockFilter.h"
#include "ArduinoTimer.h"
#include "Arduino.h"

TimeBlockFilter::TimeBlockFilter(unsigned long int sperrzeitMikroSec)
{
   this->sperrzeitMikroSec = sperrzeitMikroSec;
   mikroSecLastEvent = 0;
}

bool TimeBlockFilter::checkEventAllowed()
{
   if (ArduinoTimer::isTimeMicrosecOver(sperrzeitMikroSec + mikroSecLastEvent))
   {
      mikroSecLastEvent = micros();
      return true;
   }
   else
   {
      return false;
   }
}

