#include "Touch.h"
#include "App.h"
//#include "MainClass.cpp"

//#define NONE = 0;
#define RED = 1;
#define GREEN = 2;
#define YELLOW = 3;

long tick = 0;
Touch touch;
App *app;

void setup()
{
  Serial.begin(9600);
  
  initMatrix();
}

void loop()
{
  main.onUpdate();
  
  processMatrix();
}

void onPressed()
{
}

void onReleased()
{
}

void whilePressed()
{
}
