#include <SPI.h>
#include <Ethernet.h>
#include <Servo.h>

byte mac[] = { 0x90, 0xA2, 0xDA, 0x00, 0x9B, 0x62 };
byte ip[] = { 192, 168, 0, 177 };
byte gateway[] = { 192, 168, 0, 2 };
byte subnet[] = { 255, 255, 255, 0 };

EthernetServer server = EthernetServer(8080);
int update = 0;

int TONE = 1;
int CAM = 2;
int MOT = 3;
int LEDS = 4;
int CONSOLE = 5;
int STEER = 6;
int CONFIRM = 7;

int motor = 2;
int camera = 3;
int steer = 5;
int tonePin = 8;
int leds = 9;

void setup()
{
  pinMode(motor, OUTPUT);
  pinMode(camera, OUTPUT);
  pinMode(steer, OUTPUT);
  pinMode(tonePin, OUTPUT);
  pinMode(leds, OUTPUT);
  
  Serial.begin(9600);
  
  setServo(steer, 90);
  setServo(camera, 90);
  
  delay(50);
  
  Ethernet.begin(mac, ip, gateway, subnet);
  server.begin(); beep(1000, 100);
}

void loop()
{
  EthernetClient c = server.available();
  while(c.available() > 0) onPacket(c);
  
  if(millis() % 20000 == 0)
  {
    update++;
    print("Update ");
    print(update);
    print(": ");
    print(millis() / 60000);
    print(" min, ");
    print((millis() / 1000) % 60);
    println(" secs active");
  }
}

void onPacket(EthernetClient c)
{
  int i = read(c);
  
  if(i == TONE)
  {
    int j = readShort(c);
    int k = readShort(c);
    beep(j, k);
    Serial.print("Tone: ");
    Serial.print(j);
    Serial.print(" : ");
    Serial.println(k);
  }
  else if(i == CAM)
  {
    int r = read(c);
    setServo(camera, r);
  }
  else if(i == STEER)
  {
    int r = read(c);
    setServo(steer, r);
  }
  else if(i == MOT)
  {
    int s = read(c);
    drive(s == 1);
    if(s == 0) Serial.println("Stopping");
    else Serial.println("Driving");
  }
  else if(i == LEDS)
  {
    int j = read(c);
    analogWrite(leds, j);
  }
  
  write(CONFIRM);
}
