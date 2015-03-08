int PHASE_A = 11;
int PHASE_B = 10;
int PHASE_C = 9;
//int PHASE_N = 5;

void setup()
{
  Serial.begin(9600);
  pinMode(PHASE_A, OUTPUT);
  pinMode(PHASE_B, OUTPUT);
  pinMode(PHASE_C, OUTPUT);
  //pinMode(PHASE_N, OUTPUT);
}

void loop()
{
  int d = 10;
  delay(d);
  setPhase(1, true, 0);
  delay(d);
  setPhase(2, true, 0);
  delay(d);
  setPhase(3, true, 0);
}

void setPhase(int j, boolean b, int i)
{
  if(j == 1)
  {
    digitalWrite(PHASE_A, b);
    digitalWrite(PHASE_B, !b);
    digitalWrite(PHASE_C, !b);
    delay(i);
  }
  if(j == 2)
  {
    digitalWrite(PHASE_A, !b);
    digitalWrite(PHASE_B, b);
    digitalWrite(PHASE_C, !b);
    delay(i);
  }
  if(j == 3)
  {
    digitalWrite(PHASE_A, !b);
    digitalWrite(PHASE_B, !b);
    digitalWrite(PHASE_C, b);
    delay(i);
  }
}
