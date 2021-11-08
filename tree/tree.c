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
    tree *ptr = rt;
    while(ptr->r!=NULL){
        ptr = ptr->r;
    }
    return ptr->data;
}

tree* minrec(tree *rt){
    if(rt){
        if(rt->l==NULL)return rt;
        else return minrec(rt->l);
    }
}

void inorder(tree *t){
    if(t){
        inorder(t->l);
        printf("%d ",t->data);
        inorder(t->r);
    }
}

int identical(tree *t1,tree *t2){
    if(t1==NULL && t2==NULL){
        return 1;
    }
    if(t1 && t2){
        return (t1->data==t2->data)&&(identical(t1->l,t2->l))&&(identical(t1->r,t2->r));
    }
    return 0;
}

int cnt(tree *t){
    if(t==NULL)return 0;
    return 1+cnt(t->l)+cnt(t->r);
}

int isComplete(tree *t,int i,int c){
    if(t==NULL)return 0;
    if(i>=c)return 0;
    return isComplete(t->l,2*i+1,c)&&isComplete(t->r,2*i+2,c);
}

tree *del(tree *t,int x){
    if(t==NULL)return t;
    if(t->data>x){
        t->l = del(t->l,x);
    }
    if(t->data<x){
        t->r = del(t->r,x);
    }
    if(t->data==x){
        if(t->l==NULL){
            tree *tmp = t->r;
            free(t);
            return tmp;
        }
        else if(t->r==NULL){
            tree *tmp = t->l;
            free(t);
            return tmp;
        }
        else{
            tree *tmp = minrec(t->r);
            t->data = tmp->data;
            t->r = del(t->r,tmp->data);
        }
    }
    return t;
}

int height(tree *t){
    if(t==NULL)return 0;

    int lh = height(t->l);
    int rh = height(t->r);

    return lh>rh?lh+1:rh+1;
}

int range(tree *t,int lo,int hi){
    if(t==NULL)return 0;
    if(t->data<=hi && t->data>=lo){
        return 1+range(t->l,lo,hi)+range(t->r,lo,hi);
    }
    if(t->data<lo){
        return range(t->r,lo,hi);
    }
    if(t->data>hi){
        return range(t->l,lo,hi);
    }
}

void main(){
    tree *t1,*t2;
    t1 = NULL;
    t1 = insert(t1,10);
    t1 = insert(t1,5);
    t1 = insert(t1,50);
    t1 = insert(t1,1);
    t1 = insert(t1,40);
    t1 = insert(t1,100);

    t2 = NULL;
    t2 = insert(t2,10);
    t2 = insert(t2,5);
    t2 = insert(t2,50);
    t2 = insert(t2,1);
    t2 = insert(t2,40);
    t2 = insert(t2,100);
    printf("%d %d",height(t1),height(t2));
    printf("\n%d %d",range(t1,5,45),range(t2,1,45));
}
