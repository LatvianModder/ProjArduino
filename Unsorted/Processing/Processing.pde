void setup()
{
  Serial.begin(9600);
}

void loop()
{
  if(Serial.read() != -2)
  {
    Serial.print(Serial.read(), BYTE);
  }
}
