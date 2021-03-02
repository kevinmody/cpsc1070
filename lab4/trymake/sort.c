//
//  sort.c
//  
//
//  Created by Donald House on 9/8/19.
//

#include "sort.h"

// use insertion sort to sort table of n numbers into ascending order
void sort(int table[], int n){
  int i, j;
  int hold;
  
  for(i = 1; i < n; i++){
    hold = table[i];
    for(j = i; j > 0 && table[j - 1] > hold; j--)
      table[j] = table[j - 1];
    table[j] = hold;
  }
}
