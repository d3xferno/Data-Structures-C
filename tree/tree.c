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

tree *minrec(tree *rt){
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
    if(t==NULL)return 1;
    if(i>=c)return 0;
    return isComplete(t->l,2*i+1,c)&&isComplete(t->r,2*i+2,c);
}

tree *del(tree *t,int x){
    if(t==NULL)return NULL;
    if(x<t->data){
        t->l = del(t->l,x);
    }
    else if(x>t->data){
        t->r = del(t->r,x);
    }
    else{
        if(t->l==NULL){
            tree *tmp = t->r;
            free(tmp);
            return tmp;
        }
        if(t->r==NULL){
            tree *tmp = t->l;
            free(tmp);
            return tmp;
        }
        if(t->r && t->l){
            tree *tmp = minrec(t->r);
            t->data = tmp->data;
            t->r = del(t->r,tmp->data);
        }
    }
    return t;
}


void curlvl(tree *t,int lvl){
    if(!t)return;
    if(lvl==1)printf("%d ",t->data);
    else{
        curlvl(t->l,lvl-1);
        curlvl(t->r,lvl-1);
    }
}

void lvlorder(tree *t,int h){
    for(int i=1;i<=h;i++){
        curlvl(t,i);
        printf("\n");
    }
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
    t1 = t2 = NULL;
    t1 = insert(t1,29);
    t1 = insert(t1,23);
    t1 = insert(t1,4);
    t1 = insert(t1,13);
    t1 = insert(t1,39);
    t1 = insert(t1,31);
    t1 = insert(t1,45);
    t1 = insert(t1,56);
    t1 = insert(t1,49);
    t2 = insert(t2,29);
    t2 = insert(t2,23);
    t2 = insert(t2,4);
    t2 = insert(t2,13);
    t2 = insert(t2,39);
    t2 = insert(t2,31);
    t2 = insert(t2,45);
    t2 = insert(t2,56);
    t2 = insert(t2,49);
    printf("INORDER:");
    inorder(t1);
    printf("\n");
    printf("LEVEL_ORDER:\n");
    lvlorder(t1,height(t1));

    printf("MIN:%d\n",min(t1));
    if(identical(t1,t2)){
        printf("\nt1 and t2 are IDENTICAL");
    }
    printf("\nTREE 1 is not complete");
    printf("\nNo of Nodes in range are:");
    printf("\nrange:%d",range(t1,5,45));
}
