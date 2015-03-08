#include "Arduino.h"
#include "MainClass.cpp"
//#include "Touch.cpp"
//#include "App.cpp"

class AppPaint// : public App
{
  public:
    AppPaint()
    {
      //clearScreen();
    }
    
    void onPressed()
    {
      if(MainClass.touch.x > MainClass.touch.tWidth / 8 * 7)
      {
        int y = MainClass.touch.y * 4 / MainClass.touch.tHeight;
        
        if(y == 0) clearScreen();
        else drawColor = y;
      }
    }
    
    void onReleased()
    {
    }
    
    void whilePressed()
    {
      if(firstTime)
      {
        firstTime = false;
        return;
      }
      
      if(MainClass.touch.x < MainClass.touch.tWidth)
      {
        int th = MainClass.touch.tHeight;
        int x = MainClass.touch.x * 8 / th;
        int y = MainClass.touch.y * 8 / th;
        
        //if(x < th / 8 * 7)
        setPixel(x, y, drawColor);
      }
    }
};
