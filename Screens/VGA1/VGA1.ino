int RGBPin = 10;
int HSyncPin = 11;
int VSyncPin = 12;

int width = 480;
int height = 640;

int pixels[480 * 640];

void setup()
{
  pinMode(RGBPin, OUTPUT);
  pinMode(HSyncPin, OUTPUT);
  pinMode(VSyncPin, OUTPUT);
}

void loop()
{
  delayMicroseconds(1);
}
