boolean redBuffer[8][8];
boolean greenBuffer[8][8];

const int pinRedData = 2;
const int pinRedReset = 3;
const int pinRedClock = 4;

const int pinGreenData = 5;
const int pinGreenReset = 6;
const int pinGreenClock = 7;

const int pinBuzzer = 8;
const int pinLineReset = 9;
const int pinLineClock = 10;

void initMatrix()
{
  pinMode(pinRedData, OUTPUT);
  pinMode(pinRedReset, OUTPUT);
  pinMode(pinRedClock, OUTPUT);
  
  pinMode(pinGreenData, OUTPUT);
  pinMode(pinGreenReset, OUTPUT);
  pinMode(pinGreenClock, OUTPUT);
  
  pinMode(pinLineReset, OUTPUT);
  pinMode(pinLineClock, OUTPUT);
  
  setBitmap(bit_smiley);
}

int testTick = 0;

void processMatrix()
{
  //setBitmap(bit_smiley, touchX / 6);
  
  //if(sleep(100))
  {
    for(int y = 0; y < 8; y++)
    {
      int redData = 0;
      int greenData = 0;
      
      for(int x = 0; x < 8; x++)
      {
        redData += redBuffer[x][y] ? (1 << x) : 0;
        greenData += greenBuffer[x][y] ? (1 << x) : 0;
      }
      
      digitalWrite(pinRedReset, 0);
      shiftOut(pinRedData, pinRedClock, MSBFIRST, redData);
      digitalWrite(pinRedReset, 1);
      
      digitalWrite(pinGreenReset, 0);
      shiftOut(pinGreenData, pinGreenClock, MSBFIRST, greenData);
      digitalWrite(pinGreenReset, 1);
      
      delay(1);
      
      digitalWrite(pinRedReset, 0);
      shiftOut(pinRedData, pinRedClock, MSBFIRST, 0);
      digitalWrite(pinRedReset, 1);
      
      digitalWrite(pinGreenReset, 0);
      shiftOut(pinGreenData, pinGreenClock, MSBFIRST, 0);
      digitalWrite(pinGreenReset, 1);
      
      digitalWrite(pinLineClock, 1);
      delay(0.1);
      digitalWrite(pinLineClock, 0);
    }
    
    digitalWrite(pinLineReset, 1);
    delay(0.05);
    digitalWrite(pinLineReset, 0);
  }
}

void setPixel(int x, int y, int col)
{
  boolean red = (col == RED || col == YELLOW);
  boolean green = (col == GREEN || col == YELLOW);
  
  redBuffer[x][y] = red;
  greenBuffer[x][y] = green;
}

void setBitmap(int pixels[8][8])
{ setBitmap(pixels, 0); }

void setBitmap(int pixels[8][8], int shift)
{
  shift %= 8;
  
  for(int y = 0; y < 8; y++)
  for(int x = 0; x < 8; x++)
  setPixel((x + shift) % 8, y, pixels[y][x]);
}

void buzzer(int hz)
{
  if(hz <= 0) noTone(pinBuzzer);
  else tone(pinBuzzer, hz);
}

void clearScreen()
{
  for(int y = 0; y < 8; y++)
  for(int x = 0; x < 8; x++)
  {
    redBuffer[x][y] = 0;
    greenBuffer[x][y] = 0;
  }
}
