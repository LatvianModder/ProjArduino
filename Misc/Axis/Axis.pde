int minVal = 265;
int maxVal = 402;
int x, y, z;

void setup()
{ Serial.begin(9600); }

void loop()
{
  int rx = analogRead(A0);
  int ry = analogRead(A1);
  int rz = analogRead(A2);
  
  int x1 = map(rx, minVal, maxVal, -90, 90);
  int y1 = map(ry, minVal, maxVal, -90, 90);
  z = map(rz, minVal, maxVal, -90, 90);
  
  x = (int)(RAD_TO_DEG * (atan2(-x1, -z) + PI));
  y = (int)(RAD_TO_DEG * (atan2(-y1, -z) + PI));
  
  Serial.write(x * 255 / 360);
  Serial.write(y * 255 / 360);
  Serial.flush();
  delay(50);
}
