const int tWidth = 128;
const int tHeight = 64;
const int pinY1 = A0;
const int pinY0 = A1;
const int pinX1 = A2;
const int pinX0 = A3;

int smallestX = 90;
int biggestX = 910;
int smallestY = 173;
int biggestY = 830;

int startTouchX = 0;
int startTouchY = 0;

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
  
  touchX = map(rawX, smallestX, biggestX, 0, tWidth);
  if(touchX < 0) touchX = 0; if(touchX >= tWidth) touchX = tWidth - 1;
  touchY = map(rawY, smallestY, biggestY, 0, tHeight);
  if(touchY < 0) touchY = 0; if(touchY >= tHeight) touchY = tHeight - 1;
  
  if(prevPressed != pressed)
  {
    if(pressed)
    {
      startTouchX = touchX;
      startTouchY = touchY;
      onPressed();
    }
    else
    {
      onReleased();
      startTouchX = startTouchY = 0;
    }
  }
  
  if(pressed)
  whilePressed(touchX - prevX, touchY - prevY);
  
  delay(0.2);
}

boolean firstTime = true;
int drawColor = RED;

void onPressed()
{
  if(firstTime)
  {
    clearScreen();
  }
  
  if(touchX > tWidth / 8 * 7)
  {
    int y = touchY * 4 / tHeight;
    
    if(y == 0) clearScreen();
    else drawColor = y;
  }
}

void onReleased()
{
}

void whilePressed(int dx, int dy)
{
  if(firstTime)
  {
    firstTime = false;
    return;
  }
  
  if(touchX < tWidth)
  {
    int x = touchX * 8 / tHeight;
    int y = touchY * 8 / tHeight;
    
    if(x < tHeight / 8)
    setPixel(x, y, drawColor);
  }
}

void printPos(int x, int y)
{
  Serial.print("X: ");
  Serial.print(x);
  Serial.print(", Y: ");
  Serial.println(y);
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
  
  delay(0.4);
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
  
  delay(0.4);
  return analogRead(pinX0);
}
