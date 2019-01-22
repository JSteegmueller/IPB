#include "PulsWeitenModulator.h"

PulsWeitenModulator::PulsWeitenModulator()
{
  onPWMSteps        = 1;
  numberOfPWMSteps  = 200;
  nextPWMStep       = 0;
}

void PulsWeitenModulator::setPWM_OnSteps_AllSteps(unsigned char onPWMSteps, unsigned char numberOfPWMSteps)
{
  this->onPWMSteps       = onPWMSteps;
  this->numberOfPWMSteps = numberOfPWMSteps;
  this->nextPWMStep = 0;
}

void PulsWeitenModulator::nextStep()
{
  nextPWMStep++;
  if (nextPWMStep >= numberOfPWMSteps)
  {
    nextPWMStep = 0;
  }
}

char PulsWeitenModulator::checkPWM()
{
  if (nextPWMStep < onPWMSteps)
  {
    nextStep();
    return 1;
  }
  else
  {
    nextStep();
    return 0;
  }
}


