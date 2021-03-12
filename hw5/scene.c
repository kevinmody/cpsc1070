#include"ezdraw.h"
#include<stdio.h>

void read(char *);
void updateDisplay();


typedef struct {
	int rgb[3];
	char type[100];
	int coordinates[20];
	char fill;
	int numpoint;
}object;

int windowheight, windowwidth = 0;
enum boolean{TRUE, FALSE};

object draw[100];
int i=0;
int j =0;
int k=0;
int r,g,b;

void updateDisplay(){
  EZ_SetBackColor(r,g,b);   
  EZ_ClearDrawing();            

  for(j=0;j<1;j++){
	if(strcmp(draw[j].type, "color")==0){
	EZ_SetColor(draw[j].rgb[0],draw[j].rgb[1],draw[j].rgb[2]);
 	}	
	if(strcmp(draw[j].type, "triangle")==0){
		EZ_Point points[3];
		for(k=0;k<3;k++){
			points[k].x = draw[j].coordinates[2*k];
			points[k].y = draw[j].coordinates[2*k+1];
		}
	if(draw[j].fill == 'f'){
		EZ_FillTriangle(points[0],points[1],points[2]);
		}else{
			EZ_OutlineTriangle(points[0],points[1],points[2]);
		}
	}
	if(strcmp(draw[j].type, "circle")==0){
		if(draw[j].fill == 'f'){
		EZ_FillCircle(draw[j].coordinates[0],draw[j].coordinates[1],draw[j].coordinates[2]);
		}else{
		EZ_OutlineCircle(draw[j].coordinates[0],draw[j].coordinates[1],draw[j].coordinates[2]);
		}
	}
	if(strcmp(draw[j].type, "rect")==0){
		if(draw[j].fill == 'f'){
		EZ_FillRect(draw[j].coordinates[0],draw[j].coordinates[1],draw[j].coordinates[2],draw[j].coordinates[3]);
		}else{
		EZ_OutlineRect(draw[j].coordinates[0],draw[j].coordinates[1],draw[j].coordinates[2],draw[j].coordinates[3]);
		}
	}
 	if(strcmp(draw[j].type, "polyline")==0){
		EZ_Point ppoint[draw[j].numpoint];
		for (k=0;k<draw[j].numpoint;k++){
			ppoint[k].x=draw[j].coordinates[2*k];		
			ppoint[k].y=draw[j].coordinates[2*k+1];
		}
		EZ_DrawLineStrip(ppoint, draw[j].numpoint);
	}
  	if(strcmp(draw[j].type, "polygon")==0){
		EZ_Point ppoint[draw[j].numpoint];
		for (k=0;k<draw[j].numpoint;k++){
			ppoint[k].x=draw[j].coordinates[2*k];		
			ppoint[k].y=draw[j].coordinates[2*k+1];
		}
		if(draw[j].fill=='o'){
			EZ_DrawLineLoop(ppoint, draw[j].numpoint);
		}
		else{
			
		}
		
	}
 
  }
  EZ_DisplayDrawing(); 
}

int main(int argc, char *argv[]) {
  char *infileName = argv[1];
  
  char backcolor[100];
  char window[100];
  
  
  FILE *fptr;
  fptr = fopen(infileName,"r");
  if(fptr == NULL){
	printf("cannot open file ");
  } 
  
  if(argc != 2){
	fprintf(stderr,"usage: ./scene <infileName>");
	exit(1);
  }



  fscanf(fptr, "%s",window);
  if(strcmp(window, "window")==0){
	fscanf(fptr, "%d %d",&windowwidth, &windowheight);
  }
  fscanf(fptr, "%s",backcolor);
  if(strcmp(backcolor, "backcolor")==0){
		fscanf(fptr, "%d %d %d",&r, &g, &b);
		//fprintf(stderr,"color %d %d %d",r,g,b );
  }
  char c;
  while((fscanf(fptr, "%s", draw[i].type))!=EOF){
	
	if(strcmp(draw[i].type, "color")==0){
		fscanf(fptr, " %d %d %d ", &draw[i].rgb[0],&draw[i].rgb[1],&draw[i].rgb[2]);
		
		i++;

	}
	if(strcmp(draw[i].type, "triangle")==0){
		c=fgetc(fptr);
		draw[i].fill=fgetc(fptr);
		fscanf(fptr,"%d",&draw[i].coordinates[0]);
		fscanf(fptr, "%d", &draw[i].coordinates[1]);
		fscanf(fptr, "%d", &draw[i].coordinates[2]);
		fscanf(fptr, "%d", &draw[i].coordinates[3]);
		fscanf(fptr, "%d", &draw[i].coordinates[4]);
		fscanf(fptr, "%d", &draw[i].coordinates[5]);
		i++;	
	}
	if(strcmp(draw[i].type, "circle")==0){
		c=fgetc(fptr);
		draw[i].fill=fgetc(fptr);
		fscanf(fptr, "%d %d\n%d", &draw[i].coordinates[0], &draw[i].coordinates[1], &draw[i].coordinates[2]);
		i++;
	}
	if(strcmp(draw[i].type, "rect")==0){
		c=fgetc(fptr);
		draw[i].fill=fgetc(fptr);
		fscanf(fptr, "%d %d\n%d %d",&draw[i].coordinates[0],&draw[i].coordinates[1],&draw[i].coordinates[2],&draw[i].coordinates[3]);
		i++;
	}
	if(strcmp(draw[i].type, "polyline")==0){
		c=fgetc(fptr);
		fscanf(fptr, "%d" ,&draw[i].numpoint);
		int npnt = (2*draw[i].numpoint);
		for(int a = 0; a<npnt;a++){
			fscanf(fptr, "%d", &draw[i].coordinates[a]);
		}	
		i++;
	}
	if(strcmp(draw[i].type, "polygon")==0){
		c=fgetc(fptr);
		fscanf(fptr, "%d", &draw[i].numpoint);
		int npnt = (2*draw[i].numpoint);
		for(int a = 0; a<npnt;a++){
			fscanf(fptr, "%d", &draw[i].coordinates[a]);
		}
		i++;
	}
	else{
		fprintf(stdout,"input file error\n");
	}
	if(c==' '){
		
	}

  }

  EZ_Init(windowwidth, windowheight, "scene");
  int quit=FALSE;
  while(!quit){
    quit = EZ_HandleEvents(updateDisplay, NULL, NULL, NULL);
  }
  
  EZ_Quit();

}

