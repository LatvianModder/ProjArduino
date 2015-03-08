int dataPin = 12;
int clkPin = 11;
int rstPin = 10;
int line[] = {64,128,16,32,4,8,1,2};

int smileHappy[] = {B00000000,B01100110,B01100110,B00000000,B10000001,B01000010,B00111100,B00000000};
int smileSad[] = {B00000000,B01100110,B01100110,B00000000,B00111100,B01000010,B10000001,B00000000};
int smileAngry[] = {B00000000,B01000010,B00100100,B00000000,B00111100,B01000010,B10000001,B00000000};
int smileSuprised[] = {B00000000,B01100110,B01100110,B00000000,B00111100,B01000010,B00111100,B00000000};
int logo[] = {B00000000,B01000010,B00111100,B01111110,B11011011,B11111111,B00100100,B00100100};

void setup()
{
  pinMode(dataPin, OUTPUT);
  pinMode(clkPin, OUTPUT);
  pinMode(rstPin, OUTPUT);
}

void loop()
{
  shift(logo[4], line[0]);
}

void shift(int rowData, int colData)
{
  digitalWrite(rstPin, 1);
  shiftOut(dataPin, clkPin, MSBFIRST, colData);
  shiftOut(dataPin, clkPin, LSBFIRST, rowData);
  digitalWrite(rstPin, 0);
}
