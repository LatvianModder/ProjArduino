#include <RgbLed.h>

RgbLedCommonCathode led(13, 12, 11, true);

void setup()
{
}

void loop()
{
  for(int i = 0; i <= 255; i++)
  {
    int j = map(i, 0, 255, 255, 0);
    led.setColor(i, j, 0);
    delay(30);
  }
}
