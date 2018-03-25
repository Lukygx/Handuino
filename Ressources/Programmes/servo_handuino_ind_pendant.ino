

#include <Servo.h>

Servo pouce;
Servo index; 
Servo majeur; 
Servo annulaire; 
Servo auriculaire; // create servo object to control a servo

int val1;
int val2;
int val3;
int val4;
int val5;

void setup() {
  pouce.attach(2);
  index.attach(3);
  majeur.attach(4);
  annulaire.attach(5);
  auriculaire.attach(6);
}

void loop() {
  val1 = analogRead(0);           
  val1 = map(val1, 0, 1023, 0, 180); 
  val2 = analogRead(0);           
  val2 = map(val2, 0, 1023, 0, 180); 
  val3 = analogRead(0);           
  val3 = map(val3, 0, 1023, 0, 180); 
  val4 = analogRead(0);           
  val4= map(val4, 0, 1023, 0, 180); 
  val5 = analogRead(0);           
  val5 = map(val5, 0, 1023, 0, 180);     
  pouce.write(val1);
  pouce.write(val2);
  pouce.write(val3);
  pouce.write(val4);
  pouce.write(val5);
  delay(15);                           
}
