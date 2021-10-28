#include "adt.h"
#include<stdio.h>
#include<stdlib.h>

void push(queue **t,int x){
    queue *temp;
    temp = (queue *)malloc(sizeof(queue));
    temp->data = x;
    temp->nxt = *t;
    *t = temp;
}

void pop(queue **t){
    *t = (*t)->nxt;
}

int isEmpty(queue *t){
    return t==NULL;
}

void display(queue *t){
    queue *ptr;
    ptr = t;
    if(isEmpty(ptr)){
        printf("queue Empty\n");
        return ;
    }
    while(ptr){
        printf("%d",ptr->data);
        if(ptr->nxt!=NULL)printf("->");
        ptr = ptr->nxt;
    }
    printf("\n");
}

int top(queue *t){
    if(!isEmpty(t))
        return t->data;
}

void deq(queue **t){
    queue *tmp;
    tmp = NULL;
    while((*t)->nxt){
        push(&tmp,top(*t));
        pop(t);
    }
    pop(t);
    while(tmp){
        push(t,top(tmp));
        pop(&tmp);
    }
}