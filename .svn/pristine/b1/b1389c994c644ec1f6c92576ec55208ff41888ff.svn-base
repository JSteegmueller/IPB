#include "App_Minimal.h"
#include "Arduino.h"
#include "ChatterPin.h"
#include "LogString.h"
#include "BlumenServer.h"

#define RELAIS_PIN 42
#define RELAIS_AUS 0
#define RELAIS_EIN 1
#define FEUCH_S1 A15
#define FEUCH_S2 A14
#define FEUCH_S3 A13
#define PUMPE_EIN 1
#define PUMPE_AUS 0
#define LED_PIN 36
#define BUTTON_PIN 5
#define BID 40

int eventTimer, minutenTimerGiessen, minutenTimerGiessen2, messTimer, pumpenTimer, wasserMliter;
int eventButton;
int eventRelaisAus;
bool feuchtemessungZuTrocken;
bool zuWenigWasser;
double feuchte1, feuchteDur;
double test;
int messwert, minutenTimerMessen;
int i;

BlumenServer blume1;



void App_Minimal::feuchteMessen(int anzahlSensoren)
{
  if ( anzahlSensoren == 1)
  {
    feuchte1 = analogRead(FEUCH_S1);
    feuchtemessungZuTrocken = ( feuchte1 > 0 );
    i++;
    blume1.print(i);
    blume1.print(";");
    blume1.print(feuchte1);
    blume1.println(";");
    Serial.println("SendeDaten");

    if ( i == 3)
    {
       blume1.print("<ende>");
    }
  }

  if ( anzahlSensoren == 2)
  {
    double feuchte1, feuchte2;
    feuchte1 = analogRead(FEUCH_S1);
    feuchte2 = analogRead(FEUCH_S2);
    feuchteDur = ((feuchte1 + feuchte2 ) / 2); //Durchschnitt aller 2 Messerte
    feuchtemessungZuTrocken = ( feuchteDur == 0 );
    i++;
    Serial.print(i);
    Serial.print(";");
    Serial.print(feuchteDur);
    Serial.println(";");
  }

  if ( anzahlSensoren == 3)
  {
    double feuchte1, feuchte2, feuchte3;
    feuchte1 = analogRead(FEUCH_S1);
    feuchte2 = analogRead(FEUCH_S2);
    feuchte3 = analogRead(FEUCH_S3);
    feuchteDur = ((feuchte1 + feuchte2 + feuchte3) / 3); //Durchschnitt aller 3 Messerte
    feuchtemessungZuTrocken = ( feuchteDur == 0 );
    //Serial.println(feuchteDur);
  }

  if (messTimer > 0)
  {
    messTimer--;
  }
}



// Beim Programmstart vor dem Booten
App_Minimal::App_Minimal()
{
  minutenTimerGiessen = 0;
  messTimer = 0;
  eventTimer = 0;
  eventButton = 0;
  pumpenTimer = 0;
  wasserMliter = 500;
  minutenTimerGiessen = 0;
  eventRelaisAus = 0;
  minutenTimerGiessen2 = 0;
  feuchtemessungZuTrocken = false;
  zuWenigWasser = false;
  messwert = 0;
  i = 0;
}

// Beim Programmstart nach dem Booten
void App_Minimal::appSetup()
{
  eventTimer  =  setTimerInterrupt(10000000);

  eventButton = setPinInterrupt( BUTTON_PIN, INPUT_PULLUP, TRIGGER_UP);

  //setHeartBeatPin(0);
  pinMode(RELAIS_PIN, OUTPUT);
  pinMode(FEUCH_S1, INPUT);
  pinMode(FEUCH_S2, INPUT);
  pinMode(FEUCH_S3, INPUT);
  pinMode(LED_PIN, OUTPUT);
  pinMode(13, OUTPUT);
  blume1.begin();
}

void App_Minimal::appLoop()
{
  //digitalWrite(13, digitalRead(38));
    blume1.loop();
  //blume1.print("HALLO");


}

void App_Minimal::button(double kapazWasserbehaelter)
{
  wasserMliter = kapazWasserbehaelter;
  digitalWrite(LED_PIN, 0);
  Serial.println ("BUTTON");
  zuWenigWasser = false;
}

void App_Minimal::checkWasser(int minWasser)
{
  if ( wasserMliter < minWasser )
  {
    digitalWrite(LED_PIN, 1);
    zuWenigWasser = true;
  }
}


void App_Minimal::motorEinFuer(unsigned long int anzahlSekunden, int gepumptesWasserMl)
{
  eventRelaisAus = setTimerInterrupt(anzahlSekunden * 1000000, 1);
  motorEin(true);
  wasserMliter = wasserMliter - gepumptesWasserMl;
}

void App_Minimal::motorEin(bool trueFalse)
{
  if (trueFalse == true)
  {
    digitalWrite(RELAIS_PIN, RELAIS_EIN);
  }
  else
  {
    digitalWrite(RELAIS_PIN, RELAIS_AUS);
  }
}

// Wird immer dann aufgerufen
void App_Minimal::appEvent(int idEvent)
{
  if (idEvent == eventButton)
  {
    //digitalWrite(13, 1);
    button(200);
  }
  if (idEvent == eventRelaisAus)
  {
    motorEin(false);
  }
  if (idEvent == eventTimer)
  {
    if (getBoardID(BID, 1) == 1)
    {
      minutenTimerGiessen++;
      Serial.println("Giessen");
      //Serial.println(minutenTimerGiessen);
      if ( minutenTimerGiessen == 120 ) //55-Minuetig = 329
      {
        messTimer = 2;
      }
      if ( messTimer > 0 )
      {
        feuchteMessen(1);
        //messwert = feuchteDur * 10 ;
        //write(10, 5, messwert);
        messTimer--;
      }
      if ( minutenTimerGiessen > 359 ) //Stuendlich = 359
      {
        if ( feuchtemessungZuTrocken == true && zuWenigWasser == false )
        {
          motorEinFuer(5, 100);
          checkWasser(100);
        }
        minutenTimerGiessen = 0;
      }
    }
    if (getBoardID(BID, 1) == 0)
    {
      Serial.println("Messen");
      minutenTimerGiessen2++;
      minutenTimerMessen++;
      if  (minutenTimerGiessen2 == 360 )
      {
        motorEinFuer(5, 100);
        checkWasser(100);
        minutenTimerGiessen2 = 0;
      }
      if (minutenTimerMessen > 89 )
      {
        messTimer = 3;
        minutenTimerMessen = 0;
      }
      if ( messTimer > 0 )
      {
        feuchteMessen(1);
        //messwert = feuchteDur * 10 ;
        //write(10, 5, messwert);
        messTimer--;
      }
    }
  }
}






