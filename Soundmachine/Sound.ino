int tones[trackCount];
int prevTones[trackCount];
int toneTicks[trackCount];

void initSound()
{
  Serial.print("Loaded ");
  Serial.print(trackCount);
  Serial.println(" tracks!");
  
  t = new Track();
}

void processSound()
{
  int sum = 0;
  int divSum = 0;
  
  for(int i = 0; i < trackCount; i++)
  {
    if(toneTicks[i] > 0)
    {
      toneTicks[i] -= 3;
      if(toneTicks[i] < 0)
      toneTicks[i] = 0;
      
      sum += tones[i];
      divSum++;
    }
  }
  
  if(sum > 0) tone(tonepin, sum / divSum);
  else noTone(tonepin);
  
  if(pressed && sleep(250))
  {
    setTone(0, 200, 100);
  }
}

void setTone(int i, int t, int d)
{
  tones[i] = t;
  toneTicks[i] = d;
}

void setNoTone(int i)
{
  tones[i] = 0;
  toneTicks[i] = 0;
}
