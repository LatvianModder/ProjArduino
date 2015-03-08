#include <ps2.h>
PS2Mouse mouse(3, 2);

void setup()
{
  for(int i = 7; i <= 12; i++)
  { pinMode(i, 1); }
  
  mouse.init();
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

int mouseX = 4;
int mouseY = 4;

void loop()
{
  for(int j = 0; j < 8; j++)
  {
    for(int i = 0; i < 8; i++)
    {
      if(buffer[i][j] == 1)
      { ShiftY(j);
      ShiftX(i); }
      else
      { ShiftY(-1);
      ShiftX(-1); }
      
      
      delayMicroseconds(100);
    }
  }
  
  ShiftX(mouseX);
  ShiftY(mouseY);
  
  MouseInfo mouseInfo;
  mouse.getData(&mouseInfo);
  
  mouseX += mouseInfo.x * 0.5;
  mouseY -= mouseInfo.y * 0.5;
  
  if(mouseX < 0) mouseX = 0;
  if(mouseX > 7) mouseX = 7;
  if(mouseY < 0) mouseY = 0;
  if(mouseY > 7) mouseY = 7;
  
  if(mouseInfo.leftClick == 1)
  buffer[mouseX][mouseY] = 1;
  if(mouseInfo.rightClick == 1)
  buffer[mouseX][mouseY] = 0;
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

/*
  Serial.print("\tX=");
  Serial.print(mouseInfo.x, DEC);
  Serial.print("\tY=");
  Serial.print(mouseInfo.y, DEC);
  Serial.print("\tSc=");
  Serial.print(mouseInfo.scroll, DEC);
  Serial.print("\tLB=");
  Serial.print(mouseInfo.leftClick, DEC);
  Serial.print("\tMB=");
  Serial.print(mouseInfo.middleClick, DEC);
  Serial.print("\tRB=");
  Serial.print(mouseInfo.rightClick, DEC);
  Serial.print("\tCX=");
  Serial.print(mouseInfo.cX, DEC);
  Serial.print("\tCY=");
  Serial.print(mouseInfo.cY, DEC);
  Serial.print("\tCS=");
  Serial.print(mouseInfo.cScroll, DEC);
  Serial.println();
}
*/
