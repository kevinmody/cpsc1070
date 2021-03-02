//
// helloworld.c
// Simple drawing program to draw a rectangle on the screen
// Using the EZ Draw interface, for CPSC 1070, Fall 2019
//
// Donald House, 8/26/19
// Clemson University
//
#include "ezdraw.h"
#include <stdio.h>

// dimensions of the display window
#define WINDOWWIDTH       1200
#define WINDOWHEIGHT      800

// coordinates of the rectangle are relative to the window
#define facex0         (WINDOWWIDTH / 2)
#define facey0     (WINDOWHEIGHT / 2)

#define faceradius (WINDOWHEIGHT / 4)

// RGB colors for the rectangle and screen background
// note: R, G, and B are on a scale from 0 to 255
#define faceCOLOR         200, 100, 50
#define backCOLOR         70, 100, 140
#define eyeCOLOR           0, 0, 0

// handy boolean constants
enum boolean{FALSE, TRUE};

// display routine, called from EZ_HandleEvents every 1/30 of a second
void updateDisplay(){
  EZ_SetBackColor(backCOLOR);   // specify background color for the drawing
  EZ_ClearDrawing();            // clear the drawing to the background color
  
  EZ_SetColor(faceCOLOR);       // specify the color to be used to draw
  EZ_FillCircle(faceX0, faceY0, faceradius); // draw the rectangle
  
  EZ_DisplayDrawing();          // send the new drawing to the screen
}

int main() {
  int quit = FALSE;
  
  EZ_Init(WINDOWWIDTH, WINDOWHEIGHT, "Hello World");
  
  while(!quit){
    quit = EZ_HandleEvents(updateDisplay, NULL, NULL, NULL);
  }
  
  EZ_Quit();

  return 0;
}
