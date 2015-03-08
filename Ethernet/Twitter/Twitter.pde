#include <SPI.h>
#include <Ethernet.h>

byte mac[] = { 0x90, 0xA2, 0xDA, 0x00, 0x9B, 0x62 };
IPAddress ip(192,168,1, 177);

EthernetServer server(80);

void setup()
{
  Ethernet.begin(mac, ip);
  server.begin();
}

void loop()
{
  EthernetClient client = server.available();
  if (client)
  {
    boolean currentLineIsBlank = true;
    while (client.connected())
    {
      if (client.available())
      {
        char c = client.read();
        if (c == '\n' && currentLineIsBlank)
        {
          // send a standard http response header
          client.println("HTTP/1.1 200 OK");
          client.println("Content-Type: text/html");
          client.println();
          
          client.print("Hello!");
          client.println("<br />");
          break;
        }
        if (c == '\n')
        currentLineIsBlank = true;
        else if (c != '\r')
        currentLineIsBlank = false;
      }
    }
    delay(1);
    client.stop();
  }
}
