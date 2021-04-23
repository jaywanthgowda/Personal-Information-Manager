#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<time.h>
#include "functions.h"

int char_to_index(char ch)
{
    if(ch-'A'>=0)
    {
        return (int)(ch-'A');
    }
    return (26 + (int)(ch - '0'));
}

struct TrieNode *getTrieNode(void)
{
    struct TrieNode *pNode = (struct TrieNode *)malloc(sizeof(struct TrieNode));
  
    if (pNode)
    {
        int i;
  
        pNode->isEndOfWord = false;
  
        for (i = 0; i < ALPHABETSIZE; i++)
            pNode->child[i] = NULL;
    }
  
    return pNode;
}

void insertIntoTrie(struct TrieNode *root, const char *key)
{
    int level;
    int length = strlen(key);
    int index;
  
    struct TrieNode *pCrawl = root;
  
    for (level = 0; level < length; level++)
    {
        index = char_to_index(key[level]);

        if (!pCrawl->child[index])
            pCrawl->child[index] = getTrieNode();
  
        pCrawl = pCrawl->child[index];
    }

    pCrawl->isEndOfWord = true;
}

int searchTrie(struct TrieNode *root, const char *key)
{
    int level;
    int length = strlen(key);
    int index;
    struct TrieNode *pCrawl = root;
  
    for (level = 0; level < length; level++)
    {
        index = char_to_index(key[level]);
        if (!pCrawl->child[index])
            return 0;
  
        pCrawl = pCrawl->child[index];
    }
  
    return (pCrawl != NULL && pCrawl->isEndOfWord);
}

/*
void freeTrie(struct TrieNode *root)
{
    while(root!=NULL)
    {
        int i;
        for(i=0;i<ALPHABETSIZE;i++)
        {
            if(root->children[i]!=NULL)
            {
                free(root->children[i]);
            }
        }
    }
    free(root);
}
*/

void freeTrie(struct TrieNode *root)
{
    int i;
    if(!root)
    {
        return;
    }

    for(i=0;i<ALPHABETSIZE;i++)
    {
        freeTrie(root->child[i]);
    }
    free(root);    
}
