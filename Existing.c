#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<time.h>
#include "functions.h"

void ExistingUser(struct TrieNode* SRNTrie, queue * Q)
{
  char *SRN = (char *)malloc(sizeof(char)*7);
  printf("Enter Your SRN\n");
  for(int i=0;i<3;i++)     
  {  
    char *srn = (char *)malloc(sizeof(char)*7);
    fscanf(stdin,"%s",srn);
    printf("%s\n",srn);
    bool flag=searchTrie(SRNTrie,srn);
    if(flag==false && i!=2)
    {
      printf("SRN does not exist\n");
      printf("Re-enter SRN\n");
    }
    else if(flag==false && i==2)
    {
      printf("Too many invalid attempts\n");
      exit(-1);
    }
    else
    {
      strncpy(SRN,srn,7);
      break;
    }
   }
  int line=GetLineNo(Q,SRN);
  FILE *fptr;
  fptr=fopen("Admin.txt","r");
  printf("Enter your password\n");
  char *file_name=(char *)(malloc(sizeof(char)*15));
  char *fileName=(char *)(malloc(sizeof(char)*15));
  char *check=(char *)(malloc(sizeof(char)*15));
  char *temp1=(char *)(malloc(sizeof(char)*9));
  strcpy(fileName,SRN);
  strcpy(temp1,"info.txt");
  strncat(fileName,temp1,8);
  for(int i=0;i<3;i++)
  {
    char *pass = (char *)malloc(sizeof(char)*7);
    scanf("%s",pass);
    char *encrPass=(char *)malloc(sizeof(char)*7);
    GetData(encrPass,file_name,line);
    char *check=GetName(SRN,encrPass,pass,file_name);
    if(strncmp(check,"failed",7)!=0)
      break;
    else
     {
      printf("Incorrect Password\n");
      printf("Please Re-enter Password\n");
      if(i==2)
      {
        printf("You have entered incorrect passwords\n");
        exit(-1);
      }
    }
  }
  fclose(fptr);
  display(SRN,fileName);
 }

 void display(char *srn,char *fileName)
 {
  DecryptFile(fileName,SRNshift(srn));
  printf("This file will be available only for 2 minutes\n");
  delay();
  fileRemove();
 }

 void delay()
{
    for(double i=0;i<10500000000;i++); //delay of nearly 2 min
}

void fileRemove()
{
  FILE *fptr1;
  fptr1=fopen("output.txt","w");
  fputs("2 minutes up",fptr1);
  fclose(fptr1);
}
