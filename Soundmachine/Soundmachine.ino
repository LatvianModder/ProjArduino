int tick = 0;
int touchX, touchY;
boolean pressed = false;
const int width = 128;
const int height = 64;
const int tonepins[] = { 8, 9, 10, 11 };
const int tonepin = 8;
const int trackCount = sizeof(tonepins) / sizeof(int);

void setup()
{
  Serial.begin(9600);
  Serial.println("Initing...");
  
  initSound();
}

void loop()
{
  processTouch();
  processSound();
  
  tick++;
  delay(1);
}

boolean sleep(int ms)
{ return tick % ms == 0; }
