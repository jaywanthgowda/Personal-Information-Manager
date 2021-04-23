#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<time.h>
#include "functions.h"

 void NewUser(struct queue *q,struct TrieNode* srnTrie)
 {  
  char *srn = generateSRN(srnTrie);//Problem 4
  printf("\nThis is your SRN,remember it all times    ");
  printf("%s\n",srn);
  //enqueue(q,srn);
  char *encrPass = getPassword(srn);
  printf("\nEnter your details in this order");
  printf("\n1.Name\n2.Aadhar\n3.Pan\n4.Kyc");
  printf("\nEnter your Name ");
  char *Name = (char *)malloc(sizeof(char)*50);
  scanf("%[^\n]%*c",Name);
  printf("\nEnter your Aadhar number ");
  char *Aadhar = (char *)malloc(sizeof(char)*50);
  scanf("%s",Aadhar);
  printf("\nEnter your Pan number ");
  char *Pan = (char *)malloc(sizeof(char)*50);
  scanf("%s",Pan);
  printf("\nEnter your Kyc number ");
  char *Kyc = (char *)malloc(sizeof(char)*50);
  scanf("%s",Kyc);
  //append srn,password,SRNinfo.txt into admin.txt
  //append name,aadhar,pan,kyc into SRNinfo.txt
  char *fileName=(char *)(malloc(sizeof(char)*15));
  char *temp1=(char *)(malloc(sizeof(char)*9));
  strcpy(fileName,srn);
  strcpy(temp1,"info.txt");
  strncat(fileName,temp1,8);
  //printf("file name %s\n",fileName);
  appendAdmin(srn,encrPass,fileName);
  appendInfo(Name,Aadhar,Pan,Kyc,fileName);
  EncryptFile(fileName,SRNshift(srn));
 }

void appendAdmin(char *srn, char *encrPass,char *file_name)
{
  FILE *fptr;
  fptr=fopen("Admin.txt","a");
  if(fptr==NULL)
  {
    printf("File doesn't exist");
    exit(1);
  }
  //fputs("\n",fptr);
  fputs(srn,fptr);
  fputs("\n",fptr);
  fputs(encrPass,fptr);
  fputs("\n",fptr);
  fputs(file_name,fptr);
  fputs("\n",fptr);
  fputs("\n",fptr);
  fclose(fptr);
}
 
 void appendInfo(char *Name,char *Aadhar,char *Pan,char *Kyc,char *fileName)
 {
  FILE *fptr;
  fptr=fopen(fileName,"w");
  if(fptr==NULL)
  {
    printf("File doesn't exist");
    exit(1);
  }
  //fputs("\n",fptr);
  fputs(Name,fptr);
  fputs("\n",fptr);
  fputs(Aadhar,fptr);
  fputs("\n",fptr);
  fputs(Pan,fptr);
  fputs("\n",fptr);
  fputs(Kyc,fptr);
  fputs("\n",fptr);
  fclose(fptr);
 }
