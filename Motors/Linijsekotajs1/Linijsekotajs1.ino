int analogValues[6] = { 0, 0, 0, 0, 0, 0 };
int led[6] = { 5, 13, 4, 17, 16, 14 };
boolean sensor[6] = { false, false, false, false, false, false };

boolean hasLaunched = false;
int lastMovement = 0;
int moveSpeed = 30;
boolean pGoPressed = false;
boolean hasStopped = false;
boolean pOnCross = false;

void setup()
{
  for(int i = 0; i < 6; i++)
  pinMode(led[i], OUTPUT);
  
  pinMode(11, INPUT);
  digitalWrite(11, 1);
}

void loop()
{
  for(int i = 0; i < 6; i++)
  digitalWrite(led[i], 0);
  
  for(int i = 0; i < 6; i++)
  {
    analogValues[i] = analogRead(5 - i);
    sensor[i] = analogValues[i] < 600;
    digitalWrite(led[i], sensor[i]);
  }
  
  if(hasLaunched)
  {
    boolean b1 = getLeft() && getMiddle() && getRight();
    if(!getLeft() && getMiddle() && !getRight()) lastMovement = 3;
    //if(getMiddle()) lastMovement = 3;
    if(b1) lastMovement = 3;
    if(getLeft() && !getRight()) lastMovement = 1;
    if(!getLeft() && getRight()) lastMovement = 2;
    
    if(pOnCross != b1 && b1)
    onCross();
    
    pOnCross = b1;
    
    if(lastMovement == 0) stopMotors();
    else if(lastMovement == 1) motor('L', moveSpeed);
    else if(lastMovement == 2) motor('R', moveSpeed);
    else if(lastMovement == 3) motor('B', moveSpeed);
    
    if(hasStopped) stopMotors();
    
    if(goPressed())
    {
      stopMotors();
      hasLaunched = false;
      hasStopped = false;
      blinkLeds(2);
    }
  }
  else 
  {
    stopMotors();
    
    if(goPressed())
    {
      hasLaunched = true;
      hasStopped = false;
      blinkLeds(5);
    }
  }
  delay(10);
}

void blinkLeds(int i)
{
  for(int j = 0; j < i; j++)
  {
    for(int k = 0; k < 6; k++)
    digitalWrite(led[k], 1);
    delay(250);
    for(int k = 0; k < 6; k++)
    digitalWrite(led[k], 0);
    delay(250);
  }
}

boolean goPressed()
{ return !digitalRead(11); }

void motor(char c, int j)
{
  digitalWrite(6, 0);
  digitalWrite(8, 1);
  
  if(c == 'L')
  {
    digitalWrite(6, 1);
    analogWrite(10, j);
    analogWrite(9, 0);
  }
  else if(c == 'R')
  {
    digitalWrite(8, 0);
    analogWrite(9, j);
    analogWrite(10, 0);
  }
  else if(c == 'B')
  {
    digitalWrite(6, 1);
    digitalWrite(8, 0);
    analogWrite(10, j);
    analogWrite(9, j);
  }
}

void stopMotors()
{
  digitalWrite(6, 0);
  digitalWrite(8, 0);
  analogWrite(9, 0);
  analogWrite(10, 0);
}

boolean getLeft() { return sensor[0]; }
boolean getMiddle() { return sensor[2] || sensor[3]; }
boolean getRight() { return sensor[5]; }

int crossTimes = 0;
void onCross()
{
  crossTimes++;
  if(crossTimes >= 3) hasStopped = true;
}
