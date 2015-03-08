#include <IRremote.h>

IRrecv irrecv(11);
decode_results results;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn();
  pinMode(8, 1);
  digitalWrite(8, 0);
}

int val = 0;

void loop() {
  if (irrecv.decode(&results))
  {
    Serial.print("Readed data: ");
    int data = results.value;
    if(data > 1000) data -= 2048;
    Serial.println(data);
    
    if(data == 32) val += 3;
    else if(data == 33) val -= 3;
    if(val < 0) val = 0;
    if(val > 255) val = 255;
    analogWrite(9, val);
    
    irrecv.resume();
  }
}
