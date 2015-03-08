#ifndef Touch_h
#define Touch_h

#include "Arduino.h"

class Touch
{
  public:
    int x;
    int y;
    boolean pressed;
    int tWidth;
    int tHeight;
    int dx;
    int dy;
    int startX;
    int startY;
    
    Touch();
  
  private:
    int minX;
    int minY;
    int maxX;
    int maxY;
    int pinX0;
    int pinX1;
    int pinY0;
    int pinY1;
};

#endif
