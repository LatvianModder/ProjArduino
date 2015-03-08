long num = 0L;

const int INFO = 0;
const int VIP = 1;
const int WARN = 2;
const int ERR = 3;

void setup()
{
  Serial.begin(9600);
  
  printLog(VIP, "* Device Restart *");
}

void printLog(int lvl, String msg)
{
  String prefix = "";
  if(lvl == INFO) prefix = "[INFO]";
  if(lvl == VIP) prefix = "[VIP]";
  if(lvl == WARN) prefix = "[WARN]";
  if(lvl == ERR) prefix = "[ERR]";
  
  Serial.print(prefix);
  Serial.println(msg);
}

void loop()
{
  num++;
  
  int mn = 10000000;
  
  String s = "Num #";
  s += num;
  s += " = ";
  s += (num * 5839) % 1000000;
  
  if(num % 20 == 0) printLog(VIP, s);
  else if(num % 20 == 14) printLog(WARN, s);
  else if(num % 30 == 1) printLog(ERR, s);
  else printLog(INFO, s);
  
  String s1 = "";
  while(Serial.available() > 0)
    s1 += (char)Serial.read();
  
  if(s1.length() > 0)
  {
    s1 = "User sent text: " + s1;
    printLog(INFO, s1);
  }
  
  delay(1000);
}
