#include<stdio.h>
#include<stdlib.h>	
#include<string.h>

int main(int argc, char *argv[])
{
	
	FILE *fptr1;
	FILE *fptr2;
	FILE *fptr3;
	fptr1 = fopen("sample.txt","r");
	fptr2 = fopen("go.txt","r");
	fptr3 = fopen("hello.txt","r");
	char temp;
	char ch1,ch2,ch3, buffer[155];
	char c;
	int i = 0, arr[155],k, j = 0;
	if(argc != 2){
		printf("usage: ./a.out <filename>\n");
	        return 1;
  	}
  
  	fptr1 = fopen(argv[1], "r");
  	if(fptr1 == NULL || fptr2 == NULL || fptr3 == NULL){
    		printf("cannot open file %s\n", argv[1]);
    		return 2;
  	}
	while(1)
	{
		ch1 = fgetc(fptr1);
		ch2 = fgetc(fptr2);
		ch3 = fgetc(fptr3);
		if(ch1 == EOF){
			break;	
		}
		else if(ch1 == ' '){
			arr[j]=atoi(buffer);
			j++;
			bzero(buffer, sizeof(fptr1));
			i = 0;
		;
			continue;
		}
		else{
			buffer[i]= ch1;
			i++;
		}
	}
	for(i = 0;i<j;i++){
		
		//for(int temp=0 ; temp<j;temp--){
		//printf("Number %d: %d\n",i,arr[i]);
		int firstnum=arr[i];
		int lastnum=arr[j-1];
		int sumnum=firstnum+lastnum;
		printf("%d %d = %d \n",firstnum,lastnum,sumnum);
			printf("%d\n",lastnum);
		int numcount = sumnum+1;

			//}
		
		
	}
	



	fclose(fptr1);
	fclose(fptr2);
	fclose(fptr3);
	return 0;
}
