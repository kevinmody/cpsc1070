#include "ezdraw.h"
#include <stdio.h>

// dimensions of the display window
#define WINDOWWIDTH       600
#define WINDOWHEIGHT      600


#define rectwidth         200
#define rectheight        600
#define rectX0            200
#define rectY0            0

#define rect2width  600
#define rect2height 200
#define rect2X0 0
#define rect2Y0 200

#define rect3width  600
#define rect3height 200
#define rect3X0 0
#define rect3Y0 600

#define rect4width  200
#define rect4height 200
#define rect4X0 200
#define rect4Y0 200

#define rect1color 200, 100, 50
#define rect2color 255, 255,50
#define rect3color 255, 255, 0
#define rect4color 70, 100, 140





#define BACKCOLOR         70, 100, 140
#define linecolor         255, 255, 255



enum boolean{FALSE, TRUE};
int clicked;
char clicked1='0';	
char clicked2='0';	
char clicked3='0';
char clicked4='0';
char clicked5='0';	
char clicked6='0';
char clicked7='0';
char clicked8='0'; 
char clicked9='0';

int ex;
int os;
int rows, cols;
char player;
char turns;
//int computer;

int g1,g2,g3,g4,g5,g6,g7,g8,g9;

//line1
int line1X0 = 50;
int line1Y0 =50;    
int line1X1 =150;
int line1Y1 =150;
//line2
int line2X0 =150;
int line2Y0 =50;
int line2X1 =50;
int line2Y1 =150;

//X in grid 2
//x1
int line3X0 =250;
int line3Y0 =50; 
//y1   
int line3X1 =350;
int line3Y1 =150;
//line2
//x2
int line4X0 =350;
int line4Y0 =50;
//y2
int line4X1 =250;
int line4Y1 =150;

//X in grid 3
//line1
//x1
int line5X0 =450;
int line5Y0 =50; 
//y1   
int line5X1 =550;
int line5Y1 =150;
//line2
//x2
int line6X0 =550;
int line6Y0 =50;
//y2
int line6X1 =450;
int line6Y1 =150;

//X in grid 4
//line1
//x1
int line7X0 =50;
int line7Y0 =250; 
//y1   
int line7X1 =150;
int line7Y1 =350;
//line2
//x2
int line8X0 =150;
int line8Y0 =250;
//y2
int line8X1 =50;
int line8Y1 =350;

//X in grid 5
//line1
//x1
int line9X0 =250;
int line9Y0 =250; 
//y1   
int line9X1 =350;
int line9Y1 =350;
//line2
//x2
int line10X0 =350;
int line10Y0 =250;
//y2
int line10X1 =250;
int line10Y1 =350;

//X in grid 6
//line1
//x1
int line11X0 =450;
int line11Y0 =250; 
//y1   
int line11X1 =550;
int line11Y1 =350;
//line2
//x2
int line12X0 =550;
int line12Y0 =250;
//y2
int line12X1 =450;
int line12Y1 =350;

//X in grid 7
//line1
//x1
int line13X0 =50;
int line13Y0 =450; 
//y1   
int line13X1 =150;
int line13Y1 =550;
//line2
//x2
int line14X0 =150;
int line14Y0 =450;
//y2
int line14X1 =50;
int line14Y1 =550;

//X in grid 8
//line1
//x1
int line15X0 =250;
int line15Y0 =450; 
//y1   
int line15X1 =350;
int line15Y1 =550;
//line2
//x2
int line16X0 =350;
int line16Y0 =450;
//y2
int line16X1 =250;
int line16Y1 =550;

//X in grid 9
//line1
//x1
int line17X0 =450;
int line17Y0 =450; 
//y1   
int line17X1 =550;
int line17Y1 =550;
//line2
//x2
int line18X0 =550;
int line18Y0 =450;
//y2
int line18X1 =450;
int line18Y1 =550;

//cirlce = 'o'
int cx = 100;
int cy = 100;
int crad = 50;




int outrectwidth =100;
int outrectheight  =100;
int outrectX0 =50;
int outrectY0 =50;

int board[3][3];
int grids[3][3];

