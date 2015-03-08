#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int hours, minutes, seconds;
int a_h, a_m, a_s;

void setup()
{
  lcd.begin(8, 1);
  
  delay(1000);
  
  lcd.clear();
  
  Serial.begin(9600);
}

void loop()
{
  int i = Serial.read();
  
  if(i != -1)
  {
    i = toUpperCase(i);
    if(i == 'H') a_h++;
    if(i == 'M') a_m++;
    if(i == 'S') a_s++;
  }
  
  lcd.clear();
  
  seconds = millis() / 1000;
  minutes = seconds / 60;
  hours = minutes / 60;
  
  String h, m, s;
  
  h += (hours + a_h) % 24;
  m += (minutes + a_m) % 60;
  s += (seconds + a_s) % 60;
  
  //if(hours < 10) h = "0" + h;
  //if(minutes < 10) m = "0" + m;
  //if(seconds < 10) s = "0" + s;
  
  lcd.print(h);
  lcd.print(":");
  lcd.print(m);
  lcd.print(":");
  lcd.print(s);
  
  delay(100);
}
