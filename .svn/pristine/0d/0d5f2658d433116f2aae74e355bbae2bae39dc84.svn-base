#ifndef _LogString_h_
#define _LogString_h_

#define MAX_ANZAHL_TEILSTRINGS 50   // Maximal 255 !!

class LogString
{
   //static const char hexChar[16];
   char* teilStrings[MAX_ANZAHL_TEILSTRINGS];
   char hexChar[16];
   unsigned char anzahlTeilStrings;
   unsigned int stringlength;

   void calculate();
   int  toInt(double d);
   void operator=(char* c){/*not allowed*/};

public:
   LogString();
   ~LogString();
   LogString(const char* text);
   void add(const char* text);
   void set(const char* text);
   void add1Byte(unsigned char b);
   void add2Byte(unsigned int b);
   void add4Byte(unsigned long int b);
   void add2ByteSigned(int b);
   void add4ByteSigned(long int b);
   void addDouble(double d);
   char* c_str();
   unsigned int length();
   void deleteMemory();
};

#endif

