int rx, ry, x, y, px, py, dx, dy;
boolean pressed, moved;

const int W = 400;
const int H = 300;

void setup()
{
  Serial.begin(9600);
  Serial.println("Hello!");
  
  pinMode(A0, OUTPUT);
  pinMode(A3, OUTPUT);
  digitalWrite(A0, 0);
  digitalWrite(A3, 0);
}

void loop()
{
  readTouchScreen();
  
  px = x;
  py = y;
  x = min(max(map(rx, 85, 850, 0, W), 0), W - 1);
  y = min(max(map(ry, 100, 830, 0, H), 0), H - 1);
  pressed = rx != 0 || ry != 0;
  
  boolean ppressed = pressed;
  dx = x - px; dy = y - py;
  moved = dx != 0 || dy != 0;
  
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  
  digitalWrite(A1, 0);
  digitalWrite(A2, 0);
  
  delay(4);
  
  if(pressed)
  {
    Serial.print(x);
    Serial.print(", Y ");
    Serial.print(y);
    Serial.print(", RX: ");
    Serial.print(rx);
    Serial.print(", RY: ");
    Serial.print(ry);
    Serial.print(", DX: ");
    Serial.print(dx);
    Serial.print(", DY: ");
    Serial.println(dy);
  }
  
  if(ppressed != pressed)
  {
    if(pressed) onPressed();
    else
    {
      x = px;
      y = py;
      onReleased();
    }
  }
  
  delay(90);
}

void onPressed()
{
}

void onReleased()
{
}

void readTouchScreen()
{
  int pinX1 = A0;
  int pinX2 = A2;
  int pinY1 = A3;
  int pinY2 = A1;
  
  pinMode(pinX1, INPUT);
  pinMode(pinY1, OUTPUT);
  pinMode(pinX2, INPUT);
  pinMode(pinY2, OUTPUT);
  digitalWrite(pinY1, 0);
  digitalWrite(pinY2, 1);
  rx = analogRead(pinX2);
  delay(1);
  
  pinMode(pinX1, OUTPUT);
  pinMode(pinY1, INPUT);
  pinMode(pinX2, OUTPUT);
  pinMode(pinY2, INPUT);
  digitalWrite(pinX1, 0);
  digitalWrite(pinX2, 1);
  ry = analogRead(pinY1);
  delay(1);
}
