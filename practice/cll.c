#include<stdio.h>
#include <stdlib.h>

typedef struct circularll{
  int data;
  struct circularll *nxt;
}cll;

void insert(cll **h,int x){
  cll *tmp,*ptr;
  tmp = (cll *)malloc(sizeof(cll));
  tmp->data = x;
  ptr = *h;
  if(*h==NULL){
    *h = tmp;
    tmp->nxt = *h;
    return;
  }
  while(ptr->nxt!=*h){
    ptr = ptr->nxt;
  }
  ptr->nxt = tmp;
  tmp->nxt = *h;
}

void insertf(cll **h,int x){
  cll *tmp,*ptr;
  tmp = (cll *)malloc(sizeof(cll));
  tmp->data =x;
  ptr = *h;
  while(ptr->nxt!=*h){
    ptr = ptr->nxt;
  }
  if(*h==NULL){
    *h = tmp;
    tmp->nxt = *h;
    return;
  }
  tmp->nxt = *h;
  *h = tmp;
  ptr->nxt = tmp;
}

void display(cll *h){
  cll *ptr;
  ptr = h;
  while(ptr->nxt!=h){
    printf("%d ",ptr->data);
    ptr = ptr->nxt;
  }
  printf("%d ",ptr->data);
}

void del(cll **h,int x){
  cll *ptr,*pre;
  ptr = pre = *h;
  while(ptr->data!=x){
    pre = ptr;
    ptr = ptr->nxt;
  }
  if(ptr==pre){
    while(ptr->nxt!=*h){
      ptr = ptr->nxt;
    }
    *h = pre->nxt;
    ptr->nxt = *h;
  }
  else{
    pre->nxt = ptr->nxt;
  }
}

void josephus(cll **h,int k){
  cll *ptr;
  ptr = *h;
  int cnt=0;
  while(ptr->nxt!=*h){
    cnt++;
    ptr = ptr->nxt;
  }
  cll *p;
  p = *h;
  while(cnt--){
    for(int i=0;i<k-1;i++){
      p =p->nxt;
    }
    del(&p,p->data);
  }
  printf("\n");
  display(p);
}

void main(){
  cll *h;
  h=NULL;
  insert(&h,1);
  insert(&h,2);
  insert(&h,3);
  insert(&h,4);
  insert(&h,5);
  //insert(&h,6);
  //insert(&h,7);
  display(h);
  int k=2;
  josephus(&h,k);
}

