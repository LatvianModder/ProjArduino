void write(int data)
{
  Serial.print(data, BYTE);
}

boolean read(int data)
{
  if(Serial.read() == data) { return true; }
  else { return false; }
}

void digiW(int data1, int data2)
{
  digitalWrite(data1, data2);
}
