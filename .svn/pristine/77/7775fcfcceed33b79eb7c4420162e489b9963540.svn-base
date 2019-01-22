#ifndef _BlumenServer_h
#define _BlumenServer_h

class EthernetClient;
class EthernetServer;
class ByteBuffer;

class BlumenServer
{
  private:
    EthernetClient* client;
    EthernetServer* server;
    char buffer[10];
    bool alreadyConnected; // whether or not the client was connected previously

  public:
    void begin();
    void loop();
    void sendData(ByteBuffer* derByteBuffer);
    void sendData(unsigned char* buf, unsigned int count);
    void print(int i);
    void print(const char* buffer);
    void println(int i);
    void println(const char* buf);

};
#endif
