#include <LCD4Bit_mod.h> 
LCD4Bit_mod lcd = LCD4Bit_mod(2);

const int lontaktuSkaits = 10;
// Right, Up, Down, Left, OK
int keyValues[5] = {30, 150, 360, 535, 760 };
char keyChars[5] = {'R', 'U', 'D', 'L', 'O'};
int pressedKey = -1;
int ppressedKey = -1;

int atvertaaLapa = 0; //:P Latviski

String catalogNames[lontaktuSkaits] =
{
  "Kristians",
  "Dinija :D",
  "Kontakt1",
  "Kontakt2",
  "Kontakt3",
  "Kontakt4",
  "Kontakt5",
  "Kontakt6",
  "Kontakt7",
  "Kontakt8",
};

String catalogNumbers[lontaktuSkaits] =
{
  "25945410",
  "20000000",
  "20000001",
  "20000002",
  "20000003",
  "20000004",
  "20000005",
  "20000006",
  "20000007",
  "20000008",
};

void setup()
{
  pinMode(13, OUTPUT);
  lcd.init();
   lcd.clear();
  lcd.printIn("Nummuru katalogs");
  delay(1000);
  lcd.clear();
}

void loop()
{
  int i = getKey(analogRead(0));
  if(i != -1) pressedKey = keyChars[i];
  else pressedKey = -1;
  
  if(ppressedKey != pressedKey)
  {
    if(pressedKey != -1)
    onKeyPressed(pressedKey);
  }
  
  ppressedKey = pressedKey;
  
  if(atvertaaLapa < 0)
  atvertaaLapa = lontaktuSkaits-1;
  if(atvertaaLapa >= lontaktuSkaits)
  atvertaaLapa = 0;
}

void onKeyPressed(char c)
{
  boolean b = true;
  
  if(c == 'U') atvertaaLapa--;
  else if(c == 'D') atvertaaLapa++;
  else b = false;
  
  if(b)
  {
    lcd.clear();
    lcd.cursorTo(0, 0);
    println(catalogNames[atvertaaLapa]);
    lcd.cursorTo(0, 1);
    println(catalogNumbers[atvertaaLapa]);
  }
}

int getKey(unsigned int input)
{ int k; for (k = 0; k < 5; k++)
{ if (input < keyValues[k])
{ return k; } }
if (k >= 5) k = -1; return k; }

void println(String s)
{
  for(int i = 0; i < s.length(); i++)
  lcd.print(s.charAt(i));
}
