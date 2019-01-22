#ifndef _ByteArray2LongIntAndBack_h_
#define _ByteArray2LongIntAndBack_h_

// Im Arduino-C++ gilt:
// char ... 1 Byte
// int  ... 2 Byte
// long ... 4 Byte

// Im Borland mit 32 Bit Betriebssystem gilt:
// int  ... 4 Byte

class ByteArray2LongIntAndBack
{
public:
  static void getHighLowNibble(unsigned char dasByte, unsigned char &highNibble, unsigned char &lowNibble);
  static void getHighLowNibble(unsigned char* buffer, unsigned int index, unsigned char &highNibble, unsigned char &lowNibble);
  static void setHighNibble   (unsigned char* buffer, unsigned int index, unsigned char highNibble);
  static void setLowNibble    (unsigned char* buffer, unsigned int index, unsigned char lowNibble);
  static void setHighLowNibble(unsigned char* buffer, unsigned int index, unsigned char highNibble, unsigned char lowNibble);

  static void write_1_Byte(unsigned char* buffer, unsigned int index, unsigned char     einByte);
  static void write_2_Byte(unsigned char* buffer, unsigned int index, unsigned int      zweiByte);
  static void write_4_Byte(unsigned char* buffer, unsigned int index, unsigned long int vierByte);
  static unsigned char     read_1_Byte(unsigned char* buffer, unsigned int index);
  static unsigned int      read_2_Byte(unsigned char* buffer, unsigned int index);
  static unsigned long int read_4_Byte(unsigned char* buffer, unsigned int index);
};

#endif

