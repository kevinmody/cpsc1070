/*Author: Kevin Mody
  date: 01/27/2020
  Assignment: hw1
*/
#include <stdio.h>
#include <math.h>

#define PI 3.14159265359

int main(){

int a,b; //a = number of polygone, b = radius, c = sides

printf("Enter a positive non-zero number n for your polygon: "); //print enter a number 
scanf("%d",&a);//input from user for a

printf("Enter a positive non-zero number for the radius (in) of your polygon: ");//print enter a number for radius
scanf("%d",&b);//input from user for b


float angle = 360/a; //angle formula
float radian = (angle*(PI/180));//radian conversion from angle

float c = sqrt((b*b)+(b*b)-2*b*b*cos(radian));//formula for sides

double per = (c * a);//formula for perimeter in inches
double ft = per/12;//perimeter units to fts


printf("Side of your polygon (in)= %f\n",c);//print side
printf("Angle = %.2f\n",angle);//print angle in degrees
printf("Angle in radian = %.2f\n", radian);//print angle in radians
printf("Perimeter in inches = %.2lf", per);//print perimeter value in inches
printf(" in ft(s) = %.2lf\n", ft);//print peremeter value in ft


}
