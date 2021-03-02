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
#include <math.h>

// dimensions of the display window and define other things needed for this program
#define WINDOWWIDTH       800
#define WINDOWHEIGHT      600

#define PI   3.141592653







// RGB colors screen background


#define BACKCOLOR         0, 0, 0
#define pointcolor      255, 0, 0
// handy boolean constants
typedef enum _bool{FALSE, TRUE} bool;
int clicked;
int i = 0;
int j;
int x;
int y;
bool p;
bool k;
EZ_Point points[1001];
// display routine, called from EZ_HandleEvents every 1/30 of a second


void updateDisplay(){
  EZ_SetBackColor(BACKCOLOR);   // specify background color for the drawing
  EZ_ClearDrawing();            // clear the drawing to the background color

  if(clicked){
	EZ_SetColor(pointcolor);
	EZ_FillCircle(points[i].x, points[i].y, 5);
}
for(j = 0; j<1000; j++){
  EZ_DrawPoint(points[j].x, points[j].y);
  EZ_FillCircle(points[j].x, points[j].y, 5);
}

if(p){
 EZ_DrawLine(points[i].x, points[i].y, points[0].x, points[0].y);

}
  //EZ_DrawPoint(points[i].x, points[i].y);
  EZ_FillCircle(points[i].x, points[i].y, 5);
  EZ_FillCircle(points[j].x, points[j].y, 5);
  EZ_DrawLineStrip(points, i);

  EZ_DisplayDrawing();          // send the new drawing to the screen
}
// keyboard routine, print out the key that was pressed
void handleKey(unsigned char press){
  printf("k %c\n", press);
  if(press == 'd'){
    p = TRUE;
  }

}

// mouse button routine, print out the button status and mouse position
void handleButton(int updown, int mousex, int mousey){
  printf("b %d (%d, %d)\n", updown, mousex, mousey);
  clicked = updown;
  if(clicked == 0){
    i++;
  }
  points[i].x = mousex;
  points[i].y = mousey;

}

// mouse motion routine, print out the mouse position, and change in position
void handleMouseMotion(int mousex, int mousey, int dmousex, int dmousey){
  printf("m (%d, %d) (%d, %d)\n", mousex, mousey, dmousex, dmousey);
  points[i].x = mousex;
  points[i].y = mousey;
}

int main() {
  int quit = FALSE;

  EZ_Init(WINDOWWIDTH, WINDOWHEIGHT, "Polygon");

  while(!quit){
    quit = EZ_HandleEvents(updateDisplay, handleKey, handleButton, handleMouseMotion);
  }

  EZ_Quit();

  return 0;
}
