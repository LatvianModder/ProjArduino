void setup()
{
  Serial.begin(9600);
  pinMode(13, INPUT);
}

void loop()
{
  Serial.println(digitalRead(13));
  delay(10);
}
