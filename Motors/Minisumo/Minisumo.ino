#include "Definations.h"

void setup() {                
  pinMode(11, OUTPUT);//LED1 / PB3
  pinMode(8, OUTPUT);//LED2 / PB0
  pinMode(12, OUTPUT);//LED3 / PB4
  pinMode(6, OUTPUT);//DIR1 / PD6
  pinMode(2, OUTPUT);//DIR2 / PD2
  pinMode(9, OUTPUT);//EN1 PB1
  pinMode(10, OUTPUT);//EN2 PB2
  pinMode(4, INPUT);//Button 1 / PD4
  digitalWrite(4, HIGH);//internal pull-up on PD4
  pinMode(5, INPUT);//Button 2 / PD5
  digitalWrite(5, HIGH);//internal pull-up on PD5
  randomSeed(analogRead(A2));
  STATE = TEST;
}

void Forward() {analogWrite(9,MaxSpeed);analogWrite(10,MaxSpeed);digitalWrite(6, HIGH);digitalWrite(2, LOW);}
void Backward() {analogWrite(9,MaxSpeed);analogWrite(10,MaxSpeed);digitalWrite(6, LOW);digitalWrite(2, HIGH);}
void Right() {analogWrite(9,MaxSpeed);analogWrite(10,MaxSpeed);digitalWrite(6, LOW);digitalWrite(2, LOW);}
void Left() {analogWrite(9,MaxSpeed);analogWrite(10,MaxSpeed);digitalWrite(6, HIGH);digitalWrite(2, HIGH);}
void ForwardSLOW() {analogWrite(9,MediumSpeed);analogWrite(10,MediumSpeed);digitalWrite(6, HIGH);digitalWrite(2, LOW);}
void BackwardSLOW() {analogWrite(9,MediumSpeed);analogWrite(10,MediumSpeed);digitalWrite(6, LOW);digitalWrite(2, HIGH);}
void RightSLOW() {analogWrite(9,MediumSpeed);analogWrite(10,MediumSpeed);digitalWrite(6, LOW);digitalWrite(2, LOW);}
void LeftSLOW() {analogWrite(9,MediumSpeed);analogWrite(10,MediumSpeed);digitalWrite(6, HIGH);digitalWrite(2, HIGH);}
void RightSLOWradius() {analogWrite(9,LowSpeed);analogWrite(10,MediumSpeed);digitalWrite(6, HIGH);digitalWrite(2, LOW);}
void LeftSLOWradius() {analogWrite(9,MediumSpeed);analogWrite(10,LowSpeed);digitalWrite(6, HIGH);digitalWrite(2, LOW);}
void RightSLOWradiusBack() {analogWrite(9,LowSpeed);analogWrite(10,MediumSpeed);digitalWrite(6, LOW);digitalWrite(2, HIGH);}
void LeftSLOWradiusBack() {analogWrite(9,MediumSpeed);analogWrite(10,LowSpeed);digitalWrite(6, LOW);digitalWrite(2, HIGH);}
void RightradiusBack() {analogWrite(9,MediumSpeed);analogWrite(10,MaxSpeed);digitalWrite(6, LOW);digitalWrite(2, HIGH);}
void LeftradiusBack() {analogWrite(9,MaxSpeed);analogWrite(10,MediumSpeed);digitalWrite(6, LOW);digitalWrite(2, HIGH);}
void Rightradius() {analogWrite(9,MediumSpeed);analogWrite(10,MaxSpeed);digitalWrite(6, HIGH);digitalWrite(2, LOW);}
void Leftradius() {analogWrite(9,MaxSpeed);analogWrite(10,MediumSpeed);digitalWrite(6, HIGH);digitalWrite(2, LOW);}
void Stop() {analogWrite(9,0);analogWrite(10,0);}
int SHARP_VAL = 0;

void loop()
{
  led1OFF;
  led2OFF;
  led3OFF;
  led4OFF;
  
  SHARP_VAL = map(analogRead(A1), 640, 140, 0, 100);
  
  if(button2)
  { STATE = START; }
  if(button1)
  { STATE = TEST; }
  
  if(STATE == START)
  {
    Stop();
    blinkLeds(5000);
    STATE = DRIVE;
  }
  if(STATE == DRIVE)
  {
    if(SHARP_VAL <= 75)
    { Forward(); }
    else
    { RightSLOW(); }
    
    if(seeSomething()){led4ON;}
    if(SEN_BACK) {led2ON;}
    if(SEN_LEFT) {led1ON;}
    if(SEN_RIGHT) {led3ON;}
    
    if((SEN_RIGHT || SEN_LEFT)
    || (SEN_RIGHT && SEN_LEFT))
    { Backward(); }
    if(SEN_BACK)
    { Forward(); }
    
    delay(10);
  }
  if(STATE == TEST)
  {
    Stop();
    if(SEN_BACK) led2ON;
    if(SEN_LEFT) led1ON;
    if(SEN_RIGHT) led3ON;
    if(seeSomething()) led4ON;
    
    delay(10);
  }
}

boolean seeSomething()
{ return SHARP_VAL <= 75; }
