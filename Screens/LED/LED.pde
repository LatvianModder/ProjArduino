void setup()
{
  for(int i = 2; i <= A5; i++)
  pinMode(i, 1);
  
  digitalWrite(10, 0);
  digitalWrite(A3, 0);
  
  Serial.begin(4000);
}

void loop()
{
  while(Serial.available() > 0)
  {
    char c = (char)Serial.read();
    int s = Serial.read();
    
    setLed(c);
  }
}

void setLed(char c)
{
  dw(12, 0); // G
  dw(11, 0); // F
  dw(9, 0); // A
  dw(8, 0); // B
  dw(A1, 0); // E
  dw(A2, 0); // D
  dw(A4, 0); // C
  dw(A5, 0); // .
  
  if(c == '.') dw(A5, 1);
  else if(c == 'a') dw(9, 1);
  else if(c == 'b') dw(8, 1);
  else if(c == 'c') dw(A4, 1);
  else if(c == 'd') dw(A2, 1);
  else if(c == 'e') dw(A1, 1);
  else if(c == 'f') dw(11, 1);
  else if(c == 'g') dw(12, 1);
}

void dw(int pin, int s)
{ digitalWrite(pin, s); }
