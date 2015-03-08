void setup()
{
  PORTB = 255;
}

void loop()
{
  //long c = col(millis() * 0.0001, 1, 1);
  //int r = (c >> 16) & 255;
  //int g = (c >> 8) & 255;
  //int b = (c >> 0) & 255;
  
  int r = (int)random(0, 255);
  int g = (int)random(0, 255);
  int b = (int)random(0, 255);
  
  analogWrite(9, r);
  analogWrite(10, g);
  analogWrite(11, b);
  
  delay(1000);
}

long col (float hue, float saturation, float brightness)
{
  int r = 0;
  int g = 0;
  int b = 0;
  if (saturation == 0) {
      r = g = b = (int) (brightness * 255.0 + 0.5);
  } else {
      float h = (hue - (float)floor(hue)) * 6.0;
      float f = h - (float)floor(h);
      float p = brightness * (1.0 - saturation);
      float q = brightness * (1.0 - saturation * f);
      float t = brightness * (1.0 - (saturation * (1.0 - f)));
      switch ((int) h) {
      case 0:
          r = (int) (brightness * 255.0 + 0.5);
          g = (int) (t * 255.0 + 0.5);
          b = (int) (p * 255.0 + 0.5);
          break;
      case 1:
          r = (int) (q * 255.0 + 0.5);
          g = (int) (brightness * 255.0 + 0.5);
          b = (int) (p * 255.0 + 0.5);
          break;
      case 2:
          r = (int) (p * 255.0 + 0.5);
          g = (int) (brightness * 255.0 + 0.5);
          b = (int) (t * 255.0 + 0.5);
          break;
      case 3:
          r = (int) (p * 255.0 + 0.5);
          g = (int) (q * 255.0 + 0.5);
          b = (int) (brightness * 255.0 + 0.5);
          break;
      case 4:
          r = (int) (t * 255.0 + 0.5);
          g = (int) (p * 255.0 + 0.5);
          b = (int) (brightness * 255.0 + 0.5);
          break;
      case 5:
          r = (int) (brightness * 255.0 + 0.5);
          g = (int) (p * 255.0 + 0.5);
          b = (int) (q * 255.0 + 0.5);
          break;
      }
  }
  
  return (r << 16) | (g << 8) | (b << 0);
}
