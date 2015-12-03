/* 
 *  
 */
 
// -----INCLUDES ----- 
#include <Adafruit_GFX.h>   // Core graphics library 
#include <RGBmatrixPanel.h> // Hardware-specific library 

// ----- PREPROCESSOR DEFS ----- 
#define CLK 11
#define LAT A3
#define OE 9
#define A A0
#define B A1
#define C A2
#define F2(progmem_ptr) (const __FlashStringHelper *)progmem_ptr
#define XSIZE 33
#define YSIZE 17

// ----- INIT VARS ----- 
int m=0;
int UpBtn = 53; 
int DnBtn = 47; 
int LfBtn = 43; 
int RtBtn = 37; 
int cordX = 0; 
int cordY = 5; 
int oldX = 0; 
int oldY = 15; 
int dlytm = 50;   // Amount of delay (in ms) to debounce on button presses 
int xcol;
int XmaxN=31;
int XmaxO=32;
int r;
int g;
int b;
int blockheight;
int blockSelect=2;
int DeleteSelect=2;
int heightSelect=2;

RGBmatrixPanel matrix(A, B, C, CLK, LAT, OE, false);


// Last parameter = 'false' disable double-buffering


void StartScreen()
{
  matrix.drawRect(0,0,32,16,matrix.Color333(0,153,0));
  matrix.setCursor(1,1);
  matrix.setTextSize(1);
  matrix.setTextColor(matrix.Color333(0,0,204));
  matrix.print('S');
  matrix.setTextColor(matrix.Color333(255,255,0)); 
  matrix.print('T');
  matrix.setTextColor(matrix.Color333(0,0,204));
  matrix.print('A');
  matrix.setTextColor(matrix.Color333(255,255,0)); 
  matrix.print('R');
  matrix.setTextColor(matrix.Color333(0,0,204));  
  matrix.print('T');
  matrix.setCursor(7,8);
  matrix.setTextColor(matrix.Color333(0,0,204));
  matrix.print('U');
  matrix.setTextColor(matrix.Color333(255,255,0)); 
  matrix.print('T');
  matrix.setTextColor(matrix.Color333(0,0,204));  
  matrix.print('C');
}
void BlankAREA()
{
  matrix.fillCircle(cordX,cordY,2,matrix.Color333(0,0,0));
}

void BlankAREA2()
{
  matrix.fillRect(cordX,cordY,1,4,matrix.Color333(0,0,0));
}


void BlankAREA3()
{
  matrix.fillRect(cordX,cordY,4,1,matrix.Color333(0,0,0));
}

int BlockShapeSquare(int cordX, int cordY,int blockheight, int r,int g, int b)
{
 matrix.drawPixel(cordX,cordY,matrix.Color333(r,g,b));
 matrix.drawPixel(cordX-1,cordY-1,matrix.Color333(r,g,b));
 matrix.drawPixel(cordX-1,cordY,matrix.Color333(r,g,b));
 matrix.drawPixel(cordX,cordY-1,matrix.Color333(r,g,b));
 blockheight=2;
}

void BlockShapePlank0(int cordX, int cordY, int r, int g, int b)
{
 matrix.drawPixel(cordX,cordY,matrix.Color333(r,g,b));
 matrix.drawPixel(cordX,cordY+1,matrix.Color333(r,g,b));
 matrix.drawPixel(cordX,cordY+2,matrix.Color333(r,g,b));
 matrix.drawPixel(cordX,cordY+3,matrix.Color333(r,g,b));
 blockheight=4;
}

void BlockShapePlank1()
{
 matrix.drawPixel(cordX,cordY,matrix.Color333(0,255,0));
 matrix.drawPixel(cordX+1,cordY,matrix.Color333(0,255,0));
 matrix.drawPixel(cordX+2,cordY,matrix.Color333(0,255,0));
 matrix.drawPixel(cordX+3,cordY,matrix.Color333(0,255,0));
}


void BlockShapeL0()
{
  matrix.drawPixel(cordX,cordY,matrix.Color333(255,0,0));
  matrix.drawPixel(cordX-1,cordY,matrix.Color333(255,0,0));
  matrix.drawPixel(cordX-1,cordY+1,matrix.Color333(255,0,0));
  matrix.drawPixel(cordX-1,cordY+2,matrix.Color333(255,0,0));
}
void BlockShapeL1(int cordX, int cordY,int blockheight, int r, int g, int b)
{
  matrix.drawPixel(cordX,cordY,matrix.Color333(r,g,b));
  matrix.drawPixel(cordX,cordY-1,matrix.Color333(r,g,b));
  matrix.drawPixel(cordX-1,cordY-1,matrix.Color333(r,g,b));
  matrix.drawPixel(cordX-2,cordY-1,matrix.Color333(r,g,b));
  blockheight=3;
}
void BlockShapeL3()
{
  matrix.drawPixel(cordX,cordY,matrix.Color333(255,0,0));
  matrix.drawPixel(cordX,cordY+1,matrix.Color333(255,0,0));
  matrix.drawPixel(cordX+1,cordY+1,matrix.Color333(255,0,0));
  matrix.drawPixel(cordX+2,cordY+1,matrix.Color333(255,0,0));
}
void BlockShapeL2()
{
  matrix.drawPixel(cordX,cordY,matrix.Color333(255,0,0));
  matrix.drawPixel(cordX+1,cordY,matrix.Color333(255,0,0));
  matrix.drawPixel(cordX+1,cordY-1,matrix.Color333(255,0,0));
  matrix.drawPixel(cordX+1,cordY-2,matrix.Color333(255,0,0));
}
int DeleteShapeL1(int cordX,int cordY,int r, int g,int b)
{
  matrix.drawPixel(cordX-1,cordY,matrix.Color333(r,g,b));
  matrix.drawPixel(cordX-2,cordY,matrix.Color333(r,g,b));
  matrix.drawPixel(cordX-3,cordY-1,matrix.Color333(r,g,b));
  blockheight=3;
}
int DeleteShapeSquare(int cordX, int cordY,int blockheight, int r,int g, int b)
{
 matrix.drawPixel(cordX-2,cordY,matrix.Color333(r,g,b));
 matrix.drawPixel(cordX-2,cordY-1,matrix.Color333(r,g,b));
 blockheight=2;
}

