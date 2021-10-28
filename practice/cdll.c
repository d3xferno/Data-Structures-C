#include<stdio.h>
#include<stdlib.h>

typedef struct cirdoubll{
    int data;
    struct cirdoubll *nxt,*pre;
}cdll;

void insert(cdll **h,int x){
    cdll *tmp,*ptr;
    tmp = (cdll *)malloc(sizeof(cdll));
    tmp->data = x;
    ptr = *h;
    if(*h==NULL){
        *h = tmp;
        tmp->nxt = tmp->pre = *h;
        return;
    }
    while(ptr->nxt!=*h){
        ptr = ptr->nxt;
    }
    ptr->nxt = tmp;
    tmp->pre = ptr;
    tmp->nxt = *h;
}

void display(cdll *h){
    cdll *ptr;
    ptr = h;
    while(ptr->nxt!=h){
        printf("%d ",ptr->data);
        ptr = ptr->nxt;
    }
    printf("%d",ptr->data);
}

void del(cdll **h,int x){
    cdll *ptr;
    ptr = *h;
    while(ptr->data!=x){
        ptr = ptr->nxt;
    }
    if(ptr==*h){
        
    }
    ptr->pre->nxt = ptr->nxt;
    ptr->nxt->pre = ptr->pre;
}

void main(){
    cdll *h;
    h = NULL;
    insert(&h,1);
    insert(&h,2);
    insert(&h,3);
    del(&h,2);
    del(&h,3);
    display(h);
}