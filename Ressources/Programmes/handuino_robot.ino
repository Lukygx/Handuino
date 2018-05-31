#include <Servo.h>   

#include <SoftwareSerial.h>

SoftwareSerial HC12 (7,8);

Servo ServoThumb, ServoIndex,        
ServoMiddle, ServoAnnular, ServoPinky;

byte startPackage;   

int AngThumb   = 0;   // Variables avec les angles de rotation
int AngIndex   = 0;
int AngMiddle  = 0;
int AngAnnular = 0;
int AngPinky   = 0;


void setup()
{
  Serial.begin(9600);     
  HC12.begin(9600);
  ServoThumb.attach(2);
  ServoIndex.attach(3);   
  ServoMiddle.attach(4);
  ServoAnnular.attach(5);
  ServoPinky.attach(6);
  
  Serial.println("Setup Ok"); 
}

void loop(){ 
  if(HC12.available()) {    
    
    startPackage = HC12.read(); 
    AngThumb = HC12.read();
    AngAnnular   = HC12.read();
    AngIndex = HC12.read();
    AngMiddle= HC12.read();
  //Serial.println(AngAnnular);

    
    
    if(startPackage == '<'){   // on vérifie si la 1 er valeur envoyé par la main est "<"
    
      if(AngThumb!=255)  
      ServoThumb.write(AngThumb);  
                                                    
      if(AngIndex!=255)
      ServoIndex.write(AngIndex);
    
      if(AngMiddle!=255)
      ServoMiddle.write(AngMiddle);
    
      if(AngAnnular!=-1)
      ServoAnnular.write(AngAnnular);
    
      if(AngPinky!=255)
      ServoPinky.write(AngPinky);
          
    }
  }
  delay(30); 
}