void CallBlock(int blockSelect)
{
  switch(blockSelect){
    case 1: 
      BlockShapeL1(cordX,cordY,blockheight,7,0,0); 
      break; 
    case 2: 
      BlockShapeSquare(cordX,cordY,blockheight,0,0,7); 
      break; 
    case 3: 
      BlockShapePlank0(cordX,cordY,0,7,0); 
      break; 
    case 4:
      //BlockShape??(); 
      break; 
    case 5: 
      //BlockShape??(); 
      break; 
    case 6: 
      //BlockShape??(); 
      break; 
    case 7: 
      //BlockShape??(); 
      break; 
    default: 
      break; 
  }
}
void CallDelete(int DeleteSelect)
{
  switch(DeleteSelect){
    case 1: 
      DeleteShapeL1(cordX,cordY,0,0,0); 
      break; 
    case 2: 
      DeleteShapeSquare(cordX,cordY,blockheight,0,0,0); 
      break; 
    case 3: 
      BlockShapePlank0(cordX-4,cordY,0,0,0); 
      break; 
    case 4:
      //BlockShape??(); 
      break; 
    case 5: 
      //BlockShape??(); 
      break; 
    case 6: 
      //BlockShape??(); 
      break; 
    case 7: 
      //BlockShape??(); 
      break; 
    default: 
      break; 
  }
}
void CallHeight(int heightSelect)
{
  switch(heightSelect){
    case 1: 
      blockheight=3; 
      break; 
    case 2: 
      blockheight=2;
      break; 
    case 3: 
      blockheight=4;
      break; 
    case 4:
      //BlockShape??(); 
      break; 
    case 5: 
      //BlockShape??(); 
      break; 
    case 6: 
      //BlockShape??(); 
      break; 
    case 7: 
      //BlockShape??(); 
      break; 
    default: 
      break;
}}
boolean bufferBoard[XSIZE+2][YSIZE+2];//Creates array with a DEAD cell border
boolean board[XSIZE+2][YSIZE+2];

void printBoard()
{ //Draws pixels on LED board
 for( int i=1;i<33;i++){
 for( int n=1;n<17;n++){
     if(board[i][n] != 1) matrix.drawPixel(i-1, n-1, matrix.Color333(0, 0, 0));
     else matrix.drawPixel(i-1, n-1, matrix.Color333(r, g, b));
   }
   }
}


void setup() 
{
 
  matrix.begin(); 
  //StartScreen();
  //matrix.drawPixel(cordX,cordY,matrix.Color333(0,255,0)); 
  //BlockShapeL1();
  //BlockShapeSquare();
  //BlockShapePlank();

//
//  delay(100);
//  matrix.fillScreen(0);
//  matrix.setCursor(10,1);
//  matrix.setTextColor(matrix.Color333(0,0,204));
//  matrix.print('G');
//  matrix.setTextColor(matrix.Color333(255,255,0)); 
//  matrix.print('O');
//  
//  matrix.setCursor(2,8);
//  matrix.setTextColor(matrix.Color333(0,0,204));
//  matrix.print('M');
//  matrix.setTextColor(matrix.Color333(255,255,0)); 
//  matrix.print('O');
//  matrix.setTextColor(matrix.Color333(0,0,204));  
//  matrix.print('C');
//  matrix.setTextColor(matrix.Color333(255,255,0));
//  matrix.print('S');
//  matrix.setTextColor(matrix.Color333(0,0,204)); 
//  matrix.print('!');
//  delay(1000);
//  matrix.fillScreen(0);
//  delay(500);

  
  
}
void loop() 
{
CallBlock(blockSelect);
CallDelete(DeleteSelect);
CallHeight(heightSelect);
BlockShapeL1(10,9,3,7,7,7);
//BlockShapeSquare(cordY,cordX,0,7,0);
//BlockShapeSquare(cordY-2,cordX,0,0,0);
if(cordX != XmaxO)
{
  cordX=cordX+1;
}
if(cordX==XmaxO)
{
  XmaxN=XmaxO-blockheight;
  XmaxO=XmaxN;
  blockSelect=random(1,3);
  DeleteSelect=blockSelect;
  heightSelect=blockSelect;
  cordX=0;
}
if(XmaxN<-1)
{
  matrix.fillScreen(0);
  StartScreen();
  delay(5000);
}
  
delay(100);



 }


