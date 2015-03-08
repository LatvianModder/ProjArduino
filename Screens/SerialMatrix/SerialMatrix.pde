void setup()
{
  Serial.begin(9600);
  
  for(int i = 0; i < 8; i++)
  matrix.write(i, bit(i));
}

void loop()
{
  matrix.update(1000000);
  
  int serav = Serial.available();
  /*if(serav == 3)
  {
    int x = Serial.read();
    int y = Serial.read();
    int hl = Serial.read();
    if(x < 8 && y < 8 && hl >= 0 && hl <= 1)
    matrix.write(x, y, hl);
    
    printBuffer();
  }
  else */if(serav == 1)
  {
    if(Serial.read() == 'c')
    matrix.clear();
    
    //printBuffer();
  }
}

/*void printBuffer()
{
  for(int j = 0; j < 8; j++)
  { for(int i = 0; i < 8; i++)
  Serial.print(matrix.read(i, j));
  Serial.println(); }
  Serial.println("--------");
  delay(100);
}*/

int arrayToBinary(int* data)
{
  int r = 0;
  for(int i = 0; i < sizeof(data); i++)
  {
    int d = data[i];
    if(d == 1) r += bit(d);
  }
  return r;
}
