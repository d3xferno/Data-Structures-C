#include "adt.h"
#include<stdio.h>
#include<stdlib.h>

struct listAdt * insertFront(struct listAdt *l,char c){
  struct listAdt *temp;
  temp = (struct listAdt *)malloc(sizeof(struct listAdt));
  temp->nxt = NULL;
  temp->pre = NULL;
  temp->val = c;
  if(l==NULL){
    l=temp;
    return l;
  }
  l->pre = temp;
  temp->nxt = l;
  temp->pre = NULL;
  l=temp;
  return l;
}

void insertEnd(struct listAdt *l,char c){
  struct listAdt *ptr,*temp;
  temp = (struct listAdt *)malloc(sizeof(struct listAdt));
  ptr = l;
  while(ptr->nxt!=NULL){
    ptr =ptr->nxt;
  }
  temp->val = c;
  temp->pre = ptr;
  ptr->nxt = temp;
  temp->nxt = NULL;
}

void insertMiddle(struct listAdt *l,char c,char d){
  struct listAdt *temp,*ptr;
  ptr = l;
  while(ptr){
    if(ptr->val==c){
      break;
    }
    ptr = ptr->nxt;
  }
  temp = (struct listAdt *)malloc(sizeof(struct listAdt));
  temp->val = d;
  temp->pre = ptr;
  temp->nxt = ptr->nxt;
  ptr->nxt = temp;
}

void display(struct listAdt *l){
  struct listAdt *ptr;
  ptr=l;
  if(ptr==NULL)printf("Empty");
  while(ptr!=NULL){
    printf("%c ",ptr->val);
    ptr = ptr->nxt;
  }
}

void deleteItem(struct listAdt **l,char c){
  struct listAdt *ptr;
  ptr = *l;
  while(ptr){
    if(ptr->val==c){
      break;
    }
    ptr=ptr->nxt;
  }
  if(ptr->nxt==NULL){
    ptr->pre->nxt = NULL;
  }
  else if(ptr==*l){
    *l = (*l)->nxt;
    (*l)->pre = NULL;
  }
  else{
    ptr->pre->nxt = ptr->nxt;
    ptr->nxt->pre = ptr->pre;
  }
}

int searchItem(struct listAdt *l,char c){
  int cnt=0;
  struct listAdt *ptr;
  ptr = l;
  while(ptr){
    if(ptr->val==c){
      cnt++;
    }
    ptr=ptr->nxt;
  }
  return cnt;
}

void isPalindrome(struct listAdt *h){
    struct listAdt *l,*r;
    l=h;
    r=h;
    while(r->nxt){
        r =r->nxt;
    }
    while(l!=r && r!=l->pre){
        if(l->val==r->val){
            l = l->nxt;
            r = r->pre;
        }
        else{
            printf("\nNot a Palindrome");
            return ;
        }
    }
    printf("\nPalindrome");
}

void sep(struct listAdt *h){
    struct listAdt *con,*vow,*ptr;
    ptr = h;
    con = (struct listAdt *)malloc(sizeof(struct listAdt));
    vow = (struct listAdt *)malloc(sizeof(struct listAdt));
    con = NULL;
    vow = NULL;
    con = insertFront(con,'*');
    vow = insertFront(vow,'*');
    while(ptr){
        if(ptr->val=='A' || ptr->val=='E' || ptr->val=='I' || ptr->val=='O' || ptr->val=='U'){
            insertEnd(vow,ptr->val);
        }
        else{
            insertEnd(con,ptr->val);
        }
        ptr = ptr->nxt;
    }
    con = con->nxt;
    vow = vow->nxt;
    printf("Consonants:");
    display(con);
    printf("\nVowels:");
    display(vow);
}

void swaps(struct listAdt *h,int k){
    struct listAdt *l,*r;
    l=h;
    r=h;
    int i=0;
    while(r->nxt){
        r = r->nxt;
        i++;
    }
    if(i<k){
        printf("Too big\n");
        return ;
    }
    k-=1;
    while(k-- && l->nxt!=NULL && r->pre!=NULL){
        l = l->nxt;
        r = r->pre;
    }
    char temp;
    temp = l->val;
    l->val = r->val;
    r->val = temp;
}