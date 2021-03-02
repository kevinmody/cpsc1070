//
//  tryit.c
//  
//
//  Created by Donald House on 9/8/19.
//

#include <stdio.h>
#include "readwrite.h"
#include "sort.h"

#define MAXSIZE  10000

int main(){
  int num;
  int table[MAXSIZE];
  int n = 0;
  int i;
  
  // read numbers until a non-numeric character entered
  // and store in table. n will be the number of numbers read
  num = read();
  while(num != EOF){
    table[n++] = num;
    num = read();
  }
  
  // sort the n numbers
  sort(table, n);
  
  // print out the n numbers, 5 per line
  for(i = 0; i < n; i++)
    write(table[i]);
  
  return 0;
}
