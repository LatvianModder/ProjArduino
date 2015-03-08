int del = 1000;
int pin_down = 10;
int pin_up = 11;

void setup()
{
  Serial.begin(9600);
  pinMode(pin_down, OUTPUT);
  pinMode(pin_up, OUTPUT);
}

void loop()
{
  digitalWrite(pin_down, 0);
  digitalWrite(pin_up, 1);
  delayMicroseconds(del);
  digitalWrite(pin_down, 1);
  digitalWrite(pin_up, 0);
  delayMicroseconds(del);
  
  int serav = Serial.available();
  if(serav > 0)
  {
    String data = "";
    
    if(Serial.read() != '\n')
    data += (char)Serial.read();
    
    if(data.startsWith("dms"))
    del = data.substring(3).toInt();
    if(data.startsWith("ds"))
    del = 1000*data.substring(2).toInt();
  }
}
