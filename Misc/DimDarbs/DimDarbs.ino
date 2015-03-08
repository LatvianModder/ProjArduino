#include <Servo.h>
Servo servo[5];

int servoPins[] = { 2, 5, 6, 9, 10 };
int angles[] = { 151, 99, 45, 139, 45 };
int minAngles[] = { 133, 56, 0, 100, 0 };
int maxAngles[] = { 169, 141, 90, 179, 90 };
long tick = 0;

void setup()
{
  for(int i = 2; i <= 13; i++)
    pinMode(i, OUTPUT);
  
  servo[0].attach(3);
  //servo[1].attach(5);
  servo[2].attach(6);
  servo[3].attach(9);
  //servo[4].attach(10);
}

void loop()
{
  for(int i = 0; i < 5; i++)
  {
    double f = tick * 0.021 + i;
    double d = (sin(f) * 2.0 - 1.0) * 360.0;
    angles[i] = (int)map(d, 0, 360, minAngles[i], maxAngles[i]);
    
    servo[i].write(angles[i]);
  }
  
  Serial.println();
  
  delay(10);
  tick++;
}
