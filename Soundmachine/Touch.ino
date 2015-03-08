const int pinY1 = A0;
const int pinY0 = A1;
const int pinX1 = A2;
const int pinX0 = A3;

int smallestX = 90;
int biggestX = 910;
int smallestY = 173;
int biggestY = 830;

void processTouch()
{
  if(!sleep(5)) return;
  
  boolean prevPressed = pressed;
  
  int rawX = getX();
  int rawY = getY();
  
  pressed = rawX > 3 && rawY > 3;
  
  int prevX = touchX;
  int prevY = touchY;
  touchX = rawX;
  touchY = rawY;
  
  touchX = map(rawX, smallestX, biggestX, 0, width);
  if(touchX < 0) touchX = 0; if(touchX >= width) touchX = width - 1;
  touchY = map(rawY, smallestY, biggestY, 0, height);
  if(touchY < 0) touchY = 0; if(touchY >= height) touchY = height - 1;
  
  if(prevPressed != pressed)
  {
    if(pressed) onPressed();
    else onReleased();
  }
  
  if(pressed)
  whilePressed(touchX - prevX, touchY - prevY);
}

void onPressed()
{
  printPos(touchX, touchY);
  
  //if(touchX < width / 2)
  //setTone(0, 800, 1000);
  //else setTone(1, 3000, 1000);
}

void onReleased()
{
}

void whilePressed(int dx, int dy)
{
}

void printPos(int x, int y)
{
  Serial.print("X: ");
  Serial.print(touchX);
  Serial.print(", Y: ");
  Serial.println(touchY);
}

int getX()
{
  pinMode(pinX0, OUTPUT);
  pinMode(pinX1, OUTPUT);
  pinMode(pinY0, OUTPUT);
  pinMode(pinY1, OUTPUT);
  
  digitalWrite(pinX0, 0);
  digitalWrite(pinY0, 0);
  digitalWrite(pinX1, 1);
  digitalWrite(pinY1, 0);
  
  pinMode(pinY0, INPUT);
  pinMode(pinY1, INPUT);
  
  delay(2);
  return analogRead(pinY0);
}

int getY()
{
  pinMode(pinX0, OUTPUT);
  pinMode(pinX1, OUTPUT);
  pinMode(pinY0, OUTPUT);
  pinMode(pinY1, OUTPUT);
  
  digitalWrite(pinX0, 0);
  digitalWrite(pinY0, 0);
  digitalWrite(pinX1, 0);
  digitalWrite(pinY1, 1);
  
  pinMode(pinX0, INPUT);
  pinMode(pinX1, INPUT);
  
  delay(2);
  return analogRead(pinX0);
}
