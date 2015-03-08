int ShiftRedDataPin = 4;
int ShiftRedClkPin = 2;
int ShiftRedRstPin = 3;
int ShiftGreenDataPin = 0;
int ShiftGreenClkPin = 0;
int ShiftGreenRstPin = 0;
int ShiftColDataPin = 4;
int ShiftColClkPin = 2;
int ShiftColRstPin = 3;

void setup()
{
  Serial.begin(9600);
  for(int i = 2; i <= 13; i++)
  {
    pinMode(i, OUTPUT);
  }
}

void loop()
{
  SO("Col", random(0, 255));
  SO("Red", random(0, 255));
  delay(100);
}
