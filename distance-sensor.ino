#include <LiquidCrystal.h>
int seconds = 0;

//LCD Pin Configurations
LiquidCrystal lcd(7,6, 5, 4, 3, 2);

const int trigPin = 8;
const int echoPin = 9;

float time, distanceCm;
String message, message2;

void setup()
{
  lcd.begin(16, 2);
	
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop()
{
  //Required when using Ultrasonic Sensor
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  time = pulseIn(echoPin, HIGH);
  distanceCm = (time*0.034)/2;
  
  //Decision Statements for Sensor Values
  if (distanceCm < 51){
    message = "STOP            ";
    message2 = "               ";
  } 
  else if (distanceCm >= 51 && distanceCm <101){
    message = "SLOW DOWN       ";
    message2 = "               ";
  } 
  else if (distanceCm >= 101 && distanceCm <=301){
    message = "OBJECT          ";
    message2 = "APPROACHING    ";
  } 
  else {
    message = "                ";
    message2 = "               ";
  }
  
  lcd.setCursor(0,0);
  lcd.print(message);
  lcd.setCursor(0,1);
  lcd.print(message2);
  
}