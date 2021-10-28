#include<stdio.h>
#include<stdlib.h>

typedef struct tree{
    int data;
    struct tree *l,*r;
}tree;

tree *insert(tree *rt,int x){
    if(rt==NULL){
        rt = (tree*)malloc(sizeof(tree));
        rt->data = x;
        rt->l=rt->r=NULL;
    }
    if(rt->data>x)rt->l = insert(rt->l,x);
    if(rt->data<x)rt->r = insert(rt->r,x);
    return rt;
}

tree *find(tree *rt,int x){
    if(rt==NULL)return NULL;
    if(rt->data==x)return rt;
    if(rt->data>x)return find(rt->l,x);
    if(rt->data<x)return find(rt->r,x);
}

int min(tree *rt){
    if(rt==NULL)return -1;
    tree *ptr = rt;
    while(ptr->l!=NULL){
        ptr = ptr->l;
    }
    return ptr->data;
}

int max(tree *rt){
    if(rt==NULL)return -1;
    tree *ptr = rt;
    while(ptr->r!=NULL){
        ptr = ptr->r;
    }
    return ptr->data;
}

int minrec(tree *rt){
    if(rt==NULL)return -1;
    else{
        if(rt->l==NULL)return rt->data;
        else return minrec(rt->l);
    }
}


void main(){
    tree *root;
    root = NULL;
    root = insert(root,10);
    root = insert(root,5);
    root = insert(root,2);
    root = insert(root,8);
    root = insert(root,4);
}

//changes are reflected check..