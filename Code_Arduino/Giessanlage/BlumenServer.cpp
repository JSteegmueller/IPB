#include "BlumenServer.h"

#include "Dhcp.h"
#include "Dns.h"
#include "Ethernet.h"
#include "EthernetClient.h"
#include "EthernetServer.h"
#include "EthernetUdp.h"
#include "SPI.h"
#include "ByteBuffer.h"

void BlumenServer::begin()
{
  alreadyConnected = false;

  IPAddress ip(192,168,0,103);
  IPAddress myDns(127, 0, 0, 1);
  IPAddress gateway(192,168,0,1);
  IPAddress subnet(255, 255, 255, 0);
  byte mac[] = {
    0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED
  };

  client = new EthernetClient();
  server = new EthernetServer(123);


  // initialize the ethernet device
  Ethernet.begin(mac, ip, myDns, gateway, subnet);
  // start listening for clients
  server->begin();
  Serial.print("Chat server address:");
  Serial.println(Ethernet.localIP());
}


void BlumenServer::loop()
{
  // wait for a new client:
  if (!alreadyConnected)
  {
    *client = server->available();
    if (*client)
    {
      Serial.println("Neuer client");
      alreadyConnected = true;
    }
  }

  if (*client)
  {
    if (alreadyConnected)
    {
      if (client->available() > 0)
      {
        char thisChar = client->read();
        Serial.write(thisChar);
      }
    }
  }
}

void BlumenServer::sendData(ByteBuffer* derByteBuffer)
{
  if (*client)
  {
    client->write(derByteBuffer->getBuffer(), derByteBuffer->getValidBytes());
    client->flush();
    //Serial.println("Senden");
    //Serial.println((const char*)derByteBuffer->getBuffer());
  }
}

void BlumenServer::sendData(unsigned char* buf, unsigned int count)
{
  if (*client)
  {
    client->write(buf, count);
    client->flush();
    //Serial.println("Senden");
    //Serial.println((char*)buf);
  }
}

void BlumenServer::print(int i)
{
  sprintf(buffer, "%i", (int) i);
  sendData((unsigned char*)buffer, strlen(buffer));
}

void BlumenServer::print(const char* buffer)
{
  sendData((unsigned char*)buffer, strlen(buffer));
}

void BlumenServer::println(int i)
{
  sprintf(buffer, "%i\n", (int) i);
  sendData((unsigned char*)buffer, strlen(buffer));
}

void BlumenServer::println(const char* buf)
{
  if (*client)
  {
    client->write(buf, strlen(buf));
    client->write("\n", 1);
    client->flush();
    //Serial.println("Senden");
    //Serial.println((char*)buf);
  }
}
