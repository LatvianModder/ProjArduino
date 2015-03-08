#define led1ON digitalWrite(11, HIGH);
#define led1OFF digitalWrite(11, LOW);
#define led2ON digitalWrite(8, HIGH);
#define led2OFF digitalWrite(8, LOW);
#define led3ON digitalWrite(12, HIGH);
#define led3OFF digitalWrite(12, LOW);
#define led4ON digitalWrite(13, HIGH);
#define led4OFF digitalWrite(13, LOW);
#define button1 !digitalRead(4)//If pressed, returns TRUE
#define button2 !digitalRead(5)
#define SEN_BACK analogRead(A5)<50//White returns TRUE, black returns FALSE
#define SEN_LEFT analogRead(A4)<50
#define SEN_RIGHT analogRead(A3)<50
#define MaxSpeed 125
#define MediumSpeed 100
#define LowSpeed 90

int STATE = 0;
int START = 2;
int DRIVE = 224;
int TEST = 352;

int sensorValue,TestType=0;
long startTime,startTime2;
long elapsedTime,elapsedTime2;
int SHARPreadcount=0;
int Sens=0;
int State=0,OldState=0;
int SHARPon=1;
