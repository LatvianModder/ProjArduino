#include <SD.h>

void setup()
{
  Serial.begin(9600);
  delay(1000);
  Serial.println("Checking SD card...");
  pinMode(53, OUTPUT);

  if (!SD.begin(53)) {
    Serial.println("SD card isn't plugged in!");
    return;
  }Serial.println("SD card found!");

  File myFile = SD.open("system.txt", FILE_READ);
  Serial.println("ATOS system params:");
  while(myFile.available())
  {
    Serial.write(myFile.read());
  }
  myFile.close();
  
  File myFile = SD.open("LOG.txt", FILE_READ);
  Serial.println("ATOS Log:");
  while(myFile.available())
  {
    Serial.write(myFile.read());
  }
  myFile.close();
}

void loop()
{
}
