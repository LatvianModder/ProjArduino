#include <IRremote.h>

IRrecv irrecv(11);
decode_results results;

int UP = 154;
int DOWN = 2202;
int LEFT = 3216;
int RIGHT = 1168;
int RED = 2682;
int GREEN = 3194;
int BLUE = 442;
int YELLOW = 634;
int UPMODE = 2394;
int DOWNMODE = 346;
int NUM_1 = 26;
int NUM_2 = 2074;
int NUM_3 = 1050;
int ONOFF = 2714;

int mode = 0;
int colormode = 0;
int brightness = 255;
int redvalue = 0;
int greenvalue = 0;
int bluevalue = 0;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn();
}

void checkIR()
{
  if(irrecv.decode(&results))
  {
    int data = results.value;
    irrecv.resume();
    if(data != 0)
    {
      Serial.print("Readed data: ");
      Serial.println(data);
      onReceived(data);
    }
  }
}

void loop()
{
  checkIR();
  
  if(brightness < 10) brightness = 10;
  if(brightness > 255) brightness = 255;
  if(redvalue < 0) redvalue = 0;
  if(redvalue > 255) redvalue = 255;
  if(greenvalue < 0) greenvalue = 0;
  if(greenvalue > 255) greenvalue = 255;
  if(bluevalue < 0) bluevalue = 0;
  if(bluevalue > 255) bluevalue = 255;
  
  if(mode == 0)
  {
    float m = millis() * 0.0007F;
    int i = brightness / 2;
    
    setRed(i+sin(m*5)*i);
    setGreen(i+sin(m*3)*i);
    setBlue(i+sin(m*7)*i);
  }
  else if(mode == 1)
  {
  }
  else if(mode == 2)
  {
    setAll(0);
    
    for(int i = 0; i < 100; i+=3)
    { setRed(i); delay(30); }
    for(int i = 100; i > 0; i-=3)
    { setRed(i); delay(30); }
    
    checkIR();
    setAll(0);
    
    for(int i = 0; i < 100; i+=3)
    { setGreen(i); delay(30); }
    for(int i = 100; i > 0; i-=3)
    { setGreen(i); delay(30); }
    
    checkIR();
    setAll(0);
    
    for(int i = 0; i < 100; i+=3)
    { setBlue(i); delay(30); }
    for(int i = 100; i > 0; i-=3)
    { setBlue(i); delay(30); }
    
    checkIR();
    setAll(0);
    
    int d = 400;
    
    checkIR();
    
    delay(d); setRed(255); delay(d); setAll(0);
    delay(d); setGreen(255); delay(d); setAll(0);
    delay(d); setBlue(255); delay(d); setAll(0);
    
    checkIR();
    
    delay(d); setRgb(255, 0, 255); delay(d); setAll(0);
    delay(d); setRgb(255, 255, 0); delay(d); setAll(0);
    delay(d); setRgb(0, 255, 255); delay(d); setAll(0);
    
    checkIR();
  }
}
void setAll(float f) { setRed(f); setGreen(f); setBlue(f); }
void setRed(float f) { if(f>=0&&f<=255) analogWrite(9, (int)f); }
void setGreen(float f) { if(f>=0&&f<=255) analogWrite(5, (int)f); }
void setBlue(float f) { if(f>=0&&f<=255) analogWrite(6, (int)f); }
void setRgb(float r, float g, float b)
{ setRed(r); setBlue(b); setGreen(g); }

void onReceived(int data)
{
  int step = 10;
  
  if(data == NUM_1) mode = 0;
  else if(data == NUM_2) mode = 1;
  else if(data == NUM_3) mode = 2;
  else if(data == UP)
  {
    if(mode == 0) brightness+=step;
    else if(mode == 1)
    {
      if(colormode == 0) redvalue+=step;
      else if(colormode == 1) greenvalue+=step;
      else if(colormode == 2) bluevalue+=step;
    }
  }
  else if(data == DOWN)
  {
    if(mode == 0) brightness-=step;
    else if(mode == 1)
    {
      if(colormode == 0) redvalue-=step;
      else if(colormode == 1) greenvalue-=step;
      else if(colormode == 2) bluevalue-=step;
    }
  }
  
  if(mode == 1)
  {
    setAll(0);
    if(data == RED) setRed(255);
    else if(data == GREEN) setGreen(255);
    else if(data == BLUE) setBlue(255);
    else if(data == YELLOW) setRgb(255, 128, 0);
  }
}
