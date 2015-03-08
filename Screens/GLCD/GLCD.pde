#include <ks0108.h>
#include "Arial14.h"
#include "SystemFont5x7.h"

int width = 128;
int height = 128;

void setup()
{
  pinMode(13, 1); digitalWrite(13, 1);
  pinMode(A5, 1); digitalWrite(A5, 0);
  GLCD.Init(NON_INVERTED);
  GLCD.ClearScreen();  
  GLCD.SelectFont(System5x7);
}

void loop()
{
  GLCD.ClearScreen();
  GLCD.DrawLine(0, 0, width, height, BLACK);
  delay(100);
}
