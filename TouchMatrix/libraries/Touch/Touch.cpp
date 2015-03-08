#include "Arduino.h"
#include "Touch.h"

Touch::Touch()
{
  tWidth = 128;
  tHeight = 64;
  
  minX = 90;
  minX = 910;
  maxY = 173;
  maxY = 830;
  
  pinY1 = A0;
  pinY0 = A1;
  pinX1 = A2;
  pinX0 = A3;
}
void update()
{
  boolean prevPressed = pressed;
  
  int rawX = getTouchX();
  int rawY = getTouchY();
  
  pressed = rawX > 3 && rawY > 3;
  
  int prevX = x;
  int prevY = y;
  
  x = map(rawX, minX, maxX, 0, tWidth);
  if(x < 0) x = 0; if(x >= tWidth) x = tWidth - 1;
  y = map(rawY, minY, maxY, 0, tHeight);
  if(y < 0) y = 0; if(y >= tHeight) y = tHeight - 1;
  
  dx = x - prevX;
  dy = y - prevY;
  
  if(prevPressed != pressed)
  {
    if(pressed)
    {
      startX = x;
      startY = y;
      onPressed();
    }
    else
    {
      onReleased();
      startX = startY = 0;
    }
  }
  
  if(pressed)
  whilePressed();
  else dx = dy = 0;
  
  delay(0.2);
}

ivate:
int getTouchX()
{
  pinMode(pinX0, OUTPUT);
  pinMode(pinX1, OUTPUT);
  pinMode(pinY0, OUTPUT);
  pinMode(pinY1, OUTPUT);
  
  digitalWrite(pinX0, 0);
  digitalWrite(pinY0, 0);
  digitalWrite(pinX1, 1);
  digitalWrite(pinY1, 0);
  
  pinMode(pinY0, INPUT);
  pinMode(pinY1, INPUT);
  
  delay(0.4);
  return analogRead(pinY0);
}

int getTouchY()
{
  pinMode(pinX0, OUTPUT);
  pinMode(pinX1, OUTPUT);
  pinMode(pinY0, OUTPUT);
  pinMode(pinY1, OUTPUT);
  
  digitalWrite(pinX0, 0);
  digitalWrite(pinY0, 0);
  digitalWrite(pinX1, 0);
  digitalWrite(pinY1, 1);
  
  pinMode(pinX0, INPUT);
  pinMode(pinX1, INPUT);
  
  delay(0.4);
  return analogRead(pinX0);
}
