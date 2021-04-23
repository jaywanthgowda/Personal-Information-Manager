#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<time.h>
#include "functions.h"

void Extract(queue *q,char* srn,char* password)
{
    printf("extract\n");   
    int line_no=GetLineNo(q,srn);
    printf("%d\n",line_no);
    char pass[15];
    char file_name1[15];
    char *file_name2 = (char *)malloc(sizeof(char)*15);
    GetData(pass,file_name1,line_no);
    printf("\n%s\n%s",pass,file_name1);
    file_name2=GetName(srn,pass,password,file_name1);
    if(strncmp(file_name2,"failed",7)==0)
    {
        printf("\nIncorrect Password\n");        
    }
    else
    {
        DisplayFile(file_name2);
    }
}

int GetLineNo(queue *q,char *srn)
{    
  int i=1;
  while(strncmp(q->front->data,srn,7)!=0)
  {
      dequeue(q);
       i+=3;
  }  
  return i;
}

void GetData(char *pass,char *file_name,int line_no)
{
    FILE *fp=fopen("Admin.txt","r");
    if(fp==NULL){
        perror("Error");
        exit(-1);
    }
    char *line=(char *)(malloc(sizeof(char)*15));
    int i =1;
    while(fscanf(fp,"%s",line))
    {     
        if(i==line_no)
        {
            fscanf(fp,"%s",pass); //encrypted password for the srn_no
            fscanf(fp,"%s",file_name);//encrypted file name with personal details of that srn_no
            break;
        }
        i+=1;
    }
}


char* GetName(char srn[],char pass[],char password[],char file_name[])
{
    //compare user password after encrypting with password from file
    //char *arr=(char*)malloc(sizeof(pass)+1);//Warning Here
    char *arr=(char*)malloc(sizeof(char)*16);
    arr=SentenceEncrypt(password,SRNshift(srn));
    if(strncmp(arr,pass,7)==0){
    //Now decrypt file name and accesess it to get personal details
        char *arr=(char*)malloc(sizeof(char)*(15));
        arr=SentenceDecrypt(file_name,SRNshift(srn));     
        return arr;
    }
    else
        return "failed";
}

void DisplayFile(char *file_name)
{
    FILE *fp;
    if((fp=fopen(file_name,"r"))==NULL)
    {
        printf("error");
        exit(1);
    }    
    char Name[20],Aadhar[20],Pan[20],Kyc[20];
    fscanf(fp,"%[^\n]%*c",Name);
    fscanf(fp,"%[^\n]%*c",Aadhar);
    fscanf(fp,"%[^\n]%*c",Pan);
    fscanf(fp,"%[^\n]%*c",Kyc);

    printf("\nName:%s",Name);
    printf("\nAadhar:%s",Aadhar);
    printf("\nPan:%s",Pan);
    printf("\nKyc:%s",Kyc);
    fclose(fp);
}