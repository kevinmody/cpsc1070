#include<stdio.h>
#include<stdlib.h>	
#include<string.h>

int main(int argc, char *argv[])
{
	char temp;
	char *arr;
	FILE *fptr1;
	FILE *fptr2;
	FILE *fptr3;
	fptr1 = fopen("sample.txt","r");
	fscanf(fptr1, "%c", &temp);
	fptr2 = fopen("go.txt","r");
	fptr3 = fopen("hello.txt","r");
	
	
	char ch1,ch2,ch3, buffer[155];
	char c;
	//int i = 0, arr[155], j = 0;
	if(argc != 2){
		printf("usage: ./a.out <filename>\n");
	        return 1;
  	}
  
  	fptr1 = fopen(argv[1], "r");
  	if(fptr1 == NULL || fptr2 == NULL || fptr3 == NULL){
    		printf("cannot open file %s\n", argv[1]);
    		return 2;
  	}
	arr=malloc(temp*sizeof(char));
	//arr[sizeof(fptr1)];	
	if(arr==NULL){
		printf("unable to allocate memory");	
		return 0;
	}
	while(1)
	{
		ch1 = fgetc(fptr1);
		ch2 = fgetc(fptr2);
		ch3 = fgetc(fptr3);
		if(ch1 == EOF){
			break;	
		}
		else if(ch1==' '){
			for(int i=0;i<sizeof(fptr1);i++){
				arr[i]=i+1;
				printf("%c\n",arr[i]);			
			}
		}
	}
	


	fclose(fptr1);
	fclose(fptr2);
	fclose(fptr3);
	return 0;
}
