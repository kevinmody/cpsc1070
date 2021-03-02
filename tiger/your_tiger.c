/*
Author: Kevin Mody
Lab 3 Tiger EZDraw
*/
#include"ezdraw.h"
#include<stdio.h>

//display window
#define WINDOWWIDTH    1200
#define WINDOWHEIGHT   800


#define faceX0 (WINDOWWIDTH /2)
#define faceY0  (WINDOWHEIGHT/2)
#define faceradius  (WINDOWHEIGHT/4)

#define eye1X0 (500)
#define eye2X0 (700)
#define eyeY0 (475)
#define ear1X0 400
#define earY0 500
#define ear2X0 800

#define earradius 50
#define eyeradius 30 

#define facecolor 200, 100, 50
#define eye1color 0, 0, 0
#define eye2color 0, 0, 0

#define ear1color 200, 100, 50
#define ear2color 200, 100, 50
#define BACKCOLOR 70, 100, 140


enum boolean{FALSE, TRUE};

// display routine, called from EZ_HandleEvents every 1/30 of a second
void updateDisplay(){
  EZ_SetBackColor(BACKCOLOR);   // specify background color for the drawing
  EZ_ClearDrawing();            // clear the drawing to the background color
  
  EZ_SetColor(facecolor);       // specify the color to be used to draw
  EZ_FillCircle(faceX0, faceY0, faceradius); // draw the face
  
  EZ_SetColor(ear1color);
  EZ_FillCircle(ear1X0, earY0, earradius);

  EZ_SetColor(ear2color);
  EZ_FillCircle(ear2X0, earY0, earradius);

  EZ_SetColor(eye1color);
  EZ_FillCircle(eye1X0, eyeY0, eyeradius);

  EZ_SetColor(eye2color);
  EZ_FillCircle(eye2X0, eyeY0, eyeradius);


  EZ_DisplayDrawing();          // send the new drawing to the screen
}

// keyboard routine, print out the key that was pressed
void handleKey(unsigned char key){
  printf("k %c\n", key);
}

// mouse button routine, print out the button status and mouse position
void handleButton(int updown, int mousex, int mousey){
  printf("b %d (%d, %d)\n", updown, mousex, mousey);
}




// mouse motion routine, print out the mouse position, and change in position
void handleMouseMotion(int mousex, int mousey, int dmousex, int dmousey){
  printf("m (%d, %d) (%d, %d)\n", mousex, mousey, dmousex, dmousey);
}

int main() {
  int quit = FALSE;
  
  EZ_Init(WINDOWWIDTH, WINDOWHEIGHT, "Hello World");
  
  while(!quit){
    quit = EZ_HandleEvents(updateDisplay, handleKey, handleButton, handleMouseMotion);
  }
  
  EZ_Quit();

  return 0;
}




