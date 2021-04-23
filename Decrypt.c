#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<time.h>
#include "functions.h"

void DecryptFile(char file[],int shf)
{
	FILE *fptr2;
	FILE *fptr3;
	fptr3=fopen("output.txt","w");					
	fptr2=fopen(file,"r");						
	if(fptr2==NULL || fptr3==NULL)
	{
		printf("\nUnable to open the file\n");
		exit(-1);
	}
	char str1,str2;							
	int ch;								
	str1 = fgetc(fptr2);
	while (str1 != EOF)
	{
		ch=(int)str1;	
		
			if(ch-shf<0)	
				ch=ch-shf+256;
			else
				ch-=shf;				
		
		str2=(char)ch;
		fputc(str2,fptr3);
		str1 = fgetc(fptr2);
	}
	fclose(fptr2);
	fclose(fptr3);
}

char * SentenceDecrypt(char *srn,int shf)
{
	int n = strlen(srn); 
	int i=0;
	char* temp = (char*)malloc(sizeof(srn) + 1);
	char str1=srn[i];							
	int ch;							
	while (str1 != '\0')
	{
		ch=(int)str1;
		if(ch-shf<0)	
			ch=ch-shf+255;				
		else
			ch-=shf;
		temp[i]=(char)ch;
		i+=1;
		str1=srn[i];				
	}
	return temp;
}