#include <Stepper.h>
Stepper stepper(24, 9, 10, 11, 12);
void setup()
{
  Serial.begin(9600);
  stepper.setSpeed(240);
}

int sp = 240;

void loop()
{
  int serav = Serial.available();
  
  if(serav > 0)
  {
    String cmd = "";
    for(int i = 0; i < serav; i++)
    { cmd += (char)Serial.read(); }
    
    if(!cmd.equals("0"))
    sp = cmd.toInt();
    
    Serial.println(sp);
  }
  
  stepper.setSpeed(sp);
  stepper.step(1);
}
