//RSP funkcijas : begin
void blinkLeds(int len)
{
  led1ON;
  led2OFF;
  led3OFF;
  delay(len/5);
  led1OFF;
  led2ON;
  led3OFF;
  delay(len/5);
  led1OFF;
  led2OFF;
  led3ON;
  delay(len/5);
  led1OFF;
  led2ON;
  led3OFF;
  delay(len/5);
  led1ON;
  led2OFF;
  led3OFF;
  delay(len/5);
}
//RSP funkcijas : end
