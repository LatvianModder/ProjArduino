#include <SoftwareSerial.h>
int TX_GND = 19;
int TX_VCC = 17;
int TX_IN  = 16;
int TX_OUT = 18;
SoftwareSerial Serial1(TX_IN, TX_OUT);

void setup()
{
  Serial.begin(19200);
  Serial1.begin(19200);
  
  pinMode(TX_GND, OUTPUT);
  pinMode(TX_VCC, OUTPUT);
  
  digitalWrite(TX_GND, 0);
  digitalWrite(TX_VCC, 1);
}

void loop()
{
  while(Serial.available())
  Serial1.write(Serial.read());
  
  delay(3);
}
