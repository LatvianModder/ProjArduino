#include <TVout.h>
#include <fontALL.h>

TVout TV;
int width, height;

void setup()
{
  TV.begin(PAL, 120, 96);
  width = TV.hres();
  height = TV.vres();
  
  TV.select_font(font6x8);
  TV.clear_screen();
  TV.println("Hello!");
  TV.delay(2000);
}

void loop()
{
  TV.clear_screen();
  TV.draw_circle(width/2, height/2, random(height-5), WHITE);
}

/*
TV.draw_circle();
*/
