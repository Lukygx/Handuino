
#include <SoftwareSerial.h>

SoftwareSerial HC12(2, 3); // HC-12 TX Pin, HC-12 RX Pin

int boutonCalibrage=4;
int led=5;

int ResThumb   = A4;  
int ResIndex   = A3;  
int ResMiddle  = A2;
int ResAnnular = A1;
int ResPinky   = A0;

int OpenedThumb; // Variables main ouverte pour le mappage
int OpenedIndex; 
int OpenedMiddle;
int OpenedAnnular;
int OpenedPinky;

int ClosedThumb;      // Variables main fermé pour le mappage 
int ClosedIndex;      
int ClosedMiddle;     
int ClosedAnnular;    
int ClosedPinky;      

int thumb   =0;       // Variables à envoyer
int index   =0;
int middle  =0;
int annular =0;
int pinky   =0;


void setup()
{
 
  pinMode(ResThumb,   INPUT);   
  pinMode(ResIndex,   INPUT);
  pinMode(ResMiddle,  INPUT);
  pinMode(ResAnnular, INPUT);
  pinMode(ResPinky,   INPUT);
  pinMode(led,OUTPUT);
  pinMode(boutonCalibrage,INPUT);

 Serial.begin(9600);             
  HC12.begin(9600);       
  
}

void loop()
{


if (digitalRead(boutonCalibrage)==HIGH){  // calibrage du gant 
  digitalWrite(led,HIGH);                 //main ouverte 
  delay(5000);
  Serial.println("HIGHT");
  OpenedThumb   = analogRead(ResThumb);  
  OpenedIndex   = analogRead(ResIndex);  
  OpenedMiddle  = analogRead(ResMiddle); 
  OpenedAnnular = analogRead(ResAnnular);
  OpenedPinky   = analogRead(ResPinky);  
  digitalWrite(led,LOW);
  Serial.println("LOW");
  delay(3000);
  digitalWrite(led,HIGH);                  //main fermée
  Serial.println("high");
  delay(5000);
  ClosedThumb   = analogRead(ResThumb);  
  ClosedIndex   = analogRead(ResIndex);  
  ClosedMiddle  = analogRead(ResMiddle); 
  ClosedAnnular = analogRead(ResAnnular);
  ClosedPinky   = analogRead(ResPinky); 
  Serial.println("low");
  digitalWrite(led,LOW);
  delay(1000);

  
}



  
  thumb   = analogRead(ResThumb);  
  index   = analogRead(ResIndex);  
  middle  = analogRead(ResMiddle); 
  annular = analogRead(ResAnnular);
  pinky   = analogRead(ResPinky);  
  //Serial.println(ClosedAnnular);
  //Serial.println(OpenedAnnular);
  
  
  
  thumb   = map(thumb  ,ClosedThumb ,OpenedThumb  ,0,180);  // on déduit un angle pour chaque doit 
  index   = map(index  ,ClosedIndex  ,OpenedIndex  ,0,180);  
  middle  = map(middle ,ClosedMiddle ,OpenedMiddle ,0,180);
  annular = map(annular,ClosedAnnular,OpenedAnnular,0,180);  
  pinky   = map(pinky  ,ClosedPinky  ,OpenedPinky ,0,180);
  
  HC12.write("<");      // on signal qu'on envoit une série de mesure
  //HC12.write(thumb);
  //HC12.write(index);
  //HC12.write(middle);
  Serial.println(middle);
  HC12.write(thumb); 
  HC12.write(annular);
  HC12.write(index);
  HC12.write(middle);
  
  delay(30);
}
