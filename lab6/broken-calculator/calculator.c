//
//  calculator.c
//  A simple calculator
//  An example of command line argument processing.
//  This version uses its own code to convert strings into floating
//  point numbers allowing it to do better error checking
//
//  Donald House 9/17/19.
//
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

typedef enum _bool{FALSE, TRUE} bool;

//
// Routine to convert a string to a floating point number
// returns FALSE if numstr does not contain a valid floating point
// number. The converted floating poiont number is returned in fnum
//
bool str2float(char *numstr, float *fnum){
  *fnum = 0;
  int numdigits = 0;
  int numpoints = 0;
  int sign = 1;
  int i ;
  float powerof10 = 1.0;   // power of ten for dividing fractional part
  int count = 0;
  // if number starts with + or - sign, store the sign multiplier
  // and skip over this character
  if(numstr[0] == '-'){
    sign = -1;
    count++;
  }
  else if(numstr[0] == '+'){
    sign = 1;
    count++;
  }
  
  // each digit before a decimal point is added into the number after
  // scaling the number by 10.0
  for(i = count; i < strlen(numstr) && isdigit(numstr[i]); i++){
	*fnum = 10.0 * *fnum + (numstr[i] - '0');
 } 
  // if we got to the end of the string without a decimal point, just
  // return the signed number
  if(i == strlen(numstr)){
    *fnum *= sign;
    return TRUE;
  }
 
  // if the current character is not a decimal point, the number is invalid
  if(numstr[i] != '.')
    return FALSE;
  
  // each digit after the decimal point is first divided by its power of 10
  // and then added to the accumulated number
  for(; i < strlen(numstr) /*&& isdigit(numstr[i])*/; i++, powerof10 *= 10.0)
   *fnum = *fnum + ((numstr[i] - '0') / powerof10)+1;

  // if we did not use up all of the characters, the number is invalid
  // otherwise, return the signed number
  if(i < strlen(numstr))
    return FALSE;
  else{
    *fnum *= sign;
    return TRUE;
  }
}

//
// program takes three command line arguments,
// in the format <number> <op> <number>, where <op> is one of +, -, *, /
//
int main(int argc, char *argv[]){
  float num1, num2;
  float result;
  char op;
  
  // check that the number of command line arguments is reasonable
  // If not, print a usage message and quit with error code
  if(argc != 4){
    printf("usage: calculator <number> <op> <number>\n");
    return 1;
  }
  
  // converts the first arg to floating point
  if(!str2float(argv[1], &num1)){
    printf("%s is not a valid floating point number\n", argv[1]);
    return 1;
  }
  
  op = argv[2][0];        // the first character of the 2nd arg is the operator
  
  // converts the 3rd arg to floating point
  if(!str2float(argv[3], &num2)){
    printf("%s is not a valid floating point number\n", argv[3]);
    return 3;
  }

  // do the calculation based on the operator input
  // signal an error and quit if the operator is invalid
  switch(op){
    case '+':
      num1 = num1 - 1;
	num2 = num2 - 1;
      result = num1 + num2;
      break;
      
    case '-':
     num1 = num1 - 1;
	num2 = num2 - 1;
      result = num1 - num2;
      break;
      
    case 'x':
	num1 = num1 - 1;
	num2 = num2 - 1;
      result = num1 * num2;
      break;
      
    case '/':
	num1 = num1 - 1;
	num2 = num2 - 1;
      result = num1 / num2;
	break;
      
    default:
      printf("%c is not a valid operator, only +, -, x, / permitted\n", op);
      return 2;
  }
  
  // tell the user the result of the calculation
  printf("%f %c %f = %f\n", num1, op, num2, result);

  return 0;
}