void computer(){
	
	if(clicked1=='0'&&turns=='c')
	{
		clicked1='o';

	}
	else if(clicked2=='0'&&turns=='c'){
		clicked2='o';
	}
	else if(clicked3=='0'&&turns=='c'){
		clicked3='o';
	}
	else if(clicked4=='0'&&turns=='c'){
		clicked4='o';
	}
	else if(clicked5=='0'&&turns=='c'){
		clicked5='o';
	}
	else if(clicked6=='0'&&turns=='c'){
		clicked6='o';
	}
	else if(clicked7=='0'&&turns=='c'){
		clicked7='o';
	}
	else if(clicked8=='0'&&turns=='c'){
		clicked8='o';
	}
	else if(clicked9=='0'&&turns=='c'){
		clicked9='o';
	}
 turns='p';

	
}

void computero(){
	if(clicked1=='0'&&turns=='d')
	{
		clicked1='x';

	}
	else if(clicked2=='0'&&turns=='d'){
		clicked2='x';
	}
	else if(clicked3=='0'&&turns=='d'){
		clicked3='x';
	}
	else if(clicked4=='0'&&turns=='d'){
		clicked4='x';
	}
	else if(clicked5=='0'&&turns=='d'){
		clicked5='x';
	}
	else if(clicked6=='0'&&turns=='d'){
		clicked6='x';
	}
	else if(clicked7=='0'&&turns=='d'){
		clicked7='x';
	}
	else if(clicked8=='0'&&turns=='d'){
		clicked8='x';
	}
	else if(clicked9=='0'&&turns=='d'){
		clicked9='x';
	}
  turns='p';
}

