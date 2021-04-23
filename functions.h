#define BUFFERSIZE 255
#define ALPHABETSIZE 36
//#define CHAR_TO_INDEX(c) ((int)c - (int)'A')
#define LOWER_BOUND 200
#define UPPER_BOUND 600

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

struct TrieNode
{
    struct TrieNode *child [ALPHABETSIZE];
    bool isEndOfWord;
};

//anirudh

typedef struct node{
    char *data;
    struct node *next;
}node;

typedef struct queue{
   struct node *front,*rear;
}queue;


struct queue* create_queue();

struct node* create_node(char *);

void enqueue(queue *q,char *srn);

void dequeue(queue *q);

void deleteQueue(queue *q);

void Extract(queue *q,char *srn,char *password);

int GetLineNo(queue *q,char *srn);

void GetData(char *pass,char *file_name,int line_no);

char* GetName(char *srn,char *pass,char *password,char *file_name);

void DisplayFile(char *file_name);

//

//nikhil

char * SentenceEncrypt(char *srn,int shf);

char * SentenceDecrypt(char *srn,int shf);

void EncryptFile(char file[],int shf);

void DecryptFile(char file[],int shf);

int SRNshift(char *ptr);

int Adminshift();

int specialfunct(int srn);

 void NewUser(struct queue *,struct TrieNode *);

 void ExistingUser(struct TrieNode *,queue *);

 char *getPassword(char *);

 void appendAdmin(char *, char *,char *);

 void appendInfo(char *,char *,char *,char *,char *);

 void display(char *,char *);

void delay();

void fileRemove();

//

//Jaywanth's Side

int char_to_index(char );

void srnExtract(FILE *,struct TrieNode *,queue *);

void srnAppend(struct TrieNode *,char *);

char *generateSRN();

int srnSearch(struct TrieNode *,const char *);

struct TrieNode *getTrieNode();

void insertIntoTrie(struct TrieNode *, const char *);

int searchTrie(struct TrieNode *, const char *);

void freeTrie(struct TrieNode *);

//
