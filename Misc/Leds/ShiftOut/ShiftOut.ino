void setup()
{
  for(int i = 0; i <= A5; i++)
  { pinMode(i, 1); }
  Serial.begin(9600);
}

int buffer[8][8] = {
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0}
};

void loop()
{
  for(int j = 0; j < 8; j++)
  {
    for(int i = 0; i < 8; i++)
    {
      ShiftY(j);
      ShiftX(i);
      delay(30);
    }
  }
  
  /*if(Serial.available() == 3)
  {
    int x = Serial.read()-'0';
    int y = Serial.read()-'0';
    int hl = Serial.read()-'0';
    buffer[x][y] = hl;
  }*/
  
}

void ShiftX(int data)
{
  digitalWrite(12, 0);
  if(data >= 0)
  shiftOut(10, 11, MSBFIRST, bit(data));
  else
  shiftOut(10, 11, MSBFIRST, 0);
  digitalWrite(12, 1);
}

void ShiftY(int data)
{
  int i = map(bit(data), 0, 255, 255, 0);
  digitalWrite(9, 0);
  if(data >= 0)
  shiftOut(7, 8, MSBFIRST, i);
  else
  shiftOut(7, 8, MSBFIRST, 0);
  digitalWrite(9, 1);
}
