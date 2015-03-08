#include <Ethernet.h>
#include <SPI.h>

byte mac[] = { 0x90, 0xA2, 0xDA, 0x00, 0x9B, 0x62 };
IPAddress ip(192, 168, 1, 177);

EthernetServer server(6245);

void setup()
{
  Serial.begin(9600);
  
  Ethernet.begin(mac, ip);
  server.begin();
  Serial.print("Server is at ");
  Serial.println(Ethernet.localIP());
}

void loop()
{
  EthernetClient client = server.available();
  if(client)
  {
    while(client.available() > 0)
    {
      Serial.print((char)client.read());
    }
  }
}
