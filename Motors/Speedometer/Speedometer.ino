long tick = 0;
boolean prevButton = false;

void setup()
{
  Serial.begin(9600);
  pinMode(12, INPUT);
  tick = millis();
}

void loop()
{
  boolean b = digitalRead(12) == 1;
  
  if(prevButton != b)
  {
    if(b);
    prevButton = b;
  }
}
