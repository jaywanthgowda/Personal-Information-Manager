#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<time.h>
#include "functions.h"


//Run Initially to add srn's from admin.txt
void srnExtract(FILE *fp,struct TrieNode *srnTrie,queue *q)
{
    if(fp==NULL)
    {
      printf("Error opening file\n");
      exit(-1);
    }
    int i = 1;
    
    srand(time(0));
    while(!feof(fp))
    {
        //fgets(line,BUFFERSIZE,fp);
        char *line=(char *)malloc(sizeof(char)*6);
        char *temp=(char *)malloc(sizeof(char)*6);
        fgets(line,sizeof(line),fp);
        strncpy(temp,line,6);
        if((i-1)%4==0 && temp[0]=='P')
        {
            //printf("%s  %d\n",temp,i);
            srnAppend(srnTrie,temp);//Big Problem(NEW Problem)
            enqueue(q,temp);
        }
        //free(line);
        i++;
    }
}

//To add any srn to Trie
void srnAppend(struct TrieNode *srnTrie,char *srn)
{
    insertIntoTrie(srnTrie,srn);
}

//Generates unique SRN within Range 100 to 999
/*
    Add SRN to trie , queue , admin.txt
*/
char *generateSRN(struct TrieNode *srnTrie)//Problem 5
{
    int num;
    int generated=0;
    char *temp1,*temp2;

    while(!generated)
    {
        temp1 = (char *)malloc(sizeof(char)*4);
        temp2 = (char *)malloc(sizeof(char)*3);
        srand(time(0));
        num = (rand()% (UPPER_BOUND - LOWER_BOUND + 1)) + LOWER_BOUND; //Problem 
        sprintf(temp2,"%d",num);
        strcpy(temp1,"PES");//Problem 6
        strncat(temp1,temp2,3);//Big Problem

        if(!srnSearch(srnTrie,temp1))
        {
            srnAppend(srnTrie, temp1);
            return temp1;
        }
        else
        {
            free(temp1);
            free(temp2);
        }

    }
}

int srnSearch(struct TrieNode *srnTrie,const char *srn)
{
    if(srnTrie==NULL)
    {
      return 0;
    }
    return searchTrie(srnTrie,srn);
}
