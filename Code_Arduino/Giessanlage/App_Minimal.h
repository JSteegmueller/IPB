#ifndef _App_Minimal_h_
#define _App_Minimal_h_
#include "App_Base.h"



class App_Minimal : public App_Base
{
  public:
    App_Minimal();
    void appLoop();
    void appSetup();
    void appEvent(int idEvent);
    void durchflussHandeln();
    void pumpeSteuernEin();
    void pumpeSteuernAus();

    // Giessanlagen API
    void button(double kapazWasserbehaelter);
    void motorEin(bool trueFalse);
    void motorEinFuer(unsigned long int anzahlSekunden, int gepumptesWasserMl);
    void feuchteMessen(int anzahlSensoren);
    void checkWasser(int minWasser);



    
};

#endif





