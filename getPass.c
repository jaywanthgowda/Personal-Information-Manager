#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<time.h>
#include "functions.h"

char *getPassword(char *srn)
{

  char *newPass = (char *)malloc(sizeof(char)*7);
  char *rePass = (char *)malloc(sizeof(char)*7);
  int cmpValue=1,count=0;
  while(cmpValue&&count<4)
  {
    count++;
    printf("Enter Password -> 6 characters \n");
    scanf("%s",newPass);
    if(sizeof(newPass)>6){
      printf("\nPassword should not be more than 6 characters\n");  
      continue;
    }
    printf("Re-enter password\n");
    scanf("%s",rePass);
    cmpValue=strncmp(newPass, rePass, 7); 
   
  }
  if(count>3)
    exit(0);
  return (SentenceEncrypt(newPass,SRNshift(srn)));
}