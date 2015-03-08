#include <Servo.h>
Servo servo[5];

int angles[] =
{
  151,
  99,
  45,
  139,
  45,
};

void setup()
{
  Serial.begin(19200);
  
  for(int i = 2; i <= 13; i++)
  pinMode(i, OUTPUT);
  
  servo[0].attach(3);
  servo[1].attach(5);
  servo[2].attach(6);
  servo[3].attach(9);
  servo[4].attach(10);
}

void loop()
{
  while(Serial.available() >= 2)
  {
    int mot = Serial.read();
    int angle = Serial.read();
    angles[mot] = angle;
  }
  
  for(int i = 0; i < 5; i++)
  servo[i].write(angles[i]);
  
  delay(10);
}
