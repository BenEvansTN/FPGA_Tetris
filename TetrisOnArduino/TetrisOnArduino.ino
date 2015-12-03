
#include <Adafruit_GFX.h>   // Core graphics library
#include <RGBmatrixPanel.h> // Hardware-specific library
#define CLK 11
#define LAT A3
#define OE 9
#define A A0
#define B A1
#define C A2

int UpBtn = 37; 
int DnBtn = 35; 
int LfBtn = 33; 
int RtBtn = 31; 
int newX = 15; 
int newY = 7; 
int oldX = 7; 
int oldY = 15; 
int dlytm = 50;   // Amount of delay (in ms) to debounce on button presses 

// Last parameter = 'false' disable double-buffering
RGBmatrixPanel matrix(A, B, C, CLK, LAT, OE, false);


void setup() 
{
  matrix.begin(); 
  matrix.drawPixel(newX,newY,matrix.Color333(0,255,0)); 
}

void loop() {

  if(digitalRead(UpBtn))
  {
    delay(dlytm); 
    if(digitalRead(UpBtn))
    {
      oldY = newY;
      newY = oldY+1; 
    }
    delay(dlytm); 
  }
  
  if(digitalRead(DnBtn))
  {
    delay(dlytm); 
    if(digitalRead(DnBtn))
    {
      oldY = newY;
      newY = oldY-1; 
    }
    delay(dlytm); 
  }
  
  if(digitalRead(LfBtn))
  {
    delay(dlytm); 
    if(digitalRead(LfBtn))
    {
      oldX = newX;
      newX = oldX-1; 
    }
    delay(dlytm); 
  }
  
  if(digitalRead(RtBtn))
  {
    delay(dlytm); 
    if(digitalRead(RtBtn))
    {
      oldX = newX;
      newX = oldX+1; 
    }
    delay(dlytm); 
  }




  // Clear old: 
  matrix.fillScreen(matrix.Color333(0,0,0)); 
  // Draw new: 
  matrix.drawPixel(newX,newY,matrix.Color333(0,255,0)); 

    
  if(newX>31)
  {
    newX = 0; 
  }
  if(newY>15)
  {
    newY = 1; 
  }
  
}


