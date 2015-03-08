#include <Ethernet.h>
#include <SPI.h>

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
byte ip[] = { 168, 192, 0, 151 };
byte server[] = { 168, 192, 0, 1 };

EthernetClient client;

void setup()
{
  Serial.begin(9600);
  Ethernet.begin(mac, ip);
  delay(100);
  Serial.println("Connecting...");
  int startTime = millis();

  if (client.connect(server, 80))
  {
    Serial.println("Connection created in ");
    Serial.print((millis() - startTime) * 0.001);
    Serial.println(" seconds!");
  }
  else Serial.println("Connection failed!");
}

void loop()
{
  if(millis() % 1000 == 0) client.write("Test!");
}