void updateDisplay(){
  EZ_SetBackColor(BACKCOLOR);   // specify background color for the drawing
  EZ_ClearDrawing();            // clear the drawing to the background color

  EZ_SetColor(rect1color);       // specify the color to be used to draw
  EZ_FillRect(rectX0, rectY0, rectwidth, rectheight); // draw the rectangle

  EZ_SetColor(rect1color);       // specify the color to be used to draw
  EZ_FillRect(rect2X0, rect2Y0, rect2width, rect2height); // draw the rectangle
  
 
  EZ_SetColor(rect1color);       // specify the color to be used to draw
  EZ_FillRect(rect3X0, rect3Y0, rect3width, rect3height);

  EZ_SetColor(rect4color);       // specify the color to be used to draw
  EZ_FillRect(rect4X0, rect4Y0, rect4width, rect4height); // draw the rectangle

  EZ_SetColor(linecolor);
  EZ_OutlineRect(outrectX0, outrectY0, outrectwidth, outrectheight);
  

	//if clicked ouput X
	if(clicked1=='x'){
		EZ_SetColor(linecolor);
	    	EZ_DrawLine(line1X0, line1Y0, line1X1, line1Y1); 

		EZ_SetColor(linecolor);
	    	EZ_DrawLine(line2X0, line2Y0, line2X1, line2Y1);
  	printf("work");
		
	}
	if(clicked2=='x'){
		EZ_SetColor(linecolor);
	    	EZ_DrawLine(line3X0, line3Y0, line3X1, line3Y1); 

		EZ_SetColor(linecolor);
	    	EZ_DrawLine(line4X0, line4Y0, line4X1, line4Y1);
		
	}
	if(clicked3=='x'){
		EZ_SetColor(linecolor);
	    	EZ_DrawLine(line5X0, line5Y0, line5X1, line5Y1); 

		EZ_SetColor(linecolor);
	    	EZ_DrawLine(line6X0, line6Y0, line6X1, line6Y1);
		
	}
	if(clicked4=='x'){
		EZ_SetColor(linecolor);
	    	EZ_DrawLine(line7X0, line7Y0, line7X1, line7Y1); 

		EZ_SetColor(linecolor);
	    	EZ_DrawLine(line8X0, line8Y0, line8X1, line8Y1);
		
	}
	if(clicked5=='x'){
		EZ_SetColor(linecolor);
	    	EZ_DrawLine(line9X0, line9Y0, line9X1, line9Y1); 
		printf(" 5 %d/n",ex);
		EZ_SetColor(linecolor);
	    	EZ_DrawLine(line10X0, line10Y0, line10X1, line10Y1);
		
	}
	if(clicked6=='x'){
		EZ_SetColor(linecolor);
	    	EZ_DrawLine(line11X0, line11Y0, line11X1, line11Y1); 

		EZ_SetColor(linecolor);
	    	EZ_DrawLine(line12X0, line12Y0, line12X1, line12Y1);
	}
	if(clicked7=='x'){
		EZ_SetColor(linecolor);
	    	EZ_DrawLine(line13X0, line13Y0, line13X1, line13Y1); 

		EZ_SetColor(linecolor);
	    	EZ_DrawLine(line14X0, line14Y0, line14X1, line14Y1);
		
	}
	if(clicked8=='x'){
		EZ_SetColor(linecolor);
	    	EZ_DrawLine(line15X0, line15Y0, line15X1, line15Y1); 

		EZ_SetColor(linecolor);
	    	EZ_DrawLine(line16X0, line16Y0, line16X1, line16Y1);
	}
	if(clicked9=='x'){
		EZ_SetColor(linecolor);
	    	EZ_DrawLine(line17X0, line17Y0, line17X1, line17Y1); 

		EZ_SetColor(linecolor);
	    	EZ_DrawLine(line18X0, line18Y0, line18X1, line18Y1);
		
	}


	//if clicked output o
	if(clicked1=='o'){
		EZ_SetColor(linecolor);
		EZ_OutlineCircle(cx,cy,crad);
	}
	if(clicked2=='o'){
		EZ_SetColor(linecolor);
		EZ_OutlineCircle(cx+200,cy,crad);
	}
	if(clicked3=='o'){
		EZ_SetColor(linecolor);
		EZ_OutlineCircle(cx+400,cy,crad);
	}
	if(clicked4=='o'){
		EZ_SetColor(linecolor);
		EZ_OutlineCircle(cx,cy+200,crad);
	}
	if(clicked5=='o'){
		EZ_SetColor(linecolor);
		EZ_OutlineCircle(cx+200,cy+200,crad);
	}
	if(clicked6=='o'){
		EZ_SetColor(linecolor);
		EZ_OutlineCircle(cx+400,cy+200,crad);
	}
	if(clicked7=='o'){
		EZ_SetColor(linecolor);
		EZ_OutlineCircle(cx,cy+400,crad);
	}
	if(clicked8=='o'){
		EZ_SetColor(linecolor);
		EZ_OutlineCircle(cx+200,cy+400,crad);
	}
	if(clicked9=='o'){
		EZ_SetColor(linecolor);
		EZ_OutlineCircle(cx+400,cy+400,crad);
	}	

//mapping

 if(g1== board[0][0]){
	EZ_OutlineRect(outrectX0, outrectY0+400, outrectwidth, outrectheight);
}
 if(g2== board[0][1]){
	EZ_OutlineRect(outrectX0+200, outrectY0+400, outrectwidth, outrectheight);
}
 if(g3== board[0][2]){
	EZ_OutlineRect(outrectX0+400, outrectY0+400, outrectwidth, outrectheight);
}
 if(g4== board[1][0]){
	EZ_OutlineRect(outrectX0, outrectY0+200, outrectwidth, outrectheight);
}
 if(g5== board[1][1]){
	EZ_OutlineRect(outrectX0+200, outrectY0+200, outrectwidth, outrectheight);
}
  if(g6== board[1][2]){
	EZ_OutlineRect(outrectX0+400, outrectY0+200, outrectwidth, outrectheight);
}
  if(g7== board[2][0]){
	EZ_OutlineRect(outrectX0, outrectY0, outrectwidth, outrectheight);
}
 if(g8== board[2][1]){
	EZ_OutlineRect(outrectX0+200, outrectY0, outrectwidth, outrectheight);
}
 if(g9== board[2][2]){
	EZ_OutlineRect(outrectX0+400, outrectY0, outrectwidth, outrectheight);
}

printf("%c/n",turns);



//turns
if(turns == 'c'){
	computer();
		}
else if(turns == 'd'){
	computero();
}
	
 EZ_DisplayDrawing();          
}


