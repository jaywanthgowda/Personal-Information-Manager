#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<time.h>
#include "functions.h"

struct queue* create_queue()
{
    struct queue *q=(struct queue*)malloc(sizeof(struct queue));
    q->front=q->rear=NULL;
    return q;
}

struct node* create_node(char *srn)
{
    struct node *n=(struct node*)malloc(sizeof(struct node));
    n->data=(char *)malloc(sizeof(char)*6);
    strcpy(n->data,srn);
    n->next=NULL;
    return n;
    
}

void enqueue(queue *q,char *srn)
{
    node *temp=create_node(srn);
    if(q->rear==NULL)
    {
        q->front = q->rear = temp;
        return;
    }
    (q->rear)->next=temp;
    q->rear=temp;
}

void dequeue(queue *q)
{
    if(q->front==NULL)
    {
        return;
    }
    node *temp=q->front;
    q->front=(q->front)->next;
    if(q->front==NULL)
    {
        q->rear=NULL;
    }
    free(temp);
}


void deleteQueue(struct queue *q)
{  
  struct node* next;
  while (q->front!= NULL) {
    next = q->front->next;
    free(q->front);
    q->front= next;
  }
   free(q);
   q=NULL;

}

