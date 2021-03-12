/*
Author: Kevin Mody
Hw2 EZDraw
Date: 02/12/2020
*/
#include"ezdraw.h"
#include<stdio.h>

//display window
#define WINDOWWIDTH    1200 //window width
#define WINDOWHEIGHT  800  //window height


#define rectwidth 700  //rectangle 1 width
#define rectheight 75  //rectangle 1 height
#define rectX0 200  //rectangle 1 starting point x-axis
#define rectY0 200  //rectangle 1 starting point y-axis

#define rect2width  175 //rectangle 2 width 
#define rect2height 150 //rectangle 2 height
#define rect2X0 725 //recrangle 2 starting point 

#define rect3width (rect2width-50) //rectangle 3 width
#define rect3height (rect2height-50) //rectangle 3 height
#define rect3X0 750 //rectangle 3 starting point x-axis
#define rect3Y0 225 //rectangle 3 starting point y-axis

//below is the RGB colors for each pieces
#define rectcolor  210, 105, 30 
#define rect2color 255, 222,173
#define backcolor  255, 255, 255
#define rect3color 202, 228, 241

#define buttoncolor 186, 186, 174

//below is the size, starting point and the RGB color of bubble
#define bubbleX0  812.5
#define bubblerad 55
#define bubblecolor 162, 232, 232

//handy boolean
enum boolean{FALSE, TRUE};
int clicked;
int bubbley = 300;
double i = 0;

// display routine, called from EZ_HandleEvents every 1/30 of a second
void updateDisplay(){
  EZ_SetBackColor(backcolor);   // specify background color for the drawing
  EZ_ClearDrawing();            // clear the drawing to the background color
 
if(clicked){
  bubbley = bubbley + 5;
  EZ_SetColor(bubblecolor); //specify color for bubble
  EZ_OutlineCircle(bubbleX0, bubbley, bubblerad);
  EZ_FillCircle(bubbleX0, bubbley, bubblerad+i); //daw bubble
  i = i + .98;
}

  
  EZ_SetColor(rectcolor); //specify color for rect1
  EZ_FillRect(rectX0, rectY0, rectwidth, rectheight); //draw rect1

  EZ_SetColor(rect2color); //specify color for rect2
  EZ_FillRect(rect2X0, rectY0, rect2width, rect2height); //draw rect2

  EZ_SetColor(rect3color); //specify color for rect3
  EZ_FillRect(rect3X0, rect3Y0, rect3width, rect3height); //draw rect3

  EZ_DisplayDrawing();  //send the new drawing to the screen

}

// keyboard routine, print out the key that was pressed
void handleKey(unsigned char key){
  printf("k %c\n", key);
}


// mouse motion routine, print out the mouse position, and change in position
void handleMouseMotion(int mousex, int mousey, int dmousex, int dmousey){
  printf("m (%d, %d) (%d, %d)\n", mousex, mousey, dmousex, dmousey);
}

// mouse button routine, print out the button status and mouse position
void handleButton(int updown, int mousex, int mousey){
  printf("b %d (%d, %d)\n", updown, mousex, mousey);
  
  if(bubbley >= 800){
  	clicked=FALSE;
	bubbley=300;
	i=0;
  }
  
  if(mousex >= 750 && mousey <= 315 && mousex <= 870 && mousey >= 225){
  		updown = 0;
   		clicked=TRUE;
	
  }

}

int main() {
  int quit = FALSE;
  
  EZ_Init(WINDOWWIDTH, WINDOWHEIGHT, "BUBBLES");
  
  
  

  while(!quit){
    quit = EZ_HandleEvents(updateDisplay, handleKey, handleButton, handleMouseMotion);
  }
  
  EZ_Quit();

  return 0;
}




