//
//  readwrite.c
//  
//
//  Created by Donald House on 9/8/19.
//

#include <stdio.h>
#include "readwrite.h"

// try to read an integer. If a non-numeric character is
// encountered, return the EOF (end of file) character
int read(void){
  int num;
  int nok;
  
  // note scanf returns the number of values successfully read
  // this should be 1, unless a non-numeric character was entered
  nok = scanf("%d", &num);
  
  if(nok == 1)
    return num;
  else
    return EOF;
}

void write(int num){
  static int count = 0;
  
  printf("%d ", num);
  if(++count == 5){
    printf("\n");
    count = 0;
  }
}
