#include<stdio.h>
#include<stdlib.h>

struct stack{
    char data;
    struct stack *nxt;
};

void push(struct stack **t,char x){
    struct stack *temp;
    temp = (struct stack *)malloc(sizeof(struct stack));
    temp->data = (char)x;
    temp->nxt = *t;
    *t = temp;
}

void pop(struct stack **t){
    *t = (*t)->nxt;
}

int isEmpty(struct stack *t){
    return t==NULL;
}

void display(struct stack *t){
    struct stack *ptr;
    ptr = t;
    if(isEmpty(ptr)){
        printf("Stack Empty\n");
        return ;
    }
    while(ptr){
        printf("%c ",ptr->data);
        ptr = ptr->nxt;
    }
    printf("\n");
}

char top(struct stack *t){
    if(!isEmpty(t))
        return t->data;
}