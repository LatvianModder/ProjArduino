#include <ps2.h>
PS2Mouse mouse(3, 2);

void setup()
{
  Serial.begin(9600);
  mouse.init();
}

void loop()
{
  MouseInfo mouseInfo;
  mouse.getData(&mouseInfo);
  int x = -mouseInfo.x;
  int y = mouseInfo.y;
  int s = -mouseInfo.scroll;
  String data = "";
  data += (int)x;
  data += ",";
  data += (int)y;
  data += ",";
  data += (int)s;
  Serial.println(data);
  delay(40);
}
