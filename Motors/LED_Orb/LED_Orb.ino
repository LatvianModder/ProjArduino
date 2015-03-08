int LedPin = 12;

int d = 100;

void setup()
{
  pinMode(LedPin, OUTPUT);
}

void loop()
{
  for(int i = 0; i < 1000; i++)
  {
    digitalWrite(LedPin, 1);
    delay(1);
    digitalWrite(LedPin, 0);
    delay(1);
  }
  for(int i = 0; i < 10; i++)
  {
    digitalWrite(LedPin, 1);
    delay(100);
    digitalWrite(LedPin, 0);
    delay(100);
  }
  
  digitalWrite(LedPin, 1);
    delay(1000);
    digitalWrite(LedPin, 0);
    delay(1000);
}
