#include "adt.h"
#include<stdio.h>
#include<stdlib.h>

void enq(qll *q,int x){
    node *tmp;
    tmp = (node *)malloc(sizeof(node));
    tmp->data = x;
    if(q->r==NULL){
        q->f = q->r = tmp;
    }
    else{
        q->r->nxt = tmp;
        q->r = tmp;
    }
}

int deq(qll *q){
    int val;
    val = q->f->data;
    if(q->f!=NULL){
        q->f = q->f->nxt;
        if(q->f==NULL)q->r=NULL;
    }
    return val;
}

void display(qll *q){
    node *ptr;
    ptr = q->f;
    while(ptr){
        printf("%d ",ptr->data);
        ptr = ptr->nxt;
    }
}