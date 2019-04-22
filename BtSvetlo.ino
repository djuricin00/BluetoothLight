/*
 * Use arduino nano.
 * Pin D2 connect with rx on bluetooth module  
 * Pin D3 connect with tx on bluetooth module
 * Pin 5v connect to relay vcc 
 * Pin gnd connect to gnd on relay module
 * Pin d7 connect to trigger on relay.
 * 
 * Use apllication to turn light on or of.
 */
 
#include<SoftwareSerial.h>
#define rx 3    
#define tx 2
SoftwareSerial bt(tx,rx);
char c;

void setup() 
{
  pinMode(7,OUTPUT);
  bt.begin(9600);
  Serial.begin(9600);
}

void loop() 
{
 if(bt.available())
 {
  Serial.println("Connected");
  c = bt.read();
  Serial.println(c);
  if(c=='s') {digitalWrite(7,HIGH);}
  if(c=='w') {digitalWrite(7,LOW);} 
 }
}
