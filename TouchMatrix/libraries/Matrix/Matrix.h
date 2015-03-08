#ifndef App_h
#define App_h

#include "Arduino.h"

class App
{
  public:
    App();
    void onLoaded();
    void onClosed();
    void onUpdate();
    void onPressed();
    void onReleased();
    void whilePressed();
};

#endif
