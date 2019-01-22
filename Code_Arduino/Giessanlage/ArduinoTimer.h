#ifndef _ArduinoTimer_h_
#define _ArduinoTimer_h_

class ArduinoTimer
{
    unsigned char myID;
    unsigned int  swapsRemaining;  // Der Timer zaehlt bei jedem erfolgreichen checkSwapChange() diese Wert zurueck bis auf 0.
    unsigned long intervalTimeMicroSec;
    unsigned long nextTime;
    bool ersterAufruf;

  public:
    ArduinoTimer();

    // ID ist nur für den Anwender, die ID hat 
    // keinerlei Einfluss auf das Timer-Vrhalten.
    void setID(unsigned char dieID) {myID = dieID;};
    unsigned char getID() {return myID;};

    // Prüft ob der angegebene Zeitpunkt bereits in der Vergangenheit liegt
    static bool isTimeMicrosecOver(unsigned long int timeMicroSec); 

    void setIntervalTimeMicroSec(unsigned long int intervalTimeMicroSec, unsigned int nTimes = 0); 
    // checkSwapChange() liefert immer 0, wenn intervalTimeMicroSec = 0. (=stop)
    // nTimes beeinflusst das Timer-Verhalten nur in folgender Sache:
    // Wenn nTimes=0, dann läuft Zeitperiode erst beim nächsten checkSwapChange() los, andernfalls sofort.
    unsigned long getIntervalTimeMicroSec(){return intervalTimeMicroSec;};

    int checkSwapChange(); // Liefert ein mal eine 1, wenn Periode zu ende.
    int getSwapsRemaining() {return swapsRemaining;};
};

#endif



