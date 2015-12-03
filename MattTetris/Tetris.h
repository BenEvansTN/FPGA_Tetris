#ifndef TetrisFuncs_h
#define TetrisFuncs_h

#include <Adafruit_GFX.h>   // Core graphics library 
#include <RGBmatrixPanel.h> // Hardware-specific library 

RGBmatrixPanel matrix(A, B, C, CLK, LAT, OE, false);


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
  }
}


void printBoard()
{ //Draws pixels on LED board
  for( int i=1;i<33;i++){
    for( int n=1;n<17;n++){
      if(board[i][n] != 1) matrix.drawPixel(i-1, n-1, matrix.Color333(0, 0, 0));
      else matrix.drawPixel(i-1, n-1, matrix.Color333(r, g, b));
    }
  }
}


#endif
