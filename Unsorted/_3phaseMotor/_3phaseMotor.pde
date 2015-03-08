/*This sketch was produced to manage a
 3-phase motor using a potentiometer to
 control both direction and speed.
The middle of the travel of the pot is "off"
with the speed in either direction increasing
with clockwise or anticlockwise turning.
*/



int potPin = 2;                  // select the input pin
                                //for the potentiometer
int phase1 = 10;                 // select the output
int phase2 = 11;                 //  pins for each
int phase3 = 12;                 // of the phases
int val = 0;                     /* variable to store the
                                       value coming from
                                        the pot*/

void setup()
{
  pinMode(phase1, OUTPUT);        //declare the
  pinMode(phase2, OUTPUT);        // phase pins
  pinMode(phase3, OUTPUT);        // as OUTPUTs
                          }

void loop()
{
 {digitalWrite(13, LOW);}          //This LED will  
                                     //indicate the centre
                                     //off posistion later,
                                     //turn it off for now.
  val = analogRead(potPin);         // Read the value from
                                       // the potentiometer.
  int speedForward = 2*(1023 - val);  /* This expression  
                                      reverses the values beyond
                                      512 so that the longest
                                      delay (slowest speed)
                                      lies at the RH
                                      end of the range.
                                      Multiply by 2 to restore
                                      to maximum value of 1024*/
  int speedReverse = 2*(val);            //Only need to multiply.
  
  if (val > 542)                     //Values from 482 to 542
                                          // is "dead zone" to switch
                                          //off motor. See "else if"
                                          
    {
digitalWrite(phase1, HIGH);         // For 3 phases there are 6
  delay(speedForward/6);            // transitions per revolution.
digitalWrite(phase3, LOW);          // This switches them on and
  delay(speedForward/6);            // off in the correct order
digitalWrite(phase2, HIGH);         // in the right-hand half  
  delay(speedForward/6);            // of the travel of the pot,  
digitalWrite(phase1, LOW);          // for clockwise rotation.
  delay(speedForward/6);            //
digitalWrite(phase3, HIGH);         //
  delay(speedForward/6);            //
digitalWrite(phase2, LOW);          //
  delay(speedForward/6);            //
}


  else if (val < 482)
  {
digitalWrite(phase3, HIGH);
  delay(speedReverse/6);             //
digitalWrite(phase1, LOW);           //
  delay(speedReverse/6);             //
digitalWrite(phase2, HIGH);          //
  delay(speedReverse/6);             // The same as above,
digitalWrite(phase3, LOW);           // on the left-hand side,
  delay(speedReverse/6);             // for anticlockwise rotation.
digitalWrite(phase1, HIGH);          //
  delay(speedReverse/6);             //
digitalWrite(phase2, LOW);           //
  delay(speedReverse/6);             //
}
      
else
digitalWrite(phase1, LOW);           // Dead zone, everything off...
digitalWrite(phase2, LOW);
digitalWrite(phase3, LOW);
{digitalWrite(13, HIGH);}             //except the LED, which
                                                  //indicates "off"

}
