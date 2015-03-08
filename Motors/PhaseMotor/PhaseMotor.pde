int phase1 = 14;
int phase2 = 15;
int phase3 = 16;

void setup()
{
  pinMode(phase1, OUTPUT);
  pinMode(phase2, OUTPUT);
  pinMode(phase3, OUTPUT);
  Serial.begin(9600);
}

int d = 75;

void loop()
{
  if(Serial.available()>0)
  {
    String s = "";
    for(int i = 0; i < Serial.available(); i++)
    s += (char)Serial.read();
    d = s.toInt();
  }
  
  digitalWrite(phase1, HIGH);
  delay(d);
  digitalWrite(phase3, LOW);
  delay(d);
  digitalWrite(phase2, HIGH);
  delay(d);
  digitalWrite(phase1, LOW);
  delay(d);
  digitalWrite(phase3, HIGH);
  delay(d);
  digitalWrite(phase2, LOW);
  delay(d);
}
