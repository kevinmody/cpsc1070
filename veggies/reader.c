//
//  reader.c
//
//  Created by Donald House on 9/30/19.
//  For CPSC 1070 Lab Project on 3/2/20
//  Clemson University
//

#include <stdio.h>
#include <string.h>
#include <ctype.h>

void removePunctuation(const char *str, char *cleanstr){
  int i, j;
  char ch;
  
  for(i = 0, j = 0; str[i] != '\0'; i++){
    ch = tolower(str[i]);
    if(isalpha(ch))
      cleanstr[j++] = ch;
  }
  cleanstr[j] = '\0';
}

int main(int argc, char *argv[]){
  FILE *infile;
  char instring[1000];
  char cleanstring[1000];
  
  int carrot = 0;
  int potato = 0;
  int spinach = 0;
  int cauliflower = 0;
  int broccoli = 0;
  int eggplant = 0;



  if(argc != 2){
    printf("usage: reader <filename>\n");
    return 1;
  }
  
  infile = fopen(argv[1], "r");
  if(infile == NULL){
    printf("cannot open file %s\n", argv[1]);
    return 2;
  }
  
  while(fscanf(infile, "%s", instring) == 1){
    removePunctuation(instring, cleanstring);
    
	if (!strcmp("eggplant", cleanstring)){
		eggplant++;  	
		}
	else if (!strcmp("cauliflower",cleanstring)){
		cauliflower++;            	
		}
	if (!strcmp("potato",cleanstring)){
		potato++;            	
		}
	if (!strcmp("carrot",cleanstring)){
		carrot++;            
		}
	if (!strcmp("broccoli",cleanstring)){
		broccoli++;            	
		}
	if (!strcmp("spinach",cleanstring)){
		spinach++;
		
		}     
	}

	printf("potato %d\n", potato);
	printf("eggplant %d\n", eggplant);
	printf("spinach %d\n", spinach);   
	printf("broccoli %d\n", broccoli);
	printf("carrot %d\n", carrot);
	printf("cauliflower %d\n", cauliflower);

    	if(infile) fclose(infile);
    	return 0;
 
  return 0;
}

