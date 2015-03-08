#include "Arduino.h"
#include "Touch.cpp"
#include "App.cpp"
//#include "AppPaint.cpp"

class MainClass
{
  public:
    
    
    MainClass()
    {
      tick = 0L;
      
      NONE = 0;
      RED = 1;
      GREEN = 2;
      YELLOW = 3;
      
      touch = new Touch();
      openApp(new AppPaint());
      //app = new App();
    }
    
    void onUpdate()
    {
      if(sleep(5)) touch -> onUpdate();
      app -> onUpdate();
    }
    
    boolean sleep(int i)
    { return tick % i == 0; }

    void printPos(int x, int y)
    {
      Serial.print("X: ");
      Serial.print(x);
      Serial.print(", Y: ");
      Serial.println(y);
    }
    
    void openApp(App *a)
    {
      app = a;
      app -> onLoaded();
    }
};
