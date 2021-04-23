#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<time.h>
#include "functions.h"

int main(void)
{
  FILE *fptr;//, *fp
  /* fp=fopen("Admin.txt","w");
  fclose(fp);
   */ //Problem 1
  fptr=fopen("Admin.txt","r");
  if(fptr==NULL)
  {
    fptr=fopen("Admin.txt","w");
  }
  struct TrieNode* SRNTrie = getTrieNode();
  queue* Q= create_queue();
//Extract Srn's first
 srnExtract(fptr, SRNTrie,Q);
 (void)fclose(fptr);//Problem 2
  printf("PERSONAL INFO MANAGER\n");
  printf("1.Existing user\n2.New user\n3.Exit\n");
  printf("Enter choice\n");
  int choice;
 (void)scanf("%d",&choice);
  switch(choice)
  {
    case 1:
    //  ExistingUser(SRNTrie,Q);
        ExistingUser(SRNTrie,Q);  
        break;
    case 2:
      NewUser(Q,SRNTrie);//Problem 3
      break;
    case 3:
      exit(0);
    default:
      printf("Invalid choice\n");  
  }
  free(SRNTrie);
  deleteQueue(Q);
  return 0;
}
