#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node * nxt;
}node;

typedef struct cirq{
    node *f,*r;
}cq;

void insert(cq *h,int x){
    node *new;
    new = (node *)malloc(sizeof(node));
    new->data = x;
    if(h->f==NULL){
        h->f=h->r=new;
        h->r->nxt = h->f;
        return;
    }
    h->r->nxt = new;
    h->r = new;
    new->nxt = h->f;
}

void display(cq *h){
    node *ptr;
    ptr = h->f;
    while(ptr->nxt!=h->f){
        printf("%d ",ptr->data);
        ptr = ptr->nxt;
    }
    printf("%d",ptr->data);
}

void del(cq *h){
    h->r->nxt = h->f->nxt;
    h->f = h->f->nxt;
}

void main(){
    cq *q;
    q = (cq *)malloc(sizeof(cq));
    q->f = q->r = NULL;
    insert(q,1);
    insert(q,2);
    insert(q,3);
    del(q);
    display(q);
}

