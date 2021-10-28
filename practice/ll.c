#include <stdio.h>
#include<stdlib.h>

typedef struct ll{
  int data;
  struct ll *nxt;
}ll;

void insert(ll **h,int x){
  ll *new;
  new = (ll *)malloc(sizeof(ll));
  new->data = x;
  if(*h==NULL){
    *h = new;
    new->nxt = NULL;
    return;
  }
  ll *ptr;
  ptr = *h;
  while(ptr->nxt){
    ptr = ptr->nxt;
  }
  ptr->nxt = new;
  new->nxt = NULL;
}

void display(ll *h){
  ll *ptr;
  ptr=h;
  while(ptr){
    printf("%d ",ptr->data);
    ptr = ptr->nxt;
  }
}

void reverse(ll **h){
  ll *cur,*pre,*nxt;
  pre = nxt = NULL;
  cur = *h;
  while(cur){
    nxt = cur->nxt;
    cur->nxt = pre;
    pre = cur;
    cur = nxt;
  }
  *h = pre;
  printf("\n");
}

void main(){
  ll *h;
  h = NULL;
  insert(&h,1);
  insert(&h,2);
  insert(&h,3);
  display(h);
  reverse(&h);
  display(h);
}