void drive(boolean b)
{ digitalWrite(motor, b); }

Servo servoCamera;
Servo servoSteer;

void setServo(int pin, int val)
{
  if(pin == camera)
  {
    if(!servoCamera.attached()) servoCamera.attach(pin);
    servoCamera.write(val);
  }
  
  if(pin == steer)
  {
    if(!servoSteer.attached()) servoSteer.attach(pin);
    servoSteer.write(val);
  }
  
  //servoCamera.detach(); servoSteer.detach();
}

void beep(int i, int j)
{ if(i <= 0 || j <= 0) noTone(tonePin);
else tone(tonePin, i, j); }
