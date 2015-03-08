/*  startTime=millis();  
  while(button1){
  elapsedTime=millis()-startTime;
  if(elapsedTime>1000) {TestType=1;led1ON;}
  if(elapsedTime>2000) {TestType=2;led2ON;}
  if(elapsedTime>3000) {TestType=3;led3ON;}
}  
if(TestType)
{
  led1OFF;
  delay(500);
  led2OFF;
  delay(500);
  led3OFF;
  delay(500);
}
  switch (TestType) {
    case 1:
      while(1)
      {
        if(analogRead(A1)>100){led4ON;}else{led4OFF;}
     }
      break;
    case 2:
    while(1){
      if(SEN_BACK) {led3ON;} else {led3OFF;}
      if(SEN_LEFT) {led2ON;} else {led2OFF;}
      if(SEN_RIGHT) {led1ON;} else {led1OFF;}
    }
      break;
    case 3:
      led1ON;delay(300);led2ON;delay(300);led3ON;
      ForwardSLOW();delay(600);BackwardSLOW();delay(600);RightSLOW();delay(600);LeftSLOW();delay(600);Stop();delay(600);
      Forward();delay(600);Backward();delay(600);Right();delay(600);Left();delay(600);Stop();delay(600);
      RightSLOWradius();delay(600);RightSLOWradiusBack();delay(600);LeftSLOWradius();delay(600);LeftSLOWradiusBack();delay(600);Stop();
      Rightradius();delay(600);RightradiusBack();delay(600);Leftradius();delay(600);LeftradiusBack();delay(600);Stop();
      break;
  }*/
