#include "ByteBuffer.h"
#include <string.h>
#include "ByteArray2LongIntAndBack.h"

ByteBuffer::ByteBuffer()
{
  bufferSize = 1;
  derBuffer = new unsigned char[bufferSize];
  validBytes = 0; 
}

void ByteBuffer::setMinimumSize(unsigned int minimumSize)
{
#ifdef BYTE_BUFFER_DEBUG
  minimumSize +=100;
#endif

  if (bufferSize < minimumSize)
  {
    delete[] derBuffer;
    derBuffer = new unsigned char[minimumSize];
    bufferSize = minimumSize;
  }

#ifdef BYTE_BUFFER_DEBUG
  for (unsigned int i=0; i<bufferSize; i++)
  {
    derBuffer[i]='X';
  }
#endif

}

void ByteBuffer::copyBytesAt(unsigned int index, unsigned int anzahl, unsigned char* dieBytes)
{
  if (index+anzahl >= bufferSize) return;
  for (unsigned int i=0; i<anzahl; i++)
  {
    derBuffer[index+i] = dieBytes[i];
  }
}

void ByteBuffer::getAtHighLowNibble(unsigned int index, unsigned char &highNibble, unsigned char &lowNibble)
{
  if (index >= bufferSize) return;
  ByteArray2LongIntAndBack::getHighLowNibble(derBuffer, index, highNibble, lowNibble);
}

unsigned char ByteBuffer::getAt_1_Byte(unsigned int index)
{
  if (index >= bufferSize) return 0;
  return ByteArray2LongIntAndBack::read_1_Byte(derBuffer, index);
};

unsigned int ByteBuffer::getAt_2_Byte(unsigned int index)
{
  if (index >= bufferSize) return 0;
  return ByteArray2LongIntAndBack::read_2_Byte(derBuffer, index);
}

unsigned long int ByteBuffer::getAt_4_Byte(unsigned int index)
{
  if (index >= bufferSize) return 0;
  return ByteArray2LongIntAndBack::read_4_Byte(derBuffer, index);
}

void ByteBuffer::setAtHighLowNibble(unsigned int index, unsigned char highNibble, unsigned char lowNibble)
{
  if (index >= bufferSize) return;
  ByteArray2LongIntAndBack::setHighLowNibble(derBuffer, index, highNibble, lowNibble);
}

void ByteBuffer::setAt_1_Byte(unsigned int index, unsigned char einByte)
{
  if (index >= bufferSize) return;
  derBuffer[index]=einByte;
}

void ByteBuffer::setAt_2_Byte(unsigned int index, unsigned int zweiByte)
{
  if (index >= bufferSize) return;
  ByteArray2LongIntAndBack::write_2_Byte(derBuffer, index, zweiByte);
}

void ByteBuffer::setAt_4_Byte(unsigned int index, unsigned long int vierByte)
{
  if (index >= bufferSize) return;
  ByteArray2LongIntAndBack::write_4_Byte(derBuffer, index, vierByte);
}

void ByteBuffer::getAt_someBytes( unsigned int index,
                                  unsigned char* b0,
                                  unsigned char* b1,
                                  unsigned char* b2,
                                  unsigned char* b3,
                                  unsigned char* b4,
                                  unsigned char* b5 )
{
              *b0 = getAt_1_Byte(index+0);
   if (b1!=0) *b1 = getAt_1_Byte(index+1);
   if (b2!=0) *b2 = getAt_1_Byte(index+2);
   if (b3!=0) *b3 = getAt_1_Byte(index+3);
   if (b4!=0) *b4 = getAt_1_Byte(index+4);
   if (b5!=0) *b5 = getAt_1_Byte(index+5);
}

void ByteBuffer::setBitAt(unsigned char startByteIndex, unsigned char bitOffset, unsigned char zeroOne)
{
  unsigned char bitIndex     = bitOffset % 8; // 7..0
  unsigned char byteIndex    = (bitOffset / 8) + startByteIndex;

  if (zeroOne == 1)
  {
     setAt_1_Byte(byteIndex, getAt_1_Byte(byteIndex) | (1<<bitIndex) );
  }
  else
  {
     setAt_1_Byte(byteIndex, getAt_1_Byte(byteIndex) & (0xFF-(1<<bitIndex)) );
  }
};

unsigned char ByteBuffer::getBitAt(unsigned char startByteIndex, unsigned char bitOffset) // 0 = MSB
{
  unsigned char bitIndex     = bitOffset % 8; // 7..0
  unsigned char byteIndex    = (bitOffset / 8) + startByteIndex;

  if ((getAt_1_Byte(byteIndex) & (1<<bitIndex)) > 0)
  {
     return 1;
  }
  else
  {
     return 0;
  }
}

void ByteBuffer::copy_n_Byte(unsigned int quellStartIndex, unsigned int zielStartIndex, unsigned int anzahlBytes, unsigned char* byteArray)
{
  memcpy(&(derBuffer[zielStartIndex]), &(byteArray[quellStartIndex]), anzahlBytes);   
}

