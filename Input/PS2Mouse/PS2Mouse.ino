#include <ps2.h>
PS2Mouse mouse(2, 4);

void setup()
{
  Serial.begin(9600);
  mouse.init();
}

void loop()
{
  MouseInfo mouseInfo;
  mouse.getData(&mouseInfo);
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
