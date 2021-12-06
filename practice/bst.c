#include<stdio.h>
#include<stdlib.h>

typedef struct bst{
    int val;
    struct bst *l,*r;
}bst;

bst *insert(bst *t,int x){
    if(t==NULL){
        t = (bst *)malloc(sizeof(bst));
        t->val = x;
        t->l = t->r = NULL;
    }
    if(t->val<x)t->r = insert(t->r,x);
    if(t->val>x)t->l = insert(t->l,x);
    return t;
}

void inorder(bst *t){//LPR
    if(t){
        inorder(t->l);
        printf("%d ",t->val);
        inorder(t->r);
    }
}

void preorder(bst *t){//PLR
    if(t){
        printf("%d ",t->val);
        preorder(t->l);
        preorder(t->r);
    }
}

void postorder(bst *t){//LRP
    if(t){
        postorder(t->l);
        postorder(t->r);
        printf("%d ",t->val);
    }
}

bst *min(bst *t){
    if(t){
        if(t->l==NULL)return t;
        else return min(t->l);
    }
}

bst *del(bst *t,int x){
    if(t==NULL)return NULL;
    if(t->val>x){
        t->l = del(t->l,x);
    }
    else if(t->val<x){
        t->r = del(t->r,x);
    }
    else{
        if(t->l==NULL){
            bst *tmp = t->r;
            free(t);
            return tmp;
        }
        if(t->r==NULL){
            bst *tmp = t->l;
            free(t);
            return tmp;
        }
        if(t->l && t->r){
            bst *tmp = min(t->r);
            t->val = tmp->val;
            t->r = del(t->r,t->val);
        }
    }
}

int cnt(bst *t){
    if(t==NULL)return 0;
    return 1+cnt(t->l)+cnt(t->r);
}

int isComplete (bst *t,int i,int n)
{
    if (t == NULL)
        return 1;
    if (i>=n)
        return 0;
    return (isComplete(t->l, 2*i+1,n))&&(isComplete(t->r,2*i+2,n));
}

void main(){
    bst *t = (bst*)malloc(sizeof(bst));
    t = NULL;
    t = insert(t,1);
    t = insert(t,0);
    t = insert(t,2);
    //t = del(t,0);
    inorder(t);
    printf("\n");
    preorder(t);
    printf("\n");
    postorder(t);
    printf("\ncnt:%d",cnt(t));
    printf("\nComplete: %d\n",isComplete(t,0,cnt(t)));
}