void play(){
	printf("Welcome to TicTacToe\n");
	player = printf("Player 1, would like to play? y/n \n");
	scanf("  %c",&player);
}
void choose()
{
	if(player == 'y')
	{
		printf("Player 1 select 'x'\n");
		scanf(" %c",&player);
		if(player == 'x')
		{
			printf("Player1 is a user, symbol 'x' \n");
			ex=1;
			//printf("%d/n",ex);
			clicked=TRUE;
			printf("Computer is '0' \n");
		}	
		
	}
}	


void maping(){
	
//squares in each grid
	grids[0][0]=g1;
	grids[0][1]=g2;
	grids[0][2]=g3;
	grids[1][0]=g4;
	grids[1][1]=g5;
	grids[1][2]=g6;
	grids[2][0]=g7;
	grids[2][1]=g8;
	grids[2][2]=g9;
	
	
}


void handleKey(unsigned char press){
  printf("k %c\n", press);

}

void handleMouseMotion(int mousex, int mousey, int dmousex, int dmousey){
  printf("m (%d, %d) (%d, %d)\n", mousex, mousey, dmousex, dmousey);
}

void handleButton(int updown, int mousex, int mousey){
  printf("b %d (%d, %d)\n", updown, mousex, mousey);

 
	
   if((mousex >= 50 && mousey <= 150 && mousex <= 150 && mousey >= 50 )&&clicked1=='0'){
                 updown = 0;
		clicked=1;
		clicked1='x';
		//clicked1='o';	
		turns='c';
		
	printf("1/n");
	
	}
   else if((mousex >= 250 && mousey <= 150 && mousex <= 350 && mousey >= 50 )&&clicked2=='0'){
                updown = 0;
		clicked=2;
		clicked2='x';
		//clicked2='o';	
		turns='c';
	printf("2/n");
	}
   else if((mousex >= 450 && mousey <= 150 && mousex <= 550 && mousey >= 50)&&clicked3=='0' ){
                 updown = 0;
		clicked=3;
		clicked3='x';
		//clicked3='o';	
		turns='c';
	printf("3/n");	
	}
   else if((mousex >= 50 && mousey <= 350 && mousex <= 150 && mousey >= 250)&&clicked4=='0' ){
                 updown = 0;
		clicked=4;
		clicked4='x';
		//clicked4='o';	
		turns='c';
	printf("4/n");
	}
   else if((mousex >= 250 && mousey <= 350 && mousex <= 350 && mousey >= 250 )&&clicked5=='0'){
                 updown = 0;
		clicked=5;
		clicked5='x';
		//clicked5='o';	
		turns='c';
	printf("5/n");
	}
   else if((mousex >= 450 && mousey <= 350 && mousex <= 550 && mousey >= 250 )&&clicked6=='0'){
                 updown = 0;
		clicked=6;
		clicked6='x';
		//clicked6='o';	
		turns='c';
	printf("6/n");
	}
   else if((mousex >= 50 && mousey <= 550 && mousex <= 150 && mousey >= 450 )&&clicked7=='0'){
                 updown = 0;
		clicked=7;
		clicked7='x';
		//clicked7='o';	
		turns='c';
	printf("7/n");
	}
   else if((mousex >= 250 && mousey <= 550 && mousex <= 350 && mousey >= 450) &&clicked8=='0'){
                 updown = 0;
		clicked=8;
		clicked8='x';
		//clicked8='o';	
		turns='c';
		printf("8/n");
	}
   else if((mousex >= 450 && mousey <= 550 && mousex <= 550 && mousey >= 450 )&&clicked9=='0'){
                 updown = 0;
		clicked=9;
		clicked9='x';
		//clicked9='o';	
		turns='c';
	printf("9/n");
	}


}


int main() {
  int quit = FALSE;
  
  play();
  choose();
  computer();
  computero();

  EZ_Init(WINDOWWIDTH, WINDOWHEIGHT, "TICTACTOE");
  
  while(!quit){
    quit = EZ_HandleEvents(updateDisplay, handleKey, handleButton, handleMouseMotion);
  }
  
  EZ_Quit();

  return 0;
}
