/* 
  RemoteControl.ino  
  
  While loaded with this file, the Arduino Esplora will 
  perform the following functions: 
  
  - While SWITCH_1 pressed, output HIGH to PIN8 
  - While SWITCH_2 pressed, output HIGH to PIN0 
  - While SWITCH_3 pressed, output HIGH to PIN7 
  - While SWITCH_4 pressed, output HIGH to PIN1 
  - ELSE, output LOW to all above pins 
  
  Author: Ben Evans 
*/ 

#include <Esplora.h> 

void setup()
{
  
}

void loop()
{
       if(!(Esplora.readButton(SWITCH_1))){
    Esplora.writeRGB(255,255,255); 
    digitalWrite(8,HIGH); 
  }
  else if(!(Esplora.readButton(SWITCH_2))){
    Esplora.writeRGB(255,0,0); 
    digitalWrite(0,HIGH); 
  }
  else if(!(Esplora.readButton(SWITCH_3))){
    Esplora.writeRGB(0,255,0); 
    digitalWrite(7,HIGH); 
  }
  else if(!(Esplora.readButton(SWITCH_4))){
    Esplora.writeRGB(0,0,255); 
    digitalWrite(1,HIGH); 
  }
  else {
    Esplora.writeRGB(0,0,0); 
    digitalWrite(0,LOW); 
    digitalWrite(1,LOW); 
    digitalWrite(7,LOW); 
    digitalWrite(8,LOW); 
  }
  
}

