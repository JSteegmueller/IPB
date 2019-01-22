#include "ByteArray2LongIntAndBack.h"

void ByteArray2LongIntAndBack::getHighLowNibble(unsigned char dasByte, unsigned char &highNibble, unsigned char &lowNibble)
{
  highNibble = (dasByte&0xF0)>>4;
  lowNibble  = (dasByte&0x0F);
}

void ByteArray2LongIntAndBack::getHighLowNibble(unsigned char* buffer, unsigned int index, unsigned char &highNibble, unsigned char &lowNibble)
{
  highNibble = (buffer[index]&0xF0)>>4;
  lowNibble  = (buffer[index]&0x0F);
}

void ByteArray2LongIntAndBack::setHighNibble(unsigned char* buffer, unsigned int index, unsigned char highNibble)
{
  buffer[index] = (buffer[index]&0x0F) + (highNibble<<4);
}

void ByteArray2LongIntAndBack::setHighLowNibble(unsigned char* buffer, unsigned int index, unsigned char highNibble, unsigned char lowNibble)
{
  buffer[index] = (highNibble<<4) + lowNibble;
}

void ByteArray2LongIntAndBack::setLowNibble(unsigned char* buffer, unsigned int index, unsigned char lowNibble)
{
  buffer[index] = (buffer[index]&0xF0) + lowNibble;
}

void ByteArray2LongIntAndBack::write_1_Byte(unsigned char* buffer, unsigned int index, unsigned char einByte)
{
  buffer[index] = einByte;
}

void ByteArray2LongIntAndBack::write_2_Byte(unsigned char* buffer, unsigned int index, unsigned int      zweiByte)
{
  (buffer[index+0] = (zweiByte & 0x0000FF00)>>8);
  (buffer[index+1] = (zweiByte & 0x000000FF)>>0);
}

void ByteArray2LongIntAndBack::write_4_Byte(unsigned char* buffer, unsigned int index, unsigned long int val)
{
  (buffer[index+0] = (val & 0xFF000000)>>24);
  (buffer[index+1] = (val & 0x00FF0000)>>16);
  (buffer[index+2] = (val & 0x0000FF00)>>8 );
  (buffer[index+3] = (val & 0x000000FF)>>0 );
}

unsigned char ByteArray2LongIntAndBack::read_1_Byte(unsigned char* buffer, unsigned int index)
{
  return buffer[index+0];
}

unsigned int ByteArray2LongIntAndBack::read_2_Byte(unsigned char* buffer, unsigned int index)
{
  return (((unsigned int)buffer[index+0])<<8 )
    + (((unsigned int)buffer[index+1])<<0 );
};

unsigned long int ByteArray2LongIntAndBack::read_4_Byte(unsigned char* buffer, unsigned int index)
{
  return (((unsigned long int)buffer[index+0])<<24)
    + (((unsigned long int)buffer[index+1])<<16)
      + (((unsigned long int)buffer[index+2])<<8 )
        + (((unsigned long int)buffer[index+3])<<0 );
}
