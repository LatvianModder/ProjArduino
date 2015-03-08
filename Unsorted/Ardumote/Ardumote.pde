#define IR_BIT_LENGTH 12
#define BIT_1 1000          //Binary 1 threshold (Microseconds)
#define BIT_0 400           //Binary 0 threshold (Microseconds)
#define BIT_START 2000      //Start bit threshold (Microseconds)
#define DEBUG 0             //Serial connection must be started to debug
#define IR_PIN 7            //Sensor pin 1 wired through a 220 ohm resistor
#define LED_PIN 9           //"Ready to Recieve" flag, not needed but nice
#define POWER_PIN 11     // the red LED that indicates if the power button is pressed.

int runtime_debug = 0;
int output_key = 0;
int power_button = 0;

void setup() {
  pinMode(LED_PIN, OUTPUT);		//This shows when we're ready to recieve
  pinMode(POWER_PIN, OUTPUT);		//This is the "power on" indicator
  pinMode(IR_PIN, INPUT);
  digitalWrite(LED_PIN, LOW);	    //not ready yet
  Serial.begin(9600);
}

void loop() {
  digitalWrite(LED_PIN, HIGH);	   //Ok, i'm ready to recieve

  int key = get_ir_key();		    //Fetch the key

  digitalWrite(LED_PIN, LOW);

  do_response(key);

  delay(200);
}

void do_response(int key)
{
  switch (key)
  {
    case 1437:
      Serial.println("toggle debug pulse");
      runtime_debug = 1 - runtime_debug;
      break;
    case 1498:
      Serial.println("Toggle key output");
      output_key = 1 - output_key;
      break;
    case 1429:
      Serial.println("Power");
      power_button = 1 - power_button;
      if (power_button)
      {
        digitalWrite(POWER_PIN, HIGH);
      }
      else
      {
        digitalWrite(POWER_PIN, LOW);
      }
      break;
    case 1424:
      Serial.println("Channel Up");
      break;
    case 1425:
      Serial.println("Channel Down");
      break;
    default:
      if (output_key)
      {
        Serial.print("Key ");
        Serial.print(key);
        Serial.println(" not programmed");
      }
      break;
  }
}

void read_pulse(int data[], int num_bits)
{
  for (int i = 0; i < num_bits; i++)
  {
    data[i] = pulseIn(IR_PIN, LOW);
  }
}

void pulse_to_bits(int pulse[], int bits[], int num_bits)
{
  if (DEBUG || runtime_debug) { Serial.println("-----"); }

  for(int i = 0; i < num_bits ; i++)
  {
    if (DEBUG || runtime_debug) { Serial.println(pulse[i]); }

    if(pulse[i] > BIT_1) //is it a 1?
    {
      bits[i] = 1;
    }
    else if(pulse[i] > BIT_0) //is it a 0?
    {
      bits[i] = 0;
    } 

    else //data is invalid...
    {
      Serial.println("Error");
    }
  }
}

int bits_to_int(int bits[], int num_bits)
{
  int result = 0;
  int seed = 1;

  //Convert bits to integer
  for(int i = 0 ; i < num_bits ; i++)
  {
    if(bits[i] == 1)
    {
	result += seed;
    }

    seed *= 2;
  }

  return result;
}

int get_ir_key()
{
  int pulse[IR_BIT_LENGTH];
  int bits[IR_BIT_LENGTH];  

  do {} //Wait for a start bit
  while(pulseIn(IR_PIN, LOW) < BIT_START);

  read_pulse(pulse, IR_BIT_LENGTH);

  pulse_to_bits(pulse, bits, IR_BIT_LENGTH);

  return bits_to_int(bits, IR_BIT_LENGTH);
}
