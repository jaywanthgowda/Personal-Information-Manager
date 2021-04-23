#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<time.h>
#include "functions.h"

void EncryptFile(char file[],int shf)
{
	FILE *fptr2;
	FILE *fptr3;
	fptr3=fopen("temp.txt","w");					
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
			if(ch+shf>255)	
				ch=ch+shf-255;				
			else
				ch+=shf;				
		
		str2=(char)ch;
		fputc(str2,fptr3);
		str1 = fgetc(fptr2);
	}
	fclose(fptr2);
	fclose(fptr3);
	FILE *fptr4;
	FILE *fptr5;
	fptr5=fopen("temp.txt","r");					
	fptr4=fopen(file,"w");						
	if(fptr4==NULL || fptr5==NULL)
	{
		printf("\nUnable to open the file\n");
		exit(-1);
	}														
	str1 = fgetc(fptr5);
	while (str1 != EOF)
	{
		fputc(str1,fptr4);
		str1 = fgetc(fptr5);
	}
	fclose(fptr4);
	fclose(fptr5);
}

char * SentenceEncrypt(char *srn,int shf)
{
	int n = strlen(srn); 
	int i=0;
	char* temp = (char*)malloc(sizeof(srn)+1);
	char str1=srn[i];							
	int ch;							
	while (str1 != '\0')
	{
		ch=(int)str1;
		if(ch+shf>255)	
			ch=ch+shf-255;				
		else
			ch+=shf;
		temp[i]=(char)ch;
		i+=1;
		str1=srn[i];				
	}
	temp[i]='\0';
	return temp;
}