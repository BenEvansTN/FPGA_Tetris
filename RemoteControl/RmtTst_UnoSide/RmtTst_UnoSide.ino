/* 
  Test Sketch for reading input from Esplora 
*/ 

int readUp = 8; 
int readDn = 9; 
int readLf = 10; 
int readRt = 11; 
int ledPin = 13; 
int blinkDelay = 100; 
int debncDelay = 50; 

void blinkTimes(int i); 
boolean debncdRead(int pin); 

void setup() 
{
  pinMode(ledPin,OUTPUT); 
  pinMode(readUp,INPUT); 
  pinMode(readDn,INPUT); 
  pinMode(readLf,INPUT); 
  pinMode(readRt,INPUT); 
}

void loop() 
{
  if(debncdRead(readUp)) blinkTimes(1); 
  if(debncdRead(readDn)) blinkTimes(2); 
  if(debncdRead(readLf)) blinkTimes(3); 
  if(debncdRead(readRt)) blinkTimes(4); 
}

// ---------- 

void blinkTimes(int times)
{
  for(int i=0;i<times;i++)
  {
    digitalWrite(ledPin,HIGH); 
    delay(blinkDelay); 
    digitalWrite(ledPin,LOW); 
    delay(blinkDelay); 
  }
}

boolean debncdRead(int pin) 
{
  if(digitalRead(pin)) 
  {
    delay(debncDelay); 
    if(digitalRead(pin)) 
    {
      return true; 
    }
  }
  return false; 
}


