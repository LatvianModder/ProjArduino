#include "UsbKeyboard.h"

void setup()
{
  TIMSK0&=!(1<<TOIE0);
  cli();
  usbDeviceDisconnect();
  delayMs(250);
  usbDeviceConnect();
  sei();
  pinMode(12, OUTPUT);
}

void loop()
{
  UsbKeyboard.update();
  UsbKeyboard.sendKeyStroke(KEY_A);
  digitalWrite(12, 1);
  delay(100);
  digitalWrite(12, 0);
  delay(900);
}

void delayMs(unsigned int ms)
{
  for (int i = 0; i < ms; i++) {
    delayMicroseconds(1000);
  }
}
