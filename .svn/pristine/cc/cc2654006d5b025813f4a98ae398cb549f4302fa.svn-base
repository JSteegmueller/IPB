#include "LogString.h"
#include <string.h>
#include <math.h>

//const char LogString::hexChar[16]={'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

double ldabs(double d)
{
  if (d>0) return d;
  else     return -d;
}

LogString::LogString()
{
  anzahlTeilStrings = 0;
  stringlength      = 0;

  for(unsigned char i=0 ; i<10; i++)
  {
    hexChar[i]=(char)('0'+i);
  }

  for(unsigned char i=0 ; i<6; i++)
  {
    hexChar[i+10]=(char)('A'+i);
  }
}

LogString::LogString(const char* text)
{
  anzahlTeilStrings = 0;
  stringlength      = 0;
  for(unsigned char i=0 ; i<10; i++)
  {
    hexChar[i]=(char)('0'+i);
  }
  for(unsigned char i=0 ; i<6; i++)
  {
    hexChar[i+10]=(char)('A'+i);
  }
  add(text);
}

LogString::~LogString()
{
   deleteMemory();
}

void LogString::calculate()
{
   if (anzahlTeilStrings<2)
   {
     if (anzahlTeilStrings<1)
     {
       teilStrings[0]    = new char[1];
       (teilStrings[0])[0] = 0;
       anzahlTeilStrings = 1;
       stringlength      = 0;
       return;
     }
     else // =1
     {
       return;
     }
   }

   char* result = new char[stringlength+1];
   result[0]=0; // Falls nix kopiert wird!

   int anzahlZeichen = 0;
   for(int x=0; x<anzahlTeilStrings; x++)
   {
     strcpy(result+anzahlZeichen, teilStrings[x]);
     anzahlZeichen += strlen(teilStrings[x]);
   }

   deleteMemory();

   teilStrings[0]    = result;
   anzahlTeilStrings = 1;
   stringlength      = anzahlZeichen;
}

void LogString::add(const char* text)
{
  int len=strlen(text);
  teilStrings[anzahlTeilStrings] = new char[len+1];
  strcpy(teilStrings[anzahlTeilStrings], text); //Kopiert mit ENDE-Null
  anzahlTeilStrings++;
  stringlength += len;
}

char* LogString::c_str()
{
  calculate(); // Danach existiert mindestens teilStrings[0]
  return teilStrings[0];
}

void LogString::add1Byte(unsigned char b)
{
  char erg[3];
  erg[0] = hexChar[(b&0xF0)>>4];
  erg[1] = hexChar[(b&0x0F)   ];
  erg[2] = 0;
  add(erg);
}

void LogString::add2Byte(unsigned int b)
{
  add1Byte((b&0xFF00)>>8);
  add1Byte((b&0x00FF)   );
}

void LogString::add4Byte(unsigned long int b)
{
  add2Byte((b&0xFFFF0000)>>16);
  add(".");
  add2Byte((b&0x0000FFFF)    );
}

void LogString::add2ByteSigned(int b)
{
  if (b<0)
  {
    add("-");
    add2Byte(0xFFFF-b+1);
  }
  else
  {
    add2Byte(b);
  }
}

void LogString::add4ByteSigned(long int b)
{
  if (b<0)
  {
    add("-");
    add4Byte(0xFFFFFFFF-b+1);
  }
  else
  {
    add2Byte(b);
  }
}

void LogString::addDouble(double d)
{
  // 910
  long int expon;
  long int zahl;
  if(d>0)
  {
    expon = toInt(log10(d))-7;    // -5,... --> -5
    zahl  = toInt(d/pow(10, expon));  // 9.000.0000 
    add4Byte(zahl);
    add("^");
    add2ByteSigned(expon);  // 9.000.0000 * 10^-5
  }
  else
  {
    d=ldabs(d);
    expon = toInt(log10(d))-7;
    zahl  = toInt(d/pow(10, expon));
    add("-");
    add4Byte(zahl);
    add("^");
    add2ByteSigned(expon);
  }
}

int LogString::toInt(double d)
{
  if (d>0)
  {
    return d+0.5;
  }
  else
  {
    return d-0.5;
  }
}

unsigned int LogString::length()
{
  return stringlength;
}

void LogString::set(const char* text)
{
  deleteMemory();
  add(text);
}

void LogString::deleteMemory()
{
  for(int x=0; x<anzahlTeilStrings; x++)
   {
     delete[] teilStrings[x];
     teilStrings[x] = 0;
   }

   anzahlTeilStrings = 0;
   stringlength      = 0;
}


