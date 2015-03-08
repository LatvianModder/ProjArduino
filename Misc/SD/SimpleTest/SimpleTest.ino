#include <SD.h>

String buffer = "";

void setup()
{
  Serial.begin(9600);
  Serial.println("Initializing SD card...");
  
  pinMode(10, OUTPUT);

  if(SD.begin(4))
  Serial.println("Done!");
  else
  {
    Serial.println("Failed!");
    return;
  }
}

void loop()
{
  int i = Serial.read();
  
  if(i != -1)
  {
    if(i == '<') save();
    else buffer += (char)i;
    
    Serial.print((char)i);
  }
}

void save()
{
  File d = SD.open("TEST.txt", FILE_WRITE);
  
  d.println("Buffered text:");
  d.println(buffer);
  
  d.close();
  
  Serial.println();
  Serial.println("File saved!");
}
