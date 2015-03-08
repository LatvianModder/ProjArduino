#include <TimerHelpers.h>
#include <avr/pgmspace.h>
#include <avr/sleep.h>

const byte hSyncPin = 3;     // <------- HSYNC

const byte redPin = 4;       // <------- Red pixel data
const byte greenPin = 5;     // <------- Green pixel data
const byte bluePin = 6;      // <------- Blue pixel data

const byte vSyncPin = 10;    // <------- VSYNC

const int horizontalBytes = 60;  // 480 pixels wide
const int verticalPixels = 480;  // 480 pixels high

const int verticalLines = verticalPixels / 16;  
const int horizontalPixels = horizontalBytes * 8;

const byte verticalBackPorchLines = 35;  // includes sync pulse?
const int verticalFrontPorchLines = 525 - verticalBackPorchLines;

volatile int vLine;
volatile int messageLine;
volatile byte backPorchLinesToGo;

#define nop asm volatile ("nop\n\t")

// bitmap - gets sent to PORTD
// For D4/D5/D6 bits need to be shifted left 4 bits
//  ie. 00BGR0000

char message [verticalLines]  [horizontalBytes];

// ISR: Vsync pulse
ISR (TIMER1_OVF_vect)
  {
  vLine = 0; 
  messageLine = 0;
  backPorchLinesToGo = verticalBackPorchLines;
  } // end of TIMER1_OVF_vect
  
// ISR: Hsync pulse ... this interrupt merely wakes us up
ISR (TIMER2_OVF_vect)
  {
  } // end of TIMER2_OVF_vect


void setup()
  {
  
  // initial bitmap ... change to suit
  for (int y = 0; y < verticalLines; y++)
    for (int x = 0; x < horizontalBytes; x++)
      message [y] [x] = (x + y) << 4;
   
  // disable Timer 0
  TIMSK0 = 0;  // no interrupts on Timer 0
  OCR0A = 0;   // and turn it off
  OCR0B = 0;
  
  // Timer 1 - vertical sync pulses
  pinMode (vSyncPin, OUTPUT); 
  Timer1::setMode (15, Timer1::PRESCALE_1024, Timer1::CLEAR_B_ON_COMPARE);
  OCR1A = 259;  // 16666 / 64 uS = 260 (less one)
  OCR1B = 0;    // 64 / 64 uS = 1 (less one)
  TIFR1 = _BV (TOV1);   // clear overflow flag
  TIMSK1 = _BV (TOIE1);  // interrupt on overflow on timer 1

  // Timer 2 - horizontal sync pulses
  pinMode (hSyncPin, OUTPUT); 
  Timer2::setMode (7, Timer2::PRESCALE_8, Timer2::CLEAR_B_ON_COMPARE);
  OCR2A = 63;   // 32 / 0.5 uS = 64 (less one)
  OCR2B = 7;    // 4 / 0.5 uS = 8 (less one)
  TIFR2 = _BV (TOV2);   // clear overflow flag
  TIMSK2 = _BV (TOIE2);  // interrupt on overflow on timer 2
 
  // prepare to sleep between horizontal sync pulses  
  set_sleep_mode (SLEEP_MODE_IDLE);  
  
  // pins for outputting the colour information
  pinMode (redPin, OUTPUT);
  pinMode (greenPin, OUTPUT);
  pinMode (bluePin, OUTPUT);
  
}  // end of setup

// draw a single scan line
void doOneScanLine ()
  {
    
  // after vsync we do the back porch
  if (backPorchLinesToGo)
    {
    backPorchLinesToGo--;
    return;   
    }  // end still doing back porch
    
  // if all lines done, do the front porch
  if (vLine >= verticalPixels)
    return;
    
  // pre-load pointer for speed
  register char * messagePtr =  & (message [messageLine] [0] );

  delayMicroseconds (1);
  
  // how many pixels to send
  register byte i = horizontalBytes;

  // blit pixel data to screen    
  while (i--)
    PORTD = * messagePtr++;

  // stretch final pixel
  nop; nop; nop;

  PORTD = 0;  // back to black
  // finished this line 
  vLine++;

  // every 16 pixels it is time to move to a new line in our text
  if ((vLine & 0xF) == 0)
    messageLine++;
    
  }  // end of doOneScanLine

void loop() 
  {
  // sleep to ensure we start up in a predictable way
  sleep_mode ();
  doOneScanLine ();
 }  // end of loop
