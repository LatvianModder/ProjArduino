void Matrix(int data[])
{
}

void SO(String s, int data)
{
  if(s == "Col")
  {
    digiW(ShiftColRstPin, 1);
    shiftOut(ShiftColDataPin, ShiftColClkPin, LSBFIRST, data);
    digiW(ShiftColRstPin, 0);
  }
  else if(s == "Red")
  {
    digiW(ShiftRedRstPin, 1);
    shiftOut(ShiftRedDataPin, ShiftRedClkPin, LSBFIRST, data);
    digiW(ShiftRedRstPin, 0);
  }
  else if(s == "Green")
  {
    digiW(ShiftGreenRstPin, 1);
    shiftOut(ShiftGreenDataPin, ShiftGreenClkPin, LSBFIRST, data);
    digiW(ShiftGreenRstPin, 0);
  }
  else if(s == "Clear")
  {
    digiW(ShiftColRstPin, 1);
    digiW(ShiftRedRstPin, 1);
    digiW(ShiftGreenRstPin, 1);
    shiftOut(ShiftColDataPin, ShiftColClkPin, LSBFIRST, 0);
    shiftOut(ShiftRedDataPin, ShiftRedClkPin, LSBFIRST, 0);
    shiftOut(ShiftGreenDataPin, ShiftGreenClkPin, LSBFIRST, 0);
    digiW(ShiftColRstPin, 0);
    digiW(ShiftRedRstPin, 0);
    digiW(ShiftGreenRstPin, 0);
  }
}
