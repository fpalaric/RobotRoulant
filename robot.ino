#include <Stepper.h>

#define L 0.215 // Empattement robot

#define consigneX 2
#define consigneY 1

volatile boolean TurnDetected;  // need volatile for Interrupts
volatile boolean rotationdirection;  // CW or CCW rotation

const int PinCLK=2;   // Generating interrupts using CLK signal
const int PinDT=3;    // Reading DT signal

// Moteur propulsion 
const int PinIN1 = 6;
const int PinIN2 = 5;
const int PinEN = 7;

double distToRun;      // How much to move (meters)

// Stepper motor, pour la direction
float  consigneAngleRoue;
const int stepsPerRevolution = 2048;  // change this to fit the number of steps per revolution
const int rolePerMinute = 15;         // Adjustable range of 28BYJ-48 stepper is 0~17 rpm
Stepper myStepper(stepsPerRevolution, 8, 10, 9, 11);

// Interrupt routine runs if CLK goes from HIGH to LOW
void isr ()  {
  delay(4);  // delay for Debouncing
  distToRun -= 0.00946; // 
  Serial.println(distToRun);
}

void setup ()  {
pinMode(PinIN1,OUTPUT);
pinMode(PinIN2,OUTPUT);
pinMode(PinEN,OUTPUT);
pinMode(PinCLK,INPUT);
pinMode(PinDT,INPUT);  
myStepper.setSpeed(rolePerMinute);
Serial.begin(9600);
attachInterrupt (0,isr,FALLING); // interrupt 0 always connected to pin 2 on Arduino UNO
InitDistToRun(consigneX,consigneY, &distToRun);
InitAngleConsigneRoue(consigneX, consigneY, &consigneAngleRoue);
analogWrite(PinEN,0);
digitalWrite(PinIN1,LOW);
digitalWrite(PinIN2,LOW);
InitPositionRoue();
analogWrite(PinEN,255);
digitalWrite(PinIN1,HIGH);
digitalWrite(PinIN2,LOW);
}

void loop ()  {
  if(distToRun <= 0)
  {
    analogWrite(PinEN,0);
    digitalWrite(PinIN1,LOW);
    digitalWrite(PinIN2,LOW);    
  }      
}

void InitDistToRun(int x, int y, double* distToRun)
{
  float a = (pow(x,2)+pow(y,2))/(2*y);
  *distToRun = (3.14/2 - sin((a-y)/(sqrt(pow(x,2)+pow((a-y),2))))) * a;
  Serial.println(*distToRun);
}

void InitAngleConsigneRoue(int x, int y, float* consigneAngleRoue)
{
  float a = (pow(x,2)+pow(y,2))/(2*y);
  float consigneAngleRoueRad = - atan(a/L) + 3.14/2; 
  *consigneAngleRoue = (consigneAngleRoueRad * 180)/(3.14/2);
  Serial.println(*consigneAngleRoue);
}

void InitPositionRoue()
{
      delay(5000);
      myStepper.step(440);
      myStepper.step(-220);
      float consigneStep = (consigneAngleRoue * 2048)/ 360;
      myStepper.step(consigneStep);
      Serial.println(consigneStep);
      Serial.println("fin Init");
}

