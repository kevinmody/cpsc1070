//
// events.c
// helloworld demo program expanded to show by a printout
// whenever an event each is processed in EZ Draw
// for CPSC 1070, Fall 2019
//
// Donald House, 8/26/19
// Clemson University
//
#include "ezdraw.h"
#include <stdio.h>

// dimensions of the display window
#define WINDOWWIDTH       800
#define WINDOWHEIGHT      600

// coordinates of the rectangle are relative to the window
#define RECTWIDTH         (WINDOWWIDTH / 2)
#define RECTHEIGHT        (WINDOWHEIGHT / 2)
#define RECTX0            ((WINDOWWIDTH - RECTWIDTH) / 2)
#define RECTY0            ((WINDOWHEIGHT - RECTHEIGHT) / 2)

// RGB colors for the rectangle and screen background
// note: R, G, and B are on a scale from 0 to 255
#define RECTCOLOR         200, 100, 50
#define BACKCOLOR         70, 100, 140

// handy boolean constants
enum boolean{FALSE, TRUE};

// display routine, called from EZ_HandleEvents every 1/30 of a second
void updateDisplay(){
  EZ_SetBackColor(BACKCOLOR);   // specify background color for the drawing
  EZ_ClearDrawing();            // clear the drawing to the background color
  
  EZ_SetColor(RECTCOLOR);       // specify the color to be used to draw
  EZ_FillRect(RECTX0, RECTY0, RECTWIDTH, RECTHEIGHT); // draw the rectangle
  
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
