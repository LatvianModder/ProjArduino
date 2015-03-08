int touchX, touchY;
boolean pressed = false;
long tick = 0;

const int NONE = 0;
const int RED = 1;
const int GREEN = 2;
const int YELLOW = 3;

void setup()
{
  Serial.begin(9600);
  
  initMatrix();
}

void loop()
{
  processTouch();
  processMatrix();
  delay(1);
}

boolean sleep(int i)
{ return tick % i == 0; }
