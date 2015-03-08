int timeBeforeLastPulse = 0;
long pmillis = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(1, OUTPUT);
  pmillis = millis();
}

void loop()
{
  long l = millis();
  int i = l - pmillis;
  pmillis = l;
  
  timeBeforeLastPulse -= i;
  if(timeBeforeLastPulse < 0)
  timeBeforeLastPulse = 0;
  
  send("Hello test!");
  delay(100);
}

void send(String s)
{
  if(timeBeforeLastPulse == 0)
  { pulse(); timeBeforeLastPulse = 100; }
}

void pulse()
{
  digitalWrite(1, 1);
  delay(10);
  digitalWrite(1, 0);
  delay(10);
}
