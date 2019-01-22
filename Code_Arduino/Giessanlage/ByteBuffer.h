#ifndef _ByteBuffer_h_
#define _ByteBuffer_h_
// Ist der buffer zu klein, wird kein Schreibbefehl ausgefuehrt.

// #define BYTE_BUFFER_DEBUG

class ByteBuffer
{
  unsigned char* derBuffer;
  unsigned int bufferSize;
  unsigned int validBytes;

public:
  void setValidBytes(unsigned int anzahl){validBytes = anzahl;};
  unsigned int getValidBytes(){return validBytes;};
  ByteBuffer();
  unsigned char* getBuffer(unsigned int startIndex = 0){return &(derBuffer[startIndex]);};
  unsigned int size(){return bufferSize;};
  void setMinimumSize(unsigned int minSize);
  void copy_n_Byte(unsigned int quellStartIndex, unsigned int zielStartIndex, unsigned int anzahlBytes, unsigned char* byteArray);
  void setAt_1_Byte(unsigned int index, unsigned char einByte);
  void setAt_2_Byte(unsigned int index, unsigned int zweiByte);
  void setAt_4_Byte(unsigned int index, unsigned long int vierByte);
  void setAtHighLowNibble(unsigned int index, unsigned char highNibble, unsigned char lowNibble);
  unsigned char     getAt_1_Byte(unsigned int index);
  unsigned int      getAt_2_Byte(unsigned int index);
  unsigned long int getAt_4_Byte(unsigned int index);
  void getAt_someBytes( unsigned int index, 
                        unsigned char* b0, 
                        unsigned char* b1=0,
                        unsigned char* b2=0,
                        unsigned char* b3=0,
                        unsigned char* b4=0,
                        unsigned char* b5=0 );
  void getAtHighLowNibble(unsigned int index, unsigned char &highNibble, unsigned char &lowNibble);
  void copyBytesAt(unsigned int index, unsigned int anzahl, unsigned char* dieBytes);
  void          setBitAt(unsigned char startByteIndex, unsigned char bitOffset, unsigned char zeroOne); // 0,0 = MSB
  unsigned char getBitAt(unsigned char startByteIndex, unsigned char bitOffset);// 0,0 = MSB
};

#endif




